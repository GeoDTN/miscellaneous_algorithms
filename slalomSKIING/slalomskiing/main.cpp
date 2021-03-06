// for Visual Studio, create C++ console project and paste all this into the
// main fail

// SlalomSkiing.cpp : Defines the entry point for the console application.
//
/*
https://codility.com/programmers/lessons/90-tasks_from_indeed_prime_2015_challenge/slalom_skiing/
Lesson 90 of challenges
Ambitious

The main idea is to deal in two parts.
    Part 1
    Movement in one direction means finding the length of the longest increasing
sequence inside of array of integers. Keep all the time the ordered list of
final point of sequences with the accumulated value. The order is by number
only. A new number is added with the accumulated of the immediately previous
incremented by one, if none previous: take 0 + 1 If the next is the same -
eliminate it. Sample:

    10(4)                10(4)                      10(4)  10(4) 11(5) 8(2)  add
6 =>  8(2)    add 7 =>     8(2) => 7(2)   add 11 =>   10(4) 6(1) 7(2)    6(1)
7(2) 6(1)                        6(1) This operation is O(n*log(n))

                                                          Part 2
                                                          Add turns
                                                          The same but keep
three arrays, the second works with mirrored values of the first (right barrier
- values). Each member has accumulation of its previous OR the previous of the
fist array (maximum). The third has the same values but check maximum of the
seond or own


                               */
//////////////////////////////////////// start
#include <vector>
#include <iostream>
#include <iterator>  // for ostream_iterator
#include <algorithm>
using namespace std;


bool pred(const pair<long long, int> &a, const pair<long long, int> &b) {
  return a.first < b.first;
}

/*
https://codility.com/demo/results/trainingJQ33YP-55K/
the first solution is correct functional but performance is 20%, overall 69%
Detected time complexity:
O(N**2) as above for solution2
*/

/*

https://codility.com/demo/results/trainingDN55AN-AAM/
         100%   The improvement is in findLISBetter towards findLIS. It is a
known in the field difference in search of the max length of increasing
subsequence See
                 https://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming
                          https://en.wikipedia.org/wiki/Longest_increasing_subsequence#Efficient_algorithms


                                   */
vector<long long> prepareArray(vector<int> &AI) {
  /*
        The idea is that instead of turns we just reflect symmetrically the
     field, so the movement after the turn is the moving in the reflection The
     axis of reflection is the right barrier for the first turn plus 1 or any
     posiive number or its mirror image again for the right turn The only
     problem that gates cannot be on the same index, so we first triple index
     and use remainders 0,1,2 to put gates the rightest, the middle and the
     leftest This order ensures that we do not return after the turn
        */
  const static long long limit = 1000000000 + 1;
  int N = AI.size();
  vector<long long> AL(3 * N);
  for (int i = 0; i < N; i++) {
    long long t1 = 3 * (long long)AI.at(i);
    long long t2 = 2 * 3 * limit - t1;
    long long t3 = 4 * 3 * limit - t2;
    AL.at(3 * i + 0) = t3;
    AL.at(3 * i + 1) = t2;
    AL.at(3 * i + 2) = t1;
  }
  return AL;
}
int findLISBetter(vector<long long> AL) {
  vector<long long> res1;
  for (auto au = AL.begin(); au != AL.end(); au++) {
    auto po1 = upper_bound(res1.begin(), res1.end(), *au);
    if (res1.end() == po1) {
      res1.push_back(*au);
    } else
      *po1 = *au;
  }
  return res1.size();
}
int findLIS(vector<long long> AL) {
  vector<pair<long long, int> > res1;
  for (auto au = AL.begin(); au != AL.end(); au++) {
    pair<long long, int> np1(*au, 1);
    auto po1 = upper_bound(res1.begin(), res1.end(), np1, pred);
    if (!res1.empty() && po1 != res1.begin())
      np1.second = (po1 - 1)->second + 1;
    po1 = res1.insert(po1, np1);
    if (!res1.empty() && po1 != res1.end() && (po1 + 1) != res1.end()) {
      if (po1->second >= (po1 + 1)->second) res1.erase(po1 + 1);
    }
  }
  return res1.back().second;
}
int solution(vector<int> &AI) {
  vector<long long> AL = prepareArray(AI);
  int res = findLISBetter(AL);
  return res;
}

int main() {
  std::vector<int> points{15, 13, 5, 7, 4, 10, 12, 8, 2, 11, 6, 9, 3};
  std::cout << solution(points) << std::endl;

}
