#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i= 0;i<n;i++){
		cin >> a[i];
	}
	int minv = INT_MAX ;	
	for(int i =0;i<n-1;i++){
		int v = a[i+1]-a[i];
		if(v < 0){minv = 0; break;}
		minv = min((v)/2 + 1,minv);
	}
	cout << minv << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
