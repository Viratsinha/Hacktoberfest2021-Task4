Code : Min Cost Path
Send Feedback
Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
Cost of a path is defined as the sum of values of each cell through which path passes.
Input Format :
Line 1 : Two integers, m and n
Next m lines : n integers of each row (separated by space)
Output Format :
Minimum cost
Constraints :
1 <= m, n <= 20
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13








				PRACTICE
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCostPath(int **input, int m, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
}

				SOLUTION












#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCostPath(int **input, int m, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    for(int j=1; j<n; j++)
        input[0][j] += input[0][j-1];
    for(int i=1; i<m; i++)
        input[i][0] += input[i-1][0];
    for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
            input[i][j] += min(min(input[i-1][j],input[i][j-1]),input[i-1][j-1]);

    return input[m-1][n-1];
}


#include "solution.h"

int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}

