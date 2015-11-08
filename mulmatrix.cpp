#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#define MAX 100

using namespace std;

typedef struct Matrices {
    string name;
    int x,y;
} matrix;

typedef struct multiplier {
    string order;
    int result,x1,x2;
} mul;

void multiply(mul arr[][100], int x, int y){
    int mini = 2000000, d = 0, calc, i;
    for(i=x;i<y;i++){
        calc = arr[x][x+d].result + arr[x+d+1][y].result + (arr[x][x+d].x1 * arr[x][x+d].x2 * arr[x+d+1][y].x2);
        if(calc < mini){
            mini = calc;
            arr[x][y].result = mini;
            arr[x][y].x1 = arr[x][x+d].x1;
            arr[x][y].x2 = arr[x+d+1][y].x2;
            arr[x][y].order = "( " + arr[x][x+d].order + " " + arr[x+d+1][y].order + " )";
        }
        d++;
    }
}

int main(){
    int n,i,j,dif=0,mulcounter=0;
    matrix mat[MAX];
    mul m[MAX][MAX];
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> mat[i].name >> mat[i].x >> mat[i].y;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(dif==0) {
                m[j][j].result = 0;
                m[j][j].order = mat[j].name;
                m[j][j].x1 = mat[j].x;
                m[j][j].x2 = mat[j].y;
            }
            else if(dif!=0 && j+dif<= n){
                multiply(m,j,j+dif);
            }
        }
        dif++;
    }
    dif=0;
    /** For debugging **/
    /*
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(dif==0) {
                cout << "m" << j << j << " " << m[j][j].result << " " << m[j][j].order << " " << m[j][j].x1 << "x" << m[j][j].x2 << endl;
            }
            else if(dif!=0 && j+dif<= n){
                cout << "m" << j << j+dif << " " << m[j][j+dif].result << m[j][j+dif].order << " " << m[j][j+dif].x1 << "x" << m[j][j+dif].x2 << endl;
            }
        }
        dif++;
    }
    cout << m[1][n].x1 << " x " << m[1][n].x2 << endl;
    cout << mulcounter << endl;
    */
    cout << m[1][n].order << " = " << m[1][n].result << endl;
    return 0;
}
