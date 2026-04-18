#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n, d;
	cin >> n >> d;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];
		
	sort(a, a+n);

	int p1=n-1;
	int ans =0;
	int sum =a[p1];
	for(int i =0;i<p1;i++){
		if(sum > d){
			ans++;
			sum = a[--p1];
			i--;
			continue;
		}
		sum += a[p1];
	}
	if(sum >d) ans++;
	cout << ans << '\n';
}
