#include <bits/stdc++.h>


using namespace std;
void solve(){
	int n;
	cin >> n;
	map<int,int> sp;
	vector<int> v[n];
	for(int i =0;i<n;i++){
		int k;
		cin >> k;
		for(int j=0;j<k;j++){
			int p;
			cin >> p;
			v[i].push_back(p);
			sp[p]++;
		}
	}
	for(int i =0;i<n;i++){
		int fnd=1;
		for(int j=0;j<v[i].size();j++){
			sp[v[i][j]]--;
			if(sp[v[i][j]] == 0){
				fnd=0;
				break;
			}
			sp[v[i][j]]++;
		}
		if(fnd){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
