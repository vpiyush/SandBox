#include<iostream>
#include<vector>
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
Node* buildTree(vector<int> nodes, int index) {
	if(nodes[index]==-1) {
		return nullptr;
	}
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
    if (root == nullptr)
        return;

    if(right) {
        cout << root->data << " ";
        printEdge(root->right, true);
    } else {
        printEdge(root->left, false);
        cout << root->data << " ";
    }
}

void topView(Node * root) {
    if (root == nullptr)
        return;
    printEdge(root->left, false);
    cout << root->data << " ";
    printEdge(root->right, true);


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

int main () {
	cout << "actual nodes space separated" << endl;
	std::string rawInput;
	vector<int> numbers;
	while( getline( cin, rawInput, ' ' ))
	{
		cout << "pushing number"  << rawInput <<endl;
		if (atoi(rawInput.c_str()) == -2) {
			break;
		}
		numbers.push_back(atoi(rawInput.c_str()));
	}
    cout << "pushing done" << endl;
	Node *root = buildTree(numbers, 0);
	printInOrder(root);
	cout << endl;
	topView(root);
}
