#include <bits/stdc++.h>

using namespace std;
int a[100001];

void solve(){
	int n; cin >> n;
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int cnt = 0;
	int p = 2;
	set<int> s;
	int maxv = 0;
	for(int i =0;i<n;i++){
		int l = -1, r=i+1;

		while(r - l > 1){ 
			int m = (l+r)/2;
			if(a[m] >= i-m+1){ 
				r = m;
			}else{
				l = m;
			}
		}

		cout << i-r+1 << ' ';
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
