#include <iostream>
#include <map>
using namespace std;
typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;

} node;
void storeString(node* root, bool isRight, string &decodedStr) {
    if(root == nullptr)
        return;

    if(isRight) {
        root = root->right;
    } else {
         root = root->left;
    }
    if (root->left == nullptr && root->right == nullptr) {

        decodedStr = decodedStr+root->data;
        cout << "reached leaf" << decodedStr;
    }
}

void decode_huff(node * root, string s) {
    string decodedStr;
    for (char &a: s) {
        cout << "char " << a << endl;
        if(a == '0') {
            storeString(root->left, false, decodedStr);
        } else {
            storeString(root->right, true, decodedStr);
        }
    }

    cout << decodedStr << endl;


}

int main() {

    string s;
    std::cin >> s;

    node * tree = huffman_hidden(s);
    string code = "";
    map<char, string>mp;

/  print_codes_hidden(tree, code, mp);

    string coded;

    for( int i = 0; i < s.length(); i++ ) {
        coded += mp[s[i]];
    }

    decode_huff(tree,coded);

    return 0;
}
