#include <bits/stdc++.h>

using namespace std;
void rec(int x, set<int>& p){ 
	p.insert(x);
	if(x%3 || x == 0){ 
		return;
	}

	rec(x/3, p);
	rec(2*(x/3),p);
}

void solve(){
	int n, m;
	cin >> n >> m;

	set<int> v;

	rec(n, v);
	if(v.find(m) != v.end()){
		cout << "YES\n";
		return;
	}

	cout << "NO\n";
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
