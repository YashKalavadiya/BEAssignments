#include "iostream"

using namespace std;


struct Node {
    int data;
    Node *left, *right;
    bool isRightThread = false;
};

class BinaryTree {
    public:

    Node *root = NULL;


    /*
    * inserts element at location given by user
    */
    void insertElement(int data){
                Node *temp = root;
        char direction;
        cout<<"\nInsert To the l/r? :";
        cin>>direction;
        if(temp == NULL){
            root = new Node;
            root->data = data;
            root->left = NULL;
            root->right = NULL;
            cout<<"\nElement added to root";
            return;
        }
        bool isDest = false;
        while(!isDest) {
            if(direction == 'r') {
                if(temp->right == NULL) {
                    isDest = true;
                    continue;
                }
                temp = temp->right;
                cout<<"\nInert at l/r of "<<temp->data<<"?";
                cin>>direction;
            }
            else if(direction == 'l') {
                if(temp->left == NULL) {
                    isDest = true;
                    continue;
                }
                temp = temp->left;
                cout<<"\nInert at l/r of "<<temp->data<<"?";
                cin>>direction;
            }
            else{
                cout<<"\nDiplicate Element!!!";
                return;
            }
        }
        struct Node *newEle = new Node;
        newEle->data = data;
        newEle->left = NULL;
        newEle->right = NULL;
        if(direction == 'r') {
            if(temp->isRightThread) {
                newEle->right = temp->right;
                newEle->isRightThread = true;
                temp->isRightThread = false;
            }
            temp->right = newEle;
        }
        else{
            newEle->right = temp;
            newEle->isRightThread = true;
            temp->left = newEle;
        }
    }

    void inorderTraversal(Node *current) {


        while(true){
            while(current->left != NULL) {
                current = current->left;
            }
            cout<<"\n"<<current->data;
            while(current->isRightThread) {
                current = current->right;
                cout<<"\n"<<current->data;
            }
            if(current->right)
            current = current->right;
            else
            break;
        }

    }
    void printMenu() {
        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout<<"\n                    MENU                      ";
        cout<<"\n1. Insert Element";
        cout<<"\n2. Inorder Traversal";
        cout<<"\n3. Preorder Traversal";
        cout<<"\n4. Exit";
        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    }

    void exec() {
        int init;
        cout<<"\nEnter initial number of elements: ";
        cin>>init;
        for(int i = 0; i < init; i++) {
            int ele;
            cout<<"\nEnter element you want to insert: ";
            cin>>ele;
            insertElement(ele);
        }

        bool isExit = false;
        while(!isExit) {
            printMenu();
            cout<<"\nEnter your Choice: ";
            int choice;
            cin>>choice;
            switch(choice) {
                case 1:{
                    cout<<"\nEnter Element: ";
                    int ele;
                    cin>>ele;
                    insertElement(ele);
                    break;
                }
                case 2:
                    inorderTraversal(root);
                    break;
                case 4:
                    isExit = true;
                    break;
                default:
                    cout<<"\nInvalid Choice!!!";
            }
        }
    }

};

int main() {
    BinaryTree bt;
    bt.exec();
    return 0;
}
