#include<iostream>

using namespace std;

struct Node {
   string key;
   string meaning;
   Node *left, *right;
};

class BinaryTree {
   Node *root = NULL;

   void ascending(Node *current) {
       if(current == NULL)
       return;

       ascending(current->left);

       cout<<"\t"<<current->key<<" : "<<current->meaning;

       ascending(current->right);
   }

   void descending(Node *current) {
       if(current == NULL)
       return;

       descending(current->right);

       cout<<"\t"<<current->key<<" : "<<current->meaning;

       descending(current->left);
   }

   void insert(string key, string meaning){
       Node *current = root;
       Node *newNode = new Node;
       newNode->key = key;
       newNode->meaning = meaning;
       newNode->left = NULL;
       newNode->right = NULL;

       if(root == NULL) {
           root = newNode;
       }
       else{
           Node *parent = current;
           if(newNode->key < current->key) current = current->left;
           else if(newNode->key > current->key) current = current->right;
           while(current != NULL){
               if(current->key < newNode->key) {
                   parent = current;
                   current = current->right;
               }
               else if(current->key > newNode->key){
                   parent = current;
                   current = current->left;
               }
               else {
                   cout<<"\nNo Duplicates allowed!!!";
                   return;
               }
           }
           if(parent->key > newNode->key){
               parent->left = newNode;
           }
           else if(parent->key < newNode->key) {
               parent->right = newNode;
           }
       }
   }

   Node* getInorderSuccessorParent(Node *current) {
       Node *parent = current;
       if (current->right != NULL) {
           current = current->right;
           parent = current;
           while (current->left != NULL) {
               parent = current;
               current = current->left;
           }
       }
       return parent;
   }

   void deleteRecord(string key) {
       Node *current = root;
       Node *parent = current;

       bool isFound = false;

       while (current != NULL && !isFound) {
           if(current->key == key){
               isFound = true;
           }
           else if(current->key > key){
               parent = current;
               current = current->left;
           }
           else{
               parent = current;
               current = current->right;
           }
       }
       if(isFound){
           if(current->left == NULL and current->right == NULL) {
               if (parent->left->key == current->key){
                   parent->left = NULL;
                   delete current;
               }
               else if(parent->right->key == current->key) {
                   parent->right = NULL;
                   delete current;
               }
           }
           else {
               Node *successorParent = getInorderSuccessorParent(current);
               Node *successor = NULL;
               if(successorParent->left == NULL) {
                   successor = successorParent;
                   current->key = successor->key;
                   current->meaning = successor->meaning;
                   current->left = successor->left;
                   current->right = successor->right;
               }
               else {
                   successor = successorParent->left;
               }
               if(successor->right != NULL) {
                   successorParent->left = successor->right;
                   current->key = successor->key;
                   current->meaning = successor->meaning;
                   successor->right = NULL;
                   delete successor;
               }
           }
       }
       else {
           cout<<"\nRecord Not Found!!!";
           return;
       }
   }
   void searchRecord(string key) {
       Node *current = root;

       int count = 0;

       while (current != NULL) {
           count += 1;
           if(current->key == key){
               cout<<"\nKey Found!!!, Comparisions: "<<count;
               return;
           }
           else if(current->key > key){
               current = current->left;
           }
           else{
               current = current->right;
           }
       }
       cout<<"\nRecord Not Found";
   }

   void updateRecord(string oldKey, string newMeaning) {
       Node *current = root;

       while (current != NULL) {
           if(current->key == oldKey){
               current->meaning = newMeaning;
               cout<<"\nRecord Updated";
               return;
           }
           else if(current->key > oldKey){
               current = current->left;
           }
           else{
               current = current->right;
           }
       }
       cout<<"\nRecord Not Found";
   }

   void printMenu() {
       cout<<"\n===============================================";
       cout<<"\n1. Insert record";
       cout<<"\n2. Search Record";
       cout<<"\n3. Update Record";
       cout<<"\n4. Delete Record";
       cout<<"\n5. Print (ascending order)";
       cout<<"\n6. Print (descending order)";
       cout<<"\n7. Exit";
       cout<<"\n===============================================";
   }
   public:

   void exec() {
       bool isDone = false;
       while (!isDone) {
           string key, meaning;
           cout<<"\nEnter Key: ";
           cin>>key;
           cout<<"\nIts Meaning: ";
           cin>>meaning;
           insert(key, meaning);
           cout<<"\nDo you want to continue(y/n)?:";
           char ch;
           cin>>ch;
           if (ch == 'n'){
               isDone = true;
           }
       }

       bool isExit = false;

       while(!isExit) {
           printMenu();
           int ch;
           cout<<"\nEnter your choice: ";
           cin>>ch;
           switch(ch) {
               case 1: {
                   string key, meaning;
                   cout<<"\nEnter Key: ";
                   cin>>key;
                   cout<<"\nIts Meaning: ";                   
                   cin>>meaning;
                   insert(key, meaning);
                   break;
               }
               case 2: {
                   string key;
                   cout<<"\nEnter Key to search: ";
                   cin>>key;
                   searchRecord(key);
                   break;
               }
               case 3: {
                   string key, newMeaning;
                   cout<<"\nEnter KEY: ";
                   cin>>key;
                   cout<<"\nEnter its new Meaning: ";
                   cin>>newMeaning;
                   updateRecord(key, newMeaning);
                   break;
               }
               case 4:{
                   string key;
                   cout<<"\nEnter Key to delete: ";
                   cin>>key;
                   deleteRecord(key);
                   break;
               }
               case 5:
                   ascending(root);
                   break;
               case 6:
                   descending(root);
                   break;
               case 7:
                   isExit = true;
                   break;
           }
       }
   }
};

int main() {
   BinaryTree bt;
   bt.exec();
   return 0;
}

