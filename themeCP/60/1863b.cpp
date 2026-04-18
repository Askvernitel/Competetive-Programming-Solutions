#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int p[n];
	for(int i =0;i<n;i++){
		cin >> p[i];
	}
	map<int,int> m;
	for(int i =0;i<n;i++){
		if(m.find(p[i]-1) != m.end()){
			m[p[i]]=m[p[i]-1]+1;
			m.erase(p[i]-1);
		}else{ 
			m[p[i]] = 1;
		}
	}
	cout << m.size()-1 << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
