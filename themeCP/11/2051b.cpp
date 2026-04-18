#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n, a, b, c;
	cin >> n >> a >> b >> c;

	int k = a+b+c;


	int days = (n/k)*3;

	int left = n%k;
		
	if(left > 0){days ++; left-=a;}
	if(left > 0){days ++; left-=b;}
	if(left > 0){days ++; left-=c;}
	cout << days << '\n';	
}

int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
