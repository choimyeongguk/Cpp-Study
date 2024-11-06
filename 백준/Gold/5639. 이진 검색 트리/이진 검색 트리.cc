#include <bits/stdc++.h>
using namespace std;

class binarySearch_tree {
	public:
		int key;
		binarySearch_tree *left;
		binarySearch_tree *right;
	
	binarySearch_tree(int val) {
		key = val;
		left = NULL;
		right = NULL;
	}
	
	void insert(int val, binarySearch_tree *node) {
		if(val < node->key) {
			if(node->left == NULL) {
				node->left = new binarySearch_tree(val);
			} else {
				insert(val, node->left);
			}
		} else {
			if(node->right == NULL) {
				node->right = new binarySearch_tree(val);
			} else {
				insert(val, node->right);
			}
		}
	}
};

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
	binarySearch_tree tree = binarySearch_tree(num);
	
	while(true) {
		cin >> num;
		if(cin.eof()) break;
		tree.insert(num, &tree);
	}
	
	postorder(&tree);
	
	return 0;
}