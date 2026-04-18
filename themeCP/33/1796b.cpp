#include <bits/stdc++.h>

using namespace std;
void solve(){
	string a, b;
	cin >> a >> b;
	
	map<string,int> s1, s2;
	for(int i =0;i<(int)a.size()-1;i++){
		string s="";
		s+=a[i];
		s+=a[i+1];
		s1[s]=i;
	}	
	for(int i =0;i<(int)b.size()-1;i++) {
		string s="";
		s+=b[i];
		s+=b[i+1];
		s2[s]=i;
	}	
	if(a[0] == b[0]){ 
		cout << "YES\n";
		cout << a[0]<< "*" << '\n';
		return;
	}
	if(a.back() == b.back()){	
		cout << "YES\n";
		cout << "*"<<a.back()<<'\n';
		return;
	}
	bool pos = 0;
	string ans = "";
	for(auto &[c,d]: s1){
		if(s2.find(c) != s2.end()){ 
			pos =1;
			ans = "*" + c + "*";
			break;
		}
	}
	if(!pos){ 
		cout << "NO\n";
	}else{ 
		cout << "YES\n";
		cout << ans << '\n'; } }
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
