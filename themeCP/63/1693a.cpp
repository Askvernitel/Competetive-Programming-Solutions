#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >>n;
	int a[n];
	int arr[n];
	int d[n];
	memset(arr, 0, sizeof(arr));
	for(int i =0;i<n;i++){
		cin >> a[i];
		if(i == 0) d[i] = a[i];
		else d[i] = a[i]+1;
	}
	int j = n-1;
	while(a[j] == 0){j--;}
		
	for(int i =0;i<j;i++){
		if(d[i] <= arr[i]){
			cout << "NO\n";
			return;
		}
		int p = d[i]-arr[i];
		arr[i] = d[i];
		arr[i+1]-=(p-1);
	}
	for(int i =0;i<=j;i++){
		if(d[i] != arr[i]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
