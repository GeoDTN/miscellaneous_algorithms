#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <utility>
#include <numeric>
#include <cmath>
using namespace std;
/*
Write a function:

    int solution(int A, int B, int K);
that, given three integers A, B and K, returns the number of integers within the
range [A..B] that are divisible by K, i.e.:

    { i : A < i < B, i mod K = 0 }
For example, for A = 6, B = 11 and K = 2, your function should return 3, because
there are three numbers divisible by 2 within the range [6..11], namely 6, 8
and 10.
Write an efficient algorithm for the following assumptions:

        A and B are integers within the range [0..2,000,000,000];
        K is an integer within the range [1..2,000,000,000];
        A < B.
		int get_count_of_divisibles(int A, int B, int K);
 */
 int get_count_of_divisibles(int A, int B, int K) {
  int count{};
  int x = A > B ? B : A;
  for (int x = A > B ? B : A; x <= A > B ? A : B; x++) {
    if (x % K == 0) ++count;
  }
  return count;
}

/*
A non-empty array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only once.

For example, array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
is a permutation, but array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3

is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:

    int solution(vector<int> &A);

that, given an array A, returns 1 if array A is a permutation and 0 if it is not.

For example, given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2

the function should return 1.

Given array A such that:
    A[0] = 4
    A[1] = 1
    A[2] = 3

the function should return 0.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [1..1,000,000,000].
    int is_permutuation(vector<int> &A);
*/

 int is_permutuation(vector<int>& A) {
  int is_permutation = 1;
  int max_element = *std::max(A.begin(), A.end());
  for (int it = 1; it < max_element; ++it) {
    if (std::find(A.begin(), A.end(), it) == A.end()) {
      is_permutation = 0;
      break;
    }
  }
  return is_permutation;
}
/*
Write a function:

    int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
Given A = [1, 2, 3], the function should return 4.

Given A = [?1, ?3], the function should return 1.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [?1,000,000..1,000,000].
		int findSmallest_missing_positive_integer(vector<int> &A);
*/
int findSmallest_missing_positive_integer(vector<int>& A) {
  if (std::all_of(A.begin(), A.end(), [](int x) { return x <= 0; })) return 1;
  if (std::all_of(A.begin(), A.end(), [](int x) { return x > 0; }) &&
      *std::min(A.begin(), A.end()) > 1)
    return 1;

  int next_minimum = 2;
  int max_element = *std::max(A.begin(), A.end());
  for (int it = next_minimum; it < max_element; ++it) {
    if (std::find(A.begin(), A.end(), it) == A.end()) return it;
  }
  return ++max_element;

}
/*
A small frog wants to get to the other side of a river. The frog is initially located on one bank of the river (position 0) and wants to get to the opposite bank (position X+1). Leaves fall from a tree onto the surface of the river.

You are given an array A consisting of N integers representing the falling leaves. A[K] represents the position where one leaf falls at time K, measured in seconds.

The goal is to find the earliest time when the frog can jump to the other side of the river. The frog can cross only when leaves appear at every position across the river from 1 to X (that is, we want to find the earliest moment when all the positions from 1 to X are covered by leaves). You may assume that the speed of the current in the river is negligibly small, i.e. the leaves do not change their positions once they fall in the river.

For example, you are given integer X = 5 and array A such that:
  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4

In second 6, a leaf falls into position 5. This is the earliest time when leaves appear in every position across the river.

Write a function:

    int solution(int X, vector<int> &A);

that, given a non-empty array A consisting of N integers and integer X, returns the earliest time when the frog can jump to the other side of the river.

If the frog is never able to jump to the other side of the river, the function should return ?1.

For example, given X = 5 and array A such that:
  A[0] = 1
  A[1] = 3
  A[2] = 1
  A[3] = 4
  A[4] = 2
  A[5] = 3
  A[6] = 5
  A[7] = 4

the function should return 6, as explained above.

Write an efficient algorithm for the following assumptions:

        N and X are integers within the range [1..100,000];
        each element of array A is an integer within the range [1..X].
		int probable_solution(int X, vector<int> &A);
 */
int probable_solution(int X, vector<int>& A) {
  std::set<int> postions{};
  int it = 0;
  while (sizeof(postions) <= X) {
    postions.insert(A[it]);
    ++it;
  }
  return it;
  }


/*
A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P - 1] and A[P], A[P + 1], ..., A[N - 1].
                                                                     The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P - 1]) - (A[P] + A[P + 1] + ... + A[N - 1])|
In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

    For example, consider array A such that:
    A[0] = 3
    A[1] = 1
    A[2] = 2
    A[3] = 4
    A[4] = 3

    We can split this tape in four places:

    P = 1, difference = |3 - 10| = 7
    P = 2, difference = |4 - 9| = 5
    P = 3, difference = |6 -7| = 1
    P = 4, difference = |10 - 3| = 7

    Write a function:

    int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

                                                 For example, given:
    A[0] = 3
    A[1] = 1
    A[2] = 2
    A[3] = 4
    A[4] = 3

    the function should return 1, as explained above.
	int find_minimum_difference(vector<int> &A);
 */

