#include <stdio.h>
#include <string.h>     // strlen(),  strchr()
#include <stdlib.h>     // atoi(),  exit(0),  system("cls")
#include <ctype.h>      // isdigit()
#include <conio.h>      // getch()


int valid_odd() {
    char str[65];
    int num;
    int smb = 0;

    scanf("%s", str);   //input of value
    int len = strlen(str);

    for (int i=0; i<len; ++i) {
        if (isdigit(str[i]) == 0) {
            ++smb;
            break;
        }
    }
    if (smb == 0) {
        num = atoi(str);   //convert str to int
        if (num%2 == 1) return num;
        else printf("need odd number!: ");
    }
    else printf("need natural number!: ");

    return valid_odd();
}

void generateSquare(int n) {
    int magicSquare[n][n];

    // set all slots as 0
    memset(magicSquare, 0, sizeof(magicSquare));

    // Initialize position for 1
    int i = n/2;
    int j = n-1;
    for (int num=1; num <= n*n; ) {
        if (i < 0 && j == n) {
            j = n-2;
            i = 0;
        }
        else {
            if (j == n) j = 0;
            if (i < 0) i = n-1;
        }
        if (magicSquare[i][j]) {
            j -= 2;
            i++;
            continue;
        }
        else
            magicSquare[i][j] = num++;

        j++; i--;
    }
    printf("Sum of each row or column - %d\n\n", n*(n*n+1)/2);
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++)
            printf("%3d ", magicSquare[i][j]);
        printf("\n");
    }
}

int main() {
    int choice;
    fflush(stdin);

    printf("\nPress '1' to get Magic Square.\n"\
            "Press '8' to clear console.\n"\
            "Press '9' to get out program.\n");
    do {
        choice = getch();
    } while(!strchr("189", choice));

    switch (choice) {
        case '1': {
            printf("\nThe Magic Square for n = ");
            int n = valid_odd();
            generateSquare(n);
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
#include <stdio.h>

int main() {

    // Introductory message
    printf("This program creates a magic sqaure of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");

    // Get the users magic number and allocate to int n
    int n;
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    // Create the array (not using VLA)
    int magic[99][99];
    int start = (n / 2); // The middle column
    int max = n * n; // The final number
    magic[0][start] = 1; // Place the number one in the middle of row 0

    // Loop to start placing numbers in the magic square
    int row;
    int col;
    int next_row;
    int next_col;
    int i;
    for (i = 2, row = 0, col = start; i <= max; i++) {
        if ((row - 1) < 0) { // If going up one will leave the top
            next_row = n - 1; // Go to the bottom row
        }
        else { next_row = row - 1; } // Otherwise go up one
        printf("In row: %d\n", row);

        if ((col + 1) > (n - 1)) { // If column will leave the side
            next_col = 0; // Wrap to first column
            printf("Column will leave side\n");                                   
        }                                                                         
        else { next_col = col + 1; } // Otherwise go over one                     
        printf("In col: %d\n", col);                                              

        if (magic[next_row][next_col] > 0) { // If that position is taken         
            if (row > (n - 1)) { // If going to row below leaves bottom           
                next_row = 0; // Go back to the top                               
            }                                                                     
            else {                                                                
                next_row = row + 1; // Go to the row below                        
                next_col = col; // But stay in same column                        
            }                                                                     
        }                                                                         
        row = next_row;                                                           
        col = next_col;                                                           
        printf("About to put %d in row %d, col %d\n", i, row, col);               
        magic[row][col] = i; // Put the current value in that position            
    }                                                                             

    // Now let's print the array                                                  
    int j;                                                                        
    for (i = 0; i < n; i++) {                                                     
        for (j = 0; j < n; j++) {                                                 
            printf("%4d", magic[i][j]);                                           
        }                                                                         
        printf("\n");                                                             
    }                                                                             
    return 0;                                                                     
}





#include <stdio.h>
#include <math.h>
 
int main() {
 
    // Introductory message
    printf("This program creates a magic sqaure of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
     
    // Get the users magic number and allocate to int n
    int n;
    printf("Enter size of magic square: ");
    scanf("%d", &n);
    printf("\n");
    // Create the array (not using VLA)
    int magic[99][99], i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            magic[(n -1 + i)%n][(n - 1 + j)%n] = n * ((i + j - 1 + (n - 1) / 2) % n) + ((i + 2 * j - 2) % n) + 1;
       }
    }
    // Now let's print the array                                                  
    for (i = 0; i < n; i++) {                                                     
        for (j = 0; j < n; j++) {                                                 
            printf("%4d", magic[i][j]);                                           
        }                                                                         
        printf("\n");                                                             
    }                                                                             
    return 0;                                                                     
}
*/