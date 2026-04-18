#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];	
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int last = 0;
	int pos = 1;
	int start = 0;
	if(n%2) {
		last = a[0];
		start = 1;
	}
	for(int i = start;i<n-1;i++){
		if(!((n-i)%2)){
			if(last > a[i] || last > a[i+1]){
				pos =0;
				break;
			}
			last = max(a[i], a[i+1]);
		}
	}
	cout << ((pos)? "YES": "NO") << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
