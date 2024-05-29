#include <iostream>

using namespace std;

/*
    Link to problem:
    https://codeforces.com/problemset/problem/1738/C
*/

int main() {
    cout << "\n\n";
    int n;
    cin >> n;

    while (n--) {
        int numTotal, num, even = 0;
        cin >> numTotal;
        for (int i = 0; i < numTotal; i++) {
            cin >> num;
            if (num % 2 == 0) {
                even++;
            }
        }

        
    }
}