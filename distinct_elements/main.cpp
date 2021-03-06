#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Write a function

    int solution(vector<int> &A);

that, given an array A consisting of N integers, returns the number of distinct
values in array A.

For example, given array A consisting of six elements such that:
 A[0] = 2    A[1] = 1    A[2] = 1
 A[3] = 2    A[4] = 3    A[5] = 1

the function should return 3, because there are 3 distinct values appearing in
array A, namely 1, 2 and 3.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        each element of array A is an integer within the range
[?1,000,000..1,000,000].
 */
int solution(vector<int> &A);

int main()
{
  std::vector<int> v{67,90,0,7,6,67,45,3,21, 0,45};
  return solution(v);;
}

int solution(vector<int> &A){
  std::vector<int>::iterator it;
  it = std::unique (A.begin(), A.end());
  A.resize( std::distance(A.begin(),it) );
  return  sizeof (A);
}
