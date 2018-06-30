#include <stdio.h>
#include <string.h>		// strlen(),  strchr()
#include <stdlib.h>		// atoi(),  srand,rand(),  exit(0)
#include <ctype.h>		// isdigit()
#include <time.h>		// time()
#include <conio.h>		// system("cls"),  getch()


int valid_int(int arg) {
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
		if (arg == 1) {
			if (smb == 0) break;
			else printf("Need natural number!: ");
		}
		else {
			if ((smb == 0) || ((smb == 1) && (str[0] == '-'))) {
				break;
			}
			else printf("Need natural number!: ");
		}
		
	}
	num = atoi(str);   //convert str to int
	return num;
}


int main() {
	int choice, nv = 100;
	int pnt = 0, iter = 0, k = 0;

	int *size = &nv;	// указатель для switch
	int array[*size];
	int new_arr[*size];

	printf("\nPress '1' to form user array.\n"\
			"Press '2' to form random array.\n"\
			"Press '8' to clear console.\n"\
			"Press '9' to get out program.\n");

	do {
		choice = getch();
	} while(!strchr("1289", choice));

	switch (choice) {
		case '1': {
			printf("\nEnter number of elements: ");
			*size = valid_int(1);

			// FILING in ARRAY
			for (int i = 0; i < *size; ++i) {
				printf("array[%d] = ", i);
				array[i] = valid_int(0);
			}
			pnt = 1;
			break;
		}

		case '2': {
			*size = 3 + rand() %20;

			time_t t;
   			// Intializes random number generator 
   			srand((unsigned) time(&t));

			printf("\nEnter max range: ");
			int max_ran = valid_int(1);

			// FILING in ARRAY
			for (int i = 0; i < *size; ++i) {
				array[i] = -max_ran/2 + rand() %(max_ran+1);
				printf("array[%d] = %d\n", i, array[i]);
			}
			pnt = 1;
			break;
		}
		case '8': {
			printf("  7 ballov  :)\n");
			pnt = 0;
			system("cls");
			break;
		}
		case '9': exit(0); break;
		default: break;
	}

	if (pnt == 1) {
		// ОТБОР ПОВТОРЯЮЩИХСЯ
		for (int i = 0; i < *size; ++i) {
			for (int j = i+1; j < *size; ++j) {
				if (array[i] == array[j]) {
					new_arr[iter] = array[j];
					++iter;
					break;
				}
			}
		}

		// МАССИВ ПОСЛЕ ОТБОРА ПОВТОРЯЮЩИХСЯ
		printf("initial array = {");
		for (int i = 0; i < iter; ++i) {
			if (i < iter-1) {
				printf("%d, ", new_arr[i]);
			}
			else {
				printf("%d", new_arr[i]);
			}
		}
		printf("}\n");

		// СОКРАЩЕНИЕ МАССИВА
		for (int i = 0; i < iter; ++i) {
			for (int j = i+1; j < iter;) {
				if (new_arr[i] == new_arr[j]) {
					for (k = j; k < iter; ++k) {
						new_arr[k] = new_arr[k+1];
					}
					--iter;
				}
				else ++j;
			}
		}

		// МАССИВ ПОСЛЕ СОКРАЩЕНИЯ
		printf("middle array = {");
		for (int i = 0; i < iter; ++i) {
			if (i < iter-1) {
				printf("%d, ", new_arr[i]);
			}
			else {
				printf("%d", new_arr[i]);
			}
		}
		printf("}\n");

		// "ПУЗЫРЬКОВАЯ" СОРТИРОВКА
		for (int j = 0; j < iter; ++j) {
			for (int i = 1; i < iter; ++i) {
				if (new_arr[i-1] > new_arr[i]) {
					int switcher = new_arr[i-1];
					new_arr[i-1] = new_arr[i];
					new_arr[i] = switcher;
				}
			}
		}

		// ОКОНЧАТЕЛЬНЫЙ МАССИВ ПОСЛЕ СОРТИРОВКИ
		printf("final array = {");
		for (int l = 0; l < iter; ++l) {
			if (l < iter-1) {
				printf("%d, ", new_arr[l]);
			}
			else {
				printf("%d", new_arr[l]);
			}
		}
		printf("}\n");
	}
	return main();
}
