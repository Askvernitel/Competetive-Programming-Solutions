#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];
	map<int,int> m;
	for(int i =0;i<n;i++){
		cin >> a[i];	
		m[a[i]]++;
	}

	if(a[0] == a[n-1]){
		if(m[a[0]] <k){
			cout << "NO\n";
		}else{
			cout << "YES\n";
		}
	}else{
		map<int,int> u;
		int idx = 0;
		for(int i =0;i<n;i++){
			if(u[a[0]] >= k){ idx=i; break;}
			if(a[0] == a[i]) u[a[i]]++;

		}

		for(int i = idx;i<n;i++){
			if(a[n-1] == a[i]){
				u[a[i]]++;
			}
		}
		if(u[a[0]] >= k && u[a[n-1]] >= k){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
