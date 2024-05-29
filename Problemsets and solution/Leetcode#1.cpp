#include <iostream>
#include <vector>

using namespace std;

/*
    Link to problem:
    https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one
*/

int numSteps(string s) {
    int index = s.length() - 1;
    int num_step = 0;

    while (s[index] == '0') {
        num_step++;
        index--;
    }

    if (index == 0) {
        return num_step;
    }

    for (int i = 0; i < index; i++) {
        if (s[i] == '0') {
            num_step++;
        }
    }

    num_step += index + 2;

    return num_step;
}

int main () {
    cout << "\n\n";
    
    cout << "1101: 6 " << numSteps("1101") << endl;
    cout << "1: 0 " << numSteps("1") << endl;
    cout << "10: 1 " << numSteps("10") << endl;
    cout << "11000: 6 " << numSteps("11000") << endl;

    return 0;
}