#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	
	set<int> prev;
	set<int> cur;
	set<int> nw;
	int b = 0;
	for(int i =0;i<n;i++){
		if(prev.size() == 0){
			prev.insert(a[i]);
			b++;
			continue;
		}
		if(prev.find(a[i]) != prev.end()){
			cur.insert(a[i]);
		}else{
			nw.insert(a[i]);
		}
		if(cur.size() == prev.size()){
			for(int x:nw){
				prev.insert(x);
			}
			b++;
			cur = {};
		}
	}

	cout << b << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
