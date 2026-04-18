#include <bits/stdc++.h>
using namespace std;

int main(){
	int w, l, n;
	cin >> w >> l >> n;
	set<pair<vector<int>,vector<int>>> ss;
	for(int i =0;i<n;i++){
		vector<int> h;
		vector<int> dif;
		int a[l];
		for(int j=0;j<l;j++){
			cin >> a[j];
		}

		for(int j=0;j<l;j++){
			int num;
			cin >> num;
			h.push_back(w+1-a[j]-num);
		}
		vector<int> v1 = h;
		reverse(h.begin(),h.end());
		if((ss.find({v1, h}) != ss.end()) || (ss.find({h,v1}) != ss.end())){

		}else{
			ss.insert({h,v1});
		}
	}
	cout << ss.size(); 
}
