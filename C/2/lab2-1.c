#include <stdio.h>
#include <string.h>		// strchr()
#include <stdlib.h>		// srand,rand(),  exit(0)
#include <time.h>		// time()
#include <conio.h>		// system("cls"),  getch()
#include "../validation.h"


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
			*size = get_natur();

			// FILLING in ARRAY
			for (int i = 0; i < *size; ++i) {
				printf("array[%d] = ", i);
				array[i] = get_int();
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
			int max_ran = get_natur();

			// FILLING in ARRAY
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
