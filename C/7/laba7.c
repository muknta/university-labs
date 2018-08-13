#include <stdio.h>
#include <string.h>	// strchr(),  strcpy()
#include <stdlib.h>	// malloc(),  exit(0),  system("cls")
#include <ctype.h>	// tolower()
#include "../validation.h"
#define NAME_LEN 50


typedef struct Flat {
	char name[NAME_LEN];
	int area, rooms, floor;
	struct Flat* next;
} flat_t;


void menu(char choice);
flat_t* creating(flat_t* next, int pos);
flat_t* filling(flat_t* head);
flat_t* add_to_begin(flat_t* head);
flat_t* add_to_end(flat_t* head);
flat_t* insert_before(flat_t* head, int pos);
flat_t* insert_after(flat_t* head, int pos);
flat_t* del_begin(flat_t* head);
flat_t* del_end(flat_t* head);
flat_t* del_by_num(flat_t* head, int pos);
flat_t* del_by_name(flat_t* head, char t_name[]);
void swap(flat_t* prev, flat_t* curr);
flat_t* sort_by_name(flat_t* head);
flat_t* sort_by_area(flat_t* head);
void showing(flat_t* head);
void data_copy(flat_t* copy, flat_t* current);
flat_t* save_rest(flat_t* head_copy, flat_t* head);
int counting(flat_t* head);
flat_t* declaring();
flat_t* freeing(flat_t* head);
flat_t* error(flat_t* head, char choice[]);
int min_num(int f_num, int s_num);


