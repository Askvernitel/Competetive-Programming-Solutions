#include <bits/stdc++.h>


using namespace std;
map<int,int> m, d;
map<int,vector<int>> q;
int T(int a, int i){ 
	m[a]++;
	q[a].push_back(i);
	
	if(m[a]>=a){ 
		int ind = m[a]-a;
		int p = q[a][ind];
		return p;
	}
	return -1;
}

void solve(){
	int n;
	cin >> n;
	m.clear();
	d.clear();
	q.clear();
	int a[n];
	int f[n+1];
	f[0] = 0;
	for(int i =0;i<n;i++){
		cin >> a[i];
	}

	for(int i =1;i<=n;i++){
		int ind = T(a[i-1], i-1);

		if(ind == -1){ 
			f[i]=f[i-1];
		}else{
			f[i]=max(f[i-1], f[ind] + a[i-1]);
		}
	}
	cout << f[n] << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();


}
