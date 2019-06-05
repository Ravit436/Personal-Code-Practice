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

int findLength(struct Node *curr){
    if(curr == NULL){
        return 0;
    }
    return findLength(curr->next) + 1;
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

    int length = findLength(head);
    cout<<"Length "<<length<<endl;
}