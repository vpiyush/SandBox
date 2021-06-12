// in an array of integers of odd length median is middle most element
// if array has even number of elements meian would be average of middle 2 elements
// here we will be maintained 1 max heap and 1 min heap and always be calculate median in o(1) time.
// but the insrtion here will take the logn time
#include<iostream> 
#include<algorithm> 
#include<queue> 

using namespace std;

float getMedian(priority_queue<int> &leftHeap, priority_queue<int, vector<int>, greater<int> > &rightHeap, float oldMedian) {
  auto median = oldMedian;
  if (leftHeap.size() < rightHeap.size()) {
    median = rightHeap.top();
  } else if (leftHeap.size()> rightHeap.size()) {
    median = leftHeap.top();
  } else {
    median = (leftHeap.top() + rightHeap.top())/2.0;
  }
  return median;
}

int main() {

  priority_queue<int> leftHeap; // maxHeap
  priority_queue<int, vector<int>, greater<int> > rightHeap; // minHeap


  int d;
  cin >>d;

  leftHeap.push(d);
  float med = d;
  cout << "median is " << med << endl;
    cin >> d;
    while (d != -1) {

      if (leftHeap.size() > rightHeap.size()) {
        if (d < med) {
          // insert into the left Hea
          // pop the element from leftHeap first
          auto elem = leftHeap.top();
          leftHeap.pop();
          rightHeap.push(elem);
          leftHeap.push(d);
        } else {
          rightHeap.push(d);
        }
      } else if (leftHeap.size() < rightHeap.size()) {
        if (d < med) {
          // insert into the left Hea
          leftHeap.push(d);
        } else {
          // pop the element from leftHeap first
          auto elem = rightHeap.top();
          rightHeap.pop();
          leftHeap.push(elem);
          rightHeap.push(d);
        }
      } else {
        if (d < med) {
          // insert into the left Hea
          leftHeap.push(d);
        } else {
          rightHeap.push(d);
        }
      }
      med = getMedian(leftHeap, rightHeap, med);
      /*
      cout << "left Heap "  << leftHeap.top() << endl; 
      cout << "right Heap "  << rightHeap.top() << endl; 
      rightHeap.push(0);
      leftHeap.push(5);
      */
      cout << "left Heap "  << leftHeap.top() << endl; 
      cout << "right Heap "  << rightHeap.top() << endl; 
      cout << "median is " << med  << endl;
      cin >> d;
    }
}

