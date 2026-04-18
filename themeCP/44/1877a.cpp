#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n-1];
	for(int i =0;i<n-1;i++) cin >> a[i];

	int sum1 = 0, sum2=0;

	for(int i = 0;i<n-1;i++){
		if(a[i] < 0)sum2+=a[i] ;
		else sum1+=a[i];
	}

	cout << -(sum1 - abs(sum2)) << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
