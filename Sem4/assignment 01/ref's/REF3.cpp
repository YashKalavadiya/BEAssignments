#include<iostream>
#include<stack>
using namespace std;
class node
{
     public:
     	int data;
     	node *left;
     	node *right;
};
class bst
{

public:
		node *root;
	bst()
	{
		root=NULL;
	}
	void create();
	void insert();
	void postorder(node*);
	void inorder(node *);
    void preorder(node *);
    void search(int key);
    //int search(node*, int key);
    void iterativeInorder(node *);
    void iterativePreorder(node *);
    void iterativePostorder(node *);
	void minimum();
	int height(node*);
	void erase(node *);
	void copyTree(node * , node *);
	int getLeaf(node *);
	int getinter(node *);
	void mirrorTree(node *);
 	bst operator= (bst &rhs)
{
    if ( &rhs != this )  // for optimization purposes, check for self assignment
    {
        bst temp(rhs);  // copy the rhs (uses copy constructor)
        std::swap(temp.root, root);  // swap out the members (root with temp.root)
    } // temp now dies off with the old data (uses destructor)
    return *this;
}
};


void bst::minimum()
{
       node *temp;
	int min;
      temp=root;
	      while(temp->left!=NULL)
	         {
                  min=temp->data;
			temp=temp->left;
			if(temp->data<min)
			{
				min=temp->data;
			}
			else
			{
				temp=temp->left;

			}
		}
		cout<<"minimum no. is:"<<min;
}
int bst::height(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		if(height(root->right)>height(root->left))		//right tree is longer
		{
			return (1+height(root->right));
		}
		else
		{
			return (1+height(root->left));
		}
	}
}

void bst::create()
{
	node *curr;
	cout<<"enter data:";
    curr=new node;
    cin>>curr->data;
    curr->left=curr->right=NULL;
    if(root==NULL)
    {
        root=curr;
    }

}
void bst::inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<" "<<root->data;
		inorder(root->right);
	}
}
void bst::preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<"  "<<root->data;
		preorder(root->left);
		preorder(root->right);
	}
}
void bst::postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<" "<<root->data;
	}
}

void bst :: iterativeInorder(node *root)
{
    stack<node *> s;
    node *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the curr Node */
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }

        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;

    } /* end of while */
}


void bst :: iterativePreorder(node *root)
{
   if (root == NULL)
        return;

    stack<node*> st;

    // start from root node (set current node to root node)
    node* curr = root;

    // run till stack is not empty or current is
    // not NULL
    while (!st.empty() || curr != NULL) {
        // Print left children while exist
        // and keep pushing right into the
        // stack.
        while (curr != NULL) {
            cout << curr->data << " ";

            if (curr->right)
                st.push(curr->right);

            curr = curr->left;
        }

        // We reach when curr is NULL, so We
        // take out a right child from stack
        if (st.empty() == false) {
            curr = st.top();
            st.pop();
        }
    }
}


void bst :: iterativePostorder(node *root)
{
    if (root == NULL)
        return;

    // Create two stacks
    stack<node *> s1, s2;

    // push root to first stack
    s1.push(root);
    node* node;

    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);

        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    // Print all elements of second stack
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }

}

void bst :: erase(node *root)
{
	if (root == NULL) return;

    /* first delete both subtrees */
    erase(root->left);
    erase(root->right);

    /* then delete the node */
    cout << "\n Deleting node: " << root->data;
    delete root;
}

int bst:: getLeaf(node* node)
{
    if (node != NULL &&(node->left != NULL && node->right != NULL))
    {
        return 0;
    }
	else if (node !=NULL &&(node->left == NULL && node->right == NULL))
	{
	    // If root is Not NULL and its one of its child is also not NULL
        return 1 + getLeaf(node->left) + getLeaf(node->right);
	}
}

int bst:: getinter(node* node)
{
    // Base cases.
    if (node == NULL || (node->left == NULL && node->right == NULL))
    {
        return 0;
    }

		// If root is Not NULL and its one of its child is also not NULL
	return 1 + getinter(node->left) + getinter(node->right);
}


void bst:: mirrorTree(node *noder)
{
	node *temp;

    if (noder == NULL)
	{
		return;
	}

    else
    {
		temp = new node;

        /* do the subtrees */
        mirrorTree(noder->left);
        mirrorTree(noder->right);

        /* swap the pointers in this node */
        temp     = noder->left;
        noder->left = noder->right;
        noder->right = temp;
    }
}

void bst::insert()
{
	node *curr,*temp;
    char direction;
	temp=root;
	curr=new node;
	cout<<"enter data:";
    cin>>curr->data;
    curr->left=NULL;
    curr->right=NULL;
		if(temp==NULL)
		{
			root=new node;
            root=curr;
            cout<<"\nElement added to root";
		}
        bool tillDestination = false;
        cout<<"\nInsert at l/r? ";
        cin>>direction;
        while(!tillDestination)
        {
            if(direction=='r')
            {
                if(temp->right==NULL)
                {
                    tillDestination = true;
                    continue;
                }

                temp = temp -> right;
                cout<<"\nInsert at l/r of"<<temp->data<<"?";
                cin>>direction;
            }

            if(direction =='l'){
                if(temp->left==NULL)
                {
                    tillDestination=true;
                    continue;
                }
                temp = temp -> left;
                cout<<"\nInsert at l/r of"<<temp->data<<"?";
                cin>>direction;
            }
        }

        if(direction == 'r')
        {
            temp->right = curr;
        }
        else
        {
            temp->left = curr;
        }

}


void bst::search(int key)
{
	node *curr;
	curr=root;
	while(curr!=NULL)
	{
		if(curr->data==key)
		{
			cout<<"found";
			break;
		}
		else
		{
			if(key<curr->data)
			{
				curr=curr->left;
			}
			else
			{
				curr=curr->right;
			}
		}
	}
	if(curr==NULL)			//not found even at the end of the tree.
	{
		cout<<"not found";
	}
}

int main()
{
	bst b,c;
	int key,ch;
	do
	{
		cout<<"\n1.create\n2.insert\n3.inorder\n4.preorder\n5.postorder\n6.search\n7.minimum\n8.height\n9.Iterative Inorder\n10.Iterative Preorder\n11.Iterative Postorder\n12.Copy Tree\n13.Leaf Nodes\n14.Intermediate Nodes\n15.Mirror Tree\n16.Delete Tree\npress 0 to exit\n";
		cout<<"enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:b.create();
				break;
			case 2:b.insert();
				break;
			case 3:cout<<"inorder traversal is\n";
					b.inorder(b.root);
					break;
			case 4:cout<<"preorder traversal is\n";
					b.preorder(b.root);
					break;
			case 5:cout<<"postorder traversal is\n";
					b.postorder(b.root);
					break;
			case 6:cout<<"\nenter key:";
				cin>>key;
				b.search(key);
				break;
			case 7:b.minimum();
				break;
			case 8:cout<<"height of tree: "<<b.height(b.root);
				break;
            case 9:
                b.iterativeInorder(b.root);
                break;
            case 10:
                b.iterativePreorder(b.root);
                break;
            case 11:
                b.iterativePostorder(b.root);
                break;

			case 12:
				c=b;
				c.inorder(c.root);

			case 13:

				cout<< b.getLeaf(b.root);

			case 14:
				cout<<b.getinter(b.root);

			case 15:
				b.mirrorTree(b.root);
				b.inorder(b.root);

			case 16:
                b.erase(b.root);
		}
	}while(ch!=0);
	return 0;
}

