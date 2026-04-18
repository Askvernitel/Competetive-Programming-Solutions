#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b){ 
	if(a == 0) return b;
	return gcd(b % a, a);
}
void solve(){
	int n;
	cin >> n;
	
	int p[n], s[n];
	for(int i =0;i<n;i++){
		cin >> p[i];
	}
	for(int i =0;i<n;i++){
		cin >> s[i];
	}

	if(p[n-1] != s[0]){ 
		cout << "NO\n";
		return;
	}

	int f = p[n-1];

	for(int i =0;i<n-1;i++){
		if(gcd(p[i],s[i+1]) != f){
			cout << "NO\n";
			return;
		}
		if(p[i]%p[i+1] != 0){ 

			cout << "NO\n";
			return;
		}
	}

	for(int i =n-1;i>0;i--){
		if(s[i]%s[i-1] != 0){ 
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
