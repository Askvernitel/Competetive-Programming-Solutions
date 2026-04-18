#include <bits/stdc++.h>

using namespace std;
char grid[502][502];
int tree[502][502];
int vis_tree[502][502];
int vis_wolf[502][502];
int n, m;
int ans = 0;
void f(int i, int j, int d){
	if(i < 0 || j < 0 || i == n || j ==m || vis_wolf[i][j]) return;
	if(grid[i][j] == 'J'){ans = max(ans, d); return;}
	int dis = min(d, tree[i][j]);
	vis_wolf[i][j] = 1;
	f(i+1,j,dis);
	f(i, j+1, dis);
	f(i-1, j, dis);
	f(i,j-1,dis);

}
void dist(int i, int j, int d, int start_pos, int end_pos){
	if(i <0 || j < 0 || i == n || j == m || vis_tree[i][j]) return;

	tree[i][j] = min(tree[i][j], abs(start_pos-i) + abs(end_pos-j));
	vis_tree[i][j] = 1;
	dist(i+1,j,d+1, start_pos, end_pos);
	dist(i, j+1, d+1,start_pos,end_pos);
	dist(i-1,j,d+1, start_pos,end_pos);
	dist(i, j-1,d+1, start_pos, end_pos);
}
void set_stuff(){
	for(int i =0;i<n;i++){

		for(int j =0;j<m;j++){
			tree[i][j] = INT_MAX;
		}
	}

}/*
void set_other_stuff(){
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			vis_tree[i][j] = 0;
		}
	}
}
int main(){
	cin >> n >> m;
	set_stuff();
	int starti, startj;	
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			cin >> grid[i][j];
			if(grid[i][j] == 'V'){
				starti=i; startj=j;
			}
		}
	}
	
	
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			if(grid[i][j] == '+'){
				dist(i, j,0,i,j);
				set_other_stuff();
			}
		}
	}

/*	for(int i =0;i<n;i++){

		for(int j =0;j<m;j++){
			cout << tree[i][j] << " ";
		}
		cout << endl;
	}*/


	f(starti,startj, tree[starti][startj]);
	cout << ans;
}
