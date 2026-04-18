#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;

	cin >> n;

	vector<pair<int,pair<int,int>>> p;
	p.push_back({1, {1, n}});
	for(int i=1;i<n;i++){
		p.push_back({i+1,{1,n-i}});
		p.push_back({i+1,{n-i+1, n}});
/*		if((n-i)%2){ 
			p.push_back({i+1,{(n-i)/2,(n-i)/2+1}});
		}*/
	}
	cout << p.size() << '\n';
	for(int i =0;i<p.size();i++){
		cout << p[i].first << " " << p[i].second.first << " " << p[i].second.second << '\n';
	}

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
