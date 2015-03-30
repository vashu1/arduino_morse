#ifndef MORSE_DECODER_H
#define MORSE_DECODER_H

#include <Arduino.h>

class MorseDecoder {
  public:
    MorseDecoder(int pin, int dotMsec);
    
    void (* resetCallback)();
    void (* decodedWordCallback)(char *word);

    void loopDecodeMorse();
    
    static void printWord(char *str);

    
  private:
    int dotSize;
    int dashSize;
    int dotPauseSize;
    int letterPauseSize;
    
    int meanPip();
    
    int meanPause();
    
    int DECODING_MORSE_PIN;
    static const int DASH_DOT_BUFFER_SIZE=256;
    int dashDotBufferSize;
    unsigned short dashDotBuffer[DASH_DOT_BUFFER_SIZE];
    
    boolean testPin();
    
    boolean pinOn;
    long time;
    
    void resetBuffers();
        
    static const float fixMul = 0.5f;
    
    char searchCode(String code);
    
    char decodeChar(int &bufferPosition);
    
    void decodeWord();
    
    void fixDotSettings();
};

#endif//MORSE_DECODER_H
