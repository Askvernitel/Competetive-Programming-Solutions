#include <bits/stdc++.h>

using namespace std;
	
int main(){
	string s;

	cin >> s;
	int n = s.size();
	s+="###";	
	for(int i =0;i<n-1;i++){
		if(s[i] == 'L' && s[i+1] == 'X' && i-1 >=0 && s[i-1] != 'X'){
			swap(s[i], s[i+1]);
		}
		if(i == 0 && s[i] == 'L' && s[i+1] == 'X' && (s[i+2] != 'X' || s[i+3] == 'I')){
			swap(s[i], s[i+1]);
		}
		if(i+2 < n && s[i] == 'X' && s[i+1] == 'I' && s[i+2] == 'I'){
			swap(s[i], s[i+2]);	
		}
		if(s[i] == 'X' && s[i+1] == 'I'){
			swap(s[i], s[i+1]);	
		}
		if(s[i] == 'V' && s[i+1] == 'I' && s[i+2] != 'I'){
			swap(s[i], s[i+1]);
		}

	}
	for(int i =0;i<3;i++)
	s.pop_back();
	cout << s << '\n';

	

}
