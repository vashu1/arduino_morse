#ifndef MORSE_SETTINGS_H
#define MORSE_SETTINGS_H

//TODO optimize to external
//extern const char ENCODER_CHAR_TABLE[];
const char ENCODER_CHAR_TABLE[] = " abcdefghijklmnopqrstuwxyz1234567890";

const char ENCODER_MORSE_TABLE[sizeof(ENCODER_CHAR_TABLE)][6] = {// [6] - max length if str
	 " "// SPACE  1
	, ".-" //"A"  2
	, "-..."//"B" 3
	, "-.-."//"C"  4
	, "-.."	//"D"  5
	, "."	//"E",  6
	, "..-."//"F"  7
	, "--."	//"G"  8
	, "...."//"H"  9
	, ".."	//"I"  10
	, ".---"//"J",  11
	, "-.-"//"K"  12
	, ".-.." // "L"  13
	, "--" //"M"  14
	, "-." //"N"  15
	, "---"//"O",  16
	, ".--." // "P"  17
	, "--.-" // "Q"  18
	, ".-."//"R"  19
	, "..."//"S"  20
	, "-" //"T",  21
	, "..-"//"U"  22
	, "...-" // "V"  23
	, ".--"//"W"  24
	, "-..-" // "X"  25
	, "-.--" // "Y",  26
	, "--.." // "Z"  27
	, ".----" // "1"  28
	, "..---" // "2"  29
	, "...--" // "3",  30
	, "....-" // "4"  31
	, "....." // "5"  32
	, "-...." // "6"  33
	, "--..." // "7",  34
	, "---.." // "8"  35
	, "----." // "9"  36
	, "-----" // "0"  37
};

#endif//MORSE_SETTINGS_H
