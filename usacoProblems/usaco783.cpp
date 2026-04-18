#include <bits/stdc++.h>

using namespace std;
int covers(int x, int y, int x1, int y1, int x2, int y2){ 
    

    if(x < x1 || y < y1 || y > y2 || x > x2){
	return 0;
    }
    return 1;
}
int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout); 

    int x1, x2, x3, x4, y1, y2,y3,y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int cnt = 0;
    cnt += covers(x1,y1,x3,y3,x4,y4);
    cnt += covers(x1,y2,x3,y3,x4,y4);
    cnt += covers(x2,y2,x3,y3,x4,y4);
    cnt += covers(x2,y1,x3,y3,x4,y4);

    if(cnt == 4){
	cout << 0 << '\n';
    }else if(cnt >=2){
	int width = min(x2, x4) - max(x1, x3);
	int height = min(y2,y4) - max(y1,y3);
	cout <<(x2-x1) * (y2 - y1)-
	    width*height << '\n';

    }else{
	cout << (x2-x1) * (y2 - y1) << '\n';	
    }
}
