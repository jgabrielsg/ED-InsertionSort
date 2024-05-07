#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

Node* createNode(int);
void insertEnd(Node**, int);
void displayList(Node*);
void swapValues(Node*, Node*);


int main()
{
    Node* head = nullptr;
    
    insertEnd(&head,0);
    insertEnd(&head,1);
    insertEnd(&head,3);
    insertEnd(&head,7);
    insertEnd(&head,10);
    insertEnd(&head,13);
    
    displayList(head);
    cout << "==============" << endl;
    
    return 0;
}

Node* createNode(int iPayload)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    
    return temp;
}


void displayList(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayList" << endl;
        return;
    }
    
    if  (node -> ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar displayList" << endl;
        return;
       
    }
    
    Node* temp = node;
     
    cout << "Payload: ";
    
    while(temp != nullptr)
    {
        cout << temp->iPayload<< " ";
        temp = temp->ptrNext;
    }
    
    cout << endl;
}

void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    
    if (*head == nullptr)
    {
        (*head) = newNode;
        return;
    }
    
    Node* temp = (*head);
    
    while(temp->ptrNext != nullptr) temp = temp->ptrNext;
    
    newNode->ptrPrev = temp;
    temp->ptrNext = newNode; 
}

void swapValues(Node* node1, Node* node2) 
{
    int temp = node1->iPayload;
    node1->iPayload = node2->iPayload;
    node2->iPayload = temp;
}