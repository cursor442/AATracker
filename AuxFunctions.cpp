
#include "AA_Tracker.h"

char* uint2char(uint16_t num)
{
	uint16_t hund = 0, tens = 0;

	char str[4];
	str[3] = '\0';

	str[0] = ' ';
	str[1] = ' ';
	if (num > 99)
		str[0] = uint2char_(num / 100);
	if (num > 9)
		str[1] = uint2char_((num % 100) / 10);
	str[2] = uint2char_(num % 10);

	return str;
}

char uint2char_(uint16_t num)
{
	if (num == 0)
		return '0';
	else if (num == 1)
		return '1';
	else if (num == 2)
		return '2';
	else if (num == 3)
		return '3';
	else if (num == 4)
		return '4';
	else if (num == 5)
		return '5';
	else if (num == 6)
		return '6';
	else if (num == 7)
		return '7';
	else if (num == 8)
		return '8';
	else if (num == 9)
		return '9';
	else
		return ' ';
}

char* int2char(int num)
{
	int hund = 0, tens = 0;

	char str[4];
	str[3] = '\0';

	str[0] = ' ';
	str[1] = ' ';
	if (num < 0)
	{
		if (num >= -99 && num < -9)
			str[0] = '-';
		else if (num >= -9)
			str[1] = '-';
		num *= -1;
	}
	if (num > 99)
		str[0] = int2char_(num / 100);
	if (num > 9)
		str[1] = int2char_((num % 100) / 10);
	str[2] = int2char_(num % 10);

	return str;
}

char int2char_(int num)
{
	if (num == 0)
		return '0';
	else if (num == 1)
		return '1';
	else if (num == 2)
		return '2';
	else if (num == 3)
		return '3';
	else if (num == 4)
		return '4';
	else if (num == 5)
		return '5';
	else if (num == 6)
		return '6';
	else if (num == 7)
		return '7';
	else if (num == 8)
		return '8';
	else if (num == 9)
		return '9';
	else
		return ' ';
}

void  remZeros(char* str, uint16_t size)
{
	for (uint16_t i = 0; i < size; i++)
	{
		if (str[i] == '0')
			str[i] = ' ';
	}
}

bool isBeforeNation(uint16_t target, uint16_t current)
{
	if (target >= current)
		return false;
	else if ((target == TURN_UKE && current == TURN_UKP) ||
		(target == TURN_UKP && current == TURN_UKE))
		return false;
	else
		return true;
}

uint16_t char2uint(char* str, uint16_t n)
{
	uint16_t val = 0;

	if (n == 1)
		val = char2uint_(str[0]);
	else if (n == 2)
		val = 10 * char2uint_(str[0]) + char2uint_(str[1]);
	else if (n == 3)
		val = 100 * char2uint_(str[0]) + 10 * char2uint_(str[1]) + char2uint_(str[2]);

	return val;
}

uint16_t char2uint_(char c)
{
	if (c == '0' || c == ' ')
		return 0;
	else if (c == '1')
		return 1;
	else if (c == '2')
		return 2;
	else if (c == '3')
		return 3;
	else if (c == '4')
		return 4;
	else if (c == '5')
		return 5;
	else if (c == '6')
		return 6;
	else if (c == '7')
		return 7;
	else if (c == '8')
		return 8;
	else if (c == '9')
		return 9;
	else
		return 0;
}

int char2int(char* str, int n)
{
	int val = 0;

	bool neg = false;
	if (str[0] == '-' || str[1] == '-')
		neg = true;

	if (n == 1)
		val = char2uint_(str[0]);
	else if (n == 2)
		val = (10 * char2uint_(str[0])) + char2uint_(str[1]);
	else if (n == 3)
		val = 100 * char2uint_(str[0]) + 10 * char2uint_(str[1]) + char2uint_(str[2]);

	if (neg)
		val *= -1;

	return val;
}

int char2int_(char c)
{
	if (c == '0' || c == ' ' || c == '-')
		return 0;
	else if (c == '1')
		return 1;
	else if (c == '2')
		return 2;
	else if (c == '3')
		return 3;
	else if (c == '4')
		return 4;
	else if (c == '5')
		return 5;
	else if (c == '6')
		return 6;
	else if (c == '7')
		return 7;
	else if (c == '8')
		return 8;
	else if (c == '9')
		return 9;
	else
		return 0;
}
