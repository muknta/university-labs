#include <stdio.h>
#include <string.h>		//strchr(),  //memset()
#include <stdlib.h>		//malloc()
#include "text.h"
#include "../validation.h"	//get_natur()
#define NAME_LEN 50
#define MAX 256

void t_create(char* file_name);
FILE* t_open(char* file_name);
void t_input(FILE* fptr);
void t_output(char* file_name);
int t_offset_lower(FILE* fptr);
int t_offset_upper(FILE* fptr);
int t_offset_by_line(FILE* fptr, int line_num);
FILE* t_move_ptr(FILE* fptr, char choice);
int t_line_check(FILE* fptr, int line_num);
FILE* t_change(FILE* fptr, char* file_name, int line_num);
FILE* t_del_by_num(FILE* fptr, char* file_name, int line_num);
FILE* t_del_all(FILE* fptr, char* file_name);
void t_save(FILE* fptr, char* file_name);
FILE* t_save_as(FILE* fptr, char* cur_name);
int t_count(FILE* fptr);
void t_task1(FILE* fptr, FILE* fptr2, char* file_name);
void t_task2(FILE* fptr2);


void t_create(char* file_name)
{
	FILE* fptr;
	if ((fptr = fopen(file_name, "w")) == NULL) {
		printf("ERROR at creating file.\n%s\n", file_name);
		return;
	}
	fclose(fptr);
	free(file_name);
}


FILE* t_open(char* file_name)
{
	FILE* fptr;
	if ((fptr = fopen(file_name, "a+")) == NULL)
		printf("ERROR at opening file.\n");

	return fptr;
}


void t_input(FILE* fptr)
{
	if (fptr == NULL) {
		printf("ERROR! File wasn't opened.\n");
		return;
	}
	char str[MAX];

	printf("Start typing 1+ lines\n"\
			"(to finish - enter * at new line)\n");
	fgets(str, MAX, stdin);
	while (str[0] != '*' || str[1] != '\n')
	{
		fprintf(fptr, "%s", str);
		fgets(str, MAX, stdin);
	}
}


void t_output(char* file_name)
{
	FILE* fptr;
	if ((fptr = fopen(file_name, "r")) == NULL) {
		printf("ERROR at opening file.\n");
		return;
	}
	fseek(fptr, 0, SEEK_SET);
	char ch;
	while ((ch = fgetc(fptr)) != EOF)
		printf("%c", ch);

	fclose(fptr);
}


int t_offset_lower(FILE* fptr)
{
	int cou = 1, pos = ftell(fptr), finish = 0;
	char ch;
	fseek(fptr, 0, SEEK_SET);

	for (; cou != pos; ++cou)
	{
		if ((ch = fgetc(fptr)) == '\n')
			finish = cou;
	}
	return finish;
}


int t_offset_upper(FILE* fptr)
{
	int pos = ftell(fptr), finish = pos;
	char ch;

	for (; !feof(fptr); ++pos)
	{
		if ((ch = fgetc(fptr)) == '\n')
			finish = pos;
	}
	return finish;
}


int t_offset_by_line(FILE* fptr, int line_num)
{
	int num = t_line_check(fptr, line_num);
	if (line_num == 0)
		return 0;
	fseek(fptr, 0, SEEK_SET);
	int pos = 0, line_t = 1;
	char ch;

	for (; line_t < num; ++pos)
		if ((ch = fgetc(fptr)) == '\n')
			++line_t;
	return pos;
}


FILE* t_move_ptr(FILE* fptr, char choice)
{
	switch (choice) {
		case '1': fseek(fptr, 0, SEEK_SET); break;
		case '2': fseek(fptr, 0, SEEK_END); break;
		case '3': fseek(fptr, t_offset_lower(fptr), SEEK_SET); break;
		case '4': fseek(fptr, t_offset_upper(fptr), SEEK_CUR); break;
		case '5': {
			printf("Enter line number: ");
			int line_num = t_line_check(fptr, get_natur());
			if (line_num == 0)
				return fptr;
			fseek(fptr, t_offset_by_line(fptr, line_num), SEEK_SET);
			break;
		}
		default: printf("ERROR! Variant doesn't exist.\n");
	}
	return fptr;
}


int t_line_check(FILE* fptr, int line_num)
{
	int num = t_count(fptr);
	int choice = line_num;
	while (0 > choice || choice > num)
	{
		printf("ERROR! Line with this number doesn't exist.\n"\
				"Enter number between 1 and %d, or 0 - to cancel.\n", num);
		choice = get_natur();
	}
	return choice;
}


FILE* t_change(FILE* fptr, char* file_name, int line_num)
{
	if (fptr == NULL) {
		printf("ERROR! File wasn't opened.\n");
		return NULL;
	}
	FILE* fptr2;
	char str[MAX], ch;
	int line_t = 1;
	char copy_name[NAME_LEN];
	sprintf(copy_name, "%scopy", file_name);
	
	int num = t_line_check(fptr, line_num);
	if (num == 0)
		return fptr;

	fseek(fptr, 0, SEEK_SET);
	if ((fptr2 = fopen(copy_name, "w")) == NULL) {
		printf("ERROR at opening file.\n");
		return fptr;
	}
	ch = fgetc(fptr);
	while (!feof(fptr))
	{
		if (line_t != num)
			fputc(ch, fptr2);
		else {
			printf("Enter a line.\n");

			getchar();
			fgets(str, MAX, stdin);

			fprintf(fptr2, "\n%s", str);
			fgets(str, MAX, fptr);
			++line_t;
		}
		if ((ch = fgetc(fptr)) == '\n')
			++line_t;
	}
	fclose(fptr);
	fclose(fptr2);
	remove(file_name);
	rename(copy_name, file_name);
	
	strcpy(copy_name, file_name);
	fptr = t_open(copy_name);
	return fptr;
}


