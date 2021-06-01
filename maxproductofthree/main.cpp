#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;
/*
A non-empty array A consisting of N integers is given. The product of triplet
(P, Q, R) equates to A[P] * A[Q] * A[R] (0 ? P < Q < R < N). For example, array
A such that: A[0] = -3 A[1] = 1 A[2] = 2 A[3] = -2 A[4] = 5 A[5] = 6 contains
the following example triplets:

        (0, 1, 2), product is ?3 * 1 * 2 = ?6
        (1, 2, 4), product is 1 * 2 * 5 = 10
        (2, 4, 5), product is 2 * 5 * 6 = 60

Your goal is to find the maximal product of any triplet.

Write a function:

    int solution(vector<int> &A);

that, given a non-empty array A, returns the value of the maximal product of any
triplet.

For example, given array A such that:
  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6

the function should return 60, as the product of triplet (2, 4, 5) is maximal.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [3..100,000];
        each element of array A is an integer within the range [?1,000..1,000].
 */
std::vector<std::tuple<int, int,int>> combinations(int N, int K);
int solution(vector<int> &A);

int main()
{
  //Test here
  return 0;
}

std::vector<std::tuple<int, int, int>> combinations(int N, int K) {
  std::string bitmask(K, 1);  // K leading 1's
  bitmask.resize(N, 0);  // N-K trailing 0's
  std::vector<std::tuple<int, int, int>> combination{};
  // print integers and permute bitmask
  do {
    int k = -1, m = -1, n = -1;
    for (int i = 0; i < N; ++i)  // [0..N-1] integers
    {
      if (bitmask[i]) {
        if (k == -1) {
          k = i;
        }
        if (m == -1) {
          m = i;
        } else if (n == -1) {
          n = i;
        } else {
        }
        // std::cout << " " << i;
      }
    }
    combination.push_back(std::make_tuple(k, m, n));
    std::cout << std::endl;
  } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
  return combination;
}
int solution(vector<int> &A) {
  std::vector<std::tuple<int, int, int>> three_combinations =
      combinations(sizeof(A), 3);
  std::vector<int> products{};

  for (auto combination : three_combinations) {
    products.push_back(std::get<0>(combination) * std::get<1>(combination) *
                       std::get<2>(combination));
  }
  return *std::min(products.begin (),products.end ());
}
