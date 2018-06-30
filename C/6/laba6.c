#include <stdio.h>
#include <string.h>		// strlen(),  strchr()
#include <stdlib.h>		// atoi(),  exit(0),  system("cls")
#include <ctype.h>		// isdigit()
#include <conio.h>		// getch()
#include <time.h>		// rand()
#define SIZE 3


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
		if (smb == 0) break;
		else printf("need natural number!: ");
	}
	num = atoi(str);   //convert str to int
	return num;
}


int **init_fill(char choice) {
	// INITIALIZATION of MATRIX
	int **matrix = (int **) malloc(SIZE * sizeof(int *));
	for (int i = 0; i < SIZE; ++i) {
		matrix[i] = (int *) malloc(SIZE * sizeof(int));
	}
	// FILLING of MATRIX
	if (choice == 'u') {
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				printf("matrix[%d][%d] = ", i+1, j+1);
				matrix[i][j] = valid_int();
			}
		}
	}
	else if (choice == 'r') {
		printf("Enter max range: ");
		int max_ran = valid_int();
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				matrix[i][j] = rand()%max_ran;
				printf("matrix[%d][%d] = %d\n", i+1, j+1, matrix[i][j]);
			}
		}
	}
	return matrix;
}


void calculating(int **matrix) {
	int main_diag = 0, sec_diag = 0;

	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			printf("%4d", matrix[i][j]);
		}
		putchar('\n');
	}

	// ELEMENTS SUM of MAIN and SECONDARY DIAGONALS
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (i == j) {
				main_diag += matrix[i][j];
			}
			if (i+j == SIZE-1) {
				sec_diag += matrix[i][j];
			}
		}
	}

	if (main_diag >= sec_diag)
		printf("\nmain_diag (%d) - secondary_diag (%d) = %d\n", main_diag,sec_diag, main_diag - sec_diag);
	else printf("\nsecondary_diag (%d) - main_diag (%d) = %d\n", sec_diag,main_diag, sec_diag - main_diag);
}


void main() {
	while (1) {
		int choice;
		fflush(stdin);

		printf("\nPress '1' to create user matrix.\n"\
				"Press '2' to get random matrix.\n"\
				"Press '8' to clear console.\n"\
				"Press '9' to get out program.\n");
		do {
			choice = getch();
		} while(!strchr("1289", choice));

		switch (choice) {
			case '1': {
				// USER matrix
				int **matrix = init_fill('u');
				calculating(matrix);

				// MATRIX FREEING
				for (int i = 0; i < SIZE; ++i) {
				    int *currentIntPtr = matrix[i];
				    free(currentIntPtr);
				}
				break;
			}
			case '2': {
				time_t t;
	   			// Initializes random number generator 
	   			srand((unsigned) time(&t));
	   			// Initialization and filling by RANDOM
				int **matrix = init_fill('r');
				calculating(matrix);
				
				// MATRIX FREEING
				for (int i = 0; i < SIZE; ++i) {
				    int *currentIntPtr = matrix[i];
				    free(currentIntPtr);
				}
				free(matrix);
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
}
