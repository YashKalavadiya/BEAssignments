
struct Node;

class Stack {
    int top = -1;
    int size;
    public:
    Node **stack;
    Stack(int size){
        stack = new Node*[size];
        this->size = size;
    }
    Node* getTop() {
        return stack[top];
    }
    void push(Node *element) {
        stack[++top] = element;
    }
    Node* pop() {
        return stack[top--];
    }
    bool isEmpty() {
        return top == -1;
    }
};