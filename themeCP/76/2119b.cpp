#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int px, py, qx, qy;
	cin >> px >> py >> qx >> qy;
	double a[n+1];
	for(int i=0;i<n;i++){
		cin >> a[i];
		a[i] = a[i];
	}
	
	double dist=sqrt((qx-px)*(qx-px) + (qy-py)*(qy-py));	
	if((n == 1 && a[0] != dist)){ 
		cout << "NO\n";
		return;
	}
	if(n == 1){
		cout << "YES\n";
		return;
	}
	a[n] = dist;
	sort(a, a+n+1, greater<double>());
	double sum = 0;	
	for(int i =1;i<n+1;i++){
		sum+=a[i];
	}
	if(a[0] > sum){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
