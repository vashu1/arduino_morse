#include "MorseEncoder.h"
#include "MorseSettings.h"

MorseEncoder::MorseEncoder(int pin, int dotDuration, void (* on)(int), void (* off)(int)) {
  ENCODING_PIN = pin;
  ENCODING_DOT_LENGTH = dotDuration;
  ENCODING_MORSE_ON = on;
  ENCODING_MORSE_OFF = off;
  
  init();
}

MorseEncoder::MorseEncoder(int pin, int dotDuration) { 
  ENCODING_PIN = pin;
  ENCODING_DOT_LENGTH = dotDuration;
  ENCODING_MORSE_ON = buzzerOn;
  ENCODING_MORSE_OFF = buzzerOff;
  
  init();
}

//static 
void MorseEncoder::buzzerOn(int pin) {
  //Serial.print("on ="); //debug
  //Serial.println(millis());
  tone(pin, ENCODING_BUZZER_FREQ);
}

//static 
void MorseEncoder::buzzerOff(int pin) {
  //Serial.print("off="); //debug
  //Serial.println(millis());
  noTone(pin); 
}

//static 
void MorseEncoder::vibroOn(int pin) {
  analogWrite(pin, 255);
}

//static 
void MorseEncoder::vibroOff(int pin) {
  analogWrite(pin, 0);
}

// call this function at 1000/ENCODING_DOT_LENGTH freq or more
// to play data 
void MorseEncoder::loopPlayMorse() {
  if(waitTillMsec > millis()) 
	return;

  if(afterDashDotGap) {
	waitTillMsec = millis() + ENCODING_DOT_LENGTH;
	if(isCurrentCharFinished()) // letter gap = 3 dots
	  waitTillMsec = millis() + 3 * ENCODING_DOT_LENGTH;
	if(!isPlayingMorse())// word pause at the end
	  waitTillMsec = millis() + 7 * ENCODING_DOT_LENGTH;
	ENCODING_MORSE_OFF(ENCODING_PIN);
	afterDashDotGap = false;
	return;
  }

  REPEAT:    
  if(!isPlayingMorse())
	return;
  if(encodingCharTableIndex == -1) 
	searchCurrentCharInTable();
  if(encodingCharTableIndex == -1) 
	return;//unknown symbol
  if(isCurrentCharFinished()) {
	removeFirstEncodingBufferChar(); 
	goto REPEAT; // the horror of goto!
  }
  //playing curent dash-dot-pause
  switch(ENCODER_MORSE_TABLE[encodingCharTableIndex][dashDotPauseIndex++]) {
	case '.':
	waitTillMsec = millis() + ENCODING_DOT_LENGTH;
	ENCODING_MORSE_ON(ENCODING_PIN);
	break;
	
	case '-':
	waitTillMsec = millis() + 3 * ENCODING_DOT_LENGTH;
	ENCODING_MORSE_ON(ENCODING_PIN);
	break;
	
	case ' ': // only onedot pause - 3 more will be added as after-char-gap after, and before we had another 3
	waitTillMsec = millis() + ENCODING_DOT_LENGTH;
	ENCODING_MORSE_OFF(ENCODING_PIN);
	break;
	
	default:
	resetEncoder();// error in table
	return;
  }
  afterDashDotGap = true;
}

// returns false if encoder is buzy or str is too long
boolean MorseEncoder::playMorse(const char *str) {
  if(isPlayingMorse())
	return false;
  currentString = String(str);// copy constructor 
  return true;
}

boolean MorseEncoder::isPlayingMorse() {
  return currentString.length() > 0;
}

void MorseEncoder::resetEncoder() {
  //Serial.println("resetEncoder");//debug
  currentString = "";
  encodingCharTableIndex = -1;
  dashDotPauseIndex = -1;
  waitTillMsec = 0;
}

void MorseEncoder::searchCurrentCharInTable() {
  for(int i = 0; ENCODER_MORSE_TABLE[i] != 0 ; i++) {
	if(currentString[0] == ENCODER_CHAR_TABLE[i]) {
	  encodingCharTableIndex = i;
	  dashDotPauseIndex = 0;
	  return;
	}
  }
  resetEncoder();// didn't find anything, error, reset(encodingCharTableIndex = -1)
}

void MorseEncoder::removeFirstEncodingBufferChar() {
  currentString = currentString.substring(1);//remove first char
  //if(currentString[0] == 0)
  //	  currentString = 0;
  encodingCharTableIndex = -1;
}

boolean MorseEncoder::isCurrentCharFinished() {
  return ENCODER_MORSE_TABLE[encodingCharTableIndex][dashDotPauseIndex] == 0;
}

void MorseEncoder::init() {
  encodingCharTableIndex = -1;
  dashDotPauseIndex = -1;
  waitTillMsec = 0; 
  afterDashDotGap = false;
  currentString = "";
  waitTillMsec = 0;
}
