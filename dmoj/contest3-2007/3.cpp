#include <bits/stdc++.h>

using namespace std;


int main(){
	string s;

	cin >> s;


	int n = s.size();

	int p = 1;
	for(int i = sqrt(n) + 1; i>=2; i--){
		if(!(n%i)){
			p = i;
			break;
		}
	}
	p = min(n/p, p);
	for(int i =0;i<p;i++){
		for(int j = i; j<n;j+=p){
			cout << s[j];
		}
	}

}
