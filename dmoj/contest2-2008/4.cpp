#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main(){
	int t;
	cin >> t;

	int n,m;
	cin >> n;
	pair<int,int> t1[n];
	for(int i =0;i<n;i++) cin >> t1[i].first >> t1[i].second; 
	cin >> m;
	pair<int,int> t2[m];
	for(int i = 0;i<m;i++) cin >> t2[i].first >> t2[i].second;

	int l =1, r = t;
	
	function<int(int, bool)> calc = [&](int time, bool type){
		int res = 0;
		if(type){
			for(int i =0;i<n;i++){
				if(time >=t1[i].first){
					res+=1+((time-t1[i].first)/(t1[i].second) );
				}
			}
		}else{
			for(int i =0;i<m;i++){
				if(time >=t2[i].first){
					res+=1+((time-t2[i].first)/(t2[i].second) );
				}

			}
		}
		return res;
	};

	while(l < r){ 
		int mid = l + (r-l)/2;
		int f = calc(mid, 1), s = calc(t-mid-1, 0);
		if(f >= s){
			r = mid;
		}else{
			l = mid + 1;	
		}
	}
	cout << r << '\n';
}
