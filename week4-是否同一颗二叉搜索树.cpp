#include <iostream>
#include <array>
#include <vector>

using std::array;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

vector<vector<int>> ReadFromInput();

int main(int argc, int** argv) {
  vector<vector<int>> input_arr;
  input_arr = ReadFromInput();
  // 先序遍历
  // 后序遍历
  return 0;
}

vector<vector<int>> ReadFromInput() {
  int N, L;  // N：每个序列插入元素的个数，m：需要检查的序列个数
  cin >> N;
  if (N == 0) return;
  cin >> L;
  int circle_time = 3;
  if (N < 3) {
    circle_time = 2;
  }
  vector<vector<int>> input_array;
  input_array.reserve(3);
  int x;
  for (int i = 0; i < circle_time; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> x;
      input_array[i].push_back(x);
    }
  }
  return input_array;
}