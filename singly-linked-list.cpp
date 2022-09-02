#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next)
{
    Node *new_node = new Node;
    if (new_node == nullptr)
    {
        cout << "Error! Could not allocate memory!" << endl;
        exit(1);
    }
    new_node->data = item;
    new_node->next = next;
    return new_node;
}

// insert beginning of the linked-list
Node *prepend(Node *head, int item)
{
    Node *new_node = create_node(item, head);
    return new_node;
}

// insert end of the linked-list
Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, nullptr);

    if (head == nullptr)
        return new_node;

    Node *current_node = head;
    while (current_node->next != nullptr)
    {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    return new_node;
}

// insert between start and end
void insert(Node *node, int item)
{
    Node *new_node = create_node(item, node->next);
    node->next = new_node;
}

// remove node from the linked-list
Node *remove_node(Node *head, Node *node)
{
    if (node == head)
    {
        head = node->next;
        delete node;
        return head;
    }

    Node *current_node = head;
    while (current_node->next != nullptr)
    {
        if (current_node->next == node)
            break;
        current_node = current_node->next;
    }

    if (current_node->next == nullptr)
        return head;

    current_node->next = node->next;
    delete node;
    return head;
}

void print_linked_list(Node *head)
{
    Node *current_node = head;
    while (current_node != nullptr)
    {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    head = create_node(10, nullptr);

    head = prepend(head, 12);
    insert(head, 13);
    append(head, 14);
    head = prepend(head, 1);
    head = prepend(head, 2);

    print_linked_list(head);
    return 0;
}