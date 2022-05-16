
#ifndef STACK_
#define STACK_

class linkedList;

class stack {
    int top;
    int n;
    linkedList** list;

   public:
    stack(int n);
    void push(linkedList* node);
    linkedList* pop();
    linkedList* peek();
    bool isEmpty();
    ~stack();
};

#endif /* STACK_ */
