


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 
 Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Input: head = [1,1,1,2,3]
Output: [2,3]

 */


struct ListNode* deleteDuplicates(struct ListNode* head){
     if(head==NULL)
        return head;
    struct ListNode *temp=head,*temp1=head,*temp2=head->next;
   
    while(temp!=NULL && temp2!=NULL)
    {
        if(head->val==head->next->val)
        {
            while(temp1->val==temp2->val)
            {
                if(temp2->next!=NULL)
                temp2=temp2->next;
                else
                {
                    temp2=NULL;
                    return temp2;
                }
                   
            }
            head=temp2;
            temp1=head;
            temp=head;
            temp2=head->next;
        }
        else
        {
           
            if(temp1->val!=temp2->val)
            {
                temp=temp1;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else
            {
                while(temp1->val==temp2->val)
                {
                   if(temp2->next!=NULL)
                       temp2=temp2->next;
                    else
                    {
                       temp->next=NULL;
                        return head;
                    }
                }
                temp1=temp;
                temp->next=temp2;
            }
        }
    }
    return head;
}
