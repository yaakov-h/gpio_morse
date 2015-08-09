#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

void PrintUsageAndExit();
void Dit(int gpio);
void Dah(int gpio);

const int PinOnTimeMs = 500;
const int PinOffTimeMs = 500;

int main(int argc, const char * argv[])
{
	if (argc < 3)
	{
		PrintUsageAndExit();
	}

	int pin = atoi(argv[1]);
	if (pin == 0)
	{
		PrintUsageAndExit();
	}

	wiringPiSetup();
	wiringPiSetupGpio(); // Use Broadcom GPIO pin numbers
	pinMode(pin, OUTPUT);

	for (int argvIdx = 2; argvIdx < argc; argvIdx++)
	{
		const char * currentWord = argv[argvIdx];
	
		for (char current = *currentWord; current != '\0'; current = *++currentWord)
		{
			switch (toupper(current))
			{
				case 'A':
					Dit(pin);
					Dah(pin);
					break;
	
				case 'B':
					Dah(pin);
					Dit(pin);
					Dit(pin);
					Dit(pin);
					break;

				case 'C':
					Dah(pin);
					Dit(pin);
					Dah(pin);
					Dit(pin);
					break;

				case 'D':
					Dah(pin);
					Dit(pin);
					Dit(pin);
					break;

				case 'E':
					Dit(pin);
					break;

				case 'F':
					Dit(pin);
					Dit(pin);
					Dah(pin);
					Dit(pin);
					break;

				case 'G':
					Dah(pin);	
					Dah(pin);
					Dit(pin);
					break;

				case 'H':
					Dit(pin);
					Dit(pin);
					Dit(pin);
					Dit(pin);
					break;

				case 'I':
					Dit(pin);
					Dit(pin);
					break;

				case 'J':
					Dit(pin);
					Dah(pin);
					Dah(pin);
					Dah(pin);
					break;

				case 'K':
					Dah(pin);
					Dit(pin);
					Dah(pin);
					break;

				case 'L':
					Dit(pin);
					Dah(pin);
					Dit(pin);
					Dit(pin);
					break;

				case 'M':
					Dah(pin);
					Dah(pin);
					break;

				case 'N':
					Dah(pin);
					Dit(pin);
					break;

				case 'O':
					Dah(pin);
					Dah(pin);
					Dah(pin);
					break;

				case 'P':
					Dit(pin);
					Dah(pin);
					Dah(pin);
					Dit(pin);
					break;

				case 'Q':
					Dah(pin);
					Dah(pin);
					Dit(pin);
					Dah(pin);
					break;

				case 'R':
					Dit(pin);
					Dah(pin);
					Dit(pin);
					break;

				case 'S':
					Dit(pin);
					Dit(pin);
					Dit(pin);
					break;

				case 'T':
					Dah(pin);
					break;

				case 'U':
					Dit(pin);
					Dit(pin);
					Dah(pin);
					break;

				case 'V':
					Dit(pin);
					Dit(pin);
					Dit(pin);
					Dah(pin);
					break;

				case 'W':
					Dit(pin);
					Dah(pin);
					Dah(pin);
					break;

				case 'X':
					Dah(pin);
					Dit(pin);
					Dit(pin);
					Dah(pin);
					break;

				case 'Y':
					Dah(pin);
					Dit(pin);
					Dah(pin);
					Dah(pin);
					break;

				case 'Z':
					Dah(pin);
					Dah(pin);
					Dit(pin);
					Dit(pin);
					break;

				case '1':
					Dit(pin);
					Dah(pin);
					Dah(pin);
					Dah(pin);
					Dah(pin);
					break;

				case '2':
					Dit(pin);
					Dit(pin);
					Dah(pin);
					Dah(pin);
					Dah(pin);
					break;

				case '3':
					Dit(pin);
					Dit(pin);
					Dit(pin);
					Dah(pin);
					Dah(pin);
					break;

				case '4':
					Dit(pin);
					Dit(pin);
					Dit(pin);
					Dit(pin);
					Dah(pin);
					break;

				case '5':	
					Dit(pin);
					Dit(pin);
					Dit(pin);
					Dit(pin);
					Dit(pin);
					break;

				case '6':
					Dah(pin);
					Dit(pin);
					Dit(pin);
					Dit(pin);
					Dit(pin);
					break;

				case '7':
					Dah(pin);
					Dah(pin);
					Dit(pin);
					Dit(pin);
					Dit(pin);
					break;

				case '8':
					Dah(pin);
					Dah(pin);
					Dah(pin);
					Dit(pin);
					Dit(pin);
					break;

				case '9':
					Dah(pin);
					Dah(pin);
					Dah(pin);
					Dah(pin);
					Dit(pin);
					break;

				case '0':
					Dah(pin);
					Dah(pin);
					Dah(pin);
					Dah(pin);
					Dah(pin);
					break;
			}

			delayMicroseconds(PinOffTimeMs * 1000);
		}
		
		if ((argvIdx + 1) < argc)
		{
			// Pause for a space between words
			delayMicroseconds(PinOffTimeMs * 2 * 1000);
		}
	}

	return 0;
}

void PrintUsageAndExit()
{
	fprintf(stderr, "Usage: gpio_morse <pin> <text>\n");
	exit(-1);
}

void Dit(int gpio)
{
	digitalWrite(gpio, HIGH);
	delayMicroseconds(PinOnTimeMs * 1000);
	digitalWrite(gpio, LOW);
	delayMicroseconds(PinOffTimeMs * 1000);
}

void Dah(int gpio)
{
	digitalWrite(gpio, HIGH);
	delayMicroseconds(PinOnTimeMs * 3 * 1000);
	digitalWrite(gpio, LOW);
	delayMicroseconds(PinOffTimeMs * 1000);
}
