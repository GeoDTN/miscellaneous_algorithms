#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
A non-empty array A consisting of N integers is given. A pair of integers (P,
Q), such that 0 < P < Q < N, is called a slice of array A (notice that the slice
contains at least two elements). The average of a slice (P, Q) is the sum of
A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. To be precise,
the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q ? P + 1).

For example, array A such that:
    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8

contains the following example slices:

        slice (1, 2), whose average is (2 + 2) / 2 = 2;
        slice (3, 4), whose average is (5 + 1) / 2 = 3;
        slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.

The goal is to find the starting position of a slice whose average is minimal.

Write a function:

    int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the starting
position of the slice with the minimal average. If there is more than one slice
with a minimal average, you should return the smallest starting position of such
a slice.

For example, given array A such that:
    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8

the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [2..100,000];
        each element of array A is an integer within the range
[?10,000..10,000].
 */
std::vector<std::pair<int, int>> comb(int N, int K);
int solution(std::vector<int>& A);

int main() {
  cout << "Hello World!" << endl;
  return 0;
}

std::vector<std::pair<int, int>> comb(int N, int K) {
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

int solution(std::vector<int>& A) {
  std::vector<std::pair<int, int>> combinations = comb(sizeof(A), 2);
  std::vector<std::pair<int, double>> start_avg{};
  for (auto x : combinations) {
    double sum = 0;
    int minimum = std::min(x.first, x.second);
    int maxmum = std::max(x.first, x.second);
    for (int i = minimum; i <= maxmum; ++i) {
      sum += static_cast<double>(A[i]);
    }
    sum /= (maxmum - minimum + 1);
    start_avg.push_back(std::make_pair(minimum, sum));
    // std::cout<<x.first <<" "<<x.second<<std::endl;
  }
  std::pair<int, double> minimum_sum =
      *std::min(start_avg.begin(), start_avg.end(),
                [](std::pair<int, double> A, std::pair<int, double> B) {
                  return A.second < B.second;
                });
  std::vector<std::pair<int, double>> last_minimum;
  for (auto pairs : start_avg) {
    if (pairs.second == minimum_sum.second) last_minimum.push_back(pairs);
  }
  return std::min(last_minimum.begin (),last_minimum.end(),[](std::pair<int,double>A,std::pair<int,double>B){ return A.first<B.first;})->first;
}
