#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	set<int> x,y;
	int ax[n+1],ay[n+1];
	memset(ax, 0, sizeof(ax));
	memset(ay, 0, sizeof(ay));
	for(int i = 1;i<=n;i++){
		x.insert(i);
		y.insert(i);
	}
	while(q--){
		int t;
		cin >> t;
		int x1, x2, y1, y2;
		if(t == 1){
			cin >> x1 >> y1;
			int p1 = ax[x1]++;
			int p2 = ay[y1]++;
			if(p1 == 0) x.erase(x1);
			if(p2 == 0) y.erase(y1);
		}else if(t == 2){
			cin >> x1 >> y1;
			int p1 =--ax[x1];
			int p2 =--ay[y1];
			if(p1 == 0) x.insert(x1);
			if(p2 == 0) y.insert(y1);
		}else{
			cin >> x1 >> y1 >> x2 >> y2;
			auto it1 = x.lower_bound(x1);
			auto it2 = y.lower_bound(y1);
			if(it1 == x.end() || it2 == y.end()){
				cout << "YES" << endl;
				continue;
			}
			if( *it1 > x2 || *it2 > y2 ){ 

				cout << "YES" << endl;
			}else {
				cout << "NO" << endl;
			}
		}
	}
}
