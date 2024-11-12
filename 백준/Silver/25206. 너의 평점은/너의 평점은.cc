#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	double credit, sumCredit, sumGrade;
	string name, grade;
	map<string,double> point = {
		{"A+", 4.5}, {"A0", 4.0},
		{"B+", 3.5}, {"B0", 3.0},
		{"C+", 2.5}, {"C0", 2.0},
		{"D+", 1.5}, {"D0", 1.0},
		{"F", 0}
	};
	for(int i = 0; i < 20; i++) {
		cin >> name >> credit >> grade;
		if(grade[0] == 'P') continue;
		sumCredit += credit;
		sumGrade += credit * point[grade];
	}
	cout << sumGrade / sumCredit;
	
	return 0;
}