#include <algorithm>
#include <stddef.h>

template <typename T> class DynamicArrayList {
private:
  T *data;
  size_t size;
  size_t capacity;

public:
  DynamicArrayList(size_t cap = 1) { data = new T[cap]; }
  ~DynamicArrayList() { delete data; }

  // 左值版本
  // 能取地址，有一个确定的内存位置，可以“放在等号左边”。
  void push_back(const T &value) {
    if (size >= capacity) {
      // 扩容
      resize(2 * capacity);
    }
    data[size++] = value; // 拷贝
  }

  // 右值版本
  // 右值不能取地址，通常是临时值或字面量，生命周期一般只在当前表达式有效。
  void push_back(T &&value) {
    if (size >= capacity) {
      // 扩容
      resize(2 * capacity);
    }
    // 如果被 std::move 过的对象仍然存在，但处于“未指定的有效状态”
    // 你可以用它（不安全），但值可能为空/无效。
    data[size++] = std::move(value); // 移动
  }

  void resize(size_t size) {
    int i;
    int n = this->size;
    T *new_data = new T[size];
    for (i = 0; i < n; i++) {
      new_data[i] = data[i];
    }
    delete data;
    data = new_data;
    this->capacity = size;
  }
  size_t get_size() { return this->size; }
  size_t get_capacity() { return this->capacity; }
  T &operator[](size_t index) { return this->data[index]; }

  void remove(size_t index) {}
};
