#include <bits/stdc++.h>

using namespace std;
void solve(){
	string s;
	cin >> s;
	int n =s.size();
	int a[26];
	int skip[26];
	memset(a, 0, sizeof(a));
	memset(skip, 0, sizeof(skip));
	int p;
	cin >> p;
	int cur = 0;	
	for(int i =0;i<n;i++){
		a[s[i]-'a']++;
		cur+=s[i]-'a'+1;
	}
	int j = 25;
	while(cur > p){
		while(a[j] == 0 && j > 0) j--;
		a[j]--;	
		cur-=(j+1);
		skip[j]++;
	}
	for(int i =0;i<n;i++){
		if(skip[s[i]-'a'] > 0){skip[s[i]-'a']--; continue;}
		cout << s[i];
	}
	cout << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
} 
