#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class heap {
  public:
    std::vector<int> vec;
    bool minHeap;
    heap(int initSize = 10, bool type = true) {
      vec.reserve(initSize);
      // reserve first index
      vec.push_back(-1);
      minHeap = type;
    }

    bool compare(int parent, int child) {
      if (minHeap) {
        return parent < child;
      } else {
        return parent > child;
      }
    }

    void push (int d) {
      
      vec.push_back(d);
      int idx = vec.size()-1;
      int parent = idx/2;
      // keep moving the node up untill we reach root(idx == 1) or element gets to the correct position
      while (idx > 1 and !compare(vec[parent], vec[idx]) ) {
        std::swap(vec[parent], vec[idx]);
        idx = parent;
        parent = idx/2;
      }
      //heapify(lastIndex);
    }

    int heapTop() {
      return vec[1];
    }
    int pop() {
      int lastIdx  = vec.size()-1;
      int top = heapTop();
      std::swap(vec[1],vec[lastIdx]);
      vec.pop_back();
      heapify(1);
      return top;
    }

    void heapify(int index) {
      int minIdx = index;
      int leftChild = 2*index;
      int rightChild = 2*index +1;
      int lastIdx = vec.size()-1;
      // first compare the leftChild and parent and update the minIdx (index of the element which is min among parent and children)
      if (leftChild <= lastIdx && !compare(vec[index], vec[leftChild])){
        minIdx = leftChild;
      }

      // now copare  left and right child and update the min Index so that we can perform the swap
      if (rightChild <= lastIdx && !compare(vec[minIdx], vec[rightChild])){
        minIdx = rightChild;
      }

      if (minIdx != index) {
        std::swap(vec[minIdx], vec[index]);
        heapify(minIdx);
      }
    }

    bool empty() {
      return vec.size() == 1;
    }
    
};

int main () {
  heap h;
  int n;
  cin >> n;
  for (int i = 0; i <n; i++) {
    int no;
    cin >> no;
    h.push(no);
  }

  while (!h.empty())  {
    cout << h.pop() <<  " " << endl;
  }

}
