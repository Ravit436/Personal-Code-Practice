#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *link;
};

void insertNode(struct Node **curr, int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->link = NULL;
    if((*curr) != NULL){
        (*curr)->link = node;
    }
    (*curr) = node;
}

void reverseList(struct Node **head){
    struct Node *curr = *head, *prev = NULL;
    struct Node *next = curr->link;
    while(next != NULL){
        curr->link = prev;
        prev = curr;
        curr = next;
        next = next->link;
    }
    curr->link = prev;
    (*head) = curr;
}

void reverseListRecur(struct Node **head, struct Node *curr, struct Node *prev){
    if(curr->link == NULL){
        (*head) = curr;
        return;
    }
    prev = curr;
    curr = curr->link;
    reverseListRecur(&(*head), curr, prev);
    curr->link = prev;
    prev->link = NULL;
    return;
}

int main(){
    int n, pos, val;
    cin>>n;
    struct Node *head = NULL, *curr = NULL;
    for(int i = 0; i < n; i++){
        cin>>val;
        insertNode(&curr, val);
        if(head == NULL){
            head = curr;
        }
    }

    reverseList(&head);

    curr = head;
    while(curr != NULL){
        cout<<curr->data<<endl;
        curr = curr->link;
    }

    reverseListRecur(&head, head, NULL);

    curr = head;
    while(curr != NULL){
        cout<<curr->data<<endl;
        curr = curr->link;
    }
}