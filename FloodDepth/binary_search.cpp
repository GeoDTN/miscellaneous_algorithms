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
