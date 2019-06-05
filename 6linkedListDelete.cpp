#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void insertNode(struct Node **curr, int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    if((*curr) != NULL){
        (*curr)->next = node;
    }
    (*curr) = node;
}

void deleteNode(struct Node **head, int pos){
    struct Node *curr = *head, *prev = NULL; 
    for(int i = 0; i < pos; i++){
        prev = curr;
        curr = curr->next;
    }
    if(pos == 0){
        (*head) = (*head)->next;
        free(curr);
    }
    else{
        prev->next = curr->next;
        free(curr);
    }
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
    cout<<"Delete At "<<endl;
    cin>>n;
    for(int i = 0; i < n ; i++){
        cin>>pos;
        deleteNode(&head, pos);
    }

    curr = head;
    while(curr != NULL){
        cout<<curr->data<<endl;
        curr = curr->next;
    }
}