#include <stdio.h>
#include <string.h>		//strchr(),  strcmp()
#include <stdlib.h>		//exit(0),  system("cls"),  malloc(),  free()
#include <stdint.h>
#include "text.h"
#include "../validation.h"	//get_natur()
#define NAME_LEN 50

struct baggage bagg_t;

char check_choice(char value_field[]);
void menu(char choice[]);


int main()
{
	char* t_name = (char*)malloc(sizeof(char) * NAME_LEN);
	while (1) {
		FILE *t_fp, *t_fp2;
		int escape;
		char choice;
		menu("main");
		choice = check_choice("189");

		switch (choice) {
			case '1': {
				escape = 0;
				while (!escape)
				{
					printf("\n1)TEXT_FILE\n");
					menu("options");
					menu("text_file");
					choice = check_choice("1234567890ab");

					printf("%s\n", t_name);
					
					switch (choice) {
						case '1': {
							char* cr_name = malloc(sizeof(char) * NAME_LEN);
							printf("\n1)CREATING\n");
							printf("Enter path(if need) and name of file with extension.\n");
							fgets(cr_name, NAME_LEN, stdin);
							cr_name[strlen(cr_name) - 1] = 0;	// remove '\n'
							
							t_create(cr_name);
							free(cr_name);
							break;
						} case '2': {
							printf("\n2)OPENING\n");
							printf("Enter path(if need) and name of file with extension.\n");
							fgets(t_name, NAME_LEN, stdin);
							t_name[strlen(t_name) - 1] = 0;
							
							t_fp = t_open(t_name);
							break;
						} case '3': {
							printf("\n3)INPUT\n");
							t_input(t_fp);
							break;
						} case '4': {
							printf("\n4)OUTPUT\n");
							t_output(t_name);
							break;
						} case '5': {
							menu("move_pointer");
							choice = check_choice("123450");

							t_move_ptr(t_fp, choice);
							break;
						} case '6': {
							printf("\n6)CHANGING\n");
							if (t_fp == NULL)
								printf("ERROR! File wasn't opened.\n");
							else {
								printf("Enter line number to change.\n");
								int line_num = get_natur();

								t_fp = t_change(t_fp, t_name, line_num);
							}
							break;
						} case '7': {
							printf("\n7)DELETING\n");
							menu("text_del");
							choice = check_choice("120");

							switch (choice) {
								case '1': {
									printf("\n1)BY_NUMBER\n");
									printf("Enter line number to delete: ");
									int line_num = get_natur();

									t_fp = t_del_by_num(t_fp, t_name, line_num);
									break;
								} case '2': {
									printf("\n2)ALL\n");
									t_fp = t_del_all(t_fp, t_name);
									break;
								} case '0': break;
							}
							break;
						} case '8': {
							printf("\n8)SAVING\n");
							menu("text_saving");
							choice = check_choice("120");

							switch (choice) {
								case '1': {
									printf("\n1)\n");
									t_save(t_fp, t_name);
									break;
								} case '2': {
									printf("\n2)\n");
									t_fp = t_save_as(t_fp, t_name);
									break;
								} case '0': break;
							}
							break;
						} case '9': {
							printf("\n9)CLOSING\n");
							fclose(t_fp);
							free(t_name);
							t_name = (char*)malloc(sizeof(char) * NAME_LEN);
							break;
						} case 'a': {
							printf("\na)TASK_1\n");
							t_task1(t_fp, t_fp2, t_name);
							break;
						} case 'b': {
							printf("\nb)TASK_2\n");
							t_task2(t_fp);
							break;
						} case '0': {
							escape = 1; break;
						} default: break;
					}
				}
				break;
			} case '8': {
				system("cls"); break;
			} case '9': {
				exit(0); break;
			} default: break;
		}
	}
	return 0;
}


char check_choice(char value_field[])
{
	char* rest = malloc(sizeof(NAME_LEN));
	char choice;
	do {
		choice = getchar();
		if (choice != '\n')
			fgets(rest, NAME_LEN, stdin);
	} while(!strchr(value_field, choice) || rest[0] != '\n');
	
	free(rest);
	return choice;
}


void menu(char choice[])
{
	if (!strcmp(choice, "main")) {
		printf("\nEnter '1' to work with a text file.\n"\
				"Enter '8' to clear console.\n"\
				"Enter '9' to get out program.\n");
	} else if (!strcmp(choice, "options")) {
		printf("1: create new file.\n"\
				"2: open file.\n"\
				"3: append info.\n"\
				"4: show file.\n"\
				"5: move pointer.\n"\
				"6: change info.\n"\
				"7: delete info.\n"\
				"8: save file.\n"\
				"9: close file.\n"\
				"0: back to menu.\n");
	} else if (!strcmp(choice, "text_file")) {
		printf("a: add in F1 after ever phrase number of words and append to F2.\n"\
				"b: determine number of string that consists only of digits.\n");
	} else if (!strcmp(choice, "text_del")) {
		printf("\n1: by number of a string.\n"\
				"2: all information.\n"\
				"0: cancel.\n");
	} else if (!strcmp(choice, "move_pointer")) {
		printf("Move pointer position in file\n"\
				"1 - to the start\n"\
				"2 - to the end\n"\
				"3 - for a one line lower\n"\
				"4 - for a one line upper\n"\
				"5 - to the given line number\n"\
				"0 - cancel\n");
	} else if (!strcmp(choice, "text_saving")) {
		printf("Move pointer position in file\n"\
				"1 - save a file\n"\
				"2 - save as a file\n"\
				"0 - cancel\n");
	}

}
