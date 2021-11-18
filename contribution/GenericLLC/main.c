#include <stdio.h>
#include <stdlib.h>

struct Node
{
    void* data;
    struct Node* next;
};

void push(struct Node** head_ref, void* val,size_t datasize)
{
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node*));
    newNode->data=malloc(datasize);
    newNode->next= *head_ref;
    for(int i=0;i<datasize;i++)
        *(char *)(newNode->data+i) = *(char *)(val+i);
    *head_ref=newNode;
}
void print(struct Node *head,void (*func)(void *))
{
    while(head!=NULL)
    {
        (*func)(head->data);
        head=head->next;
    }
}
void printInt(void *n)
{
    printf(" %d ",*(int *)n);
}
void printFloat(void *n)
{
    printf(" %f ",*(float *)n);
}
int main()
{
    struct Node* start=NULL;
    int arr[]={1,2,3,4,5};
    unsigned datasize=sizeof(int);
    for(int i=4;i>=0;i--)
        push(&start,&arr[i],datasize);
    print(start,printInt);
    start=NULL;
    float arr2[]={1.0,2.2,3.3};
    datasize=sizeof(float);
    for(int i=2;i>=0;i--)
        push(&start,&arr2[i],datasize);
    print(start,printFloat);
    return 0;
}
