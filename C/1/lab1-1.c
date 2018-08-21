#include <stdio.h>
#include <string.h>		// strchr()
#include <stdlib.h>		// exit(0)
#include <conio.h>		// system("cls"),  getch()
#include <math.h>
#include "../validation.h"


int main() {
	printf("\nSadchenko Nikita, student of KM-73.\n### Laboratory Work 1 ###\n");

	int choice;
	do {
		printf("\nPress '1' to calculate perimeter and area of truncated cone.\n"\
			// Периметр і площа усіченого конуса.
			"Press '2' to calculate perimeter and area of triangle with coordinates.\n"\
			"Press '3' to clear console.\n"\
			"Press '9' to get out program.\n");
		choice = getch();
	} while (!strchr("1239", choice));

	switch (choice) {
		case '1': {
			float R, r, L, h, s, v;

			printf("\nEnter R: ");
			do {
				R = get_float();
			} while (R <= 0);
			printf("Enter r: ");
			do {
				r = get_float();
			} while (r <= 0);
			printf("Enter L: ");
			do {
				L = get_float();
			} while (L <= 0);
			printf("Enter h: ");
			do {
				h = get_float();
			} while (h <= 0);

			s = M_PI*(R*R + (R + r)*L + r*r);
			v = M_PI/3 * (R*R + r*r + R*r)*h;
			printf("s = %g\n", s);
			printf("v = %g\n\n", v);
			break;
		}
		case '2': {
			float x1, y1, x2, y2, x3, y3;
			float ab, bc, ac, p, s;

			printf("\nEnter x-coordinate of A: ");
			x1 = get_float();
			printf("Enter y-coordinate of A: ");
			y1 = get_float();
			printf("Enter x-coordinate of B: ");
			x2 = get_float();
			printf("Enter y-coordinate of B: ");
			y2 = get_float();
			printf("Enter x-coordinate of C: ");
			x3 = get_float();
			printf("Enter y-coordinate of C: ");
			y3 = get_float();

			ab = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
			bc = sqrt(pow((x2-x3),2) + pow((y2-y3),2));
			ac = sqrt(pow((x1-x3),2) + pow((y1-y3),2));
			p = ab + bc + ac;
			s = sqrt((p/2)*((p/2) - ab)*((p/2) - bc)*((p/2) - ac));
			printf("p = %g\n", p);
			printf("s = %g\n\n", s);
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
