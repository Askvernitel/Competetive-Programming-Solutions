#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;

	string s1, s2;
	cin >> s1 >> s2;
	int cnt1 = 0, cnt2 =0;
	for(int i =0;i<n;i++){
		if(s1[i] != s2[i]){ 
			cnt1++;
		}
		if(s1[i] != s2[n-i-1]){
			cnt2++;
		}
	}
	int u = (cnt1%2 || cnt1 == n)?(2*cnt1 -1):2*cnt1;

	int p = (cnt2%2)?2*cnt2:2*cnt2-1;
	
	if(cnt2 <= 1) p=2;

	cout << max(0,min(p, u)) << '\n';
}

int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}

