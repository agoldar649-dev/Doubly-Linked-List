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

void at_any_pos(int item , int pos){
    struct node *newnode ;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(pos==1){
        newnode->data=item;
        newnode->next=head;
        newnode->prev=NULL;
        if(head!=NULL){
            head->prev=newnode;
        }
        head=newnode;
        return;
        }
        int i =1;
        struct node *temp=head;
        while(i!=pos-1 && temp!=NULL){
            temp=temp->next;
            i++;
        }
        if(temp==NULL){
            printf("Invalid position");
            free(newnode);
            return;
        }
        newnode->data=item;
        newnode->next=temp->next;
        newnode->prev=temp;
        if(temp->next!=NULL){
        newnode->next->prev=newnode;
        }
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
    int data,index;
    printf("\nEnter data : ");
    scanf("%d",&data);
    printf("Enter position : ");
    scanf("%d",&index);
    at_any_pos(data,index);
    traverseList();
    return 0;

}