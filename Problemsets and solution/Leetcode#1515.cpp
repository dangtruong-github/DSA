#include<iostream>
#include<vector>
#include<cmath> 
#include<algorithm>

using namespace std;

/*
    Link to problem:
    https://leetcode.com/problems/best-position-for-a-service-centre/description/
*/

class Solution {
    public:
        int getBegin(vector<int> item) {
            return *(item.begin());
        }

        int getEnd(vector<int> item) {
            for (auto it = item.begin(); it != item.end(); it++) {
                if (it != item.begin()) {
                    return *it;
                }
            }
            return 0;
        }

        double getMinDistSum(vector<vector<int>>& positions) {
            vector<int> x_value, y_value;
            float x_centre = 0, y_centre = 0;

            for (auto it = positions.begin(); it != positions.end(); it++) {
                for (auto it_inside = (*it).begin(); it_inside != ((*it)).end(); it_inside++) {
                    if (it_inside == (*it).begin()) {
                        x_value.push_back(*it_inside);
                    } else {
                        y_value.push_back(*it_inside);
                    }
                }
            }

            sort(x_value.begin(), x_value.end(), greater<int>());
            sort(y_value.begin(), y_value.end(), greater<int>());

            int index = 0;
            for (auto it = x_value.begin(); it != x_value.end(); it++) {
                if (index == positions.size() / 2) {
                    x_centre += *it;
                } else if (index == (positions.size() - 1) / 2) {
                    x_centre += *it;
                }
                index++;
            }

            index = 0;
            for (auto it = y_value.begin(); it != y_value.end(); it++) {
                if (index == positions.size() / 2) {
                    y_centre += *it;
                } else if (index == (positions.size() - 1) / 2) {
                    y_centre += *it;
                }
                index++;
            }
            
            if (positions.size() % 2 == 0) {
                x_centre /= 2;
                y_centre /= 2;
            }
            cout << "x_centre: " << x_centre << "\n";
            cout << "y_centre: " << y_centre << "\n";

            float total = 0;

            for (auto it = positions.begin(); it != positions.end(); it++) {
                float diff_x = (x_centre - getBegin(*it));
                float diff_y = (y_centre - getEnd(*it));

                cout << "diff_x: " << diff_x << "\n";
                cout << "diff_y: " << diff_y << "\n";

                total += sqrt(pow(diff_x, 2) + pow(diff_y, 2));
            }

            return total;
        }  
};

int main() {
    cout << "\n\n";
    Solution solutionObj;

    vector<vector<vector<int>>> testCases;

    /* First test case */
    vector<vector<int>> firstTest;
    int posArr1[4][2] = {{0,1},{1,0},{1,2},{2,1}};
    for (int i = 0; i < 4; i++) {
        vector<int> pos;
        pos.push_back(posArr1[i][0]);
        pos.push_back(posArr1[i][1]);
        firstTest.push_back(pos);
    }
    testCases.push_back(firstTest);

    /* Second test case */
    vector<vector<int>> secondTest;
    int posArr2[2][2] = {{1,1},{3,3}};
    for (int i = 0; i < 2; i++) {
        vector<int> pos;
        pos.push_back(posArr2[i][0]);
        pos.push_back(posArr2[i][1]);
        secondTest.push_back(pos);
    }
    testCases.push_back(secondTest);

    /* Third test case */
    vector<vector<int>> thirdTest;
    int posArr3[3][2] = {{1,1},{0,0},{2,0}};
    for (int i = 0; i < 3; i++) {
        vector<int> pos;
        pos.push_back(posArr3[i][0]);
        pos.push_back(posArr3[i][1]);
        thirdTest.push_back(pos);
    }
    testCases.push_back(thirdTest);

    for (auto it = testCases.begin(); it != testCases.end(); it++) {
        cout << solutionObj.getMinDistSum(*it) << "\n";
    }

    return 0;
}