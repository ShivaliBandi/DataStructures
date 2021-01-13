int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{
    SinglyLinkedListNode *temp1 = head1, *temp2 = head2;

    while(temp1 != temp2)
    {
        if(temp1 -> next != NULL)
            temp1 = temp1 -> next;
        else {
            temp1 = head2;
        }
        if(temp2 -> next != NULL)
            temp2 = temp2 -> next;
        else {
            temp2 = head1;
        }
    }
    return temp1 -> data;
}
