#ifndef TEXT_H
#define TEXT_H

#include <stdio.h>

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
void t_task2(FILE* fptr);

#endif // TEXT_H
