#include <bits/stdc++.h>
using namespace std;

struct binarySearch_tree {
	int key;
	binarySearch_tree* left;
	binarySearch_tree* right;
};

binarySearch_tree* createNode(int val) {
	binarySearch_tree* newNode = new binarySearch_tree;
	newNode->key = val;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void insert(binarySearch_tree* root, int val) {
	binarySearch_tree* node = root;
	if(node == NULL) {
		node = createNode(val);
		return;
	}
	while(true) {
		if(val < node->key) {
			if(node->left == NULL) {
				node->left = createNode(val);
				break;
			} else node = node->left;
		} else {
			if(node->right == NULL) {
				node->right = createNode(val);
				break;
			} else node = node->right;
		}
	}
}

void postorder(binarySearch_tree *node) {
	if(node->left != NULL) postorder(node->left);
	if(node->right != NULL) postorder(node->right);
	cout << node->key << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int num;
	cin >> num;
	binarySearch_tree* tree = createNode(num);
	
	while(true) {
		cin >> num;
		if(cin.eof()) break;
		insert(tree, num);
	}
	
	postorder(tree);
	
	return 0;
}