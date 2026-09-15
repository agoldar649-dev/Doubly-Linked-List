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

void insert_at_beginning(int item){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->prev=NULL;
    newnode->next=head;
    if(head != NULL){
        head->prev=newnode;
    }
    head=newnode;
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
    printf("\nEnter element you wanna insert at beginning : ");
    scanf("%d",&data);
    insert_at_beginning(data);
    traverseList();
    
    return 0;
}