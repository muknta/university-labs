#include <stdio.h>
#include <string.h>		// strlen(),  strchr()
#include <stdlib.h>		// atoi(),  exit(0)
#include <ctype.h>		// isdigit(),  isalpha()
#include <conio.h>		// system("cls"),  getch()


int valid_int() {
	char str[65];
	int num;

	while (1) {
		int smb = 0;

		scanf("%s", str);  //input of value
		int len = strlen(str);

		for (int i=0; i<len; ++i) {
			if (isdigit(str[i]) == 0) {
				++smb;
				break;
			}
		}
		if (smb == 0) {
			num = atoi(str);   //convert str to int
			if (num > 20) printf("No bigger than 20!: ");
			else break;
		}
		else printf("Need natural number!: ");
	}
	return num;
}

int main() {
	int choice;

	printf("\nPress '1' to form and sort array.\n"\
			"Press '8' to clear console.\n"\
			"Press '9' to get out program.\n");
	do {
		choice = getch();
	} while(!strchr("189", choice));

	switch (choice) {
		case '1': {
			printf("\nEnter number of words: ");
			int n = valid_int();
			char str[n][20];

			int nz = 20;
			int *iter = &nz;

			for (int i = 0; i < n; ++i) {

				do {
					*iter = 0;
					printf("%d. yours symbols: ", i+1);
					scanf("%s", &str[i]);

					for (int j = 0; j < strlen(str[i]); ++j) {
						if (!isalpha(str[i][j])) {
							++*iter;
							break;
						}
					}
				} while ((*iter != 0) || (strlen(str[i]) > 20));
			}

			for (int i = 0; i < n; ++i) {
				for (int j = 1; j < n; ++j) {
					if (strlen(str[j-1]) > strlen(str[j])) {
						for (int k = 0; k < 20; ++k) {
							char switcher[1][20];
							switcher[0][k] = str[j-1][k];
							str[j-1][k] = str[j][k];
							str[j][k] = switcher[0][k];
		    			}
					}
				}
			}

			printf("sort_array = {");
			for (int i = 0; i < n; ++i) {
				if (i != n-1) printf("%s, ", str[i]);
				else printf("%s", str[i]);
			}
			printf("}\n");

			break;
		}
		case '8': {
			printf("  7 ballov  :)\n");
			system("cls");
			break;
		}
		case '9': exit(0); break;
		default: break;
	}
	return main();
}
