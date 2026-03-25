// brute force : O ( (m+n) * (m*n) )

/*
// optimal : 

totalSum - sum of all elements of the grid

the function sumGrid(i, j); sum within the region : [(0,0) till (i,j)]
formally : summation {x=0; x<=i; x++} ( summation {y=0; y<=j; y++} (grid[x][y]) )

optimized version of this formally : 
    prefixSum


// alternatively : 2 * sum == totalSum

for each columns partition : 
    f ( i,0,n-1 ) : 
        sum = sumGrid(m-1, i);
        check if ( sum == totalSum - sum ) ? return true : false;

for each rows partition : 
    f ( i,0,m-1 ) : 
        sum = sumGrid(i, n-1);
        check if ( sum == totalSum - sum ) ? return true : false;

*/

#define ll long long

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<ll>> sumGrid(m, vector<ll>(n) );

        // i=0 base case
        ll prefSum = 0;
        for ( int j=0; j<n; j++ ) {
            prefSum += 1LL*grid[0][j];
            sumGrid[0][j] = prefSum;
        }

        for ( int i=1; i<m; i++ ) {
            ll prefSum = 0;
            for ( int j=0; j<n; j++ ) {
                prefSum += 1LL*grid[i][j];
                sumGrid[i][j] = prefSum + sumGrid[i-1][j];
            }
        }

        ll totalSum = sumGrid[m-1][n-1];

        // columns partition
        for ( int j=0; j<n-1; j++ ) {
            if ( sumGrid[m-1][j] == totalSum - sumGrid[m-1][j] ) return true;
        }

        // rows partition
        for ( int i=0; i<m-1; i++ ) {
            if ( sumGrid[i][n-1] == totalSum - sumGrid[i][n-1] ) return true;
        }

        return false; // not found

    }
};