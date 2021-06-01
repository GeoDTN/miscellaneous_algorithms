#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


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
    compinations.push_back (std::make_pair(m, n));
    std::cout << std::endl;
  } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
  return compinations;
}

int main() {
  std::vector<std::pair<int, int>> combinations = comb(5, 2);
  for (auto x:combinations) std::cout<<x.first <<" "<<x.second<<std::endl;
}
