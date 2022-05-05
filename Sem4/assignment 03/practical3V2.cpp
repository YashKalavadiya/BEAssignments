#include "iostream"

using namespace std;


struct Node {
    int data;
    Node *left, *right;
    bool isRightThread = false;
    bool isLeftThreaded = false;
};

class BinaryTree {
    public:

    Node *root = NULL;



    /**
    * @brief Inserting Element in binary search tree at correct position 
    * 
    */
    void insertElement(int data){
        Node *temp = root;
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
            if(data < temp->data) {
                if(temp->left == NULL) {
                    isDest = true;
                    continue;
                }
                if(temp->isLeftThreaded) {
                    isDest = true;
                    continue;
                }
                temp = temp->left;
            }
            else if(data > temp->data) {
                if(temp->right == NULL) {
                    isDest = true;
                    continue;
                }
                if(temp->isRightThread) {
                    isDest = true;
                    continue;
                }
                temp = temp->right;
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
        if(data > temp->data) {
            if(temp->isRightThread) {
                newEle->right = temp->right;
                newEle->isRightThread = true;
                temp->isRightThread = false;
            }
            if(temp->isLeftThreaded) {
                newEle->left = temp->left;
                newEle->isLeftThreaded = true;
                temp->isLeftThreaded = false;
            }
            else {
                newEle->left = temp;
                newEle->isLeftThreaded = true;
            }
            temp->right = newEle;
        }
        else {
            if(temp->isLeftThreaded) {
                newEle->left = temp->left;
                newEle->isLeftThreaded = true;
                temp->isLeftThreaded = false;
            }
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

    void preOrderTraversal(Node *current) {
        while(true) {
            cout<<"\n"<<current->data;
            while (current->left != NULL) {
                current = current->left;
                cout<<"\n"<<current->data;
            }
            while(current->isRightThread) {
                current = current->right;
            }
            if(current->right) {
                current = current->right;
            }
            else {
                break;
            }
        }
    }


    void deleteNode(int data) {
        Node *current = root;
        if (root->data == data) {
            //TODO: deleting root will be different
            return;
        }

        bool isFound = false;
        string foundLoc = "";

        bool isExit = false;
        while (!isExit) {
            if (data > current->data) {
                if (current->right && !current->isRightThread) {
                    if (current->right->data == data) {
                        isFound = true;
                        foundLoc = "right->data";
                        isExit = true;
                    }
                    else {
                        current = current->right;
                    }
                }
            }
            else if (data < current->data) {
                if (current->left && !current->isLeftThreaded) {
                    if(current->left->data == data) {
                        isFound = true;
                        foundLoc = "left->data";
                        isExit = true;
                    }
                    else {
                        current = current->left;
                    }
                }
            }
        }
        if(isFound) {
            cout<<"\nFound Element";
            cout<<foundLoc;
            if (foundLoc == "left->data") {
                cout<<"\nCurrent: "<<current->data;
                cout<<"\nTo be deleted: "<<current->left->data;
            }
            else if(foundLoc == "right->data") {
                cout<<"\nCurrent: "<<current->data;
                cout<<"\nTo be deleted: "<<current->right->data;
            }
        }
    }

    void printMenu() {
        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout<<"\n                    MENU                      ";
        cout<<"\n1. Insert Element";
        cout<<"\n2. Inorder Traversal";
        cout<<"\n3. Preorder Traversal";
        cout<<"\n4. delete node";
        cout<<"\n5. Exit";
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
                case 3:
                    preOrderTraversal(root);
                    break;
                case 4:{
                    int data;
                    cout<<"\nEnter element to delete: ";
                    cin>>data;
                    deleteNode(data);
                    break;
                }
                case 5:
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
