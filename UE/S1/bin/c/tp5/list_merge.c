# include "list.h"


static void list_merge(list l1,list l2,list* result){
        *result=NULL;
        if (l1 == NULL) {
		*result = l2;
		return;
	}
	if (l2 == NULL) {
		*result = l1;
		return;
	}
	list p=*result;
	list x=p;

	while(l1!=NULL&&l2!=NULL){
	  
	if(l1->value <=l2->value){
	  p->next=l1;
	  l1=l1->next;
	  p=p->next;
	}else{
	  p->next=l2;
	  l2=l2->next;
	  p=p-next;
	  }

	}
         if (l1 == NULL) {
		p->next = l2;
		*result=x;
		return;
	}
	if (l2 == NULL) {
		p->next = l1;
		*result=x;
		return;
	}
	
}



static void list_split(list head, list* n1, list* n2) {
	if (head == NULL || head->next == NULL) {
		*n1 = head;
		*n2 = NULL;
		return ;
	}

	list mid = head;
	list end = head->next;
	while (end != NULL) {
		end = end->next;
		if (end != NULL) {
			mid = mid->next;
			end = end->next;
		}
	}

	*n1 = head;
	*n2 = mid->next;
	mid->next = NULL;
}

static void list_mergesort(list* head) {
	list p = *head;

	/* list of size 0 or 1 */
	if (head == NULL || head->next == NULL) {
		return ;
	}

	list n1;
	list n2;
	list_split(p, &n1, &n2);
	list_mergesort(&n1);
	list_mergesort(&n2);
	list_merge(n1, n2, head);
}


void list_sort(list* lst) {
	list_mergesort(lst);
}
