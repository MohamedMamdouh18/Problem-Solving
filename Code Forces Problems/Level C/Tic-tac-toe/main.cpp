#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define el "\n"
#define se second
#define fi first
#define ll long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

char table[3][3];

bool rowWin(char z, int row) {
    if (row >= 3) return false;
    int num = 0;
    for (int i = 0; i < 3; ++i) {
        if (table[row][i] == z) num++;
    }

    if (num == 3) return true;
    else return rowWin(z, row + 1);
}

bool colWin(char z, int col) {
    if (col >= 3) return false;
    int num = 0;
    for (int i = 0; i < 3; ++i) {
        if (table[i][col] == z) num++;
    }

    if (num == 3) return true;
    else return colWin(z, col + 1);
}

bool diagWin(char z) {
    int num = 0;
    if (table[0][0] == z) num++;
    if (table[1][1] == z) num++;
    if (table[2][2] == z) num++;
    if (num == 3) return true;

    num = 0;
    if (table[0][2] == z) num++;
    if (table[1][1] == z) num++;
    if (table[2][0] == z) num++;
    if (num == 3) return true;
    return false;
}

bool checkWin(char z) {
    return rowWin(z, 0) || colWin(z, 0) || diagWin(z);
}

int main() {
    IOS
    int empty = 0, xs = 0, os = 0;
    bool xwin = false, owin = false;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            char z;
            cin >> z;
            table[i][j] = z;
            if (z == '.') empty++;
            else if (z == '0') os++;
            else xs++;
        }

    xwin = checkWin('X');
    owin = checkWin('0');

    if (xs > os + 1 || os > xs || (xwin && owin) || (xwin && xs == os) || (owin && xs > os)) {
        cout << "illegal";
        return 0;
    }

    if (xwin) {
        cout << "the first player won";
        return 0;
    } else if (owin) {
        cout << "the second player won";
        return 0;
    }

    if (xs == os && empty != 0) cout << "first";
    else if (xs > os && empty != 0) cout << "second";
    else if (empty == 0) cout << "draw";
}
