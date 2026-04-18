#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int pos = 0;
	int idx = -1;
	for(int i =0;i<n;i++){
		int v = a[i];
		int maxv = INT_MIN, minv = INT_MAX;
		for(int j = 0;j<n;j++){
			if(j == i) continue;
			maxv = max(a[j], maxv);
			minv = min(a[j], minv);
		}
		if(maxv-minv != 0){
			pos =1;
			idx=i;
			break;
		}
	}

	if(!pos) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for(int i =0;i<n;i++){
		if(idx == i) cout <<"B";
		else cout << "R";
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
