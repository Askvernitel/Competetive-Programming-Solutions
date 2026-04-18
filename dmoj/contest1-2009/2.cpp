#include <bits/stdc++.h>

using namespace std;
int main(){
	int n;
	cin >> n;
	int ans = 0;
	for(int i =0;i<=n;i++){
		ans += i*(n+1);	
	}
	cout << ans +(((n+1)*n)/2);
}
