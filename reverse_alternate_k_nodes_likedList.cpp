// Reverse consecutive k nodes

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
}Node;

class LinkedList
{
    public:
    Node *head;
    Node* createNode(int data);
    void reverse_k_elements(int k);
    void printList(Node *first);
    LinkedList()
    {
        head = NULL;
    }
};

Node* LinkedList::createNode(int data)
{
    Node *newNode = new Node(data);
    return newNode;
}

void LinkedList::reverse_k_elements(int k)
{
    Node *temp_head = NULL , *temp_last = NULL , * final_list = NULL , *previous_last = NULL;
    Node *temp = head , *t = NULL;
    int p = 0;
    bool last_k_nodes_addressed = false;

    while(temp != NULL)
    {
        t = temp->next;
        if(last_k_nodes_addressed)
        {
            if(temp_head == NULL)
            {
                temp_head = temp;
            }
            if(p == k)
            {
                p = 0;
                last_k_nodes_addressed = false;
                previous_last->next = temp_head;
                previous_last = temp;
                temp_head = NULL;
            }
            else
                p++;
            temp = t;
        }
        else
        {
        if(p < k)
        {
            if(temp_head == NULL)
            {
                temp_last = temp;
            }
            temp->next = temp_head;
            temp_head = temp;
            p++;
            temp = t;
        }
        else
        {
            p = 0;
            if(previous_last == NULL)
            {
                head = temp_head;
            }
            if(previous_last != NULL)
            {
                previous_last->next = temp_head;
            }
            previous_last = temp_last;
            temp_head = NULL;
            last_k_nodes_addressed = true;
        }
        }
    }
    previous_last->next = temp_head;
}

void LinkedList::printList(Node *first)
{
    Node *my_list = first;
    while(my_list != NULL)
    {
        cout<<my_list->data<<endl;
        my_list = my_list->next;
    }
}

int main()
{
    LinkedList l1;
    for(int i = 1; i <= 15; i++)
    {
        Node * new_node = l1.createNode(i);
        new_node->next = l1.head;
        l1.head = new_node;
    }
        cout<<"...origial List..."<<endl;
        l1.printList(l1.head);
        cout<<"...reversing k elements for k = 3..."<<endl;
        l1.reverse_k_elements(3);
        l1.printList(l1.head);
}
