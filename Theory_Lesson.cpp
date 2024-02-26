#include <iostream>

struct node
{
    int data;
    node* next;
};

node* makeNode(int x){
    node* newNode = new node;
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}

node* findX(node* head, int x){
    node* tmp = head;
    //if (head == NULL) return NULL; // we dont need this line because this was already checked
    while (tmp != NULL && tmp -> data <= x)
    {
        if (tmp -> data == x) return tmp;
        tmp = tmp -> next;  
    }
    return NULL;
}

node* findXFixed(node* head, int x){
    node* tmp = head;
    //if (head == NULL) return NULL; // we dont need this line because this was already checked
    while (tmp != NULL && tmp -> data < x)
    {
        tmp = tmp -> next;  
    }
    if (tmp && tmp -> data == x) return tmp;    // check if tmp is a null to avoid accessing to null data
    return NULL;
}

int main(){
    node* head = NULL;
    return 0;
}