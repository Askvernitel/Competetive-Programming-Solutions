#include <bits/stdc++.h>

using namespace std;

int cards[4];
int vis[4];
vector<int> perms;
int cur_max = INT_MIN;

int calc(int n, int num, char op){
	int ans = n;
	if(op == 0){
		ans+=num;	
	}else if(op == 1){
		ans-=num;
	}else if(op == 2){
		if(num == 0 || ans % num != 0) return INT_MAX;
		ans/=num;
	}else if(op == 3){
		ans*=num;
	}
	return ans;
}
void comp(){ 
	
	for(int i = 0;i<4;i++){
		for(int j = 0;j<4;j++){
			for(int v=0;v<4;v++){
				int res1 = calc(perms[0], perms[1], i);
				if(res1 == INT_MAX) continue;
				int res2 = calc(res1, perms[2], j);
				if(res2 == INT_MAX) continue;
				int res3 = calc(res2, perms[3], v);
				if(res3 != INT_MAX && res3 <=24){ 
					cur_max = max(res3,cur_max);
				}
			}

		}
	}
	
	for(int i = 0;i<4;i++){
		for(int j = 0;j<4;j++){
			for(int v=0;v<4;v++){
				int res11 = calc(perms[0], perms[1],i);
				if(res11 ==INT_MAX) continue;
				int res22 = calc(perms[2], perms[3],j);
				if(res22 ==INT_MAX) continue;
				int res33 = calc(res11, res22, v);
				if(res33 !=INT_MAX && res33<=24){ 
					cur_max = max(res33, cur_max);
				}
			}

		}
	}

}


void place(int k){ 
	if(k > 3){
		comp();
		return;
	}
	for(int i =0;i<4;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		perms.push_back(cards[i]);
		place(k+1);
		perms.pop_back();
		vis[i] = 0;
	}

}

int main(){
	int n;
	cin >> n;
	

	while(n--){
		cin >> cards[0] >> cards[1] >> cards[2] >> cards[3];
		
		place(0);
		cout << cur_max << '\n';
		cur_max = INT_MIN;
	}
}
