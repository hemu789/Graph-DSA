#include <iostream>
#include <vector>
// harsh Dsa

using namespace std;

void print(vector<vector<int>> v, int sv, vector<bool> &visited)
{
    // using recursion
    cout << sv << endl;
    visited[sv] = true;
    int n = v.size();

    // traverse adj of source vertex
    for (int i = 0; i < n; i++)
    {
        if (v[sv][i] == 1 && visited[i] == false)
        {
            print(v, i, visited);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    // for Adj matrix
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    // 0 in complete matrix

    for (int i = 1; i <= e; i++)
    {
        int fv, sv; // edge bt fv and sv
        cin >> fv >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }

    cout << "Printing" << endl;

    vector<bool> visited(n, false);

    print(matrix, 0, visited);

    return 0;
}