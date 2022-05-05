#include "iostream"
#include "string"
#include <bits/stdc++.h>

using namespace std;

struct Node {
    string meaning, keyword;
    Node *left, *right;
};

class DictionaryStore {
    public:
        Node *root = NULL;
        void enterData() {
            string keyword, meaning;
            bool isEnd = false;
            while(!isEnd){
                cout<<"\nEnter KEYWORD: ";
                cin>>keyword;
                cout<<"\nEnter it's Meaning";
                // cin.ignore();
                cin.ignore(INT_MAX, '\n');
                getline(cin, meaning);
                struct Node *newEle = new Node;
                newEle->keyword = keyword;
                newEle->meaning = meaning;
                newEle->left = NULL;
                newEle->right = NULL;
                if(root == NULL){
                    root = newEle;
                }
                else{
                    insertElement(newEle, root);
                }
                cout<<"\nWant to enter more data? (y/n): ";
                char ch;
                // ch = getchar();
                cin>>ch;
                cin.ignore();
                ch == 'y' ? isEnd = false : isEnd = true;
            }
        }

        void insertElement(Node *newData, Node *current) {
            int diff = current->keyword.compare(newData->keyword);
            if(diff > 0){
                if(current->left == NULL){
                    current->left = newData;
                    return;
                }
                else{
                    insertElement(newData, current->left);
                }
            }
            else if(diff < 0) {
                if(current->right == NULL){
                    current->right = newData;
                    return;
                }
                else{
                    insertElement(newData, current->right);
                }
            }
            else{
                cout<<"\nDuplicate Entry found!! Please try updating insted of inserting";
                return;
            }
        }

        void ascendingPrint(Node *current) {
            if(current == NULL) {
                return;
            }
            ascendingPrint(current->left);
            cout<<"\n+++++++++++++++++++++";
            cout<<"\nKeyword: "<<current->keyword;
            cout<<"\nMeaning: "<<current->meaning;
            cout<<"\n+++++++++++++++++++++";
            ascendingPrint(current->right);
        }
        void decendingPrint(Node *current) {
            if(current == NULL) {
                return;
            }
            decendingPrint(current->right);
            cout<<"\n+++++++++++++++++++++";
            cout<<"\nKeyword: "<<current->keyword;
            cout<<"\nMeaning: "<<current->meaning;
            cout<<"\n+++++++++++++++++++++";
            decendingPrint(current->left);
        }

        void search(string keyword) {
            Node *temp = root;
            int count = 0;
            while(temp != NULL) {
                if(keyword == temp->keyword){
                    cout<<"\nFound Element "<<keyword<<" : "<<temp->meaning;
                    count += 1;
                    cout<<"\nNo of comparisons: "<<count;
                    return;
                }
                else if(keyword > temp->keyword) {
                    count += 1;
                    temp = temp->right;
                }
                else{
                    count += 1;
                    temp = temp->left;
                }
            }
            cout<<"\nNot Found";
            return;
        }

        void update(string keyword, string newMeaning) {
            Node *temp = root;
            while(temp != NULL) {
                if(keyword == temp->keyword){
                    temp->meaning = newMeaning;
                    return;
                }
                else if(keyword > temp->keyword) {
                    temp = temp->right;
                }
                else{
                    temp = temp->left;
                }
            }
            cout<<"\nNot Found";
            return;
        }


//TODO: Fix deleting leaf node

        void deleteNode(Node *parent, Node *toBeDeleted){
            if(toBeDeleted->left == NULL && toBeDeleted->right == NULL) {
                toBeDeleted->left = NULL;
                toBeDeleted->right = NULL;
                delete toBeDeleted;
                return;
            }
            else if(toBeDeleted->left == NULL){
                if(parent->left == toBeDeleted){
                    parent->left = toBeDeleted->right;
                }
                else if(parent->right == toBeDeleted){
                    parent->right = toBeDeleted->right;
                }
                return;
            }
            else if(toBeDeleted->right == NULL) {
                if(parent->left == toBeDeleted){
                    parent->left = toBeDeleted->left;
                }
                else if(parent->right == toBeDeleted){
                    parent->right = toBeDeleted->left;
                }
                return;
            }
            Node *successor = toBeDeleted->right;
            Node* parentOfSuccessor = toBeDeleted;
            while(successor->left != NULL){
                parentOfSuccessor = successor;
                successor = successor->left;
            }


            if(parent != NULL) {
                if(parent->left == toBeDeleted){
                    parent->left = successor;
                }
                else if(parent->right == toBeDeleted){
                    parent->right = successor;
                }
            }
            if(parent == NULL){
                delete root;
                root = successor;
            }

            successor->left = toBeDeleted->left;
            if (toBeDeleted->right != successor) {
                parentOfSuccessor->left = successor->right;
                successor->right = toBeDeleted->right;
            }
            toBeDeleted->left = NULL;
            toBeDeleted->right = NULL;
            delete toBeDeleted;
        }

        void deleteKw(string key) {

            Node *temp = root;

            if(temp->keyword == key){
                deleteNode(NULL, temp);
                cout<<"\nDeleted Element";
                return;
            }

            while(temp != NULL) {
                if(key == temp->left->keyword){
                    cout<<"\nDeleting Left";
                    deleteNode(temp, temp->left);
                    cout<<"\nDeleted Element";
                    return;
                }
                else if(key == temp->right->keyword){
                    deleteNode(temp, temp->right);
                    cout<<"\nDeleted Element";
                    return;
                }

                if(root->keyword < key) {
                    if(key > temp->keyword){
                        temp = temp->right;
                    }
                    else if(key < temp->keyword){
                        temp = temp->left;
                    }
                }
                else if(root->keyword > key) {
                    if(key > temp->keyword ) {
                        temp = temp->right;
                    }
                    else if(key < temp->left->keyword){
                        temp = temp->left;
                    }
                }
            }
            cout<<"\nNot Found";
            return;
        }

        void printMenu() {
            cout<<"\n==============MENU==============";
            cout<<"\n1. Insert Element";
            cout<<"\n2. Display in ascending order";
            cout<<"\n3. Display in decending order";
            cout<<"\n4. Search and display MAX comparisions";
            cout<<"\n5. Delete keyword";
            cout<<"\n6. Update Data";
            cout<<"\n7. EXIT";
        }

        void exec() {
            bool isEXit = false;
            enterData();
            while(!isEXit) {
                printMenu();
                int ch;
                cout<<"\nEnter choice: ";
                cin>>ch;
                switch(ch) {
                    case 1:
                        enterData();
                        break;
                    case 2:
                        ascendingPrint(root);
                        break;
                    case 3:
                        decendingPrint(root);
                        break;
                    case 4:{
                        string kw;
                        cout<<"\nEnter keyword to search: ";
                        cin>>kw;
                        search(kw);
                        break;
                    }
                    case 5:{
                        string kw;
                        cout<<"\nEnter keyword to be deleted: ";
                        cin>>kw;
                        deleteKw(kw);
                        break;
                    }
                    case 6:{
                        cout<<"\nEnter Keyword to update: ";
                        string kw, meaning;
                        cin>>kw;
                        cout<<"\nEnter new Meaning: ";
                        cin.ignore(INT_MAX, '\n');
                        getline(cin, meaning);
                        update(kw, meaning);
                        break;
                    }
                    case 7:
                        isEXit = true;
                        break;
                }
            }
        }
};

int main(){
    DictionaryStore ds;
    ds.exec();
    return 0;
}