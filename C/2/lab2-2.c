#include <stdio.h>
#include <string.h>		// strlen(),  strchr()
#include <stdlib.h>		// atoi(), atof(), srand,rand(), exit(0)
#include <ctype.h>		// isdigit()
#include <time.h>		// time()
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
		if (smb == 0){
			num = atoi(str);   //convert str to int
			if (num == 0) printf("not zero!: ");
			else break;
		}
		else printf("Need natural number!: ");
	}
	return num;
}


float valid_float() {
	char str[65];
	float num;

	while (1) {
		int smb = 0, dot = 0;

		scanf("%s", str);  //input of value
		int len = strlen(str);

		for (int i=0; i<len; ++i) {
			if (isdigit(str[i]) == 0) {
				if (str[i] == '.') {
					++dot;
				}
				else {
					++smb;
					break;
				}
			}
		}
		if ((dot < 2) && ((smb == 0) ||
			((smb == 1) && (str[0] == '-') && str[1]))) {
			break;
		}
		else printf("Need float number!: ");
	}
	num = atof(str);   //convert str to float
	return num;
}


int main() {
	int choice, pnt = 0;
	int nc = 100, nr = 100;

	int *col = &nc, *row = &nr;	// указатель для switch
	float matrix[*row][*col];
	float new_arr[*row];

	printf("\nPress '1' to form user matrix.\n"\
			"Press '2' to form random matrix.\n"\
			"Press '8' to clear console.\n"\
			"Press '9' to get out program.\n");

	do {
		choice = getch();
	} while(!strchr("1289", choice));

	switch (choice) {
		case '1': {
			printf("\nEnter number of columns: ");
			*col = valid_int();
			printf("Enter number of rows: ");
			*row = valid_int();

			// FILING in MATRIX
			for (int i = 0; i < *row; ++i) {
				for (int j = 0; j < *col; ++j) {
					printf("matrix[%d][%d] = ", i+1, j+1);
					matrix[i][j] = valid_float();
				}
			}
			pnt = 1;
			break;
		}
		case '2': {
			*col = 1 + rand() %10;
			*row = 1 + rand() %10;

			time_t t;
   			// Intializes random number generator 
   			srand((unsigned) time(&t));

			printf("\nEnter max range: ");
			int max_ran = valid_int();

			// FILING in MATRIX
			for (int i = 0; i < *row; ++i) {
				for (int j = 0; j < *col; ++j) {
					matrix[i][j] = -max_ran/2 + rand() %max_ran;
					printf("matrix[%d][%d] = %g\n", i+1, j+1, matrix[i][j]);
				}
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
		// DEMONSTRATION of the MATRIX
		for (int i = 0; i < *row; ++i) {
			for (int j = 0; j < *col; ++j) {
				printf("%g ", matrix[i][j]);
			}
			putchar('\n');
		}

		for (int i = 0; i < *row; ++i) {
			new_arr[i] = 0;
			for (int j = 0; j < *col; ++j) {
				if (matrix[i][j] >= 10) {
					new_arr[i] = matrix[i][j];
					break;
				}
			}
		}

		printf("\narray = {");
		for (int k=0; k < *row; ++k) {
			if (k < *row-1) {
				printf("%g, ", new_arr[k]);
			}
			else {
				printf("%g", new_arr[k]);
			}
		}
		printf("}\n");
	}

	return main();
}
