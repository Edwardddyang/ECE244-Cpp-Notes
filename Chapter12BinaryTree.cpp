#include <iostream> 
#include <string> 

using namespace std; 

/* 
Binary Search: 

- Data structure should be sorted and in an array 
- Checks the middle of the list, then discards one half 

In arrays: 
int binarySearch(int list[], int listLength, int item){
  int low = 0; 
  int high = listLength - 1; 
  int middle; 

  while(low <= high){
    middle = (low + high) / 2; 
    if(item == list[middle])
      return middle; 
    else if(item < list[middle])
      high = middle - 1; 
    else if(item > list[middle)
      low = middle + 1; 
  }
  return -1; 
}

Binary Search Tree: 

- Each node has at most 2 children 
- Search, insertion, and deletion are all O(log n)
- For each node, value of all the nodes in left is lesser and value of all nodes in the right is greater 
- After insertion and deletion, you want to rebalance the binary tree

struct Node{
  int data; 
  Node* left; 
  Node* right; 
}

Node* getNewNode(int data){ <-- Creates new nodes for the tree
  Node* newNode = new Node();
  newNode->data = data; 
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode; 
}

Node* Insert(Node* root, int data){ <- This inserts a new node and stores data in it 
  if(root == NULL){
    root = getNewNode(data);
  }
  else if(data <= root->data){
    root->left = Insert(root->left, data); 
  }
  else if(data >= root->data){
    root->right = Insert(root->right, data); 
  }
  return root;
}

bool Search(Node* root, int data){
  if(root == NULL)
    return false; 
  else if(root->data == data)
    return true
  else if(data <= root->data)
    return Search(root->left, data);
  else if(data >= root->data)
    return Search(root->right, data); 
}

To find min/max element of a binary tree: 

1. Iteratively 
Node* findMin(Node* root){
  Node* current = root; 
  while(current->left != nullptr){
    current = current->left; 
  }
  return current->data; 
}

2. Recursively 
Node* findMin(Node* root){
  Node* current = root; 
  if(current == NULL){
    cout << "Tree is empty"; 
    return; 
  } 
  else if(root->left == NULL){
    return root->data; 
  }
  return findMin(current->left); 
}

To find height of a binary tree: 
//Find the height of the right and left subtree. The height of the root is max of right and left + 1, then repeat. 
//Height of an empty binary tree is -1 
//Height is counted by counting edges 

int binaryHeight(Node* root){
  if(root == NULL)
    return -1; 
  return max(binaryHeight(root->left), binaryHeight(root->right)) + 1; 
}

To traverse a binary search tree: 

Breadth-first/Level order traversal - Visit all the nodes at each level, then go lower 
//Create a queue by starting with one node, and putting all its children in the end of the queue. Then traverse the queue. 

void levelOrderTraversal(Node* root){ <- Time complexity - O(n), Space complexity - O(1) or O(n) 
  if(root == NULL)
    return; 

  queue<Node*> Q; <- Need to use #include <queue>, creates a queue of Node* type. 
  Q.push(root); <- Adds the root to the queue 

  while(!Q.empty()){ <- Returns true if the queue has an element in it 
    Node* current = Q.front(); <- Makes current the Node* that is in the front 
    cout << current->data; 
    if(current->left != NULL) Q.push(current->left);
    if(current->right != NULL) Q.push(current->right); 
    Q.pop(); <- Removes the element at the front  
  }

}

Depth-first - Visit all the children of a node before going to the other side 
- Space complexity O(n) where n is height of tree, Time complexity is O(n)

  1. Preorder - root -> left -> right (DLR)

void Preorder(Node* root){ 
  if(root == NULL)
    return; 
  cout << root->data << endl;
  Preorder(root->left);
  Preorder(root->right); 
}

  2. Inorder - left -> root -> right (LDR)
   
void Inorder(Node* root){
  if(root == NULL)
    return; 
  Inorder(root->left);
  cout << root->data << endl; 
  Inorder(root->right); 
}
  3. Postorder - left -> right -> root (LRD)

void Postorder(Node* root){
  if(root == NULL)
    return; 
  Postorder(root->left);
  Postorder(root->right);
  cout << root->data << endl; 
}

To delete a node from Binary Search Tree: 

Node* Delete(Node* root, int data){

  if(root == NULL)
    return root; 
  else if(data < root->data) 
    root->left = Delete(root->left, data); 
  else if(data > root->data)
    root->right = Delete(root->right, data); 
  else{ <- Executes once you found the node to be deleted 
    if(root->left == NULL && root->right == NULL){ <--0 children 
      delete root; 
      root = NULL;
    }
    else if(root->left == NULL){ <- There is a right child
      Node* temp = root; 
      root = root->right;
      delete temp; 
    }
    else if(root->right == NULL){ <- There is a left child 
      Node* temp = root; 
      root = root->left; 
      delete temp; 
    }
    else{ <- 2 Children 
      Node* temp = findMin(root->right); 
      root->data = temp->data; 
      root->right = Delete(root->right, temp->data); 
    } 
  }
  return root;
}


int main(){
Node* root = nullptr <- This creates the root of the binary search tree, it is empty
}

*/