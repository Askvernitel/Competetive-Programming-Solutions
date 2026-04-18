#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
int n;
pair<int,int> a[200001];
bool f(int x){ 
	int l=0, r = 0;
	
	for(int i =0;i<n;i++){
		int maxr = r+x;
		int minl = l-x;
		if(maxr < a[i].F || minl > a[i].S){ 
			return false;
		}
		l=max(a[i].F, minl);
		r=min(a[i].S, maxr);
	}
	return true;
}
void solve(){
	cin >> n;	
	for(int i = 0;i<n;i++){
		cin >> a[i].F >> a[i].S;
	}
	

	int l =-1,r=1e9;

	while(r-l>1){
		int m = (l+r)/2;
		if(f(m)){ 
			r=m;
		}else{ 
			l=m;
		}
	}
	cout << r << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
