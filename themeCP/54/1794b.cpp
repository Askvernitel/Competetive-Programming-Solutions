#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	for(int i =0;i<n-1;i++){
		if(a[i] == 1){ 
			a[i]++;
		}
		if(a[i+1]%a[i] == 0){
			a[i+1]++;
		}
	}
	for(int i =0;i<n-1;i++){
		if(a[i] == 1){ 
			a[i]++;
		}
		if(a[i+1]%a[i] == 0){
			a[i+1]++;
		}
	}
	for(int i =0;i<n;i++){
		cout << a[i] << ' ';
	}
	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
