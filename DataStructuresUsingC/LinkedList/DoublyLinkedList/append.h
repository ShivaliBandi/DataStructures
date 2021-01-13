void append(NODE **head,int value)
{
    NODE  *newNode=getNode(value);
    NODE *temp=*head;
    if(*head==NULL)
    {
        *head=newNode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}
