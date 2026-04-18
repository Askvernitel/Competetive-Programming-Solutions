#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];
	int pos =1;	

	int maxv = 0, minv = INT_MAX;
	bool desc = 0;
	for(int i=0;i<n-1;i++){
		if(a[i+1] >a[i] && desc){
			pos = 0;
			break;
		}
		if(a[i+1] < a[i] && !desc){
			desc = 1;
		}
	}
	cout << ((pos)?"YES":"NO") << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