int main()
{
	flat_t *head = NULL, *head_copy = NULL;

	while (1) {
		char choice;
		menu('0');
		do {
			choice = getchar();
		} while (!strchr("12345689", choice));

		switch (choice) {
			case '1': {
				printf("\n1)APPENDING\n");
				menu(choice);
				do {
					choice = getchar();
				} while (!strchr("123450", choice));
				switch (choice) {
					case '1': {
						head = add_to_begin(head); break;
					} case '2': {
						head = add_to_end(head); break;
					} case '3': {
						if (head == NULL) {
							printf("ERROR! List is empty.\n"); break;
						}
						printf("Enter position: ");
						int pos = get_natur();
						head = insert_before(head, pos); break;
					} case '4': {
						if (head == NULL) {
							printf("ERROR! List is empty.\n"); break;
						}
						printf("Enter position: ");
						int pos = get_natur();
						head = insert_after(head, pos); break;
					} case '5': {
						head = filling(head); break;
					} case '0': break;
				}
				break;
			} case '2': {
				printf("\n2)DELETING\n");
				menu(choice);

				if (head == NULL) {
					printf("ERROR! List is empty.\n"); break;
				}
				do {
					choice = getchar();
				} while (!strchr("123450", choice));
				switch (choice) {
					case '1': {
						head = del_begin(head); break;
					} case '2': {
						head = del_end(head); break;
					} case '3': {
						printf("Enter position: ");
						int pos = get_natur();
						head = del_by_num(head, pos); break;
					} case '4': {
						printf("Enter name: ");
						char t_name[NAME_LEN];
						scanf("%s", &t_name);
						head = del_by_name(head, t_name); break;
					} case '5': {
						head = freeing(head); break;
					} case '0': break;
				}
				break;
			} case '3': {
				printf("\n3)SORTING\n");
				menu(choice);
				do {
					choice = getchar();
				} while (!strchr("120", choice));
				switch (choice) {
					case '1': {
						head = sort_by_name(head); break;
					} case '2': {
						head = sort_by_area(head); break;
					} case '0': break;
				}
				break;
			} case '4': {
				printf("\n4)SHOWING\n");
				showing(head);
				printf("\n4)A COPY\n");
				showing(head_copy);
				break;
			} case '5': {
				printf("\n5)SAVING\n");
				head_copy = save_rest(head_copy, head);
				break;
			} case '6': {
				printf("\n6)RESTORING\n");
				head = save_rest(head, head_copy);
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


void menu(char choice)
{
	if (choice == '0') {
		printf("\nEnter '1' to add items.\n"\
				"Enter '2' to delete one element.\n"\
				"Enter '3' to sort the structure.\n"\
				"Enter '4' to show the table.\n"\
				"Enter '5' to save.\n"\
				"Enter '6' to restore.\n"\
				"Enter '8' to clear console.\n"\
				"Enter '9' to get out program.\n");
	} else if (choice == '1') {
		printf("1: to the beginning.\n"\
				"2: to the end.\n"\
				"3: in front of the item.\n"\
				"4: after the item.\n"\
				"5: several items to the end.\n"\
				"0: back to menu.\n");
	} else if (choice == '2') {
		printf("1: at the beginning.\n"\
				"2: at the end.\n"\
				"3: with a given number.\n"\
				"4: with a given name.\n"\
				"5: all items.\n"\
				"0: back to menu.\n");
	} else if (choice == '3') {
		printf("1: by name (A-Z).\n"\
				"2: by area of the flat.\n"\
				"0: back to menu.\n");
	}
}

/*
	Create an one node with data of the structure.
*/
flat_t* creating(flat_t* next, int pos)
{
	flat_t* new_node = declaring();

	printf("\n%d).Name: ", pos);
	scanf("%s", &new_node->name);
	printf("%d).Area of the flat: ", pos);
	new_node->area = get_natur();
	printf("%d).Number of rooms: ", pos);
	new_node->rooms = get_natur();
	printf("%d).Floor of the building: ", pos);
	new_node->floor = get_natur();

	new_node->next = next;
	return new_node;
}

/*
	Append several items to the end.
*/
flat_t* filling(flat_t* head)
{
	// head = NULL;
	// head = declaring();
	// strcpy(head->name, "zda");  head->area = 11; head->rooms = 12; head->floor = 13;
	
	// flat_t* current = head;
	// current->next = NULL;
	// current->next = declaring();
	// strcpy(current->next->name, "asssa");  current->next->area = 21; current->next->rooms = 22; current->next->floor = 23;
	// current = current->next;

	// current->next = NULL;
	// current->next = declaring();
	// strcpy(current->next->name, "zda");  current->next->area = 31; current->next->rooms = 32; current->next->floor = 33;
	// current = current->next;

	// current->next = NULL;
	// current->next = declaring();
	// strcpy(current->next->name, "azaaz");  current->next->area = 41; current->next->rooms = 42; current->next->floor = 43;
	// current = current->next;

	// current->next = NULL;
	// current->next = declaring();
	// strcpy(current->next->name, "aaagha");  current->next->area = 51; current->next->rooms = 52; current->next->floor = 53;
	// current = current->next;
	// current->next = NULL;

	int counter = counting(head);
	printf("How much you need?: ");
	int value = get_natur();
	if (value == 0)
		return head;
	if (head == NULL) {
		head = creating(NULL, ++counter);
		--value;
	}
	flat_t* current = head;

	for (int i = 0; i < value; ++i) {
		current->next = creating(NULL, ++counter);
		current = current->next;
	}
	return head;
}

/*
	Add one item to the begin of the structure.
*/
flat_t* add_to_begin(flat_t* head)
{
	return creating(head, 1);
}

/*
	Add one item to the end of the structure.
*/
flat_t* add_to_end(flat_t* head)
{
	int size = 1;
	if (head == NULL)
		return creating(NULL, size);

	flat_t* current = head;

	for (; current->next != NULL; ++size)
		current = current->next;
	current->next = creating(NULL, ++size);
	return head;
}

/*
	Insert item before the given item.
*/
flat_t* insert_before(flat_t* head, int pos)
{
	if (head == NULL)
		return error(head, "empty");

	flat_t* current = head;
	
	if (pos == 1) 
		return add_to_begin(head);
	for (int i = 2; i < pos; ++i)
	{
		current = current->next;
		if (current->next == NULL)
			return error(head, "does_not_exist");
	}
	flat_t* new_node = creating(current->next, pos);
	current->next = new_node;
	return head;
}

/*
	Insert item after the given item.
*/
flat_t* insert_after(flat_t* head, int pos)
{
	if (head == NULL)
		return error(head, "empty");

	flat_t* current = head;

	for (int i = 1; i < pos; ++i) {
		if (current->next == NULL)
			return error(head, "does_not_exist");

		current = current->next;
	}
	flat_t* new_node = creating(current->next, pos+1);
	current->next = new_node;
	return head;
}

/*
	Remove one item from the begin.
*/
flat_t* del_begin(flat_t* head)
{
	if (head == NULL)
		return error(head, "empty");

	flat_t* temp = head->next;
	free(head);
	return temp;
}

/*
	Remove one item from the end.
*/
flat_t* del_end(flat_t* head)
{
	if (head == NULL)
		return error(head, "empty");

	flat_t* prev;
	flat_t* current = head;
	while (current->next != NULL) {
		prev = current;
		current = current->next;
	}
	if (current == head)
		head = NULL;
	else if (prev != NULL)
		prev->next = NULL;

	free(current);
	return head;
}

/*
	Remove one item with given number.
*/
flat_t* del_by_num(flat_t* head, int pos)
{
	if (head == NULL)
		return error(head, "empty");

	flat_t* prev;
	flat_t* current = head;
	for (int i = 1; i < pos; ++i)
	{
		if (current->next == NULL)
			return error(head, "does_not_exist");
		prev = current;
		current = current->next;
	}
	if (current == head)
		return del_begin(head);
	else if (prev != NULL)
		prev->next = current->next;

	free(current);
	return head;
}

/*
	Remove one item with given name.
*/
flat_t* del_by_name(flat_t* head, char t_name[])
{
	if (head == NULL)
		return error(head, "empty");

	if (head->next == NULL) {
		if (strcmp(head->name, t_name) != 0)
			return error(head, "does_not_exist");
		return del_begin(head);
	}

	flat_t* prev;
	flat_t* current = head;
	int iter = 0;
	while (current->next != NULL) {
		if (strcmp(current->name, t_name) == 0) {	//if strings are equal
			if (current == head)
				head = del_begin(head);
			else if (prev != NULL)
				prev->next = current->next;
			free(current);
			++iter;
		}
		prev = current;
		current = current->next;
	}
	if (iter == 0)
		return error(head, "does_not_exist");
	return head;
}

/*
	Swap a data of two items(nodes).
*/
void swap(flat_t* prev, flat_t* curr)
{
	char s_temp[NAME_LEN];
	strcpy(s_temp, prev->name);
	strcpy(prev->name, curr->name);
	strcpy(curr->name, s_temp);

	int i_temp = prev->area;
	prev->area = curr->area;
	curr->area = i_temp;

	i_temp = prev->rooms;
	prev->rooms = curr->rooms;
	curr->rooms = i_temp;

	i_temp = prev->floor;
	prev->floor = curr->floor;
	curr->floor = i_temp;
}

/*
	Sorting by the name in structure.
*/
flat_t* sort_by_name(flat_t* head)
{
	if (head == NULL)
		return error(head, "empty");

	flat_t *current, *ptr = NULL;
	int swapped;
	do {
		swapped = 0;
		current = head;
		while (current->next != ptr)
		{
			int min_len = min_num(strlen(current->name), strlen(current->next->name));
			for (int k = 0; k < min_len; ++k)
			{
				if ((tolower(current->next->name[k]) < tolower(current->name[k]))
					|| (tolower(current->next->name[k]) == tolower(current->name[k])
					&& !current->next->name[k+1] && current->name[k+1]))
				{
					swap(current, current->next);
					swapped = 1;
					break;
				}
				else if (tolower(current->next->name[k]) > tolower(current->name[k]))
					break;
			}
			current = current->next;
		}
		ptr = current;
	} while (swapped);
	return head;
}

/*
	Sorting by the area in structure.
*/
flat_t* sort_by_area(flat_t* head)
{
	if (head == NULL)
		return error(head, "empty");

	flat_t *current, *ptr = NULL;
	int swapped;
	do {
		swapped = 0;
		current = head;
		while (current->next != ptr)
		{
			if (current->area < current->next->area)
			{
				swap(current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
		ptr = current;
	} while (swapped);

	return head;
}

/*
	Output of an all structure.
*/
void showing(flat_t* head)
{
	if (head == NULL) {
		printf("ERROR! List is empty.\n");
		return;
	}

	flat_t* current = head;
	int counter = 0;

	printf("\n          NAME   AREA  ROOMS  FLOOR\n");
	while (current != NULL) {
		printf("%d). %10s %6d %6d %6d\n",
			++counter, current->name, current->area,
			current->rooms, current->floor);
		current = current->next;
	}
}

/*
	Copying data from current item to the copy_node.
*/
void data_copy(flat_t* copy, flat_t* current)
{
	strcpy(copy->name, current->name);
	copy->area = current->area;
	copy->rooms = current->rooms;
	copy->floor = current->floor;
}

/*
	Can save and restore structure.
*/
flat_t* save_rest(flat_t* head_copy, flat_t* head)
{
	if (head == NULL)
		return error(NULL, "empty");
	freeing(head_copy);

	head_copy = NULL;
	head_copy = declaring();
	flat_t* current = head;
	data_copy(head_copy, current);
	flat_t* copy = head_copy;
	
	while (current->next != NULL)
	{
		copy->next = NULL;
		copy->next = declaring();
		data_copy(copy->next, current->next);

		copy = copy->next;
		current = current->next;
	}
	copy->next = NULL;

	return head_copy;
}

/*
	Auxiliary function for counting until the last.
*/
int counting(flat_t* head)
{
	int counter = 0;
	flat_t* current = head;

	while (current != NULL) {
		current = current->next;
		++counter;
	}
	return counter;
}

/*
	Declare an structure variable.
*/
flat_t* declaring()
{
	flat_t* foo = (flat_t*)malloc(sizeof(flat_t));
	return foo;
}

/*
	Free the structure.
*/
flat_t* freeing(flat_t* head)
{
	flat_t* curr;
	while ((curr = head) != NULL) {
		head = head->next;
		free(curr);
	}
	return head;
}
//another variant
/*for (p = curr; NULL != p; p = next) {
    next = p->next;
    free(p);
}*/

/*
	Auxiliary function for printing error and returning a head.
*/
flat_t* error(flat_t* head, char choice[])
{
	if (strcmp(choice, "does_not_exist") == 0)
		printf("ERROR! Element doesn't exist.\n");
	else if (strcmp(choice, "empty") == 0)
		printf("ERROR! List is empty.\n");

	return head;
}

/*
	Auxiliary function for determining of minimal number among the couple.
*/
int min_num(int f_num, int s_num)
{
	if (f_num <= s_num)
		return f_num;
	else
		return s_num;
}
