#include <bits/stdc++.h>

using namespace std;
int covered(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){ 
    
    return (x >= x1 && y >= y1 && x <= x2 && y <= y2) || (x >= x3 && y >= y3 && x <= x4 && y<=y4);
}
int covered_black(int x, int y, int x1, int y1, int x2, int y2){
    return (x >= x1 && y >= y1 && x <= x2 && y <= y2);
}
int main(){
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6,y6;
    
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

    int covb1 = 0, covb2 =0, cov;
    
    cov += covered(x1,y1,x3,y3,x4,y4,x5,y5,x6,y6);
    cov += covered(x1,y2,x3,y3,x4,y4,x5,y5,x6,y6);
    cov += covered(x2,y1,x3,y3,x4,y4,x5,y5,x6,y6);
    cov += covered(x2,y2,x3,y3,x4,y4,x5,y5,x6,y6);
    
    covb1 += covered_black(x1,y1,x3,y3,x4,y4);
    covb1 += covered_black(x2,y1,x3,y3,x4,y4);
    covb1 += covered_black(x1,y2,x3,y3,x4,y4);
    covb1 += covered_black(x2,y2,x3,y3,x4,y4);


    covb2 += covered_black(x1,y1,x5,y5,x6,y6);
    covb2 += covered_black(x2,y1,x5,y5,x6,y6);
    covb2 += covered_black(x1,y2,x5,y5,x6,y6);
    covb2 += covered_black(x2,y2,x5,y5,x6,y6);


    if(cov==4){
        int cov1 = 0;
        int cov2 = 0;
        cov1 += covered_black(x3,y3,x5,y5,x6,y6);
        cov1 += covered_black(x4,y3,x5,y5,x6,y6);
        cov1 += covered_black(x3,y4,x5,y5,x6,y6);
        cov1 += covered_black(x4,y4,x5,y5,x6,y6);

        cov2 += covered_black(x5,y5,x3,y3,x4,y4);
        cov2 += covered_black(x6,y5,x3,y3,x4,y4);
        cov2 += covered_black(x5,y6,x3,y3,x4,y4);
        cov2 += covered_black(x6,y6,x3,y3,x4,y4);
        if((cov2 >= 1 || cov1 >= 1) || (covb1 == 4 || covb2 == 4)){
            cout << "NO";
            return 0;
        }
    }
     cout << "YES";
    
}
