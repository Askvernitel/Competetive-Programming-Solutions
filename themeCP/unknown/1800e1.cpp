#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n,k;
	cin >> n >> k;
	string s, t;

	cin >> s >> t;
	if(n<=3 && s != t){ 
		cout << "NO\n";
		return;
	}else if(n == 4 && (s[1] != t[1] || s[2] != t[2])){
		cout << "NO\n";
		return;
	}else if(n == 5 && s[2] != t[2]){
		cout << "NO\n";
		return;
	}
	int arr[26];
	memset(arr,0,sizeof(arr));
	for(int i =0;i<n;i++) arr[s[i]-'a']++;
	
	for(int i =0;i<n;i++){
		arr[t[i]-'a']--;
	}
	bool pos = 1;
	for(int i =0;i<26;i++){
		if(arr[i] != 0){pos=0;break;}
	}
	if(pos){ 
		cout << "YES\n";
	}else{ 
		cout << "NO\n";
	}
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
