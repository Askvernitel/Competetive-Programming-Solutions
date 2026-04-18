#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	int a[n];
	int cnt = 0;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i] != 0){
			v.push_back(i);
			cnt++;
		}
	}
	if(cnt%2){
		cout << -1 << '\n';
		return;
	}
	vector<pair<int,int>> p;
	int mark[n];
	memset(mark,0,sizeof(mark));
	for(int i =0;i<(int)v.size() -1;i++){
		mark[v[i]] = 1;
		mark[v[i+1]] = 1;
		if(a[v[i]] == a[v[i+1]]){
			if(v[i]+1 != v[i+1]){
				p.push_back({v[i],v[i]});
				p.push_back({v[i+1]-1,v[i+1]});
				mark[v[i+1]-1] = 1;
			}else{
				p.push_back({v[i],v[i+1]});
			}
		}else{
			p.push_back({v[i],v[i]});
			p.push_back({v[i+1],v[i+1]});
		}
		i++;
	}
	for(int i= 0;i<n;i++){
		if(!mark[i]){
			p.push_back({i,i});
		}
	}
	sort(p.begin(),p.end());
	cout << p.size() << '\n';
	for(int i =0;i<p.size();i++){
		cout << p[i].first+1 << " " << p[i].second+1<< '\n';
	}
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
