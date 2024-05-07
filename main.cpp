#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

#include <cstdlib> // Para usar a função rand()
#include <ctime> // Para usar a função time()

typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

Node* createNode(int);
void insertEnd(Node**, int);
void displayList(Node*);

void swapPayload(Node*, Node*);
void bubbleSort(Node*);
void optimizedBubbleSort(Node*);

void selectionSort(Node*);
void optimizedSelectionSort(Node*);

int main()
{
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios

    Node* head = nullptr;
    Node* head2 = nullptr;
    Node* head3 = nullptr;
    Node* head4 = nullptr;
    
    for(int i = 0; i < 100; i++)
    {
        int payload = rand() % 100; // Gera um número aleatório entre 0 e 99
        insertEnd(&head, payload);
        insertEnd(&head2, payload);
        insertEnd(&head3, payload);
        insertEnd(&head4, payload);
    }
    
    cout << "Lista Original:" << endl;
    displayList(head);
    
    cout << "============================================================" << endl;
    
    cout << "\n### BubbleSort ###\n";
    
    // Cálculo de tempo de duração da função:
    auto timeStart = high_resolution_clock::now();
    bubbleSort(head);
    auto timeEnd = high_resolution_clock::now();
    
    displayList(head);
    
    auto timeDuration = duration_cast<nanoseconds>(timeEnd - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos" << endl;
    cout << "------------------------------" << endl;
    
    cout << "\n### BubbleSort Otimizado ###\n";
    
    // Cálculo de tempo de duração da função:
    auto timeStart2 = high_resolution_clock::now();
    optimizedBubbleSort(head2);
    auto timeEnd2 = high_resolution_clock::now();
    
    displayList(head2);
    
    auto timeDuration2 = duration_cast<nanoseconds>(timeEnd2 - timeStart2);
    cout << "Tempo utilizado: " << timeDuration2.count() << " nanosegundos" << endl;
    
    cout << "============================================================" << endl;
    
    cout << "\n### SelectionSort ###\n";
    
    // Cálculo de tempo de duração da função:
    auto timeStart3 = high_resolution_clock::now();
    selectionSort(head3);
    auto timeEnd3 = high_resolution_clock::now();
    
    displayList(head3);
    
    auto timeDuration3 = duration_cast<nanoseconds>(timeEnd3 - timeStart3);
    cout << "Tempo utilizado: " << timeDuration3.count() << " nanosegundos" << endl;
    cout << "------------------------------" << endl;
    
    cout << "\n### SelectionSort Otimizado ###\n";
    
    // Cálculo de tempo de duração da função:
    auto timeStart4 = high_resolution_clock::now();
    optimizedSelectionSort(head4);
    auto timeEnd4 = high_resolution_clock::now();
    
    displayList(head4);
    
    auto timeDuration4 = duration_cast<nanoseconds>(timeEnd4 - timeStart4);
    cout << "Tempo utilizado: " << timeDuration4.count() << " nanosegundos" << endl;
    
    return 0;
}

void swapPayload(Node* node1, Node* node2)
{
    int iTemp = node1->iPayload;
    node1->iPayload = node2->iPayload;
    node2->iPayload = iTemp;
}

void bubbleSort(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar bubbleSort" << endl;
        return;
    }
    
    if (node -> ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar bubbleSort" << endl;
        return;
    }
    
    Node* outerLoop = node;
    
    while(outerLoop != nullptr && outerLoop->ptrNext != nullptr)
    {
        Node* current = node;
        while(current != nullptr && current->ptrNext != nullptr)
        {
            if(current->iPayload > current->ptrNext->iPayload)
            {
                swapPayload(current, current->ptrNext);
            }
            current = current->ptrNext;
        }
        outerLoop = outerLoop->ptrNext;
    }
}


void optimizedBubbleSort(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar bubbleSort" << endl;
        return;
    }
    
    if (node -> ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar bubbleSort" << endl;
        return;
    }
    
    bool notOrdered;
    do
    {
        notOrdered = false;
        Node* current = node;
        while(current->ptrNext != nullptr)
        {
            if(current->iPayload > current->ptrNext->iPayload)
            {
                swapPayload(current, current->ptrNext);
                notOrdered = true;
            }
            current = current->ptrNext;
        }
    } while(notOrdered);
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
        return; //Usa return pra sair da função, o resto do código não será executado
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
  //newNode -> ptrNext = nullptr;
  
  if (*head == nullptr)
  {
      //newNode -> ptrNext = nullptr; Essa linha não é obrigatória pois já definimos anteriormente
      (*head) = newNode;
      return;
      
  }
  
  Node* temp = (*head);
  
  //Percorremos a lista até seu fim(ptrNext do ultimo nó é NULL)
  while(temp->ptrNext != nullptr) temp = temp->ptrNext;
  
  newNode->ptrPrev = temp; //newNode aponta para o fim da lista
  temp->ptrNext = newNode; //Antigo último elemento aponta para o novo nó
}

void selectionSort(Node* head)
{
    if (head == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar SelectionSort" << endl;
        return;
    }
    
    if (head->ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar SelectionSort" << endl;
        return;
    }
    
    Node* ptrOuter = head;
    Node* ptrInner = nullptr;

    while(ptrOuter != nullptr && ptrOuter->ptrNext != nullptr)
    {
        ptrInner = ptrOuter->ptrNext;
        
        while (ptrInner != nullptr)
        {
            if (ptrInner->iPayload < ptrOuter->iPayload)
            {
                swapPayload(ptrInner, ptrOuter);
            }
            ptrInner = ptrInner->ptrNext;
        }
        
        ptrOuter = ptrOuter->ptrNext;
    }
}

void optimizedSelectionSort(Node* head)
{
    if (head == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar SelectionSort" << endl;
        return;
    }
    
    if (head->ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar SelectionSort" << endl;
        return;
    }
    
    Node* ptrOuter = head;
    Node* ptrInner = nullptr;

    while(ptrOuter != nullptr && ptrOuter->ptrNext != nullptr)
    {
        ptrInner = ptrOuter->ptrNext;
        
        Node* ptrMinPayload = ptrOuter;
        
        while (ptrInner != nullptr)
        {
            if (ptrInner->iPayload < ptrMinPayload->iPayload)
            {
                ptrMinPayload = ptrInner;
            }
            ptrInner = ptrInner->ptrNext;
        }
        
        if (ptrMinPayload != ptrOuter)
        {
            swapPayload(ptrMinPayload, ptrOuter);
        }
        
        ptrOuter = ptrOuter->ptrNext;
    }
}