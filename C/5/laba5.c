#include <stdio.h>
#include <string.h>		// strlen(),  strchr()
#include <stdlib.h>		// exit(0),  system("cls")
#include <ctype.h>		// tolower()
#include <conio.h>		// getch()
#define FIXED 5		// number of fields
#define NAME_LEN 50


typedef struct FLAT {
	char name[NAME_LEN];
	int area, rooms, floor;  // этаж
} flat_t;


void filling(flat_t arr[]);
void showing(flat_t arr[], int fields);
int filtering(flat_t arr[], int fields);
void sorting(flat_t arr[], int fields);
void field_copy(flat_t arr[], flat_t arr_copy[]);
int min_num(int f_num, int s_num);


int main() {
	flat_t arr[FIXED];
	flat_t arr_copy[FIXED];
	int fields = 0;

	while (1) {
		int choice;
		printf("\nPress '1' to fill the structure.\n"\
			"Press '2' to show the table.\n"\
			"Press '3' to filter the data (area <= 30).\n"\
			"Press '4' to sort alphabetically (A-Z).\n"\
			"Press '5' to restore to the initial structure.\n"\
			"Press '8' to clear console.\n"\
			"Press '9' to get out program.\n");
		do {
			choice = getch();
		} while (!strchr("1234589", choice));

		switch (choice) {
			case '1': {
				printf("\n1)FILLING\n");
				filling(arr);
				field_copy(arr, arr_copy);
				fields = FIXED;
				break;
			} case '2': {
				printf("\n2)SHOWING\n");
				showing(arr, fields);
				break;
			} case '3': {
				printf("\n3)FILTERING\n");
				fields = filtering(arr, fields);
				break;
			} case '4': {
				printf("\n4)SORTING\n");
				sorting(arr, fields);
				break;
			} case '5': {
				printf("\n5)RESTORING\n");
				field_copy(arr_copy, arr);
				fields = FIXED;
				break;
			} case '8': {
				system("cls");
				break;
			} case '9': {
				exit(0);
				break;
			} default: break;
		}
	}
	return 0;
}


void filling(flat_t arr[]) {
	for (int i = 0; i < FIXED; ++i) {
		printf("%d)))0  (name-ENTER-area-ENTER-rooms-ENTER-floor-ENTER)\n", i+1);
		scanf("%s %d %d %d", &arr[i].name, &arr[i].area, &arr[i].rooms, &arr[i].floor);
	}

	// strcpy(arr[0].name, "zda");  arr[0].area = 11; arr[0].rooms = 12; arr[0].floor = 13;
	// strcpy(arr[1].name, "asssa");  arr[1].area = 21; arr[1].rooms = 22; arr[1].floor = 23;
	// strcpy(arr[2].name, "zda");  arr[2].area = 31; arr[2].rooms = 32; arr[2].floor = 33;
	// strcpy(arr[3].name, "azaaz");  arr[3].area = 41; arr[3].rooms = 42; arr[3].floor = 43;
	// strcpy(arr[4].name, "aaagha");  arr[4].area = 51; arr[4].rooms = 52; arr[4].floor = 53;
}


void showing(flat_t arr[], int fields) {
	printf("\n      ");
	for (int i = 0; i < fields; ++i) {
		printf("%7d))0", i+1);
	}
	printf("\n  NAME");
	for (int i = 0; i < fields; ++i) {
		printf("%10s", arr[i].name);
	}
	printf("\n  AREA");
	for (int i = 0; i < fields; ++i) {
		printf("%10d", arr[i].area);
	}
	printf("\n ROOMS");
	for (int i = 0; i < fields; ++i) {
		printf("%10d", arr[i].rooms);
	}
	printf("\n FLOOR");
	for (int i = 0; i < fields; ++i) {
		printf("%10d", arr[i].floor);
	}
	printf("\n");
}


int filtering(flat_t arr[], int fields) {
	int counter = fields;
	for (int i = 0; i < counter; ++i) {
		if (arr[i].area > 30) {
			for (int j = i+1; j < counter; ++j) {
				arr[j-1] = arr[j];
			}
			--i; --counter;
		}
	}
	return counter;
}


void sorting(flat_t arr[], int fields) {
	for (int i = 0; i < fields; ++i) {
		for (int j = 1; j < fields; ++j) {
			flat_t temp[1];
			int min_len = min_num(strlen(arr[j-1].name), strlen(arr[j].name));
			for (int k = 0; k < min_len; ++k) {
				if (tolower(arr[j-1].name[k]) > tolower(arr[j].name[k])
					|| (!arr[j].name[k+1] && arr[j-1].name[k+1])) {
					temp[0] = arr[j-1];
					arr[j-1] = arr[j];
					arr[j] = temp[0];
					break;
				}
				else if (tolower(arr[j-1].name[k]) < tolower(arr[j].name[k]))
					break;
			}	
		}
	}
}


int min_num(int f_num, int s_num) {
	if (f_num <= s_num)
		return f_num;
	else
		return s_num;
}


void field_copy(flat_t arr[], flat_t arr_copy[]) {
	for (int i = 0; i < FIXED; ++i) {
		arr_copy[i] = arr[i];
	}
}
