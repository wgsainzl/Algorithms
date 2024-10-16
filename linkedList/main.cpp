#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void addNode(Node* &head, int value) {
    Node* newNode = new Node(); // crear nuevo nodo en memoria
    newNode->data = value; // asignación de value a la estructura accediendo a data
    newNode->next = nullptr; // el siguiente nodo es nullptr

    if(head == nullptr) {
        head = newNode; // si la lista está vacía el nuevo nodo es la head
    }else {
        Node* temp = head; // crear una variable temporal que almacene el current head
        // recorremos la lista hasta el último nodo
        while(temp->next != nullptr) {
            temp=temp->next;
        }
        temp->next = newNode; // enlazamos
    }
}

void printList(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int main()
{
    Node* list = nullptr;
    addNode(list, 40);
    addNode(list, 50);

    cout<<"The list is: ";
    printList(list);

    return 0;
}
