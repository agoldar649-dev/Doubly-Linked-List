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

void delFromAny(int pos){
    struct node *deletenode=head;
    if(head==NULL){
    printf("List is empty\n");
    return ;
    }
    if(pos==1){
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    free(deletenode);
    return;
    }
    int i=1;
    while(i!=pos && deletenode->next!=NULL){
        deletenode=deletenode->next;
        i++;
    }
    if(deletenode==NULL){
        printf("Invalid Index\n");
        return;
    }
    deletenode->prev->next=deletenode->next;
    if(deletenode->next!=NULL){
    deletenode->next->prev=deletenode->prev;
    }
    free(deletenode);
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
    int index;
    printf("Delete Index : ");
    scanf("%d",&index);
    delFromAny(index);
    traverseList();
    return 0;

}