#include <stdio.h>
#include <string.h>		// strlen(),  strchr()
#include <ctype.h>		// isxdigit(),  isdigit()
#include <stdlib.h>		// atoi(),  strtol(),  exit(0)
#include <conio.h>		// system("cls"),  getch()

int valid_int() {
	char str[65];
	int num;

	while (1) {
		int j = 0;

		scanf("%s", str);  //input of value
		int len = strlen(str);

		for (int i=0; i<len; ++i) {
			if (isdigit(str[i]) == 0) {
				++j;
				break;
			}
		}
		if (j == 0) break;
		else printf("Need natural number!: ");
	}
	num = atoi(str);   //convert str to int
	return num;
}

int valid_hex() {
	char str[65];
	int num;

	while (1) {
		int j = 0;
		scanf("%s", str);  //input of value
		int len = strlen(str);

		for (int i=0; i<len; ++i) {
			if (isxdigit(str[i]) == 0) {
				++j;
				break;
			}
			else if ((isalpha(str[i]) != 0) && (strlen(str) > 4)) {
				printf("\nlength of hex digit no more than 4\n");
				++j;
				break;
			}
		}
		if (j == 0) break;
		else printf("Need hex digit!: ");
	}
	num = (int)strtol(str, NULL, 16);   //convert str(hex) to int
	return num;
}

int main() {
	char t; /*тип пакета*/
	char s; /*ідентифікатор джерела*/
	unsigned char l; /*довжина пакета*/
	unsigned int UnitStateWord; /*слово стану*/
	int choice;

	printf("\nSadchenko Nikita, student of KM-73.\n### Laboratory Work 1 ###\n");

	do {
		printf("\nPress '1' to form Program Status Word.\n"\
				"Press '2' to get initial data. (Source ID, package type and length)\n"\
				"Press '3' to clear console.\n"\
				"Press '9' to get out program.\n");
		choice = getch();
	} while (!strchr("1239", choice));

	switch (choice) {
		case '1': {
			printf("\nEnter package type (0-7): ");
			while (1) {
				int n = valid_int();
				
				if ((0 <= n) && (n <= 7)) {
					t = (char) n;		// Assignment int to char (Присвоєння)
					break;
				}
				else printf("from '0' to '7': ");
			}
			printf("Enter Source ID (0-15): ");
			while (1) {
				int n = valid_int();
				
				if ((0 <= n) && (n <= 15)) {
					s = (char) n;
					break;
				}
				else printf("from '0' to '15': ");
			}
			printf("Enter package length (0-255): ");
			while (1) {
				int n = valid_int();

				if ((0 <= n) && (n <= 255)) {
					l = (unsigned char) n;
					break;
				}
				else printf("from '0' to '255': ");
			}
			/*формування упакованого коду*/
			UnitStateWord = ((unsigned int) t & 7) << 13;
			UnitStateWord |= ((unsigned int) s & 0xF) << 8;
			UnitStateWord |= l & 0xFF;
			/*слово стану пристрою*/
			printf("\nProgram Status Word = %04x\n\n", UnitStateWord);
			break;
		}
		case '2': {
			char ch[65];

			printf("\nEnter Program Status Word\n");
			printf("(hex digit from 0 to 0xFFFF): ");

			int numb = valid_hex();
			sprintf (ch, "%x", numb);  //convert int(dex) to str(hex)
			UnitStateWord = (unsigned int)strtol(ch, NULL, 16);  //str(hex) to int(hex)
			/*виділення складових частин*/
			t = (UnitStateWord >> 13) & 7;
			s = (UnitStateWord >> 8) & 0xF;
			l = UnitStateWord & 0xFF;
			/*виведення результатів*/
			putchar('\n');
			printf("Package type = %d\n", t);
			printf("Source ID = %d\n", s);
			printf("Package length = %d\n\n", l);
			break;
		}
		case '3': {
			printf("  7 ballov  :)\n");
			system("cls");
			break;
		}
		case '9': exit(0); break;
		default: break;
	}
	return main();
}
