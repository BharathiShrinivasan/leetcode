#include<stdio.h>

 struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* deleteMiddle(struct ListNode* head){
	
	struct ListNode* OriginalHead=head;
	int count=0;
	
	while(head!=NULL)
	{
	    head=head->next;
	    count++;
	}
	
	count=count/2;
	head=OriginalHead;
	for(int i=0;i<count-1;i++)
	{
	    head=head->next;
	}
	
	head->next = (head->next)->next;
	
	return OriginalHead;

}

int main()
{
	struct ListNode Temp[4];
	Temp[0].val=11;
	Temp[0].next=&Temp[1];
	
	Temp[1].val=22;
	Temp[1].next=&Temp[2];
	
	Temp[2].val=33;
	Temp[2].next=&Temp[3];
	
	Temp[3].val=44;
	Temp[3].next=NULL;
	
	struct ListNode *head ;//= &Temp[0];
	
	head = deleteMiddle(&Temp[0]);

	while(head!=NULL)
	{
		printf("%d -> ",head->val);
		head=head->next;
	}
	
	return 1;
}
