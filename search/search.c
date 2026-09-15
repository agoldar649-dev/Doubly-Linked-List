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

void searchElement(int item){
    struct node *temp=head;
    while(temp!=NULL){
        if (temp->data==item){
            printf("Element found in the list\n");
            return;
        }
        temp=temp->next;
    }
    printf("Eement not found\n");
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
    int element ;
    printf("Enter element : ");
    scanf("%d",&element);
    searchElement(element);
    return 0;

}