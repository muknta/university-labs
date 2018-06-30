#include <stdio.h>
#include <string.h>		// strlen(),  strchr()
#include <stdlib.h>		// atoi(),  exit(0),  system("cls")
#include <ctype.h>		// isdigit()
#include <conio.h>		// getch()
#include "locale.h"		// для отображения кириллицы
#include <windows.h>
#define STRCT 5
#define WRD_LEN 60


int valid_int(int n, int lvl) {
	char str[WRD_LEN];
	int num;

	if (n == 1) printf("\n%d. Area of the flat: ", lvl);
	else if (n == 2) printf("%d. Number of rooms: ", lvl);
	else if (n == 3) printf("%d. Floor of the flat: ", lvl);
	while (1) {
		int smb = 0;

		scanf("%s", str);  //input of value
		int len = strlen(str);

		for (int i=0; i<len; ++i) {
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


char *valid_str(int lvl) {
	setlocale(LC_ALL, "Russian");

	static char str[WRD_LEN];

	printf("%d. Enter your last name: ", lvl);
	while (1) {
		int smb = 0;

		
		scanf("%s", str);
		for (int i = 0; i < strlen(str); ++i) {
			if (!isalpha(str[i])) {
				++smb;
				break;
			}
		}
		if (smb == 0) break;
		else printf("need literal input!: ");
	}
	return str;
}


void permutation(char arr[][WRD_LEN]) {
	for (int i = 0; i < STRCT; ++i) {
		for (int j = 1; j < STRCT; ++j) {
			for (int m = 0; m < STRCT; ++m) {
				if (tolower(arr[j-1][m]) > tolower(arr[j][m])) {
					for (int k = 0; k < STRCT; ++k) {
						char switcher[1][WRD_LEN];
						switcher[0][k] = arr[j-1][k];
						arr[j-1][k] = arr[j][k];
						arr[j][k] = switcher[0][k];
				    }
				    break;
				}
				else if (tolower(arr[j-1][m]) < tolower(arr[j][m])) break;
			}
		}
	}
	printf("\nsort array = {");
	for (int i = 0; i < STRCT; ++i) {
		if (i != STRCT-1) printf("%s, ", arr[i]);
		else printf("%s", arr[i]);
	}
	printf("}\n");
}


struct FLAT {
	int area, rooms, floor;	// этаж
	char *name[WRD_LEN];
};


int main() {
	while (1) {
		int choice;
		fflush(stdin);

		printf("\nPress '1' to fill the structure.\n"\
				"Press '8' to clear console.\n"\
				"Press '9' to get out program.\n");
		do {
			choice = getch();
		} while(!strchr("189", choice));

		switch (choice) {
			case '1': {
				char arr[STRCT][WRD_LEN];
				int num_area = 0;

				struct FLAT flat1 = {valid_int(1,1), 12, 13, valid_str(1)};
				strcpy(arr[0], *flat1.name);
				struct FLAT flat2 = {valid_int(1,2), 22, 23, valid_str(2)};
				strcpy(arr[1], *flat2.name);
				struct FLAT flat3 = {valid_int(1,3), 32, 33, valid_str(3)};
				strcpy(arr[2], *flat3.name);
				struct FLAT flat4 = {valid_int(1,4), 42, 43, valid_str(4)};
				strcpy(arr[3], *flat4.name);
				struct FLAT flat5 = {valid_int(1,5), 52, 53, valid_str(5)};
				strcpy(arr[4], *flat5.name);

				permutation(arr);
				if (flat1.area < 30) ++num_area;
				if (flat2.area < 30) ++num_area;
				if (flat3.area < 30) ++num_area;
				if (flat4.area < 30) ++num_area;
				if (flat5.area < 30) ++num_area;
				printf("\nnumber of flats with area <30: %d\n\n", num_area);
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
	}
	return 0;
}
