        // while(true) {
        //     while (current->left->left != NULL) {
        //         // if (current->left->data == data) {
        //         //     isFound = true;
        //         //     break;
        //         // }
        //         current = current->left;
        //     }
        //     if (current->left->data == data) {
        //         isFound = true;
        //         foundLoc = "left->data";
        //         break;
        //     }
        //     current = current->left;
        //     if (current->right) {
        //         if (current->right->data == data) {
        //             isFound = true;

        //         }
        //     }
        // }










            /**
    * @brief old code snippet for simple binary threaded tree
    *
    */
    // void insertElement(int data){
    //             Node *temp = root;
    //     char direction;
    //     cout<<"\nInsert To the l/r? :";
    //     cin>>direction;
    //     if(temp == NULL){
    //         root = new Node;
    //         root->data = data;
    //         root->left = NULL;
    //         root->right = NULL;
    //         cout<<"\nElement added to root";
    //         return;
    //     }
    //     bool isDest = false;
    //     while(!isDest) {
    //         if(direction == 'r') {
    //             if(temp->right == NULL) {
    //                 isDest = true;
    //                 continue;
    //             }
    //             if(temp->isRightThread) {
    //                 isDest = true;
    //                 continue;
    //             }
    //             temp = temp->right;
    //             cout<<"\nInert at l/r of "<<temp->data<<"?";
    //             cin>>direction;
    //         }
    //         else if(direction == 'l') {
    //             if(temp->left == NULL) {
    //                 isDest = true;
    //                 continue;
    //             }
    //             temp = temp->left;
    //             cout<<"\nInert at l/r of "<<temp->data<<"?";
    //             cin>>direction;
    //         }
    //         else{
    //             cout<<"\nDiplicate Element!!!";
    //             return;
    //         }
    //     }
    //     struct Node *newEle = new Node;
    //     newEle->data = data;
    //     newEle->left = NULL;
    //     newEle->right = NULL;
    //     if(direction == 'r') {
    //         if(temp->isRightThread) {
    //             newEle->right = temp->right;
    //             newEle->isRightThread = true;
    //             temp->isRightThread = false;
    //         }
    //         temp->right = newEle;
    //     }
    //     else{
    //         newEle->right = temp;
    //         newEle->isRightThread = true;
    //         temp->left = newEle;
    //     }
    // }
