
/*
Before going to main problem first remember some basis.

We know that, to multiply two matrices it is condition that, number of columns in first matrix should be equal to number of rows in second matrix. Let say there are two matrices A and B with dimensions A (2 x 3) and B (3 x 2)
 resultant matrix is (2 x 2) matrix i.e. it contains total 4 elements. To calculate each element we did 3 multiplications (which is equal to number of columns in first matrix and number of rows in second matrix). So totally for 4 elements 4*3 = 12 multiplications are required.

 If 4 matrices A, B, C, D we can find final result in 5 ways A(B(CD)) or A((BC)(D)) or (AB)(CD) 4. ((AB)C)D  or (A(BC))D. In this case also each way requires different number of multiplications.

 General formula to find number of ways we can find solution is  (2n)! / [ (n+1)! n! ]. After parenthesizing these many ways each way requires different number of multiplications for final result. When dimensions are large (200 x 250 like this) with more number of matrices, then finding the parenthesizing way which requires minimum number of multiplications need will gives less time complexity.

So Matrix Chain Multiplication problem aim is not to find the final result of multiplication, it is finding how to parenthesize matrices so that, requires minimum number of multiplications.

Efficient way of solving this is using dynamic programming

Time Complexity
If there are n number of matrices we are creating a table contains [(n) (n+1) ] / 2 cells that is in worst case total number of cells n*n = n2 cells we need calculate = O (n2)
For each one of entry we need find minimum number of multiplications taking worst (it happens at  last cell in table) that is Table [1,4] which equals to  O (n) time.
Finally O (n2) * O (n) = O (n3) is time complexity.
Space Complexity
We are creating a table of n x n so space complexity is O (n2).
*/

#include <iostream>
#include <limits.h>

using namespace std;

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n

int MatrixChainMultiplication(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0; //number of multiplications are 0(zero) when there is only one matrix
    //Here L is chain length. It varies from length 2 to length n.
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX; //assigning to maximum value

            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q; //if number of multiplications found less that number will be updated.
                }
            }
        }
    }
    return m[1][n - 1]; //returning the final answer which is M[1][n]
}

//Dimensions
/*
A1 = 10 x 100 
A2 = 100 x 20 
A3 = 20 x 5 
A4 = 5 x 80;
*/

int main()
{
    int n, i;
    //cout << "Enter number of matrices\n";
    cin >> n;
    n++;
    int arr[n];
    //cout << "Enter dimensions \n";
    for (i = 0; i < n; i++)
    {
        // cout << "Enter d" << i << " :: ";
        cin >> arr[i];
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications is " << MatrixChainMultiplication(arr, size);
    return 0;
}