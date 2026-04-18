#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	
	int pos = 1;
	int p = (n*(n+1))/2;
	int sum=0;

	int a1=a[0], a2=a[1];

	int y = (2*a1-a2)/(n+1);
	int x = a1-y*n;
	if(x < 0 || y < 0) pos = 0;
	for(int i =0;i<n;i++){
		if(x*(i+1)+y*(n-i) != a[i]){ 
			pos=0;
			break;
		}
	}
	cout << ((pos)?"YES":"NO") << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
