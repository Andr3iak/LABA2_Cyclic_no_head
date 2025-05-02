#include <iostream>
#include <string>

using namespace std;
//7.	Динамические структуры данных.
//      Работа с симметричным циклическим списком без головного элемента.

// 1. 	 Создание пустого списка.
// 2. 	 Подсчет количества элементов списка.
// 3. 	 Вывод на экран содержимого списка.
// 4. 	 Вставка элемента в начало или в конец списка (оба варианта).
// 5. 	 Исключение элемента из начала или конца списка (оба варианта).
// 6. 	 Уничтожение списка с освобождением памяти.



struct Node{
    unsigned int data;
    string inf;
    Node* next;
    Node* prev;
};

Node* CreatHead() {
    return nullptr;
};

void AddStart(Node** head, int data, const string &inf) {
    Node* NewNode = new Node(data, inf, nullptr, nullptr);
    if (!*head) {
        NewNode->next = NewNode->prev = NewNode;
        *head = NewNode;
    }
    else {
        Node* temp = (*head)->prev;
        NewNode -> next = *head;
        temp -> next = NewNode;
        (*head)->prev = NewNode;
        NewNode -> prev = temp;
        *head = NewNode;
    }
}

void AddEnd(Node** head, int data, const string &inf) {
    Node* NewNode = new Node(data, inf, nullptr, nullptr);
    if (!*head) {
        NewNode -> next = NewNode->prev = NewNode;
    }
    else {
        NewNode -> next = *head;
        Node* temp = (*head)->prev;
        NewNode -> prev = temp;
        temp -> next = NewNode;
        (*head)->prev = NewNode;
    }
}

void DeleteStart(Node** head) {
    if (!*head) {
        return;
    }
    if ((*head) -> next == *head) {
        delete (*head);
        *head = nullptr;
        return;
    }
    Node* temp= (*head);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    *head = temp->next;
    delete temp;
}

void DeleteEnd(Node** head) {
    if (!*head) {
        return;
    }
    if ((*head)-> next == *head) {
        delete (*head);
        *head = nullptr;
        return;
    }
    Node* temp = (*head)->prev;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void DeleteAll(Node** head) {
    if (!*head) {
        return;
    }
    if ((*head) -> next == *head) {
        delete (*head);
        *head = nullptr;
        return;
    }
    Node* current = (*head)->next;
    while (current != *head) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete (*head);
    *head = nullptr;
}

int CountNode(Node* head) {
    if (!head) {
        return 0;
    }
    int count = 1;
    Node* temp = head->next;
    while (temp!=head) {
        count++;
        temp = temp->next;
    }
    return count;
}

void PrintNode(Node *head) {
    if (!head) {
        return;
    }
    Node* temp = head;
    cout << "HEAD <-> ";
    do {
        cout << "K: " << temp->data << "; Inf: " << temp->inf << " <-> ";
        temp = temp->next;
    }
    while (temp != head);
    cout << "HEAD\n";
}





int main() {

    Node *head = CreatHead();
    AddStart(&head, 2, "First");
    AddStart(&head, 15, "Second");
    AddStart(&head, 1412, "Third");
    PrintNode(head);
    cout << CountNode(head) << endl;
    // DeleteStart(&head);
    DeleteEnd(&head);
    PrintNode(head);
    cout << CountNode(head) << endl;
    DeleteAll(&head);
    PrintNode(head);

    return 0;
}


