#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];

	int maxv = 0;
	for(int i =0;i<n;i++){ 
		cin >> a[i];
		maxv = max(a[i],maxv);
	}

	
	sort(a, a+n);
	for(int i =0;i<n;i++){

	}



}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