int find_minimum_difference(vector<int>& A) {
  std::vector<size_t> differences;

  for (auto it = A.begin() + 1; it < A.end() - 1; ++it) {
    differences.push_back(std::abs(std::accumulate(*A.begin(), *(it - 1), 0) -
                                   std::accumulate(*it, *(A.end() - 1), 0)));
  }
  return *std::min(differences.begin(), differences.end());
}
/*
An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.
int solution(vector<int> &A);
 */

int solution(vector<int>& A) {
  int sum = std::accumulate(A.begin(), A.end(), 0);
  int expected_sum = *std::max_element(A.begin(), A.end()) *
                     (*(A.begin()) + *(A.end() - 1)) / 2;
  int missing = expected_sum - sum;
  return missing;
}
/*
 * The problem is to find the single unpaired element in an odd numbered integer
 * array. A brute force method will take too long so I had to find a more
 * creative solution.
  int find_unque(std::vector<int>&);
 */
/*??????????????????????????????????????????????????*/
int find_unque(std::vector<int>& int_array) {
  int unique{};
  std::set<int> sorted_elements;
  for (auto element : int_array) sorted_elements.insert(element);
  auto i = sorted_elements.begin();
  if (*i != *(++i)) return *i;
  ++i;
  auto k = sorted_elements.end();
  auto l = --k;
  if (*l != *(--l)) return *l;

  while (i != l) {
    if (*i != *(--i) && *i != *(++i)) {
      unique = *i;
      break;
    }
    ++i;
  }
  return unique;
}
/*??????????????????????????????????????????????????*/
/*
 The problem is to count the minimum number of jumps from position X to Y. The
 main strategy is to use division and modulus (remainder) to calculate jumps
 required.
 int minimumRequiredJums(int x, int y, int jumpUnit);
 */
 int minimumRequiredJums(int x, int y, int jumpUnit) {
  int number_of_jumps = (y - x) / jumpUnit;
  if (number_of_jumps * jumpUnit < (y - x)) ++number_of_jumps;
  return number_of_jumps;
}

/*
 The problem is to find the longest sequence of zeros in a binary representation
 of an integer. The main strategy is: convert the integer to a binary string go
 through each character one by one and save the index of each 1 to a list go
 through the list of 1 indices and look for the largest difference in indices

 std::string find(std::vector<std::string>&, std::vector<std::string>&,
                 std::string&);
*/

std::string find(std::vector<std::string>& A, std::vector<std::string>& B,
                 std::string& search) {
  if (std::find(B.begin(), B.end(), search) == B.end())
    return "NOT FOUND";
  else if (std::count_if(B.begin(), B.end(), search) == 1) {
    auto it = std::find(B.begin(), B.end(), search);
    size_t position = std::distance(B.begin(), it);
    return A[position];
  } else {
    std::set<std::string> matches;
    auto it = B.begin();
    while (it != B.end()) {
      it = find(it, B.end(), search);
      matches.insert(*it);
      ++it;
    }
    return A[std::distance(B.begin(),
                           std::find(B.begin(), B.end(), *matches.begin()))];
  }
}
/*
 A binary gap within a positive integer N is any maximal sequence of consecutive
 zeros that is surrounded by ones at both ends in the binary representation of
 N.Convert to binary and find longest sequence
 std::string convertToBinary(
    int n);
 */
std::string convertToBinary(int n) {
  int binary[32];
  int i = 0;
  while (n > 0) {
    binary[i] = n % 2;
    n = n / 2;
    ++i;
  }
  std::vector<size_t> ones;
  for (size_t it = 0; it < 32; it++) {
    if (binary[i]) ones.push_back(i);
  }
  int difference = ones[1] - ones[0];
  std::pair<size_t, size_t> pair = {ones[0], ones[1]};
  difference = ones[1] - ones[0];
  for (size_t it = 0; i < sizeof(ones) - 1; ++i) {
    if (ones[it + 1] - ones[it] > difference)
      difference = ones[it + 1] - ones[it];
    pair = {ones[it], ones[it + 1]};
  }
}
/*
The problem is to rotate an integer array K times to the right and calculate
what the final array will look like. The main strategy is to use the mod
operator to calculate final index after wrapping around end of array.
*/
void rotate_array(size_t k, std::vector<int>& array) {
  std::vector<int> tmp_vector(sizeof(array));
  size_t array_size = sizeof(array);
  for (size_t i = 0; i < k; i++) {
    for (size_t j = array_size - 1; j >= 0; j--) {
      tmp_vector.push_back(array[j]);
    }
    array = tmp_vector;
    tmp_vector.clear();
  }
}

int main()
{
  cout << "Hello World!" << endl;
  return 0;
}









