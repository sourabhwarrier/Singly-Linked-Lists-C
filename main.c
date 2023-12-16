#include <stdio.h>
#include "sllist.h"

int main(void){
    Node* head;
    for (int i = 0;i<10;i++){
        head = append(head,i*i);
    }
    display(head);
    return 0;
}