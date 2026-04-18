#include <bits/stdc++.h>
#define F first
#define S second
#define int long long
using namespace std;
int f(int x){ 
	int res = 0;
	while(x != 0){ 
		x/=10;
		res++;
	}
	return res;
}
void solve(){
	int n;

	cin >> n;
	int a[n], b[n];
	priority_queue<int> pq;
	multiset<int> ma, mb;
	int ans=0;
	for(int i =0;i<n;i++){
		cin >> a[i];
		ma.insert(a[i]);
		pq.push(a[i]);
	}
	for(int i=0;i<n;i++){
		cin >> b[i];
		mb.insert(b[i]);
		pq.push(b[i]);
	}	
	while(!pq.empty()){
		int t = pq.top();

		if(ma.find(t) != ma.end() && mb.find(t) !=mb.end()){
			pq.pop();
			ma.erase(ma.find(t));
			mb.erase(mb.find(t));
		}else{
			ans++;
			if(ma.find(t) != ma.end()){
				ma.erase(ma.find(t));
				ma.insert(f(t));
			}else if(mb.find(t) != mb.end()){
				mb.erase(mb.find(t));
				mb.insert(f(t));
			}
			
			pq.push(f(t));
		}
		pq.pop();
	}

	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
