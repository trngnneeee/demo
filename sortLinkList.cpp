#include <iostream>
#include <string.h>

struct sinhvien
{
    std:: string name;
    double gpa;
    sinhvien(){};
    sinhvien(std:: string ten, double diem)
    {
        name = ten;
        gpa = diem;
    }
};

struct node
{
    sinhvien data;
    node* next;
};

node* makeNode(sinhvien s){
    node* newNode = new node;
    newNode -> data = s;
    newNode -> next = NULL;
    return newNode;
}

void pushBack(node* &head, sinhvien s){
    node* newNode = makeNode(s);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    node* tmp = head;
    while (tmp -> next != NULL)
    {
        tmp = tmp -> next;
    }
    tmp -> next = newNode;
}

void duyet(node* head){
    node* tmp = head;
    while (tmp != NULL)
    {
        std:: cout << tmp -> data.name << " " << tmp -> data.gpa << "\n";
        tmp = tmp -> next;
    }
}

void sortGPA(node* head){
    for (node* i = head; i != NULL; i = i -> next)
    {
        node* minNode = i;
        for (node* j = i -> next; j != NULL; j = j -> next)
        {
            if (j -> data.gpa < minNode -> data.gpa)
                minNode = j;
            else if (minNode -> data.gpa == j -> data.gpa)
            {
                if (minNode -> data.name > j -> data.name)
                minNode = j;
            }
        }
        sinhvien tmp = minNode -> data;
        minNode -> data = i -> data;
        i -> data = tmp;
    }
}

int main(){
    node* head = NULL;
    sinhvien a("Nguyen", 8.3);
    sinhvien b("Linh", 10);
    sinhvien c("Cuong", 9.5);
    sinhvien l("Long", 9.5);
    sinhvien h("Hai", 5.4);
    pushBack(head, a);
    pushBack(head, b);
    pushBack(head, c);
    pushBack(head, l);
    pushBack(head, h);
    duyet(head);
    std:: cout << "\n";
    sortGPA(head);
    duyet(head);
    return 0;
}