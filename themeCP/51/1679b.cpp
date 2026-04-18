#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n, q;
	cin >> n >> q;

	int a[n];	
	int sum =0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	
	int p[n];
	memset(p,0,sizeof(p));
	bool pl=0;
	int prev = -1;
	vector<int> v={};
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int idx, x;
			cin >> idx >> x;
			idx--;
			if(pl){ 
				if(p[idx]){
					sum = sum+x-a[idx];
					cout << sum << '\n';
				}else{
					p[idx]=1;
					v.push_back(idx);
					sum = sum+x-prev;
					cout << sum <<'\n';
				}
			}else{
				sum = sum+x-a[idx];
				cout << sum << '\n';
			}
			a[idx]=x;
		}else{
			int x;
			cin >> x;
			pl=1;
			prev =x;
			for(int i =0;i<v.size();i++) p[v[i]]=0;
			v={};
			sum = x*n;
			cout <<sum << '\n';
		}

	}
}
