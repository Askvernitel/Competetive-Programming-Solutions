#include <bits/stdc++.h>

using namespace std;

int mlog(int x, int div){
	int res=0;
	while(x > 1){
		x/=div;
		res++;
	}
	return res;	
}
void f(int& x, int& y, int& ind1, int& ind2){
	if(x < y){
		swap(x, y);
		swap(ind1,ind2);
	}	
	x=(x%y)?x/y+1:x/y;
}

void solve(){
	int n;
	cin >> n;
	int a[n];
	vector<pair<int,int>> vec;
	int ind1 = 0, ind2 =0;
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	for(int i =0;i<n;i++){
		if(a[ind1] != a[i]){ 
			ind2 = i;
			break;
		}
	}
	int prev = a[0];
	int eq = 1, pos = 1;
	for(int i =1;i<n;i++){
		if(prev != a[i]){
			eq = 0;
		}
		if(prev == 1 || a[i] == 1){
			pos=0;
		}
	}
	if(eq){ 
		cout << 0 << '\n';
		return;
	}
	if(!pos){
		cout << -1 << '\n';
		return;
	}
	
	for(int i =0;i<n;i++){
		int p1 = a[i];
		for(int j = i;j<n;j++){
			int p2 = a[j];
			int ind1=i, ind2 = j;
			while(p1!=p2 && (p1 != 2 || p2 !=2)){
				f(p1,p2, ind1, ind2);
				vec.push_back({ind1+1,ind2+1});
				a[ind1] = p1;
				a[ind2] =p2;
			}
		}
	}
/*	for(int i =0;i<n;i++){
		if(i == ind1 || i == ind2) continue;
		for(int j =0;j<mlog(a[i], 2)-1;j++){
			vec.push_back({i, ind1});
		}
	}*/
	cout << vec.size() << endl;
	for(int i =0;i<vec.size();i++){
		cout << vec[i].first << " " << vec[i].second << endl;
	}
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
