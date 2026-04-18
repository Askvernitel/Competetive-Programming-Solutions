#include <bits/stdc++.h>

using namespace std;

int n, m;
map<int,int> u, t, c;
int f(int z){
	if(u[z] == 0 || z <= 0){
		return -1;
	}
	int l = z-1;
	int r = z+1;
	int cnt = 1;
	while(l > 0 || r <=m){ 
		if(l > 0){
			if(u[l]){
				cnt++;
			}else if(u[-1] > 0){
				cnt++;
				u[-1]--;
			}
		}
		if(r <= m){ 
			if(u[r]){
				cnt++;
			}else if(u[-2] > 0){
				cnt++;
				u[-2]--;
			}
		}
		l--;
		r++;
	}
	u = c;
	return cnt;
}
void solve(){
	cin >> n >> m;
	int a[n];
	u={}; t ={}; c={};
	for(int i =0;i<n;i++){
		cin >> a[i];
		u[a[i]]++;
		t[a[i]]++;
		c[a[i]]++;
	}
	int k = m/2;
	int dif = m, x = 0, idx = -1;	

	for(int i =0;i<n;i++){
		if(a[i]<0) continue;
		int p = abs(a[i]-k);
		if(dif > p){ 
			dif=p;
			x = a[i];
			idx = i;
		}
	}
	int cnt =0;
	int ans =max(min(u[-1], m), min(u[-2], m));
	if(idx == -1){
		cout << ans << '\n';
		return; 
	}
	ans = max({f(k+1), f(k-1),f(k), f(x), f(k+2), f(k-2)});

	cnt = 0;
	int l = 1;
	while(l <= m){
		if(c[l]){
			cnt++;
		}else if (c[-2] > 0){
			cnt++;
			c[-2]--;
		}
		l++;
	}
	ans = max(ans,cnt);
	cnt = 0;
	int r=m;
	while(r >= 1){
		if(t[r]){
			cnt++;
		}else if(t[-1] > 0){
			cnt++;
			t[-1]--;
		}
		r--;
	}
	ans = max(ans, cnt);

	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
