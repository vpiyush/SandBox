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

Node * head = nullptr;
std::queue<Node*> bfsQueue;
Node* buildTree(vector<int> nodes, int index) {
	if(nodes[index]==-1) {
		return nullptr;
	}
  cout <<  "index " << index << "building node " << nodes[index] << endl;
	Node *root = new Node(nodes[index]);
	root->left = buildTree(nodes, 2*index +1);
	root->right = buildTree( nodes, 2*index+2);
	return root;
}

void printInOrder(Node* root) {
    if(root == nullptr) {
        return;
    }
    cout << root->data << " ";
    printInOrder(root->left);
    printInOrder(root->right);
}
void printEdge(Node * root, bool right) {

    if(right) {
        cout << root->data << " ";
        if(root->right == nullptr)
            return;
        printEdge(root->right, true);
    } else {
        if(root->left == nullptr)
            return;
        printEdge(root->left, false);
        cout << root->data << " ";
    }
}

void topView(Node * root) {
    if(root == nullptr)
        return;
    if(root->left != nullptr)
        printEdge(root->left, false);
    cout << root->data << " ";
    if(root->right != nullptr)
        printEdge(root->right, true);
}

int height(Node *root) {
  // root null
  //   return  0
  //   height would be max of hight of left subTree and right subtree + 1 ()

  if (root == nullptr) {
    return 0;
  }
  int h = max(height(root->left), height(root->right)) + 1;
  return h;
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

// traverse in level order fashion,
// on entering the each level print the first node encountered 
// maintain the level which is traversed already
//
void printRightView(Node *root, int level, int &maxlevel) {
  if (root == nullptr) {
    return;
  }
  if (maxlevel < level) {
    cout << root->data << endl;
    maxlevel = level;
  }
  // first go to right
  printRightView(root->right, level+1, maxlevel );
  printRightView(root->left, level+1, maxlevel );
}

void printVerticalOrder(Node *root, bool isRight) {
    if (root == nullptr) {
        return;
    }
    if(isRight) {
        printVerticalOrder(root->left, false);
        cout << root->data <<  " ";
        if (root->right != nullptr) {
            cout << root->data <<  " ";
        }
    } else {
    }

}

// to find lca
// starting from root, check if one of the node present in left or right subtree
// if a node is found, check the other node in the right subtree of the node, if it is found
// its an lca otherwise repeat the process
Node* lca(Node* root, int n1, int n2) {
  if (root == nullptr) {
    return nullptr;
  }

  if  (root->data == n1 or root->data == n2) {
    return root;
  }
  Node* leftNode = lca(root->left, n1, n2);
  if (leftNode != nullptr) {
    Node* rightNode = lca(root->right, n1, n2);
    if (rightNode != nullptr ) {
      return root;
    }
  }

  Node* rightNode = lca(root->right, n1, n2);
  if (rightNode != nullptr ) {
    Node* leftNode = lca(root->left, n1, n2);
    if (leftNode != nullptr) {
      return root;
    }
  }
  return nullptr;
}


class Pair {
  public:
    int height;
    int diameter;
};

Pair fastDiameter (Node *root) {
  Pair p;
  if (root == nullptr)  {
    p.height = p.diameter = 0;
    return p;
  }
  Pair left= fastDiameter(root->left);
  Pair  right= fastDiameter(root->right);
  p.height = max(left.height, right.height) + 1;
  p.diameter = max(left.height+right.height, max(left.diameter, right.diameter));
  return p;
}

int replaceSum(Node * root) {
  if (root == nullptr) {
    return 0;
  }
  if (root->left == nullptr && root->right == nullptr) {
    return root->data;
  }

  int left = replaceSum(root->left);
  int right = replaceSum(root->right);
  int temp = root->data;
  root->data = left + right;
  return temp + root->data;
}

// longest path in a tree
int Diameter(Node * root) {
  
  if (root == nullptr) 
    return 0;

  int h1 = height(root->left); 
  int h2 = height(root->right);
  int cd = h1 + h2;
  int ld = Diameter(root->left);
  int rd = Diameter(root->right);

  return max(cd, max(ld, rd));
}

// get Node level
int getNodeLevel(Node *root, int key, int level) {
  if(root == nullptr) {
    return -1;
  }
  if(root->data == key) {
    return level;
  }
  int level1 = getNodeLevel(root->left, key, level +1);
  int level2 = getNodeLevel(root->right, key, level +1);
  if(level1 != -1 or level2 != -1) {
    return level;
  }
  return -1;
}

int main () {
	cout << "actual nodes space separated" << endl;
	std::string rawInput;
	vector<int> numbers;

	/*while(1)
	{
    int d;
    cin>>d;
		if (d == -2) {
			break;
		}
		numbers.push_back(d);
	}
    cout << "pushing done" << endl;
	Node *root = buildTree(numbers, 0);
  */
 Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
/*    
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
root->left->right->left->left = new Node(7);
    root->left->right->left->left->left = new Node(8);
    */
    
    
    cout << "build done" << endl;
//	printInOrder(root);
  cout << endl;
  cout << "height "<< height(root) << endl;
  BFS(root);
  //cout << "diameter " << Diameter(root) << endl;
  auto p = fastDiameter(root);
  cout << "diameter " << p.diameter << endl;
 // replaceSum(root);
  //BFS(root);
  int maxlevel = -1;
  // maxlevel -1 and level 0
  printRightView(root, 0, maxlevel);
  Node* temp = lca(root, 2, 3);
  cout << "lca " << temp->data << endl;
//	topView(root);
}
