#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printVector(vector<int> &v) {
  if (v.empty()) return;
  for(int i = 0; i < v.size() - 1; i++) {
    cout << v[i] << " " << endl;
  }
  cout << v[v.size()-1] << endl;
}

void compare(vector<int> &expected, vector<int> &result) {
  if (result == expected) {
    cout << "CORRECT" << endl;
  } else {
    cout << "Expected: ";
    printVector(expected);
    cout << "but received: ";
    printVector(result);
  }
}

/* Time: O(N)
 * Space: O(1) */
vector<int> &rotate(vector<int> &v) {
  int cur = v[0];
  int next;
  for(int i = 0; i < v.size(); i++) {
    next = v[(i + 1) % v.size()];
    v[(i+1) % v.size()] = cur;
    cur = next;
  }
  return v;
}

/* Time: O(N*d)
   Space: O(1)
 */
vector<int> &rotateN(vector<int> &v, int d) {
  int times = d % v.size();
  while(times-- > 0) {
    v = rotate(v);
  }
  return v;
}

void testEasy() {
  int arr[] = {1};
  vector<int> a(arr, arr + sizeof(arr) / sizeof(int));
  compare(a, rotate(a));
}

void testMedium() {
  int arr[] = {1,2,3,4};
  vector<int> a(arr, arr + sizeof(arr) / sizeof(int));
  int exp[] = {4,1,2,3};
  vector<int> b(exp, exp + sizeof(arr) / sizeof(int));
  compare(a, rotate(a));
}

void testHard() {
  int arr[] = {1,1,1,2,1,1};
  vector<int> a(arr, arr + sizeof(arr) / sizeof(int));
  int exp[] = {1,1,1,1,2,1};
  vector<int> b(exp, exp + sizeof(arr) / sizeof(int));
  compare(a, rotate(a));
}

void testRotate2() {
  int arr[] = {1,2,3,4};
  vector<int> a(arr, arr + sizeof(arr) / sizeof(int));
  int exp[] = {3,4,1,2};
  vector<int> b(exp, exp + sizeof(arr) / sizeof(int));
  compare(a, rotateN(a, 2));
}

int main() {
  cout << "testEasy: ";
  testEasy();
  cout << "testMedium: ";
  testMedium();
  cout << "testHard: ";
  testHard();
  cout << "testRotate2: ";
  testRotate2();
  return 0;
}
