/*
 You are helping a geologist friend investigate an area with mountain lakes. A
recent heavy rainfall has flooded these lakes and their water levels have
reached the highest possible point. Your friend is interested to know the
maximum depth in the deepest part of these lakes.

We simplify the problem in 2-D dimensions. The whole landscape can be divided
into small blocks and described by an array A of length N. Each element of A is
the altitude of the rock floor of a block (i.e. the height of this block when
there is no water at all). After the rainfall, all the low-lying areas (i.e.
blocks that have higher blocks on both sides) are holding as much water as
possible. You would like to know the maximum depth of water after this entire
area is flooded. You can assume that the altitude outside this area is zero and
the outside area can accommodate infinite amount of water.

For example, consider array A such that:
    A[0] = 1
    A[1] = 3
    A[2] = 2
    A[3] = 1
    A[4] = 2
    A[5] = 1
    A[6] = 5
    A[7] = 3
    A[8] = 3
    A[9] = 4
    A[10] = 2

The following picture illustrates the landscape after it has flooded:

The gray area is the rock floor described by the array A above and the blue area
with dashed lines represents the water filling the low-lying areas with maximum
possible volume. Thus, blocks 3 and 5 have a water depth of 2 while blocks 2, 4,
7 and 8 have a water depth of 1. Therefore, the maximum water depth of this area
is 2.

Write a function:

    int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the maximum
depth of water.

Given array A shown above, the function should return 2, as explained above.

For the following array:
    A[0] = 5
    A[1] = 8

the function should return 0, because this landscape cannot hold any water.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [1..100,000,000].
  */

// you can use includes, for example:
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <vector>
#include <iostream>
/*
#define DEBUG 1

#if DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...)
#endif

int solution(std::vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  std::vector<int> highest_right_wall(A.size());
  int higest_right = 0;
  if (A.size() > 1) {
    for (ssize_t i = A.size() - 2; i >= 0; --i) {
      highest_right_wall[i] = higest_right = std::max(higest_right, A[i + 1]);
    }
  }

#if DEBUG
  LOG("highest_right_wall: ");
  for (auto h : highest_right_wall) {
    LOG("%d ", h);
  }
  LOG("\n");
#endif


  int highest_depth = 0;
  int current_water_top = 0;

  for (size_t i = 0; i < A.size(); ++i) {
   LOG("A[%d]=%d, right wall=%d\n", (int)i, A[i], highest_right_wall[i]);

    if (A[i] > current_water_top) {
      current_water_top =
          std::min(A[i], highest_right_wall[i]);  // start of new water area
    } else {
      current_water_top = std::min(
          current_water_top, highest_right_wall[i]);  // start of new water area

      int depth = 0;

      if (current_water_top > A[i]) depth = current_water_top - A[i];

      highest_depth = std::max(highest_depth, depth);

      LOG("--> depth = %d, highest = %d\n", depth, highest_depth);
    }

      LOG("current_water_top=%d\n", current_water_top);
  }

  return highest_depth;
}

int main() {
  std::vector<int> heights{1, 3, 2, 1, 2, 1, 5, 3, 3, 4, 2};
  std::cout << solution(heights) << std::endl;
  return 0;
}
*/
/*
#include <stdexcept>
#include <iostream>
#include <queue>
#include <list>


class Node
{
 public:
  Node(Node* leftChild, Node* rightChild)
  {
    this->leftChild = leftChild;
    this->rightChild = rightChild;
  }

  Node* getLeftChild() const
  {
    return this->leftChild;
  }

  Node* getRightChild() const
  {
    return this->rightChild;
  }

  int height()
  {
    Node* root;

    if (root == nullptr) {
      return 0;
    }


    std::list<Node*> queue;
    queue.push_back(root);

    Node* front = nullptr;
    int height = 0;


    while (!queue.empty())
    {

      int size = queue.size();


      while (size--)
      {
        front = queue.front();
        queue.pop_front();

        if (front->leftChild) {
          queue.push_back(front->leftChild);
        }

        if (front->rightChild) {
          queue.push_back(front->rightChild);
        }
      }


      height++;
    }

    return height;
  }

private:
    Node* leftChild;
    Node* rightChild;
};

#ifndef RunTests
int main()
{
  Node* leaf1 = new Node(NULL, NULL);
  Node* leaf2 = new Node(NULL, NULL);
  Node* node = new Node(leaf1, NULL);
  Node* root = new Node(node, leaf2);

  std::cout << root->height();
}
#endif
*/
#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>
#include <memory>


int main()
{


}

