## An implementation in C

This is a personal project undertaken to implement **linked lists** in **C**, a commonly encountered data structure in the courseware for CS1101 in BS programs (DSA/ES) at IIT Madras.    

#### List Structure

<img src="https://mermaid.ink/svg/pako:eNp10MFqwzAMBuBXEeqlA_ewGgrzYdCkvWU7bOw07-DFShPmOMWxx0rXd5_qllIK08n8-iyB9lgPllDhJphtC9WL9sC1fNfYkrHwC9Nv4xLdC_D0E-80fsBs9ggFA88_5xcxvxHlWciLkAKe36rqKE5bamfGcUUN8PIdNJ1zarLOJcYYhi9SEynljf3kSWe7KB4WpfzHwjLT66TIi66TMicosKfQm87yIfbHvsbYUk8aFT89pRiM06j9galJcXjd-RpVDIkEpq01kVad4VE9qsa4kVOyXRzC0-m4-caHPw4NchU" width=50%></img>

The above list structure is implemented using **Nodes**. A node holds a value and a pointer to the next node.\n
A node is implemented using a struct with members *value* and *next*. 

The head of a list is marked in blue. <span style="background-color: #6B96C3">‎ ‎ ‎ ‎ ‎ </span>

Deleted nodes are marked in red. <span style="background-color: #FF3333">‎ ‎ ‎ ‎ ‎ </span>

#### The Node Type

```
typedef struct node{
    int value;
    struct node* next;
} Node;
```
The first node in a list is the head. In this project, all nodes reside in the heap.\n
The first node (head) can be created as follows.
```
Node* head = (Node*)calloc(1,sizeof(Node));
```
or
```
Node* head;
```
The former places the head node in the heap with a default value of 0. Deleting the node in this case would require freeing the memory \n
allocated to it.
```
free(head);
```

#### Examples

##### 1

**Getting started**
```
#include <stdio.h>
#include <stdlib.h>
#include "sllist.h"

int main(void){
    Node* head = (Node*)calloc(1,sizeof(Node));
    head->value = 11;
    display(head);
    return 0;
}
```
**output**
```
[0]:11 -> NULL
```
<img src="https://mermaid.ink/svg/pako:eNpNjzEPgjAQhf_K5Vw06SBpQmI3lBEdNE7WocIhxNKS0g4G-e9WWLzp5d6XvPdGLG1FKPDpVN9AcZYG4mU3iVv4wDpJGJyuRbGReF-sUqthyKmGhw4Edau1WKX7XXrgbPDOvkisOOd_LGQzigw7cp1qq5g2_nyJvqGOJIooDQXvlJYozRRRFby9vE2JwrtADENfKU95q2LPDkWt9BC_VLXeuuOyYB4yfQGuvkHB" width=10%></img>

##### 2

**Appending some nodes to a list**

The **append** function has a return type of **Node\***. This is because an empty list can be represented by a NULL pointer too, in which \n case the function creates a new node with the given value and returns a pointer to the newly created node. This operation potentially \n changes the head node. Therefore, the head pointer is reassigned when the append function is called.

```
Node* head = (Node*)calloc(1,sizeof(Node));
head->value = 11;
for (int i = 0;i<10;i++){
    head = append(head,i*i);
}
display(head);
```
**output**
```
[0]:11 -> [1]:0 -> [2]:1 -> [3]:4 -> [4]:9 -> [5]:16 -> [6]:25 -> [7]:36 -> [8]:49 -> [9]:64 -> [10]:81 -> NULL
```
<img src = "https://mermaid.ink/svg/pako:eNp10T1PwzAQBuC_crouIF2lOE6cj4EBylYYQEyYwTQujchHlThDVfrfObsQVUh4ih6_Ot_ljrjpK4slfgxmv4P1k-6AT_SqMYIvuBKCQFxrfIPl8gYEs_AcEchZY9Y4hC9VskqvCUE6a8KaeC0uNWVNQwVFoGZWzMpznBJkM2fMmWfJ6XzmnDkPD3LtYuaCufCsuBER_brwI4owY859P76s1_7qPP6mMeO4slvgv3KAbd005eI-HBrd0H_aciGl_JN9byb7k1W3hbqT_2RBUEySEkpJUUY5FcR9-JcuQ1Goh4StHVpTV7yio7_X6Ha2tRpL_uzs5AbTaNTdiaNmcv3zodtg6YbJEk77yji7qg0Xb7HcmmZktVXt-uHhvPaw_dM3ONSJTQ" width = 100%></img>


