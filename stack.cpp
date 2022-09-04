#include <iostream>
using namespace std;

#define STACK_MAX 10

struct Stack
{
  int top;
  int data[STACK_MAX];
};

void push(Stack *s, int data)
{
  if (s->top < STACK_MAX)
  {
    s->data[s->top] = data;
    s->top += 1;
  }
  else
    cout << "Stack is Full!!" << endl;
}

int pop(Stack *s)
{
  if (s->top == 0)
  {
    cout << "Stack is empty!" << endl;
    return -1;
  }
  else
  {
    s->top -= 1;
    return s->data[s->top];
  }
}

int main()
{
  Stack my_stack;
  int item;
  my_stack.top = 0;

  push(&my_stack, 1);
  push(&my_stack, 2);
  push(&my_stack, 5);

  item = pop(&my_stack);
  cout << item << endl;

  item = pop(&my_stack);
  cout << item << endl;

  item = pop(&my_stack);
  cout << item << endl;

  item = pop(&my_stack);
  cout << item << endl;
  return 0;
}