#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	map<int,int> m;
	int a[n];
	set<int> s;
	for(int i =0;i<n;i++){
		cin >> a[i];
		m[a[i]]++;
	}
	vector<int> v;
	for(auto &[c,d]:m){ 
		if(d > 2 && c != 0){ 
			cout << "NO\n";
			return;
		}
		for(int i =0;i<min(2,d);i++){
			v.push_back(c);
		}
	}
	if(m.size() > 4 ){ 
		cout << "NO\n";
		return;
	}
	int p = v.size();
	for(int i =0;i<p;i++){
		for(int j =i+1;j<p;j++){
			for(int t=j+1;t<p;t++){
				if(m.find(v[i]+v[j]+v[t]) == m.end()){
					cout << "NO\n";
					return;
				}
			}
		}
	}

	cout << "YES\n";


}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
