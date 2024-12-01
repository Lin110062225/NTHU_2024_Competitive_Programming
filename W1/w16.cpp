// #include <bits/stdc++.h>
// using namespace std;

// #define LOCAL
// #define MAXN 30 //題目最大區域量，保險起見開更大
// int num[MAXN], ans[MAXN], result[MAXN];
// //num 題目的區域，ans 我們要輸出的答案，result 當前 DFS 中每個區域到行政據點最短距離的總和
// //ans, result 只會用到前 5 個陣列值
// int t, n, a, b, c; //輸入資料用
// int d = MAXN*MAXN*1000; //理論上每個區域到行政據點最大距離不超過此值，因為人口最多只有 1000
// //因此 25個區域*最大距離25(不可能達到)*人口數量，可以當作此題的最大值

// void dfs(int p, int office){
//     if(office >= 5){ //如果建立了 5 個辦公室，就開始找每個區域到行政據點最短距離的總和
//         int sum = 0; //當前 DFS 每個區域到行政據點最短距離的總和
//         //cout << "result " << result[i] << '\n';
//         for(int j = 0; j < 25; j++){ //遍地每個區域
//             int compute = MAXN*MAXN*1000, temp; 
//             for(int i = 0; i < 5; i++){ //判斷哪個行政據點離當前區域最短
//                 temp = num[j] * (abs(result[i]/5 - j/5) + abs(result[i]%5 - j%5));
//                 compute = min(temp, compute); //取最小的
//             }
//             sum += compute; //加到 sum
//         }

//         //定義: A = 每個區域到行政據點最短距離的總和
//         if(sum < d){ //如果當前的 A 比過去中最小的 A，還小就取代
//             //cout << "test:" << sum << ' ';
//             d = sum; //將答案值替換
//             for(int i = 0; i < 5; i++){ //將答案值替換
//                 ans[i] = result[i];
//                 //cout << result[i] << ' ';
//             }
//             //cout << '\n';
//         }
//         return;
//     }
//     for(int i = p+1; i < 25; i++){ //不斷進行 DFS，做所有的排列組合
//         result[office] = i; //當前的第 office 的辦公室為 i 區域 
//         dfs(i, office+1); //往下一層邁進，題目有說明輸出要遞增，因此 i 必須是 p+1，否則會重覆到
//     }
// }

// void debug() { //debug 用
//     for(int i = 0; i < 5; i++){
//         for(int j = 0; j < 5; j++)
//             cout << num[i*5+j] << ' ';
//     cout << '\n';
//     }
// }

// int main() {
//     cin >> t;
//     while(t--){
//         cin >> n;
//         memset(num, 0, sizeof(num)); //清空，以免干擾這次資料
//         while(n--){ //輸入資料
//             cin >> a >> b >> c;
//             num[a*5+b] = c;
//         }
//         //debug();
//         d = MAXN*MAXN*1000;
//         dfs(-1, 0); //一開始是 -1 是因為，我們的 DFS 排列組合迴圈是 p+1

//         cout << ans[0];
//         for(int i = 1; i < 5; i++) cout << ' ' << ans[i]; //輸出答案
//         cout << '\n';
//     }
// }

#include <bits/stdc++.h>
using namespace std;

vector<int> city(25, 0);
vector<int> location(5, 0);
vector<int> ans(5, 0);

int max_dis = 25 * 25 * 1000;
int min_dis;

void dfs(int p, int offices) {
    if (offices == 5) {
        int sum = 0;
        for (int i = 0; i < 25; i++) {
            int tmp = max_dis;
            for (int j = 0; j < 5; j++) {
                tmp = min(city[i] * (abs(location[j]/5 - i/5) + abs(location[j]%5 - i%5)), tmp);
            }
            sum += tmp;
        }
        if (sum < min_dis) {
            min_dis = sum;
            for (int i = 0; i < 5; i++) {
                ans[i] = location[i];
            }
        }
        return;
    }
    for (int i = p+1; i < 25; i++) {
        location[offices] = i;
        dfs(i, offices + 1);
    }
}

int main() {
	int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            int r, c, p;
            cin >> r >> c >> p;
            city[r*5 + c] = p;
        }
        
        min_dis = max_dis;
        dfs(-1, 0);

        for (int i = 0; i < 5; i++) {
            cout << ans[i] << " \n"[i == 4];
        }

        city.assign(25, 0);
    }
}