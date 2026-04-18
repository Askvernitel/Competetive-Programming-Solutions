#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int cnt1=0;	
	for(int i =0;i<n;i++){
		if(s[i] == '1') cnt1++;
	}

	if(cnt1 <= k){
		cout << "Alice\n";
		return;
	}

	int p = n/2;

	if(p < k){ 
		cout << "Alice\n";
	}else{
		cout << "Bob\n";
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
