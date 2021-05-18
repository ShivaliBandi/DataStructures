
#Structure of node
class Node:
#parameterized constructor
    def __init__(self,data):
        self.data=data
        self.prev=None
        self.next=None

#doublyCircularLinkedList class it contains all functions
class doublyCircularLinkedList:
    #default  constructor
    def __init__(self):
        self.head=None
        #insertFirst function inserts element at first position in linked list
    def insertFirst(self,element):
        newNode=Node(element)
        #to check whether linked list is empty
        if(self.head==None):
            self.head=newNode
            newNode.next=newNode
            newNode.prev=newNode
        else:
            newNode.next=self.head
            newNode.prev=self.head.prev
            self.head.prev=newNode
            newNode.prev.next=newNode
            self.head=newNode
    #displayForward function displays linked list in forward manner
    def displayForward(self):
        temp=self.head
        if(self.head==None):
            print("Linked List is Empty")
        else:
            while(temp.next!=self.head):
                print(temp.data,end=" ")
                temp=temp.next
            print(temp.data)
    #displayBackward function displays Linked List in reverse
    def displayReverse(self):
        temp=self.head
        if(self.head==None):
            print("Linked List is Empty")
        else:
            while(temp.prev!=self.head):
                temp=temp.prev
                print(temp.data,end=" ")
            temp=temp.prev
            print(temp.data)
    #insertLast function appends element at the end of the linked List
    def insertLast(self,element):
        newNode=Node(element)
        temp=self.head
        if(self.head!=None):
            temp=temp.prev
            temp.next=newNode
            newNode.prev=temp
            newNode.next=self.head
            self.head.prev=newNode
        else:
            self.head=newNode
            newNode.next=newNode
            newNode.prev=newNode
    #count function displays total numbers of linked List
    def count(self):
        temp=self.head
        count=0
        if(self.head==None):
            print("Linked List is Empty")
            return 0
        else:
            while(temp.next!=self.head):
                count=count+1
                temp=temp.next
            count=count+1
        return count
    #insertAt function insert Linked List at specific position in LinkedList
    def insertAt(self,element,pos):
        temp=self.head
        newNode=Node(element)
        if(pos==1):
            self.insertFirst(element)
        elif(pos==self.count()+1):
            self.insertLast(element)
        elif(pos>=2 and pos<=self.count()):
            while(pos>2):
                pos=pos-1
                temp=temp.next
            newNode.prev=temp
            newNode.next=temp.next
            temp.next=newNode
            newNode.next.prev=newNode
        else:
            print("invalid position please enter valid position")
    #deleteFirst function is used to delete first element in linked List
    def deleteFirst(self):
        temp=self.head
        if(self.head==None):
            print("Linked List is empty")
        elif(temp.next==self.head):
            self.head=None
            del temp
        else:
            temp=temp.prev
            temp.next=self.head.next
            self.head=self.head.next
            self.head.prev=temp
    #deleteLast function is Used to delete last element in linked List
    def deleteLast(self):
        temp=self.head
        if(self.head==None):
            print("Linked List is empty")
        elif(temp.next==self.head):
            self.head=None
            del temp
        else:
            temp=temp.prev
            self.head.prev=temp.prev
            temp.prev.next=self.head
            del temp
    #deleteAt function is used to delete element at specific Position
    def deleteAt(self,pos):
        temp=self.head
        if(self.head==None):
            print("Linked List Is empty")
        elif(pos==1):
            self.deleteFirst()
        elif(pos==self.count()):
            self.deleteLast()
        elif(pos>1 and pos<self.count()):
            temp1=None
            while(pos>2):
                pos=pos-1
                temp=temp.next
            temp1=temp.next
            temp.next=temp1.next
            temp1.next.prev=temp1.prev
            del temp1
        else:
            print("INVALID POSITION PLEASE ENTER VALID POSITION")
    #search function is used to search a specific element from linkedList
    def search(self,element):
        temp=self.head
        flag=0
        if(temp==None):
            flag=-1
            
        else:
            while(temp.next!=self.head):
                if(temp.data==element):
                    flag=1
                    break
                temp=temp.next
            if(temp.data==element):
                flag=1
        return flag
def main():
    print("InsideMain")
    dobj=doublyCircularLinkedList()
    
    dobj.insertFirst(50)
   
    dobj.insertFirst(40)
    dobj.insertFirst(30)
    dobj.insertLast(60)
    dobj.insertLast(70)
    print("display forward")
    dobj.displayForward()
    dobj.deleteFirst()
   
    dobj.insertAt(100,dobj.count()+1)
    print("display forward")
    dobj.displayForward()
    print("display backward")
    dobj.displayReverse()
    dobj.deleteAt(1)
    print("display forward")
    dobj.displayForward()
    print("display backward")
    dobj.displayReverse()
    flag=dobj.search(0)
    if(flag==1):
        print("Element is present in Linked List")
    elif(flag==-1):
        print("linkedList Is Empty")
    else:
        print("Element is not present in linkedList")


   # print("count of nodes in linked list -->",dobj.count())
if __name__=="__main__":
    main()