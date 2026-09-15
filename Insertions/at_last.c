#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head;

void traverseList(){
    struct node *temp=head;  
    
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void at_end(int item){
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
struct node *temp=head;

if(head == NULL){
    newnode->data = item;
    newnode->prev = NULL;
    newnode->next = NULL;
    head = newnode;
    return;
}

while(temp->next!=NULL){
    temp=temp->next;
}
newnode->data=item;
newnode->next=temp->next;
newnode->prev=temp;
temp->next=newnode;
}

int main (){
    struct node *second,*third;
    head=(struct node*)malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data=10;
    head->prev=NULL;
    head->next=second;

    second->data=20;
    second->prev=head;
    second->next=third;

    third->data=30;
    third->prev=second;
    third->next=NULL;

    traverseList();
    int data;
    printf("\nEnter data : ");
    scanf("%d",&data);
    at_end(data);
    traverseList();
    return 0;

}