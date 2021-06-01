#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cassert>

using namespace std;
/*
An array A consisting of N integers is given. A triplet (P, Q, R) is triangular
if 0 < P < Q < R < N and:

        A[P] + A[Q] > A[R],
        A[Q] + A[R] > A[P],
        A[R] + A[P] > A[Q].

For example, consider array A such that:
  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20

Triplet (0, 2, 4) is triangular.

Write a function:

    int solution(vector<int> &A);

that, given an array A consisting of N integers, returns 1 if there exists a
triangular triplet for this array and returns 0 otherwise.

For example, given array A such that:
  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20

the function should return 1, as explained above. Given array A such that:
  A[0] = 10    A[1] = 50    A[2] = 5
  A[3] = 1

the function should return 0.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        each element of array A is an integer within the range
[?2,147,483,648..2,147,483,647].
 */
std::vector<std::tuple<int, int, int>> permutation(int N, int K);
int solution(vector<int> &A);
int main()
{
  cout << "Hello World!" << endl;
  return 0;
}

std::vector<std::tuple<int, int, int>> permutation(int N, int K) {
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
  assert(sizeof(A) > 3);
  int triangle_exists = 0;
  std::vector<std::tuple<int, int, int>> triangle = permutation(sizeof(A), 3);
  for (auto perm : triangle) {
    if ((std::get<0>(perm) + std::get<1>(perm)) > std::get<2>(perm) &&
        (std::get<0>(perm) + std::get<2>(perm)) > std::get<1>(perm) &&
        (std::get<1>(perm) + std::get<2>(perm)) > std::get<0>(perm)) {
      triangle_exists = 1;
      break;
    }

  }
  return  triangle_exists;
}
