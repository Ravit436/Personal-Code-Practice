#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *insertEnd(int value){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void insertStart(struct Node **head, int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    node->data = value;
    node->next = temp;
    (*head) = node; 
}

void insertAtIth(struct Node **head, int value, int pos){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* curr = *head, *prev = NULL;
    for(int i = 0; i < pos; i++){
        prev = curr;
        curr = curr->next;
    }
    node->data = value;
    if(pos != 0){
        node->next = prev->next;
        prev->next = node;
    }
    else{
        node->next = curr;
        (*head) = node;
    }
}

int main(){
    int n, value, pos;
    cin>>n;
    struct Node *head = NULL, *curr = NULL, *newNode = NULL;
    for(int i = 0; i < n; i++){
        cin>>value;
        if(i % 2 == 0){
            newNode = insertEnd(value);
            if(curr == NULL){
                head = curr = newNode;
            }
            else{
                curr->next = newNode;
                curr = newNode;
            }
        }
        else{
            insertStart(&head, value);
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin>>pos>>value;
        insertAtIth(&head, value, pos);
    }

    curr = head;
    while(curr != NULL){
        cout<<curr->data<<endl;
        curr = curr->next;
    }
}