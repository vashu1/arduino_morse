#ifndef MORSE_ENCODER_H
#define MORSE_ENCODER_H

#include <Arduino.h>

class MorseEncoder {
  public:
    MorseEncoder(int pin, int dotDuration, void (* on)(int), void (* off)(int));
    MorseEncoder(int pin, int dotDuration);
    
    static const int ENCODING_BUZZER_FREQ = 1000;
    
    static void buzzerOn(int pin);
    static void buzzerOff(int pin);
    
    static void vibroOn(int pin);
    static void vibroOff(int pin);
  
    int ENCODING_DOT_LENGTH; // in msec
    
    // call this function at 1000/ENCODING_DOT_LENGTH freq or more
    // to play data 
    void loopPlayMorse();
    
    // returns false if encoder is buzy or str is too long
    boolean playMorse(const char *str);
    
    boolean isPlayingMorse();
    
    void resetEncoder();


  private:
    int ENCODING_PIN;
      
    void (* ENCODING_MORSE_ON)(int);
    void (* ENCODING_MORSE_OFF)(int);
    
    char *currentString;
    int encodingCharTableIndex;
    char dashDotPauseIndex;
    unsigned long waitTillMsec; // no checks for 50th day overflow!
    
    void searchCurrentCharInTable();

    void removeFirstEncodingBufferChar();
    
    boolean isCurrentCharFinished();

    boolean afterDashDotGap; // used in loopPlayMorse() only
    
    void init();
};

#endif//MORSE_ENCODER_H
