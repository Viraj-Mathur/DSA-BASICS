// PROGRAM TO CONVERT BST INTO DOUBLY LINKED LIST

/*
APPROACH : 
1. LET ROOT BE THE HEAD(INITIALLY)
2. SOLVE FOR RIGHT SUBTREE USING RECURSION
3. TRANSFER BACK POINTER TO THE HEAD(BECAUSE OF DOUBLY LL)
4. UPADTE THE HEAD
5. SOLVE FOR LEFT SUBTREE USING RECURSION
*/

#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};
Node* insertIntoBST(Node* root,int data){
    // Empty tree
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    // Not empty tree
    if(root->data > data){
        // insert into left
        root->left = insertIntoBST(root->left,data);
    }
    else{
        // insert into right
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

// MAIN FUNCTION HERE!!!!!!!!

void bst_dll(Node* root, Node* &head){
    // base case
    if(root == NULL){
        return;
    }

    // convert right subtree to linked list
    bst_dll(root->right, head);

    // update the right pointer of the current node
    root->right = head;

    // attach the previous pointer from right subtree to the head
    if(head!=NULL){
        head->left = root;
    }


    // update the head to the current node
    head = root;

    // convert left subtree to linked list
    bst_dll(root->left, head); 
}

void levelOrderTraversal(Node *root)
{
    // Empty tree
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    // Push the root in queue
    q.push(root);
    q.push(NULL);
    // Run the loop until queue becomes empty
    while (!q.empty())
    {
        // Fetch front node and then pop
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // go to the next line
            cout << endl;
            // Marking for next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            // left child exists
            if (temp->left)
            {
                q.push(temp->left);
            }
            // right child exists
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void printDLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        // next pointer is right pointer
        temp = temp->right; 
    }
    cout<<"NULL"<<endl;
}


int main(){
    
    // Create a root node for the BST
    Node* root = NULL;

    // Take input to create the BST
    cout << "Enter elements to create BST (-1 to stop): ";
    takeInput(root);

    // Display the BST in level order
    cout << "Level order traversal of BST:" << endl;
    levelOrderTraversal(root);

    // Convert BST to doubly linked list
    Node* head = NULL;
    bst_dll(root, head);

    // Print the doubly linked list
    cout << "Doubly linked list from BST:" << endl;
    printDLL(head);

    return 0;
}

