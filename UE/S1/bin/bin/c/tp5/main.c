#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	list l = create_list();
	int i;
	
	/*srand(time(NULL));*/
	srand(42);
	for (i = 0; i < 100000; i++) {
		
		list_eAdd(&l, rand()%1000000 / (double)(rand()%1000000+1));
	}
	
	list_sort(&l);
	list_print(l);
	
	return EXIT_SUCCESS;
}
