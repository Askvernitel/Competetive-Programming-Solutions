#include <bits/stdc++.h>

using namespace std;
int a[100001];
int n;

void solve(){
	cin >> n;
	for(int i =0;i<n;i++){
		cin >> a[i];	
	}
	int times[n];
	times[n-1] = a[n-1];
	for(int i = n-2;i >=0;i--){
		times[i] = max(times[i+1] + 1, a[i]);
	}
/*	for(int i =0;i<n;i++){
		cout << times[i] << " ";
	}*/
	cout << times[0] << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
