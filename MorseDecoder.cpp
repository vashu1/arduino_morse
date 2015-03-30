#include "MorseDecoder.h"
#include "MorseSettings.h"

MorseDecoder::MorseDecoder(int pin, int dotMsec) {
  DECODING_MORSE_PIN = pin;
  dotSize = dotMsec;
  dashSize = 3*dotMsec;
  dotPauseSize = dotMsec;
  letterPauseSize = 3*dotMsec;
  time = 0;
  pinOn = false;
  dashDotBufferSize=0;
  
  decodedWordCallback = printWord;// just print at Serial by default
  resetCallback = 0;
}

void MorseDecoder::loopDecodeMorse() {
  long interval = millis()-time;

  if(pinOn ^ testPin()) {  // pin state changed
	if(interval<10) {//TODO better
	  if(dashDotBufferSize == 0)
		return;
	  Serial.print("j");//debug
	  dashDotBuffer[dashDotBufferSize-1] += interval & ~0x1; 
	  return;
	}
	
	pinOn = testPin();
	time = millis();
	
	if(pinOn && (dashDotBufferSize==0))
	  return; // don't write length of before letter pause in buffer 
	  
	dashDotBuffer[dashDotBufferSize  ] = interval & ~0x1;
	dashDotBuffer[dashDotBufferSize++] |= pinOn ? 0 : 1;// write value of the pin on the previous interval
  }
  
  if(interval>2*meanPause()) { // got word
	if(pinOn) {
	  time = millis();
	  if(resetCallback != 0)
		resetCallback();
	  //TODO call other callback
	  resetBuffers(); 
	} else {
	  if(dashDotBufferSize == 0)
		return;
	  decodeWord();
	  //fixDotSettings();
	  resetBuffers();
	}
  }
}  

//static 
void MorseDecoder::printWord(char *str) {
  Serial.println(str);
}

int MorseDecoder::meanPip(){
  return (dotSize + dashSize) / 2;
}

int MorseDecoder::meanPause(){
  return (dotPauseSize + letterPauseSize) / 2;
}

boolean MorseDecoder::testPin() { // true if key is pressed, false otherwise  //TODO add filter for button jitter
  return analogRead(DECODING_MORSE_PIN) < 512;
}

void MorseDecoder::resetBuffers() {
  //Serial.println("reset");//debug
  dashDotBufferSize = 0;
}
	
char MorseDecoder::searchCode(String code) {
  Serial.println(code);
  //Serial.println("decodeCode="+code);//debug
  if(code.length() == 0)
	return 0;
  for(int i = 0; i < sizeof(ENCODER_CHAR_TABLE)-1 ; i++) 
	if(code == ENCODER_MORSE_TABLE[i]) 
	  return ENCODER_CHAR_TABLE[i];
  return '*';
}

char MorseDecoder::decodeChar(int &bufferPosition) {
  if(bufferPosition >= dashDotBufferSize)
	  return 0;
  String code = String("");
  while(1) {
	boolean   pip = dashDotBuffer[bufferPosition  ] & 0x1;
	int  interval = dashDotBuffer[bufferPosition++];
	
	if(pip) {
	  code += (interval < meanPip()) ? '.' : '-';
	} else {
	  if(interval > meanPause())
		return searchCode(code);          
	}
	if(bufferPosition >= dashDotBufferSize)
	  return searchCode(code);
  }
}

void MorseDecoder::decodeWord() {
  Serial.println("decodeWord");//debug
  for(int j=0; j<dashDotBufferSize ; j++) {
	Serial.print(dashDotBuffer[j]);Serial.print(" ");
  }
  Serial.println(" ");;
  String result = String("");
  
  char cur;
  int bufferPosition = 0;
  while((cur = decodeChar(bufferPosition)) != 0) {
	result += cur;
  }
  
  if((decodedWordCallback != 0))
	decodedWordCallback((char*)result.c_str());
}

void MorseDecoder::fixDotSettings(){
  if(dashDotBufferSize<3)
	return;
  for(int flag = 0; flag<=1 ; flag++) {
	int minMax[] = {10000, 0};
	int i;
	for(i=0; i < dashDotBufferSize ; i++) {
	  if(dashDotBuffer[i]&0x1 != flag)
		continue;
	  if(dashDotBuffer[i] < minMax[0])
		minMax[0] = dashDotBuffer[i];
	  if(dashDotBuffer[i] > minMax[1])
		minMax[1] = dashDotBuffer[i];
	}
	int mean = (minMax[0] + minMax[1]) / 2, sums[] = {0, 0}, counts[] = {0, 0};
	for(i=0; i < dashDotBufferSize ; i++) {
	  if(dashDotBuffer[i]&0x1 != flag)
		continue;
	  int index = (dashDotBuffer[i] < mean) ? 0 :1;
	  sums[index] += dashDotBuffer[i]; 
	  counts[index]++;
	}
	int meanDot  = sums[0]/counts[0];
	int meanDash = sums[1]/counts[1];
	if(meanDash < 2*meanDot)
	  return;
	if(flag) {
	  dotSize += (int)((meanDot - dotSize) * fixMul);
	  dashSize += (int)((meanDash - dashSize) * fixMul);
	} else {
	  dotPauseSize += (int)((dotPauseSize - dotSize) * fixMul);
	  letterPauseSize += (int)((letterPauseSize - dashSize) * fixMul);
	}
  }
  Serial.print("dotSize=");Serial.println(dotSize);//debug
  Serial.print("dashSize=");Serial.println(dashSize);
  Serial.print("dotPauseSize=");Serial.println(dotPauseSize);
  Serial.print("letterPauseSize=");Serial.println(letterPauseSize);
}
