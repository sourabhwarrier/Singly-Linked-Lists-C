#include <stdio.h>
#include <stdlib.h>
#include "sllist.h"

void display(Node* head){
    Node* current = head;
    int index = 0;
    while(current != NULL){
        printf("[%d]:%d -> ",index++,current->value);
        current = current->next;
    }
    if (current == NULL){
        printf("NULL\n");
    }
    return;
}

Node* attach(Node* head, int new_value){
    Node* new_node = calloc(1,sizeof(Node));
    new_node->value = new_value;
    if (head != NULL){
        new_node->next = head;
    }
    return new_node;
}

Node* append(Node* head, int new_value){
    Node* new_node = calloc(1,sizeof(Node));
    new_node->value = new_value;
    if (head == NULL){
        head = new_node;
    }
    else{
        Node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
    return head;
}

Node* drop_head(Node* head){
    if (head != NULL){
        Node* head_prev = head;
        head = head->next;
        free(head_prev);
    }
    return head;
}

Node* drop_tail(Node* head){
    if(head == NULL){
        return head;
    }
    else if(head->next == NULL){
        free(head);
        return NULL;
    }
    else{
        Node* current = head;
        Node* node_prev;
        while(current->next != NULL){
            node_prev = current;
            current = current->next;
        }
        free(current);
        node_prev->next = NULL;
    }
    return head;
}

int length(Node* head){
    int len = 0;
    Node* current = head;
    while(current != NULL){
        len++;
        current = current->next;
    }
    return len;
}

int present(Node* head, int target){
    int found = 0;
    Node* current = head;
    while(current != NULL){
        if (current->value == target){
            found = 1;
            break;
        }
        current = current->next;
    }
    return found;
}

int count(Node* head, int target){
    int count = 0;
    Node* current = head;
    while(current != NULL){
        if (current->value == target){
            count++; 
        }
        current = current->next;
    }
    return count;
}

void replace(Node* head, int target, int new_value, int ttl){
    int flag = (ttl > 0);
    Node* current = head;
    while(current != NULL){
        if ((flag && ttl) || !flag){
            if (current->value == target){
                current->value = new_value;
                ttl--; 
            }
        }
        current = current->next;
    }
    return;
}

Node* drop_matches(Node* head, int target, int ttl){
    int flag = (ttl > 0);
    Node* current = head;
    Node* node_prev;
    if(current == NULL){
        return current;
    }
    else if(current->next == NULL){
        if ((flag && ttl) || !flag){
            if(current->value == target){
                free(current);
                return NULL;
            }
        }
    }
    else{
        while(current != NULL){
            if ((flag && ttl) || !flag){
                if (current->value == target){
                    if(node_prev == NULL){
                        head = head->next;
                        free(current);
                        current = head;
                        ttl--;
                    }
                    else{
                        node_prev->next = current->next;
                        free(current);
                        current = node_prev->next;
                        ttl--;
                    }
                }
                else{
                    node_prev = current;
                    current = current->next;
                }
            }
            else{
                break;
            }
        }
    }
    return head;
}

Node* join(Node* head1, Node* head2){
    if(head1 == NULL){
        return head2;
    }
    else if(head2 == NULL){
        return head1;
    }
    else{
        Node* current = head1;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = head2;
    }
    return head1;
}

Node* reverse(Node* head, int ttl){
   int flag = (ttl > 0);
    Node* current = head;
    if (ttl == 1 || current == NULL || current->next == NULL){
        return current;
    }
    Node* node_prev = NULL; 
    Node* node_next = NULL; 
    while(current->next != NULL){
        if ((flag && ttl>1) || !flag){
            node_next = current->next;
            if(node_prev !=NULL){
                current->next = node_prev;
            }
            node_prev = current;
            current = node_next;
            ttl--;
        }
        else{
            break;
        }
    }
    head->next = current->next;
    current->next = node_prev;
    return current;
}

void sort(Node* head){      //IMPLEMENTS BUBBLE SORT
    if (head == NULL){
        return;
    }
    Node* current;
    int temp;
    int swapped = 1;
    do{
        current = head;
        swapped = 0;
        while(current->next != NULL){
            if(current->value>current->next->value){
                temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                swapped = 1;
            }
            current = current->next;
        }
    }while(swapped);
    return;
}

void drop_duplicates(Node* head, int max_duplicates){
    int flag = (max_duplicates > 0);
    Node* current = head;
    Node* node_prev;
    int duplicate_counter;
    while(current!= NULL && current->next != NULL){
        duplicate_counter = max_duplicates;
        node_prev = current;
        Node* node_next = current->next;
        while(node_next != NULL){
            if(current->value == node_next->value){
                if((flag && duplicate_counter==0) || !flag){
                    node_prev->next = node_next->next;
                    free(node_next);
                }
                else{
                    node_prev = node_next;
                    duplicate_counter--;
                }
                node_next = node_prev->next;
            }
            else{
                node_prev = node_next;
                node_next = node_next->next;
            }
        }
        current = current->next;
    }
    return;
}

void delete(Node* head){
    Node* current = head;
    while(head != NULL){
        current = head;
        head=head->next;
        free(current);
    }
    return;
}

Node* insert_after(Node* head, int target, int new_value){
    Node* new_node = (Node*)calloc(1, sizeof(Node));
    Node* current = head;
    Node* temp;
    new_node->value = new_value;
    int inserted = 0;
    while(current != NULL){
        if(current->value == target){
            temp = current->next;
            current->next = new_node;
            new_node->next = temp;
            inserted = 1;
            break;
        }
        current = current->next;
    }
    if (!inserted){
        printf("Value %d was not inserted : expected predecessor %d not found\n", new_value, target);
        free(new_node);
    }
    return head;
}
