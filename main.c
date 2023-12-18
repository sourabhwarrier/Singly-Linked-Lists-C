#include <stdio.h>
#include <stdlib.h>
#include "sllist.h"

int main(void){
    //Node* head = (Node*) calloc(1,sizeof(Node));
    //head->value = 11;
    Node* head;
    head = append(head,5);
    head = append(head,7);
    head = append(head,3);
    head = append(head,9);
    head = append(head,4);
    head = append(head,1);
    head = append(head,8);
    head = append(head,2);

    display(head);
    sort(head);
    display(head);
    return 0;
}