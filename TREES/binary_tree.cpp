#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter Data : " <<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;  //return -1 if you don't wanna give value
    }

    // Entering values through recursion

    cout<<"Enter data for inserting in Left of  "<< data <<endl;
    root->left = buildTree(root->left);

    cout<<"Entering data for inserting in Right of "<< data << endl;
    root->right = buildTree(root->right);
    return root;
}

/*
a Traversal Using Queue
For each node, first, the node is visited and then it’s child nodes are put in a FIFO queue. 
Then again the first node is popped out and then it’s child nodes are put in a FIFO queue 
and repeat until queue becomes empty.
*/

void LevelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

        // For displaying (tree like structure with spaces)
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp == NULL){ //IF PREVIOUS NODE IS COMPLETELY TRAVERSED
                cout<<endl;
                if(!q.empty()){ // QUEUE STILL HAVE SOME CHILD NODES in them
                    q.push(NULL);
                }
            }
            else{
                cout<< temp -> data <<" ";
                if(temp -> left){
                    q.push(temp ->left);
                }

                if(temp -> right){
                    q.push(temp ->right);
                }
            }

        } 
    }


// INORDER = L N R ; L = LEFT PART  N = PRINT ; R = RIGHT PART
// PREORDER = N L R
// POSTORDER = L R N

// INORDER

void inorder(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    inorder(root->left); // L
    cout<< root->data <<" "; // N
    inorder(root->right); // R
}

void preorder(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    cout<< root->data <<" "; // N
    preorder(root->left); // L
    preorder(root->right); // R
}

void postorder(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    postorder(root->left); // L
    postorder(root->right); // R
    cout<< root->data <<" "; // N
}

void buildFromLevelOrder(Node* &root){
    queue<Node*>q;
    cout<<"Enter Data for the root: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left node for: "<< temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData !=-1){
            temp-> left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<< temp-> data <<endl;
        int rigthData;
        cin>>rigthData;

        if(rigthData != -1){
            temp-> right = new Node(rigthData);
            q.push(temp->left);
        }
    }
}

int main(){

    Node*root = NULL;

    // buildFromLevelOrder(root);
    // LevelOrderTraversal(root);
    // // values: 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1  

    // // creating a Tree
    // root = buildTree(root);


    //data: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    // level order
    cout<<"Print the level order of traversal output: "<<endl;
    LevelOrderTraversal(root);

    cout<<"Inorder Traversal is: "<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Postorder Traversal is: "<<endl;
    postorder(root);
    cout<<endl;

    cout<<"Preorder Traversal is: "<<endl;
    preorder(root);
    cout<<endl;
    

    return 0;
}