#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
typedef struct node* list;


list create_list();
int list_isEmpty(list l);
list list_vAdd(double value, list l);
void list_eAdd(list* pl, double value);
void list_print(list l);
int list_count(list l);
int list_sum(list l, double* ret);
list inverse(list l);
void list_reverse(list* pl);
int ise(double e);
/*int list_find(list l, double value, double* ret);
//int list_elementAt(list l, int index, double* ret);*/
int list_remove(list* pl, double value);
int list_removeAll(list* pl, double value);

list sort(list l);
void list_sort(list* pl);

#endif
