#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
	int n;
	cin >> n;
	int b[n];
	for(int i=0;i<n;i++){
		cin >> b[i];
	}
	

	map<int, int> m1, m2;
	int t[n];
	int c = 1;
	int last = 1;
	m1[1] = 0;
	t[0] = last;
	cout << 1 << " ";
	for(int i =1;i<n;i++){
		int d = b[i] - b[i-1];
		if(i-d >= 0 && m1[t[i-d]] == i-d){
			t[i] = t[i-d];
			m1[t[i]]=i;
			cout << t[i] << " ";
		}else{
			last++;
			t[i]=last;
			m1[last]=i;
			cout << last << " ";
		}
	}
	cout << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
