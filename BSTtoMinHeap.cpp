#include<iostream>
#include<vector>
using namespace std;

struct Node 
{
    int data;
    Node* left=NULL;
    Node* right=NULL;
};

Node* creation(Node *root, int data)
{
    if(root==NULL)
    {
        Node *newn = new Node;
        newn->data=data;
        root=newn;
    }
    
    else
    {
        if (data < (root->data))
	    {
		    root->left = creation(root->left, data);
	    }
	    else if (data >= root->data)
	    {
		    root->right = creation(root->right, data);
	    }
    }
    return root;
}

void inorderTraversal(Node *root, vector<int>& arr)
{
	if (root != NULL)
	{	
	    inorderTraversal(root->left, arr);
    	arr.push_back(root->data);      //Storing Increasing Order DATA in Increasing Order
    	inorderTraversal(root->right, arr);
    }
}

void Convert(Node *root, vector<int> arr, int *i)
{
	if (root == NULL)
		return;

	root->data = arr[++*i];

	Convert(root->left, arr, i); //Left Sub-Tree to Heap

	Convert(root->right, arr, i); //Right Sub-Tree to Heap
}

void MinHeap(Node *root)
{
	vector<int> arr;        //Using Vector to store all the Nodes of BST
	int i = -1;

	inorderTraversal(root, arr);  //Inorder Traversal to Store Nodes in Ascending Order

	Convert(root, arr, &i);
}

void preorderTraversal(Node *root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

int main()
{
    system("cls");
    int n;
    int data;
    Node *root=new Node;
    root=NULL;
    cout<<"\n\nEnter number of nodes: ";
    cin>>n;

    cout<<"\n\nEnter tree linearly: "; 
    while(n--)
    {   
        cin>>data;
        root=creation(root,data);
    }

    cout << "\n\nPreOrder Traversal in BST:" << endl;
    preorderTraversal(root);
    
	MinHeap(root);
	cout << "\n\nPreOrder Traversal in MinHeap:" << endl;
	preorderTraversal(root);

    cout<<"\n\n";
}
