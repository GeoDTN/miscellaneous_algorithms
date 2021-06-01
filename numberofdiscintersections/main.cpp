#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
/*
We draw N discs on a plane. The discs are numbered from 0 to N ? 1. An array A
of N non-negative integers, specifying the radiuses of the discs, is given. The
J-th disc is drawn with its center at (J, 0) and radius A[J].

We say that the J-th disc and K-th disc intersect if J ? K and the J-th and K-th
discs have at least one common point (assuming that the discs contain their
borders).

The figure below shows discs drawn for N = 6 and A as follows:
  A[0] = 1
  A[1] = 5
  A[2] = 2
  A[3] = 1
  A[4] = 4
  A[5] = 0
There are eleven (unordered) pairs of discs that intersect, namely:

        discs 1 and 4 intersect, and both intersect with all the other discs;
        disc 2 also intersects with discs 0 and 3.

Write a function:

    int solution(vector<int> &A);

that, given an array A describing N discs as explained above, returns the number
of (unordered) pairs of intersecting discs. The function should return ?1 if the
number of intersecting pairs exceeds 10,000,000.

Given array A shown above, the function should return 11, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        each element of array A is an integer within the range
[0..2,147,483,647].
 */
std::vector<std::pair<int, int>> permutation(int N, int K);
int solution(std::vector<int> &A);
int main()
{
  //Test here
  return 0;
}

std::vector<std::pair<int, int>> permutation(int N, int K) {
  std::string bitmask(K, 1);  // K leading 1's
  bitmask.resize(N, 0);  // N-K trailing 0's
  std::vector<std::pair<int, int>> compinations{};
  // print integers and permute bitmask
  do {
    int m = -1, n = -1;
    for (int i = 0; i < N; ++i)  // [0..N-1] integers
    {
      if (bitmask[i]) {
        if (m == -1) {
          m = i;
        } else if (n == -1) {
          n = i;
        } else {
        }
        // std::cout << " " << i;
      }
    }
    compinations.push_back(std::make_pair(m, n));
    std::cout << std::endl;
  } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
  return compinations;
}

int solution(std::vector<int> &A) {
  std::vector<std::pair<int, int>> combinations = permutation(sizeof(A), 2);
  int counter{};
  for (auto comb : combinations) {
    if (std::abs(comb.first - comb.second) < (A[comb.first] + A[comb.second]))
                                                    ++counter;
  }
  if(counter>10000000) return -1;
  return counter;
}