##### 3

**Dropping duplicates from a list**

The **drop duplicates** function has a second parameter, *max_duplicates* which specifies the number of extra copies of a value to retain. \n If this value is 0, then each distinct value is retained only once and all copies are dropped.

```
Node* head = (Node*)calloc(1,sizeof(Node));
head->value = 11;
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
[0]:11 -> [1]:5 -> [2]:5 -> [3]:7 -> [4]:7 -> [5]:3 -> [6]:5 -> [7]:4 -> [8]:1 -> [9]:8 -> [10]:2 -> NULL
[0]:11 -> [1]:5 -> [2]:7 -> [3]:3 -> [4]:4 -> [5]:1 -> [6]:8 -> [7]:2 -> NULL
```
<img src="https://mermaid.ink/svg/pako:eNp9kstOwzAQRX9l5G5AmkpxnPeCBZSuCgsQEhJhYRqXRuRROc6iavvvjOO2iiKBV55zrzxzrTmwdVsolrFvLXdbWL3kDdDxPnLmwRFuOEfgtzn7hPn8DjhhbnGIIC70-H4EnwR_KoAgKiyNEcKxPSAhmAoQEg0tFQjx2B6REJ1fvwoQE40tDRCSK02IJsPkCOmVpkRTSxOK410wtzH5kNNHeH5brazifoC7BK4Qbj5XhK67K9aV7LqF2gD93x42ZVVls8fhYGd0-6OymRBi4v2qenX2Rvdp9CD-8WpVnK3LJal_WYGjwBBjTDBFimTHGcs-BhjZx8bQGyZhyGqla1kWtAYHq-fMbFWtcpbRtVG90bLKWd6cyCp7077umzXLjO4Vsn5XSKMWpaSONcs2suqIqqI0rX5yqzVs2OkXkcmlVQ" width = 100%></img>

**output 2** \(max_duplicates = 1\)
```
[0]:11 -> [1]:5 -> [2]:5 -> [3]:7 -> [4]:7 -> [5]:3 -> [6]:5 -> [7]:4 -> [8]:1 -> [9]:8 -> [10]:2 -> NULL
[0]:11 -> [1]:5 -> [2]:5 -> [3]:7 -> [4]:7 -> [5]:3 -> [6]:4 -> [7]:1 -> [8]:8 -> [9]:2 -> NULL
```
<img src="https://mermaid.ink/svg/pako:eNp90j1PwzAQBuC_cnIXkK5SHOd7YIDSqTCAkJBqBtO4NCIfleMMVdv_zjlJowoJPCXPvbLvEh_Zpsk1y9iXUfsdrF5kDbS8tWQenOCGcwR-K9kHzOd3wIm54xDBn9Qn9UcVkwpS4TRGCCYNSINRw0lD0tCpQIgveno_QUSFaNx6KkBMGjsNEJJJE9Kk7xkhnTQlTZ0mNIh3Ye4G5P2EPsLz22rlKsPs4XDG8LIpVdsu9Bbo-xxgW5RlNnvsF7bWNN86mwkhfmU_y06P2eg-jR7EP1mj8zG6XFL1ryhwFBhihDEmmCK17hq6DkRuq2vw-j4YskqbShU5_eSjq0tmd7rSkmX0WOvOGlVKJuszRVVnm9dDvWGZNZ1G1u1zZfWiUHRaxbKtKltSnRe2MU_Dxenvz_kH112dRw" width=100%></img>

##### 4

**Reversing a list**

The **reverse** function has a second parameter, *ttl* which specifies the length of the initial n-node segment of the list to reverse. \n If this value is 0, then the entire list is reversed.

