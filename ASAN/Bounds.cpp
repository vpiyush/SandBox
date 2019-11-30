int main(int argc, char **argv) {
  int arr[2][3][4] = {};

  return arr[argv[1][0] - '0'][argv[2][0] - '0'][argv[3][0] - '0'];
  // CHECK-A-2: bounds.cpp:[[@LINE-1]]:10: runtime error: index 2 out of bounds for type 'int [2][3][4]'
  // CHECK-B-3: bounds.cpp:[[@LINE-2]]:10: runtime error: index 3 out of bounds for type 'int [3][4]'
  // CHECK-C-4: bounds.cpp:[[@LINE-3]]:10: runtime error: index 4 out of bounds for type 'int [4]'
}