FILE* t_del_by_num(FILE* fptr, char* file_name, int line_num)
{
	if (fptr == NULL) {
		printf("ERROR! File wasn't opened.\n");
		return NULL;
	}
	FILE* fptr2;
	char copy_name[NAME_LEN];
	sprintf(copy_name, "%scopy", file_name);

	char ch;
	int line_t = 1;
	int del_line = t_line_check(fptr, line_num);
	if (del_line == 0)
		return fptr;

	fseek(fptr, 0, SEEK_SET);
	if ((fptr2 = fopen(copy_name, "w")) == NULL) {
		printf("ERROR at opening file.\n");
		return fptr;
	}
	ch = fgetc(fptr);
	while (!feof(fptr))
	{
		if (line_t != del_line)
			fputc(ch, fptr2);
		if ((ch = fgetc(fptr)) == '\n')
			++line_t;
	}
	fclose(fptr);
	fclose(fptr2);
	remove(file_name);
	rename(copy_name, file_name);

	strcpy(copy_name, file_name);
	fptr = t_open(copy_name);

	return fptr;
}


FILE* t_del_all(FILE* fptr, char* file_name)
{
	if (fptr == NULL) {
		printf("ERROR! File wasn't opened.\n");
		return NULL;
	}
	fclose(fptr);
	remove(file_name);

	fptr = t_open(file_name);
	return fptr;
}


void t_save(FILE* fptr, char* file_name)
{
	fclose(fptr);
	fptr = t_open(file_name);
}


FILE* t_save_as(FILE* fptr, char* cur_name)
{
	char* new_name = (char*)malloc(sizeof(char) * NAME_LEN);
	FILE* fptr2;

	printf("Enter new name with extension and path.\n"\
			"(to save the current name - enter * )\n");
	int escape = 0;
	while (!escape) {
 		scanf("%s", new_name);
		if (new_name[0] == '*' && !new_name[1])
			return fptr;
		if ((fptr2 = fopen(new_name, "w")) != NULL)
			escape = 1;
		else
			printf("ERROR! Try again.\n");
	}
	fclose(fptr);
	fclose(fptr2);
	remove(new_name);
	rename(cur_name, new_name);

	strcpy(cur_name, new_name);
	fptr = t_open(new_name);
	free(new_name);
	return fptr;
}


int t_count(FILE* fptr)
{
	if (fptr == NULL) {
		printf("ERROR! File wasn't opened.\n");
		return 0;
	}
	int lines = 1;
	char ch;
	fseek(fptr, 0, SEEK_SET);
	while (!feof(fptr))
	{
		if ((ch = fgetc(fptr)) == '\n')
			++lines;
	}
	return lines;
}


void t_task1(FILE* fptr, FILE* fptr2, char* file_name)
{
	char ch, str[NAME_LEN];
	char* file_name2;
	sprintf(file_name2, "%s2", file_name);

	if ((fptr2 = fopen(file_name2, "w")) == NULL) {
		printf("ERROR at opening file.\n");
		return;
	}
	if (fptr == NULL) {
		printf("ERROR! File wasn't opened.\n");
		return;
	}
	fseek(fptr, 0, SEEK_SET);
	for (int cou = 0; (ch = fgetc(fptr)) != EOF;)
	{
		if (ch == '\n') {
			sprintf(str, " ->(%d characters)", cou);
			fputs(str, fptr2);
			cou = 0;
		} else {
			++cou;
		}
		fputc(ch, fptr2);
	}
	fclose(fptr2);
	fptr2 = t_open(file_name2);
}


void t_task2(FILE* fptr)
{
	if (fptr == NULL) {
		printf("ERROR! File wasn't opened.\n");
		return;
	}
	int line_num = 1, winner = 0, words = 0, sens = 1;
	char ch;
	fseek(fptr, 0, SEEK_SET);

	printf("Rows which contain words consisting of digits:\n");
	int escape = 0;
	while (!escape)
	{
		ch = fgetc(fptr);
		if (strchr("\n\t .,:;!?-\\|/\"'<>", ch)
				|| ch == EOF)
		{
			if (winner > 0 && sens == 1) {
				++words;
				winner = 0;
			}
			if (ch == '\n' || ch == EOF) {
				if (words > 0) {
					printf("number - %d; word(s) - %d\n", line_num, words);
					words = 0;
				}
				++line_num;
			}
			sens = 1;
			if (ch == EOF)
				escape = 1;
		}
		else if (strchr("1234567890", ch)) {
			if (sens == 1)
				winner = line_num;
		}
		else {
			winner = 0;
			sens = 0;
		}
	}
}
