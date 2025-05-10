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

// Андрей 1:
void InsertAfter(Node** head, int i, int data, const string& inf) {
    int count = CountNode(*head);
    if (i<0) {
        cout << "Uncorrect number" <<endl;
        return;
    }
    if (i > count) {
        AddEnd(head, data, inf);
        return;
    }

    Node* NewNode = new Node;
    NewNode->data = data;
    NewNode->inf = inf;

    Node * temp = (*head)->next;
    for (int i = 0; i < count; i++ ) {
        temp -> next;
    }
    NewNode->next = temp->next;
    temp->next = NewNode;
    NewNode->prev = temp;
    temp->next->prev = NewNode;
}


// Егор 6:
void include_instead_the_key (Node **head, unsigned int new_data, const string new_inf) {
    Node *current = (*head)->next;
    // unsigned int new_data;
    while (current != *head) {
        if (current->data == new_data) {
            // cin >> new_inf >> new_data;
            auto *new_node = new Node{new_data, new_inf, current->next, current->prev};
            current->prev->next = new_node;
            current->next->prev = new_node;
            delete current;
            return;
        }
        current = current->next;
    }
}

// Соня:
void InsertBefore(Node** head, int i, int data, const string& inf) {
    if (i <= 0 || !*head) {
        AddStart(head, data, inf);
        return;
    }
    int count = CountNode(*head);
    if (i >= count) {
        AddEnd(head, data, inf);
        return;
    }
    Node* current = *head;
    for (int pos = 0; pos < i; pos++) {
        current = current->next;
    }
    Node* NewNode = new Node;
    NewNode->data = data;
    NewNode->inf = inf;
    NewNode->next = current;
    NewNode->prev = current->prev;

    current->prev->next = NewNode;
    current->prev = NewNode;


    if (current == *head && i == 0) {
        *head = NewNode;
    }
}


int  main() {

    Node *head = CreatHead();
    AddStart(&head, 2, "First");
    AddEnd(&head, 15, "Second");
    AddEnd(&head, 1412, "Third");
    PrintNode(head);
    cout << CountNode(head) << endl;
    // DeleteStart(&head);
    // DeleteEnd(&head);
    // PrintNode(head);
    // cout << CountNode(head) << endl;
    // DeleteAll(&head);
    include_instead_the_key(&head, 1, "adfasd");
    PrintNode(head);

    return 0;
}


