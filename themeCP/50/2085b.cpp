#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	set<int> s;
	for(int i =0;i<n;i++){
		if(a[i] == 0) s.insert(i);
	}
	int p = *s.begin();
	p++;
	if(s.size() == 0){ 
		cout << 1 << "\n";
		cout << 1 << " " << n << '\n';
	}else if(s.size() == 1){
		cout << 2 << '\n';
		if(p == 1){ 
			cout << p << " " << p+1 << '\n';
			cout << p << " " << n-1 << '\n';
		}else if(p == n){ 
			cout << p-1 << " " << p << '\n';
			cout << 1 << " " << n-1 << '\n';
	 	}else{ 
			cout << p << " " << n << '\n';
			cout << 1 << " " << n-(n-p) << '\n';
		}
	}else{ 
		int c = *s.rbegin();
		c++;
		if(p == 1){ 
			if(c == n){
				cout << 3 << '\n';
				cout << p << " " << c-2 << '\n';
				cout << n-(c-2-p)-1 <<" " <<  n-(c-2-p) << '\n';
				cout << 1 << " " << 2 << '\n';
				return;
			}
			cout << 2 << '\n';
			cout << p << " " << c << '\n';
			cout << 1 << " " << (n-(c-p)) << '\n';
		}else if(c == n){
			cout << 2 << '\n';
			cout << p << " " << c << '\n';
			cout << 1 << " " << (n-(c-p)) << '\n';
		}else{
			cout << 2 << '\n';
			cout << p << " " << c << '\n';
			cout << 1 << " " << (n-(c-p)) << '\n';
		}
	}
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
