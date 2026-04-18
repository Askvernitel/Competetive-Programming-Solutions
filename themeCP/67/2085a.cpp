#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;

	cin >> n >> k;

	string s;
	cin >> s;
	string t = s;

	bool f = 0;
	int ind  =0;
	int u = 0;
	for(int i =0;i<n;i++){
		if(s[i] != s[i+1]){u=1;break;}
	}
		
	if(!u){
		cout << "NO\n";
		return;
	}
	int p1=0,p2=n-1;
	while(p1<p2 && s[p1] == s[p2]){
		for(int i = p1+1;i<=p2-1;i++){
			if(s[i] != s[p1] || s[i] != s[p2]){
				f=1;
				break;
			}
		}
		p1++;
		p2--;
	}
	if(s[p1] < s[p2] ){ 
		cout << "YES\n";
		return;
	}
	if(s[p1] > s[p2] && k>=1){
		cout << "YES\n";
		return;
	}
	if(f && k >= 1){ 
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
