#include <stdio.h>
#include <stdlib.h>
typedef struct print{
    int job;
    int page;
    struct print *prev;
    struct print *next;
}*NODE;

NODE getnode(NODE head){
     NODE newNode, cur = head;
     newNode = (NODE)malloc(sizeof(struct print));
     scanf("%d%d", &newNode->job, &newNode->page);
     newNode->next = newNode;
     newNode->prev = newNode;
     if(head == NULL){
         head = newNode;
     }else{
         while(cur->next!=head){
             cur = cur->next;
         }
         cur->next = newNode;
         newNode->prev = cur;
         newNode->next = head;
         head->prev = newNode;
     }
     return head;
 }

void display(NODE head){
     NODE cur = head;
     do{
         printf("%d\t", cur->page);
         cur = cur->next;
     }while( cur->next != head->next);
     printf("\n");
 }

NODE job_done(NODE head){
    NODE cur = head;

    do{
        cur->page -= 1;
        cur = cur->next;
    }while(cur->next != head->next);

    return head;
}

NODE delete(NODE head){
    NODE cur = head, temp, temp1;
    do{
        temp = cur->prev;
        if(cur->page == 0){
            temp1 = cur->next;
            temp->next = temp1;
            temp1->prev = temp;
            free(cur);
        }
        cur = cur->next;
    }while(cur->next != head->next);
    return head;
}

int main(){
    int k, p;
    char it[20];
    NODE head = NULL;
    scanf("%d", &k);
    for(int i = 0; i<k; i++){
        head = getnode(head);
    }
    scanf("%s%d",it, &p);

    for(int i = 0; i<p; i++){
        head = job_done(head);
        head = delete(head);
        display(head);
    }



    return 0;
}
