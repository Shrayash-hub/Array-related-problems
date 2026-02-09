/*Structure of the Node of the BST is as
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {

  public:
    Node* build(vector<int> &arr,int leftInd, int rightInd){
        if(leftInd>rightInd) return NULL;
        int mid = leftInd + (rightInd- leftInd)/2;
        Node* root = new Node(arr[mid]);
        
        root->left = build(arr,leftInd,mid-1);
        root->right = build(arr,mid+1,rightInd);
        
        return root;
    }
    void inorder(vector<int> &inord,Node* root){
        if(root==NULL) return;
        
        inorder(inord,root->left);
        inord.push_back(root->data);
        inorder(inord,root->right);
    }
    Node* balanceBST(Node* root) {
        // Code here
        vector<int> inord;
        inorder(inord,root);
        return build(inord,0,inord.size()-1);
    }
};