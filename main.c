// Temperature Calculator by NaИ Λrk
// Created by Reymo Je
// IOS(Informatics of SMANA)

/*
HOW TO COMPILE
>> clang *.c -o ~/bin/temcal -Wall -Wextra -Ofast -DTEMCAL_EN && clang *.c -o ~/bin/temcal-id -Wall -Wextra -Ofast -DTEMCAL_ID
This will compile the source code into machine code both in English and Indonesian
Note : TEMCAL_EN for English, TEMCAL_ID for Indonesian
*/

/*
HOW TO USE
User just simply type : temcal [mode] [value]
Instruction type : temcal --help or -h
Any Unit : temcal --min [min] --max [max] [value]
-
Pengguna cukup mengetik : temcal [mode] [nilai]

MODES
c-r : Celcius to Reamur
c-f : Celcius to Fahrenheit
c-k : Celcius to Kelvin
r-c : Reamur to Celcius
r-f : Reamur to Fahrenheit
r-k : Reamur to Kelvin
f-c : Fahrenheit to Celcius
f-r : Fahrenheit to Reamur
f-k : Fahrenheit to Kelvin
k-c : Kelvin to Celcius
k-f : Kelvin to Fahrenheit
k-r : Kelvin to Reamur
*/

#define USAGE_MSG \
	"Usage : temcal [mode] [value]\n"

#define USAGE_MSG_ID \
	"Ketik : temcal-id [mode] [nilai]\n"

#include <stdio.h>
#include <string.h>

// MODES
#define CELCIUS 0
#define REAMUR 1
#define FAHRENHEIT 2
#define KELVIN 3
typedef int TempMode;

// Min and Max Degree of each unit
#define CELCIUS_MIN 0
#define CELCIUS_MAX 100
#define REAMUR_MIN 0
#define REAMUR_MAX 80
#define FAHRENHEIT_MIN 32
#define FAHRENHEIT_MAX 212
#define KELVIN_MIN 273.15
#define KELVIN_MAX 373.15

// This function calculates the target temperature
float calculateTemperature (
		float minInput,
		float maxInput,
		float minOutput,
		float maxOutput,
		float inputValue
		) {
	return (inputValue - minInput / maxInput - minInput) * (maxOutput - minOutput) + minOutput;
}

// Main Function
int main(int argc, const char* argv[]) {
	for(int i = 1; i < argc; i++) {
		if(argv[i][0] == '-') {
			if(strcmp(argv[i], "-debug")) {
#ifdef TEMCAL_EN
				printf(USAGE_MSG);
				printf("30 Celcius = %f Reamur\n", calculateTemperature(CELCIUS_MIN, CELCIUS_MAX, REAMUR_MIN, REAMUR_MAX, 30.0));
#endif
#ifdef TEMCAL_ID
				printf(USAGE_MSG_ID);
#endif
			}
		}
	}

	return 0;
}
