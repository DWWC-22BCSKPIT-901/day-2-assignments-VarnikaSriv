#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascalTriangle;

    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1, 1); // Initialize a row with all 1s
        for (int j = 1; j < i; j++) {
            row[j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
        }
        pascalTriangle.push_back(row); 
    }

    return pascalTriangle;
}

int main() {
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;

    vector<vector<int>> result = generate(numRows);
    cout << "Pascal's Triangle:" << endl;

    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
