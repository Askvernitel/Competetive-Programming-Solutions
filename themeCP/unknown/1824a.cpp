#include <bits/stdc++.h>

using namespace std;

void solve(){ 
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int p = 0;
	int c1=0,c2=0,c3=0;
	set<int> v;
	for(int i=0;i<n;i++){
		if(a[i] == -1) c1++;
		else if(a[i] == -2) c2++;
		else{ v.insert(a[i]); c3++;}
		//p = max(abs(a[i]),abs(m-a[i]));
	}
	int l=0;
	int ans =0;
	for(int x:v){
		int p1 = x-1;
		int left=l, right=0;
		left=min(p1, c1+left);
		right=min(m-x, c2+((int)v.size()-l-1));
		//cout << left << " " << right << '\n';
		ans=max(ans,right+left+1);
		l++;
	}
	cout << min(max({ans,(int)v.size()+c1,(int)v.size()+c2}),m) << '\n';
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
