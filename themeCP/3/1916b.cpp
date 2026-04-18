#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b){ 
	if(b==0) return a;

	return gcd(b, a%b);
}
void solve(){
	int a, b;
	cin >> a >> b; 

	int t = a * b;
	int lcm= t/gcd(a,b);
	if(a < b) swap(a,b);
	if(lcm == a || lcm == b) lcm *= (a/b);
	cout << lcm << '\n';
}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
