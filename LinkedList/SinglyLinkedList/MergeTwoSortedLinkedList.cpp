/*





 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3=NULL,*temp=l3;
        ListNode *temp1=l1,*temp2=l2;
        if (!l1 && !l2) return nullptr;

        // if 'l1' is empty then return 'l2'
        if (!l1) return l2;

        // if 'l2' is empty then return 'l1'
        if (!l2) return l1;
        while(temp1!=NULL && temp2!=NULL)
        {
            
             ListNode *newNode=new ListNode();
            if(temp1->val<temp2->val)
            {
               
                newNode->val=temp1->val;
                temp1=temp1->next;
            }
            else 
            {
                newNode->val=temp2->val;
                temp2=temp2->next;
            }
            
            if(l3==NULL)
            {
                l3=newNode;
                temp=l3;
            }
                
            else
            {
		        temp->next=newNode;
                temp=temp->next;
            }
           
        }
       
        if(temp1!=NULL)temp->next=temp1;
       
        if(temp2!=NULL)temp->next=temp2;
        
        return l3;
    }
};
