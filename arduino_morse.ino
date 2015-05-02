#include "MorseEncoder.h"
#include "MorseDecoder.h"

const int ENCODING_BUZZER_PIN = A1;
MorseEncoder *morseEncoder = new MorseEncoder(ENCODING_BUZZER_PIN, 100);
MorseEncoder *morseEncoderQuick = new MorseEncoder(ENCODING_BUZZER_PIN, 35);

const int DECODING_KEY_PIN = A3;
MorseDecoder *morseDecoder = new MorseDecoder(DECODING_KEY_PIN, 100);

//"a", "i", "e", "m", "n", "t"
//"in", "it", "at", "an", "me", "am", "man", "ten", "men", "eat", "net", "aim", "ant", "inn", "int"
//, "name", "mean", "main", "meet", "time", "team"
// "amen", "anna", "ante", "anti", "emit", "item", "main", "mama", "mane", "mate", "meat", "meta", "mime", "mine", "neat", "tame", "teen", "tent", "tint", 
// "mania", "anime", "enema", "inane", "titan", 
char vocabulary[][5] = {
"in", "it", "at", "an", "me", "am", "man", "ten", "men", "eat", "net", "aim", "ant", "inn", "int"};//, "name", "mean", "main", "meet", "time", "team"};
char *cur = 0;
void startTest() {
  randomSeed(millis());
  Serial.print("Start Test - ");
  cur = vocabulary[random(0, sizeof(vocabulary) / sizeof(vocabulary[0]))];
  Serial.println(cur);
  morseEncoder->playMorse(cur);
}
char msg[128];
void endTest(char *str) {
  if(morseEncoder->isPlayingMorse())
    return;
  if(String(cur) == "n") { // new word on 'n' letter
    startTest();
    return;
  }
  Serial.print("End Test - ");
  if(String(str) != String(cur)) {
    Serial.println(str);
    Serial.println(cur);
    String(String(str) + "   " + String(cur)).toCharArray(msg, sizeof(msg));
    morseEncoder->playMorse(msg);
  } else {
      morseEncoderQuick->playMorse("ok");
      Serial.println("OK");
  }
}

void setup() {
  Serial.begin(9600); 
  pinMode(ENCODING_BUZZER_PIN, OUTPUT);
  pinMode(DECODING_KEY_PIN, INPUT_PULLUP);

  morseDecoder->resetCallback = startTest;
  morseDecoder->decodedWordCallback = endTest;
 
  morseEncoderQuick->playMorse("ok");
}

void loop() {
  morseEncoder->loopPlayMorse();
  morseEncoderQuick->loopPlayMorse();
  
  morseDecoder->loopDecodeMorse();
  
  // key sound
  if(!morseEncoder->isPlayingMorse() && !morseEncoderQuick->isPlayingMorse()) {
    if(morseDecoder->testPin()) {
      MorseEncoder::buzzerOn(ENCODING_BUZZER_PIN);  
    } else {
      MorseEncoder::buzzerOff(ENCODING_BUZZER_PIN);
    } 
  } else {
    // to stop replay - simply press the button
    morseEncoder->resetEncoder();
    morseEncoderQuick->resetEncoder();
  }
}
