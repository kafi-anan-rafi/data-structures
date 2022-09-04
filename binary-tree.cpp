#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
};

Node *create_node(int item)
{
  Node *new_node = new Node;
  if (new_node == nullptr)
  {
    cout << "Error! Could not allocate memory!" << endl;
    exit(1);
  }

  new_node->data = item;
  new_node->left = nullptr;
  new_node->right = nullptr;

  return new_node;
}

void add_left_child(Node *node, Node *child)
{
  node->left = child;
}

void add_right_child(Node *node, Node *child)
{
  node->right = child;
}

Node *create_tree()
{
  Node *two = create_node(2);
  Node *seven = create_node(7);
  Node *nine = create_node(9);
  
  add_left_child(two, seven);
  add_right_child(two, nine);

  Node *one = create_node(1);
  Node *six = create_node(6);
  
  add_left_child(seven, one);
  add_right_child(six, one);

  Node *five = create_node(5);
  Node *ten = create_node(10);
  
  add_left_child(five, six);
  add_right_child(ten, six);

  Node *eight = create_node(8);
  add_right_child(eight, nine);

  Node *three = create_node(3);
  Node *four = create_node(4);

  add_left_child(three, eight);
  add_right_child(four, eight);
  return two;
}

int main()
{
  Node *root = create_tree();
  cout << root->data << endl;

  return 0;
}