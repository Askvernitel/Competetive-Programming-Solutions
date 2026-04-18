#include <bits/stdc++.h>

using namespace std;

int main(){
	int n , c;
	cin >> n >> c;
	map<int,int> m, u;
	map<int,int> inds;
	vector<pair<pair<int,int>,int>> v;
	for(int i =0;i<n;i++){
		int num;
		cin >> num;
		if(inds.find(num) == inds.end()){
			inds[num] = i;
		}
		m[num]++;
	}
	for(auto &[c,d]:m) {
		v.push_back({{d,n-inds[c]}, c});
	}
	sort(v.begin(), v.end(), greater<pair<pair<int,int>,int>>());
	for(auto x:v) { 
		for(int i =0;i<x.first.first;i++){
			cout << x.second << " ";
		}
	}
}
