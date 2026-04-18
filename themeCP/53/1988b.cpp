#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;

	cin >> n;

	char a[n+1];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	a[n]=1;
	int cnt =0;
	int p = 0;
	for(int i =0;i<n;i++){
		if(a[i] == '1'){
			cnt++;
		}
		if(a[i] == '0' && a[i] != a[i+1]){
			p++;
		}
	}
	if(p >= cnt){ 
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
