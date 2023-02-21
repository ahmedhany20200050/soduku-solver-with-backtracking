#include <bits/stdc++.h>

using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define el '\n'
//#define el endl
//#define int  long long int
#define MOD 1000000007
/*꧁༒☬  ☠︎ I_Hate_This_Code ☠︎  ☬༒꧂
 *
 */
//int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
//int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n = 9;
int soduku [9][9] ;
int taken [9][10];
bool valid(int r, int c) {
    if (r >= n || c >= n || r < 0 || c < 0)
        return false;
    return true;
}

void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << soduku[i][j] << " ";
        }
        cout << el;
    }
}

bool checkCell(int& a, int& b, int& value) {
    for (int i = 0; i < n; ++i) {
        if (soduku[a][i] == value) {
            return false;
        }
        if (soduku[i][b] == value) {
            return false;
        }
    }
    // check the 3 by 3 zone (in which the cell belongs)
    int offsetOne = (a / 3) * 3, offsetTwo = (b / 3) ;
    if(taken[offsetOne+offsetTwo][value]){
        return false;
    }
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            int first = offsetOne + i, second = offsetTwo + j;
//            if (first == a && second == b)continue;
//            if (soduku[first][second] == value) {
//                return false;
//            }
//        }
//    }
    return true;
}


void backtracking(int a, int b) {
    if (!valid(a, b)) {
        print();
        exit(0);
    }
    if(soduku[a][b]!=0){
        if(b==8){
            backtracking(a+1,0);
        } else{
            backtracking(a,b+1);
        }
        return;
    }



    for (int i = 1; i <= 9 ; ++i) {
        if(checkCell(a,b,i)){
            soduku[a][b]=i;
            int number=soduku[a][b];
            int offsetOne = (a / 3)*3 , offsetTwo = (b / 3);
            taken[offsetOne+offsetTwo][number]=1;
            if(b==8){
                backtracking(a+1,0);
            } else{
                backtracking(a,b+1);
            }
            soduku[a][b]=0;
            taken[offsetOne+offsetTwo][number]=0;
        }
    }

}


void solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> soduku[i][j];
            int number=soduku[i][j];
            int offsetOne = (i / 3)*3 , offsetTwo = (j / 3);
            taken[offsetOne+offsetTwo][number]=1;
        }
    }

    backtracking(0,0);


}


signed main() {
    fast
//#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

////valid indices
//bool valid(int r,int c){
//    if(r>=n||c>=m||r<0||c<0)
//        return false;
//    return true;
//}

//// bitmask code
//    for (int bits = 0; bits < (1<<n); ++bits) {
//        int sum=0,minv=100000000,maxv=-10;
//        for (int i = 0; i < n; ++i) {
//            if (bits&(1<<i)){
//                sum+=v[i];
//                minv=min(minv,v[i]);
//                maxv=max(maxv,v[i]);
////                cout<<v[i];
//            }
//        }

//// Function to return
//// gcd of a and b
//int gcd(int a, int b)
//{
//    if (a == 0)
//        return b;
//    return gcd(b % a, a);
//}
