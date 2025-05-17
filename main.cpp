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
    unsigned int key;
    string inf;
    Node* next;
    Node* prev;
};

Node* CreatHead() {
    return nullptr;
};

void AddStart(Node** head, int p_key, const string &p_inf) {
    Node* newNode = new Node;
    newNode->key = p_key;
    newNode->inf = p_inf;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (!*head) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        Node* last = (*head)->prev;

        newNode->next = *head;
        newNode->prev = last;

        last->next = newNode;
        (*head)->prev = newNode;

        *head = newNode;
    }
}

void AddEnd(Node** head, int p_key, const string &p_inf) {
    Node* NewNode = new Node;
    NewNode->key = p_key;
    NewNode->inf = p_inf;
    NewNode->next = nullptr;
    NewNode->prev = nullptr;

    if (!*head) {
        NewNode -> next = NewNode->prev = NewNode;
        *head = NewNode;
    }

    else {
        NewNode -> next = *head;
        NewNode -> prev = (*head)->prev;
        (*head)->prev->next = NewNode;
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
        cout << "K: " << temp->key << "; Inf: " << temp->inf << " <-> ";
        temp = temp->next;
    }
    while (temp != head);
    cout << "HEAD\n";
}

// Андрей 1:
void InsertAfter(Node** head, int i, int p_key, const string& p_inf) {
    if (i < 0) {
        cout << "Uncorrect number" << endl;
        return;
    }

    int count = CountNode(*head);

    if (!*head && i == 0) {
        AddStart(head, p_key, p_inf);
        return;
    }

    // Если индекс больше или равен количеству — вставка в конец
    if (i >= count) {
        AddEnd(head, p_key, p_inf);
        return;
    }

    Node* temp = *head;
    for (int n = 0; n < i; n++) {
        temp = temp->next;
    }

    Node* newNode = new Node;
    newNode->key = p_key;
    newNode->inf = p_inf;
    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

// Егор 6:
void Include_instead_the_key (Node **head, unsigned int a_key, unsigned int b_key, const string &new_inf) {

    if (!head || !*head)
        return;

    Node* current = *head;

    do {
        if (current->key == a_key) {
            Node* new_node = new Node;
            new_node->key = b_key;
            new_node->inf = new_inf;
            new_node->prev = current->prev;
            new_node->next = current->next;

            current->prev->next = new_node;
            current->next->prev = new_node;
            if (current == *head) {
                *head = new_node;
            }
            Node* to_delete = current;
            current = current->next;
            delete to_delete;
        } else {
            current = current->next;
        }
    } while (current != *head);

}

// Соня :
void InsertBefore(Node** head, int i, int key, const string& inf) {
    if (!head || i < 0) {
        cout << "Uncorrect number" << endl;
        return;
    }
    int count = CountNode(*head);
    // Вставка в начало
    if (i == 0 || !*head) {
        AddStart(head, key, inf);
        return;
    }
    // Вставка в конец
    if (i >= count) {
        AddEnd(head, key, inf);
        return;
    }
    // Вставка в середину
    Node* current = *head;
    for (int pos = 0; pos < i; pos++) {
        current = current->next;
    }
    Node* NewNode = new Node;
    NewNode->key = key;
    NewNode->inf = inf;
    NewNode->next = current;
    NewNode->prev = current->prev;

    current->prev->next = NewNode;
    current->prev = NewNode;

    // Если вставка перед головой — обновить head
    if (current == *head) {
        *head = NewNode;
    }
}

//Петя:
void Zamena(Node** head, int elem, int new_key, const string new_inf) {

    if (!*head) {
        return;
    }
    if (elem<1) {
        cout << "Uncorrect number" <<endl;
        return;
    }
    int count = CountNode(*head);
    if (elem > count) {
        cout << "Uncorrect number" << endl;
        return;
    }
    else {
        Node * temp = (*head);
        for (int i=1; i < elem; i++) {
            temp = temp->next;
        }
        temp->key = new_key;
        temp->inf = new_inf;
    }
}


int  main() {

    Node *head = CreatHead();
    AddStart(&head, 2, "First");
    AddEnd(&head, 15, "Second");
    AddEnd(&head, 1412, "Third");
    AddEnd(&head, 13, "Fourth");
    AddEnd(&head, 72, "Fifth");
    PrintNode(head);
    // cout << CountNode(head) << endl;

    InsertAfter(&head, 2, 0, "NEW");
    // Include_instead_the_key(&head, 13, 9999, "NEW_2");
    // InsertBefore(&head, 1, -2222, "NEW_3");
    // Zamena(&head, 2, 1, "NEW_4");
    PrintNode(head);

    // cout << CountNode(head) << endl;
    // DeleteAll(&head);
    // PrintNode(head);

    return 0;
}


