#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head;
void enque(int value){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=value;
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else {
        struct Node* temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
}
void deque(){
    struct Node* temp=head;
    head=temp->next;
    free(temp);
}
void print(){
    struct Node* temp=head;
    printf("%d",temp->data);
    while(temp!=NULL)
    {
        temp=temp->next;
        printf("%d",temp->data);
    }
}


int main() {
    head=NULL;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int q;
        scanf("%d",&q);
        if(q==1){ int value;scanf("%d",&value);enque(value);}
        if(q==2) deque();
        if(q==3) print();
    }
    return 0;
}

