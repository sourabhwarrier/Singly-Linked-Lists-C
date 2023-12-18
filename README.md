## Linked List Library in C 

This is a personal project undertaken to implement **linked lists** in **C**, a commonly encountered data structure in the courseware for CS1101 in BS programs (DSA/ES) at IIT Madras.    

#### List Structure

[![](https://mermaid.ink/img/pako:eNp1kD0LwkAMhv9KiItCXex2g-DXVh0UJ88h9FJbvF7L9SqK-t-N1aEgZgpvnuRNcse0MowKT57qHJKtdiAxO2jMmQw8YHgh23IEjq9hpPEI4_EU5lJ30jj5Byy-QNwDNvskeQMfi9RS0yw5A3G-QVZYqwarLqIm-OrMahDHcY-FWYf2lfmPsvgqGGHJvqTCyG33N6Ex5FyyRiWp4zZ4shq1ewpKbah2N5eiCl42xbY2FHhZkAwrUWVkG1HZFKHy68-_urc9XzJIZOI?type=png)](https://mermaid.live/edit#pako:eNp1kD0LwkAMhv9KiItCXex2g-DXVh0UJ88h9FJbvF7L9SqK-t-N1aEgZgpvnuRNcse0MowKT57qHJKtdiAxO2jMmQw8YHgh23IEjq9hpPEI4_EU5lJ30jj5Byy-QNwDNvskeQMfi9RS0yw5A3G-QVZYqwarLqIm-OrMahDHcY-FWYf2lfmPsvgqGGHJvqTCyG33N6Ex5FyyRiWp4zZ4shq1ewpKbah2N5eiCl42xbY2FHhZkAwrUWVkG1HZFKHy68-_urc9XzJIZOI)

The above list structure is implemented using **Nodes**. A node holds a value and a pointer to the next node.\n
A node is implemented using a struct with members *value* and *next*.

#### The Node Type

```
typedef struct node{
    int value;
    struct node* next;
} Node;
```
The first node in a list is the head node. In this project, nodes reside in the heap.\n
The first node (head) can be created as follows.
```
Node* head = (Node*)calloc(1,sizeof(Node));
```
or
```
Node* head;
```
Note that the former places the head node in the heap.

#### Examples

##### 1

**Getting started**
```
#include <stdio.h>
#include <stdlib.h>
#include "sllist.h"

int main(void){
    Node* head = (Node*)calloc(1,sizeof(Node));
    display(head);
    return 0;
}
```
**output**
```
[0]:0 -> NULL
```

##### 2

**Appending some nodes to a list**
```
for (int i = 0;i<10;i++){
    head = append(head,i*i);
}
display(head);
```
**output**
```
[0]:0 -> [1]:0 -> [2]:1 -> [3]:4 -> [4]:9 -> [5]:16 -> [6]:25 -> [7]:36 -> [8]:49 -> [9]:64 -> [10]:81 -> NULL
```
Note that the **append** function has a return type of **Node\***. This is because an empty list can be represented by a NULL pointer too, \n in which case the function creates a new node with the given value and return a pointer to the newly created node. This operation potentially \n changes the head node, hence the head pointer is reassigned when the append function is called.

##### 3

**Dropping duplicate from a list**
```
head = append(head,5);
head = append(head,5);
head = append(head,7);
head = append(head,7);
head = append(head,3);
head = append(head,5);
head = append(head,4);
head = append(head,1);
head = append(head,8);
head = append(head,2);

display(head);
drop_duplicates(head,0);
display(head);
```
**output 1** \(max_duplicates = 0\)
```
[0]:0 -> [1]:5 -> [2]:5 -> [3]:7 -> [4]:7 -> [5]:3 -> [6]:5 -> [7]:4 -> [8]:1 -> [9]:8 -> [10]:2 -> NULL
[0]:0 -> [1]:5 -> [2]:7 -> [3]:3 -> [4]:4 -> [5]:1 -> [6]:8 -> [7]:2 -> NULL
```
The **drop duplicates** function has a second parameter, *max_duplicates* which specifies the number of extra copies of a value to retain. \n If this value is 0, then all unique values are retained only once and all copies are dropped.

**output 2** \(max_duplicates = 1\)
```
[0]:0 -> [1]:5 -> [2]:5 -> [3]:7 -> [4]:7 -> [5]:3 -> [6]:5 -> [7]:4 -> [8]:1 -> [9]:8 -> [10]:2 -> NULL
[0]:0 -> [1]:5 -> [2]:5 -> [3]:7 -> [4]:7 -> [5]:3 -> [6]:4 -> [7]:1 -> [8]:8 -> [9]:2 -> NULL
```

##### 4

**Reversing a list**
```
head = append(head,5);
head = append(head,7);
head = append(head,3);
head = append(head,9);
head = append(head,4);
head = append(head,1);
head = append(head,8);
head = append(head,2);

display(head);
head = reverse(head,0);
display(head);
```
**output 1**  \(ttl = 0\)
```
[0]:0 -> [1]:5 -> [2]:7 -> [3]:3 -> [4]:9 -> [5]:4 -> [6]:1 -> [7]:8 -> [8]:2 -> NULL
[0]:2 -> [1]:8 -> [2]:1 -> [3]:4 -> [4]:9 -> [5]:3 -> [6]:7 -> [7]:5 -> [8]:0 -> NULL
```
The **reverse** function has a second parameter, *ttl* which specifies the length of the initial n-node segment of the list to reverse. If this value is 0, then the entire list is reversed.

**output 2** \(ttl = 5\)
```
[0]:0 -> [1]:5 -> [2]:7 -> [3]:3 -> [4]:9 -> [5]:4 -> [6]:1 -> [7]:8 -> [8]:2 -> NULL
[0]:9 -> [1]:3 -> [2]:7 -> [3]:5 -> [4]:0 -> [5]:4 -> [6]:1 -> [7]:8 -> [8]:2 -> NULL
```

##### 5

**Sorting a list**
```
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
```
**output**
```
[0]:0 -> [1]:5 -> [2]:7 -> [3]:3 -> [4]:9 -> [5]:4 -> [6]:1 -> [7]:8 -> [8]:2 -> NULL
[0]:0 -> [1]:1 -> [2]:2 -> [3]:3 -> [4]:4 -> [5]:5 -> [6]:7 -> [7]:8 -> [8]:9 -> NULL
```
---