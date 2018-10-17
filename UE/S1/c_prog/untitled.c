#include 'list.h'
list merge(list head1, list head2){
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        list res;
	list p ;
        if(head1->value < head2->value){
	  res = head1; head1 = head1->next;
	    }
        else{
	  res = head2; head2 = head2->next;
	}
        p = res;
        while(head1 != NULL && head2 != NULL){
            if(head1->value < head2->value){
                p->next = head1;
                head1 = head1->next;
            }
            else{
                p->next = head2;
                head2 = head2->next;
            }
            p = p->next;
        }
        if(head1 != NULL) p->next = head1;
        else if(head2 != NULL) p->next = head2;
        return res;
}

list list_merge(list head){
     
  if(head == NULL || head->next == NULL) return head;
  else{
    list fast = head;
    list slow = head;
      while(fast->next != NULL && fast->next->next != NULL)
	{
	  fast = fast->next->next;
	  slow = slow->next;
	}
      fast = slow;
      slow = slow->next;
      fast->next = NULL;
      fast = list_merge(head);
      slow = list_merge(slow);
      return merge(fast,slow);
    }
         
}