```
Node* head = (Node*)calloc(1,sizeof(Node));
head->value = 11;
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
[0]:11 -> [1]:5 -> [2]:7 -> [3]:3 -> [4]:9 -> [5]:4 -> [6]:1 -> [7]:8 -> [8]:2 -> NULL
[0]:2 -> [1]:8 -> [2]:1 -> [3]:4 -> [4]:9 -> [5]:3 -> [6]:7 -> [7]:5 -> [8]:11 -> NULL
```
<img src="https://mermaid.ink/svg/pako:eNp90rtOwzAUgOFXOXIXkE6lOI6dNAMDlE6FAYSE1DCYxqURuVS5DFXbd-fY7mAhgaf8-Y4SJ_KJbbvSsJx99fqwh_VL0QKtaFOwCM5wwznC89t6fVuwD5jP787vZ-CE3KJEiEKICWILKQIPQRAICwIhDiEhSCwsEEQIkkBaSBCSEBSBcjtDkCGkBKmFDEGFkBFkFmKE1IL_xMw6pD5SF8qHciF9SBeJj8SF8CFcxD5iF9wHdxH52NZ6GJZmB_SHj7Cr6jqfPbqFw9h33yafCSF-zX7Wk7nOqvuFehD_zPamvI6uVqR_jUKEHGMUmKBEhanbT-iZeytD1pi-0VVJh-JkvWDj3jSmYDldtmYae10XrGgvNKqnsXs9tluWj_1kkE2HUo9mWWl6eMPyna4HumvKauz6J3_Q3Hm7_ABX5KkL" width=80%></img>

**output 2** \(ttl = 5\)
```
[0]:11 -> [1]:5 -> [2]:7 -> [3]:3 -> [4]:9 -> [5]:4 -> [6]:1 -> [7]:8 -> [8]:2 -> NULL
[0]:9 -> [1]:3 -> [2]:7 -> [3]:5 -> [4]:11 -> [5]:4 -> [6]:1 -> [7]:8 -> [8]:2 -> NULL
```
<img src="https://mermaid.ink/svg/pako:eNp90rtOwzAUBuBXOXIXkE6lOM6tGRigdCoMICQkzGASl0bkUjnOULV9d46dUkVI4Cn__x0lTuIDK7pSs5x9GrXbwvpJtkAreJMsgCNccY4QX0v2DvP5zfH1CJyEO4kRgimEBKGDFIFPQRAIBwIhnEJEEDlYIIgpxASxgwgh-QFIqE38nhDSS5tSm7o2Q8gubUZt5toQ4fFlvXZwfjPv8RgiH8QYhA_hGEIf-Bi4D8EYilr1_VJvgL7YHjZVXeeze7-wt6b70vlMCPFr9qMe9Hk2uV0kd-KfWaPL8-hqRfrXKATIMUSBMSaYYub3M_XIP5Uha7RpVFXSTz44l8xudaMly-my1YM1qpZMticaVYPtnvdtwXJrBo1s2JXK6mWl6OYNyzeq7qnVZWU78zAeHH9-Tt8jyp1u" width=80%></img>

##### 5

**Sorting a list**

The **sort** function sorts a list in ascending order of values.

```
Node* head = (Node*)calloc(1,sizeof(Node));
head->value = 11;
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
[0]:11 -> [1]:5 -> [2]:7 -> [3]:3 -> [4]:9 -> [5]:4 -> [6]:1 -> [7]:8 -> [8]:2 -> NULL
[0]:1 -> [1]:2 -> [2]:3 -> [3]:4 -> [4]:5 -> [5]:7 -> [6]:8 -> [7]:9 -> [8]:11 -> NULL
```
<img src="https://mermaid.ink/svg/pako:eNp1kT1PwzAQhv_KyV1AukpxnNglAwOUrTCAkJAwg0lcGpGPKnGGqu1_52wDipDwlOd9Xvnk3JGVfWVZwT4Gs9_B5lF3QCd51SyBE1xwjvDwvNlcavYGy-X16eUEnCT3MkdIfwSklKY-VQhyXhckhBcCIfutZ5RmPs0Q-Lyek8jDaAQ1F5KE9GKFkMyFIqG8SBGEF_ENeZijIqgAIkIWgEdIA8gIMkASoWzMOK7tFujfHGBbN02xuAsHRzf0n7ZYCCH-dN-byX535c2VvBX_dCFBjikKzFCiwlUYMvd5uIoha-3QmrqiHR2918ztbGs1K-izs5MbTKOZ7s5UNZPrnw5dyQo3TBbZtK-Ms-va0OUtK7amGSm1Ve364T7uPaz__AW0yYu7" width=80%><img>

There are a total of 16 functions in this project. To explore them go to **File** \> **File members** \>  **Functions**.

---