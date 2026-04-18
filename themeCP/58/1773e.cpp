#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> s;
	int nsum=0;
	vector<int> vec;
	for(int i =0;i<n;i++){
		int k;
		cin >> k;
		nsum+=k;
		vector<int> v(k);
		for(int i=0;i<k;i++){
			cin >> v[i];
			vec.push_back(v[i]);
		}
		reverse(v.begin(), v.end());
		s.push_back(v);
	}
	sort(vec.begin(), vec.end(), greater<int>());
	vector<int> p;
	int cur = 0;
	int ans = 0;
	int split = 0, comb = 0;
	while(cur !=nsum ){ 
		int u = s.size();
		int p1=0, p2=0;
		int maxv=0;
		for(int i = 0;i<u;i++){
			int z = s[i].size();
			bool found = 0;
			int full = 1;
			int start = 0;
			int zz = 0;
			if(cur == 0) zz=1;
			for(int j = 0;j<z;j++){
				if(found && s[i][j] == -1) break;
				if(found && s[i][j] != vec[cur] && s[i][j] != -1){ 
					full=0;
					break;
				}
				if(s[i][j] == vec[cur]){
					if(j == 0 || (!found && j >0 && s[i][j-1] == -1)) start = 1;
					found=1;
					s[i][j] = -1;
					cur++;
				}
			}
			if(found){
				//ans += 3 - (start+full) - zz;
				if(!start) split++;
				if(!full) split++;
				if(!zz) comb++;
			}
		}
	}
	cout << split << " " << comb << '\n';
	
}
