#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int n =s.size();
	cout << s[0];

	for(int i = 1;i<n;i++){
		if(s[i] == '-') cout << s[i+1];
	}

}
