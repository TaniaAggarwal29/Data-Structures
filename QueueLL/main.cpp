//Implementing queue using linked list
#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};
class Queue
{
    Node* frontE;
    Node* rear;
    public:
    Queue()
    {
        frontE=NULL;
        rear=NULL;
    }
    void enqueue(int val);
    void print_queue();
    int dequeue();
    bool isEmpty();
    int front_element();
    int rear_element();
};
void Queue::enqueue(int val)
{
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    if(frontE==NULL)
    {
        frontE=newNode;
        rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=rear->next;
    }
}
void Queue::print_queue()
{
    Node* ptr=frontE;
    while(ptr!=nullptr)
    {
        cout<< ptr->data <<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
int Queue::dequeue()
{
    if(frontE==NULL)
    {
        cout<<"Queue is empty"<<endl;
        return INT_MIN;
    }
    int item = frontE->data;
    Node* ptr = frontE;
    if(ptr->next==nullptr)
    {
        frontE=nullptr;
        rear=nullptr;
    }
    else
        frontE = frontE->next;
    delete ptr;
    return item;
}
bool Queue::isEmpty()
{
    if(frontE==NULL)
        return true;
    return false;
}
int Queue::front_element()
{
    if(frontE==NULL)
    {
        cout<<"no element";
        return INT_MIN;
    }
    return frontE->data;
}
int Queue::rear_element()
{
    if(rear==nullptr)
    {
        cout<<"No element";
        return INT_MIN;
    }
    return rear->data;
}
int main()
{
    Queue q;
    cout<<q.isEmpty()<<endl;
    q.enqueue(4);
    cout<<q.isEmpty()<<endl;
    q.enqueue(5);
    cout<<q.front_element()<<" "<<q.rear_element()<<endl;
    q.print_queue();
    q.dequeue();
    q.print_queue();
    q.dequeue();
    cout<<q.front_element()<<" "<<q.rear_element()<<endl;
    return 0;
}
