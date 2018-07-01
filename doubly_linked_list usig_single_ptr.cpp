#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *ptr;
    node(int d)
    {
        data = d;
        ptr = NULL;
    }
}Node;

class LinkedList
{
    public:
    Node *head;
    Node* createNode(int data);
    Node *prev;
    Node *next;
    Node *curr;
    Node *last;
    void printList(LinkedList *first);
    void insertNode(Node *temp,LinkedList *myList);
    LinkedList()
    {
        head = NULL;
        prev = NULL;
        next = NULL;
        curr = NULL;
        last = NULL;
    }
};

Node* LinkedList::createNode(int data)
{
    Node *newNode = new Node(data);
    return newNode;
}

void LinkedList::insertNode(Node *temp , LinkedList *myList)
{
    if(head == NULL)
    {
        myList->last = temp;
        temp->ptr = NULL;
        myList->head = temp;
    }
    else
    {
        temp->ptr = myList->last;
        int k = reinterpret_cast<int> (myList->last->ptr);
        (myList->last->ptr) = reinterpret_cast<Node*> (k ^ (int)temp);
        myList->last = temp;
    }
}
void LinkedList::printList(LinkedList *my_List)
{
    if(my_List->head == NULL)
    {
        cout<<"empty list"<<endl;
    }
    else
    {
        my_List->curr = my_List->head;
        Node *temp;
        while(my_List->curr != NULL)
        {
            temp = my_List->curr;
            cout<<my_List->curr->data<<endl;
            my_List->curr = (Node*)(((int)my_List->curr->ptr) ^ ((int)my_List->prev));
            my_List->prev = temp;
        }
    }
}

int main()
{
    LinkedList l1;
    for(int i = 1; i <= 15; i++)
    {
        Node * new_node = l1.createNode(i);
        l1.insertNode(new_node , &l1);
    }
        cout<<"...origial List..."<<endl;
        l1.printList(&l1);
}
