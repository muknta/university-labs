#include <stdio.h>
#include <string.h>		// strlen()
#include <stdlib.h>		// atoi(),  atof(),  strlol()
#include <ctype.h>		// isdigit(),  isalpha()
#include "validation.h"


/*  NATURAL NUMBERS  */
int get_natur()
{
	char str[65];
	int num;

	while (1) {
		int smb = 0;

		scanf("%s", str);  //input of value
		int len = strlen(str);

		for (int i = 0; i < len; ++i) {
			if (!isdigit(str[i])) {
				++smb;
				break;
			}
		}
		if (smb == 0) break;
		else printf("need natural number!: ");
	}
	num = atoi(str);   //convert str to int
	return num;
}


/*  INTEGERS  */
int get_int()
{
	char str[65];
	int num;

	while (1) {
		int smb = 0;

		scanf("%s", str);  //input of value
		int len = strlen(str);

		for (int i = 0; i < len; ++i) {
			if (!isdigit(str[i])) {
				++smb;
				break;
			}
		}
		if ((smb == 0) || ((smb == 1) && (str[0] == '-')))
			break;
		else
			printf("need integer number!: ");
	}
	num = atoi(str);   //convert str to int
	return num;
}


float get_float()
{
	char str[65];
	float num;

	while (1) {
		int smb = 0, dot = 0;

		scanf("%s", str);  //input of value
		int len = strlen(str);

		for (int i = 0; i < len; ++i) {
			if (!isdigit(str[i])) {
				if (str[i] == '.')
					++dot;
				else
					++smb;
			}
		}
		if ((dot < 2) && ((smb == 0) ||
			((smb == 1) && (str[0] == '-') && str[1]))) {
			break;
		}
		else printf("need float number!: ");
	}
	num = atof(str);   //convert str to float
	return num;
}


/*  HEXADECIMAL NUMBERS  */
int get_hex()
{
	char str[65];
	int num;

	while (1) {
		int j = 0;
		scanf("%s", str);  //input of value
		int len = strlen(str);

		for (int i = 0; i < len; ++i) {
			if (!isxdigit(str[i])) {
				++j;
				break;
			}
			else if (isalpha(str[i]) && (strlen(str) > 4)) {
				printf("\nlength of hex digit no more than 4\n");
				++j;
				break;
			}
		}
		if (j == 0) break;
		else printf("need hex digit!: ");
	}
	num = (int)strtol(str, NULL, 16);   //convert str(hex) to int
	return num;
	// return to int(dex); need convert to str(hex), then to int(hex)
}
