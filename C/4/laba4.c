#include <stdio.h>
#include <string.h>		// strlen(),  strchr()
#include <stdlib.h>		// atoi(),  exit(0),  system("cls")
#include <ctype.h>		// isdigit()
#include <conio.h>		// getch()
#include <time.h>		// time()


int valid_int() {
	char str[65];
	int num;
	int smb = 0;

	scanf("%s", str);	//input of value
	int len = strlen(str);

	for (int i=0; i<len; ++i) {
		if (isdigit(str[i]) == 0) {
			++smb;
			break;
		}
	}
	if (smb == 0) {
		num = atoi(str);   //convert str to int
		return num;
	}
	else printf("need natural number!: ");

	return valid_int();
}

int counting(int c, int n, int count, int ar[]) {
	if (c > n-1) {
		printf("Counts of '1' before two zeros: %d\n", count);
		return 0;
	}

	if ((ar[c] == 0) && (c < n-1)) {
		if (ar[c+1] == 0) {
			for (int j = 0; j < c; ++j) {
				if (ar[j] == 1) {
					++count;
				}
			}
		}
	}
	return counting(c+1, n, count, ar);
}

int filling(int c, int n, int ar[]) {
	if (c > n-1 ) {
		return counting(0, n, 0, ar);
	}
	printf("%d) ", c+1);
	ar[c] = valid_int();

	return filling(c+1, n, ar);
}

int random(int c, int n, int max_ran, int ar[]) {
	if (c > n-1 ) {
		return counting(0, n, 0, ar);
	}
	ar[c] = rand()%max_ran;
	printf("array[%d] = %d\n", c, ar[c]);
	return random(c+1, n, max_ran, ar);
}

int main() {
	int choice;
	fflush(stdin);

	printf("\nPress '1' to input sequence.\n"\
			"Press '2' to get random sequence.\n"\
			"Press '8' to clear console.\n"\
			"Press '9' to get out program.\n");
	do {
		choice = getch();
	} while(!strchr("1289", choice));

	switch (choice) {
		case '1': {
			printf("\nNumber of elements: ");
			int n = valid_int();
			int ar[n];
			printf("\nEnter natural sequence\n");
			filling(0, n, ar);
			break;
		}
		case '2': {
			time_t t;
   			// Initializes random number generator 
   			srand((unsigned) time(&t));

			printf("\nEnter max range: ");
			int max_ran = valid_int();
			printf("Number of elements: ");
			int n = valid_int();
			int ar[n];
			random(0, n, max_ran, ar);
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
















/*

int counting(int c, int n) {
	int *ar[n], count = 0, e = 0;

	printf("%d), n=%d ", c+1, n);
	int v = valid_int();
	ar[n-1-c] = &v;

	if (c < n-1) {
		counting(c+1, n);
	}


	for (int i = 0; i < c; ++i) {
		printf("c = %d, ar[%d]: %d\n", c, i, *ar[i]);
	}

	


	printf("ar[c-1],ar[c],ar[c+1]: %d,%d,%d\n", *ar[c-1],*ar[c],*ar[c+1]);
	printf("2count: %d\n", count);
	if (e > 0) {
		printf("3count: %d\n", count);
		return count;
	}
	if ((*ar[c] == 0) && (*ar[c+1] == 0)) {
		for (int i = 0; i < c; ++i) {
			if (*ar[i] == 1) ++count;
		}
		++e;
		printf("1count: %d\n", count);
		return count;
	}
}

int main() {
	printf("Number of elements: ");
	int n = valid_int();
	int count = counting(0, n);
	printf("\nCount of '1' in array: %d\n", count);
}






int main() {
	printf("Number of elements: ");
	int n = valid_int();
	int ar[n], count = 0;

	printf("Enter natural sequence\n");
	for (int i = 0; i < n; ++i) {
		printf("%d) ", i+1);
		ar[i] = valid_int();
	}

	for (int i = 0; i < n; ++i) {
		if ((ar[i] == 0) && (i < n-1)) {
			if (ar[i+1] == 0) {
				for (int j = 0; j < i; ++j) {
					if (ar[j] == 1) {
						++count;
					}
				}
				break;
			}
		}
	}
	printf("\nCount of '1' in array: %d\n", count);
	counting(0);
}
*/