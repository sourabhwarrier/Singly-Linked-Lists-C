/**
 * Header File
 * @file sllist.h
 * @author Sourabh Warrier
 * @date Saturday December 16th, 2023
*/

#ifndef sllist

/**
 * Type Node stores a value and a pointer to the next node in the list.
 * The node whose next pointer is NULL marks the end of the list.
*/
typedef struct node{
    int value; /**< Value stored in the node*/
    struct node* next; /**< Pointer to the next node*/
} Node;

void display(Node* head);
int length(Node* head);
int present(Node* head, int target);
int count(Node* head, int target);
void replace(Node* head, int target, int new_value, int ttl);
Node* attach(Node* head, int new_value);
Node* append(Node* head, int new_value);
Node* drop_head(Node* head);
Node* drop_tail(Node* head);
Node* drop_match(Node* head, int target, int ttl);
Node* join(Node* head1, Node* head2);
Node* reverse(Node* head, int ttl);
void sort(Node* head);
void drop_duplicates(Node* head, int max_duplicates);
Node * insert_after(Node* head, int target, int new_value);
void del(Node* head);

#define sllist
#endif