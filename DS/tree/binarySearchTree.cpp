#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
std::queue<Node*> bfsQueue;

Node* findMin(Node * root) {
  if (root == nullptr) {
    return nullptr;
  }
  while (root->left != nullptr) {
    root = root->left;
  }
  return root;
}

class LinkedList {
  public:
    Node* head;
    Node* tail;
};

LinkedList * flattenTree(Node * root) {
  LinkedList *l = new LinkedList();
  if (root ==  nullptr) {
    return nullptr;
  }
  // leaf case
  if (root->left == nullptr and root->right == nullptr) {
    l->head = l->tail = root;
    return l;
  }else  if (root->left == nullptr) {
    auto rightLL = flattenTree(root->right);
    root->right = rightLL->head->left;
    l->head = root;
    l->tail = rightLL->tail;
    return l;
  }else if (root->right == nullptr) {
    auto leftLL = flattenTree(root->left);
    leftLL->tail->right = root;
    l->head = leftLL->head;
    l->tail = root;
    return l;
  }
  auto leftList = flattenTree(root->left);
  auto rightList = flattenTree(root->right);

  root->left = leftList->tail->right;
  root->right = rightList->head->left;
  l->head = leftList->head;
  l->tail = rightList->tail;
  return l;
  
}
// delete From BST
Node * deleteFromBST(Node * root, int d) {
  if (root ==  nullptr) {
    return nullptr;
  }

  if (root->data > d ) {
    root->left = deleteFromBST(root->left, d);
  } else  if (root->data < d ) {
    root->right = deleteFromBST(root->right, d);
  } else {
    // leaf node case
    if (root->left == nullptr and root->right == nullptr) {
      delete root;
      return nullptr;
    // case 2. only one child
    }  else if (root->left != nullptr and root->right == nullptr) {
      Node * temp  = root->left;
      delete root;
      return temp;
    } else if (root->left == nullptr and root->right != nullptr) {
      Node * temp  = root->right;
      delete root;
      return temp;
    } else {  // both child present
      Node *temp =  findMin(root->right);
      root->data =  temp->data;
      root->right = deleteFromBST(root->right, temp->data);
      return temp;
    }
  }
  return root;
}

// to check if a give tree is bst, 
// In BST left subTree cannot have a node whose value is higher then the root node (all elements in the left subtree are smaller)
// similarly right subTree cannot have a node whose value is lowet then the root node (all elements in the right subtree are greater)
// considering these, we can implement the below function
bool checkIfBST(Node *root, int minValue, int maxValue) {
  if (root == nullptr) {
    return true;
  }
  if (root->data >= minValue  && root->data <= maxValue && 
      checkIfBST(root->left, minValue, root->data) 
      && checkIfBST(root->right, root->data, maxValue) ) {
    return true;
  }
  return false;
}


Node * insertInBST(Node * root, int d) {
  if (root ==  nullptr) {
    return new Node(d);
  }
  if (root->data >= d ) {
    root->left = insertInBST(root->left, d);
  } else {
    root->right = insertInBST(root->right, d);
  }
  return root;
}

Node* build() {
  int d;
  cin >> d;

  Node* root = nullptr;
  while(d != -1) {
    root = insertInBST(root, d);
    cin >> d;
  }
  return root;
}

void BFS (Node* root ) {
  int count = 0;
  int sum = 0;
  bfsQueue.push(root);
  while(!bfsQueue.empty()) {
    count ++;
    Node *temp = bfsQueue.front();
    bfsQueue.pop();
    cout << temp->data << " ";
    sum += temp->data;
    if (temp->left != nullptr)
      bfsQueue.push(temp->left);
    if (temp->right != nullptr)
    bfsQueue.push(temp->right);

  }
  cout <<"count " << count <<endl;
  cout <<"Sum " << sum <<endl;
}

int main () {
	cout << "actual nodes in new lines " << endl;
  Node *root = build();
  BFS(root);
  root = deleteFromBST(root, 4);
  BFS(root);
  LinkedList * l = flattenTree(root);
  cout << "head " <<l->head->data << " tail " << l->tail->data <<endl;
}
