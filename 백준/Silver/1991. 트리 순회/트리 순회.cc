#include <bits/stdc++.h>
using namespace std;

struct node {
	char left;
	char right;
};

vector<node> tree(26);

void preorder(char node) {
	if(node == '.') return;
	cout << node;
	preorder(tree[node].left);
	preorder(tree[node].right);
}

void inorder(char node) {
	if(node == '.') return;
	inorder(tree[node].left);
	cout << node;
	inorder(tree[node].right);
}

void postorder(char node) {
	if(node == '.') return;
	postorder(tree[node].left);
	postorder(tree[node].right);
	cout << node;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, i;
	char parent, left, right;
	
	cin >> N;
	for(i = 0; i < N; i++) {
		cin >> parent >> left >> right;
		tree[parent] = { left, right };
	}
	
	preorder('A'); cout << "\n";
	inorder('A'); cout << "\n";
	postorder('A');
	
	return 0;
}