#include <algorithm>
#include <iostream>
#include <vector>
#include "linkedlist.h"

using namespace std;

vector<int> numVector;

template <typename T>
std::vector<int> findItems(std::vector<T> const &v, int target) {
  std::vector<int> indices;

  for (int i = 0; i < v.size(); i++) {
    if (v[i] == target) {
      indices.push_back(i);
    }
  }

  return indices;
}

void insertAfter(vector<int> &nVector, int firstValue, int secondValue) {
  vector<int> indices = findItems(nVector, firstValue);

  int i = 1;
  for (auto &e : indices) {
    nVector.insert(nVector.begin() + e + i, secondValue);
    i++;
  }
}

Linkedlist createListFromVector(vector <int> &nVector){
  Linkedlist list;
  
  for (int i = 0; i < nVector.size(); i++) {
    list.insertNode(nVector[i]);
  }

  return list;
}

int main() {
  cout << "Type in size of vector " << endl;

  int size = 0;

  cin >> size;

  int input = 0;

  cout << "Type in numbers " << endl;

  for (int i = 0; i < size; i++) {
    cin >> input;
    numVector.push_back(input);
  }

  for (int i = 0; i < numVector.size(); i++) {
    cout << numVector[i] << endl;
  }
  
  return 0;
}
