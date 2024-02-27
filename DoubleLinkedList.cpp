#include <iostream>

struct node
{
    int data;
    node* next;
    node* pre;
};

node* makeNode(int x){
    node* newNode = new node;
    newNode -> data = x;
    newNode -> next = NULL;
    newNode -> pre = NULL;
    return newNode;
}

void duyet(node* head){
    while (head != NULL)
    {
        std:: cout << head -> data << " ";
        head = head -> next;
    }
    std:: cout << "\n";
}

void pushFront(node* &head, int x){
    node* newNode = makeNode(x);
    newNode -> next = head;
    if (head != NULL) head -> pre = newNode;
    head = newNode;
}

void pushBack(node* &head, int x){
    node* newNode = makeNode(x);
    node* tmp = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (tmp -> next != NULL)
    {
        tmp = tmp -> next;
    }
    tmp -> next = newNode;
    newNode -> pre = tmp;
}

int sz(node* head){
    int count = 0;
    node* tmp = head;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp -> next;
    }
    return count;
}

void insert(node* &head, int x, int index){
    int n = sz(head);
    if (index < 0 || index > n) return;
    node* newNode = makeNode(x);
    node* tmp = head;
    for (int i = 0; i < index; i++)
    {
        tmp = tmp -> next;
    }
    node* tmp1 = tmp -> next;
    tmp -> next = newNode;
    newNode -> pre = tmp;
    newNode -> next = tmp1;
    tmp1 -> pre = newNode;
}

int main(){
    node* head = NULL;
    int a[] = {1, 4, 3, 2};
    for (int i = 0; i < 4; i++)
    {
        pushBack(head, a[i]);
    }
    duyet(head);
    std:: cout << "\n";
    insert(head, 10, 1);
    duyet(head);
    return 0;
}