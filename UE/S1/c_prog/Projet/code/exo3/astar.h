
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    int F;
    int H;
    int G;
    int x,y;
    char sym;
    struct node * parent;
    int is_in_closed;
    int is_in_open;
}node;


void printnode(node n);


int distance(int i,int j,int x,int y);


node * insert_to_opentable( node ** Amap,node * open_table, int x, int y, node * curr_node,  int w ,int timer);

int A(char (*matrix)[1002],char begin,char end,int size,int timer);