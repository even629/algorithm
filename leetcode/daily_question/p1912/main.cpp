#include <set>
#include <unordered_map>
#include <vector>

using std::set;
using std::unordered_map;
using std::vector;

class Movie {
public:
  int shop;
  int movie;
  int price;

  bool operator<(const Movie &other) const {
    if (price != other.price)
      return price < other.price;
    if (shop != other.shop)
      return shop < other.shop;
    return movie < other.movie;
  }
};

class MovieRentingSystem {
private:
  // map<movies, map<shop,price>> 存放全局数据data map
  unordered_map<int, unordered_map<int, int>> dmap;
  // map<movie, set<Movie>> 未借出的map
  unordered_map<int, set<Movie>> umap;
  // set<Movies> 表示已经借出
  set<Movie> rented;
  // set<Movies> 表示未借出
  set<Movie> unrented;

  int shop_num;

public:
  // [shopi, moviei, pricei]
  MovieRentingSystem(int n, vector<vector<int>> &entries) {
    int shop, movie, price;
    shop_num = n;
    for (vector<int> vec : entries) {
      shop = vec[0];
      movie = vec[1];
      price = vec[2];
      // 全局数据
      dmap[movie][shop] = price;
      // 未租赁的set
      unrented.insert({shop, movie, price});
      // 未租赁的map
      umap[movie].insert({{shop, movie, price}});
    }
  }
  // 找到拥有指定电影且 未借出 的商店中 最便宜的 5 个
  vector<int> search(int movie) {
    vector<int> res;
    set<Movie> &tmp_set = umap[movie];
    int cnt = 0;
    for (auto it = tmp_set.begin(); it != tmp_set.end() && cnt < 5;
         it++, cnt++) {
      res.push_back(it->shop);
    }
    return res;
  }

  // 从指定商店借出指定电影，题目保证指定电影在指定商店未借出
  void rent(int shop, int movie) {
    int price = dmap[movie][shop];
    rented.insert({shop, movie, price});
    unrented.erase({shop, movie, price});
    umap[movie].erase({shop, movie, price});
    if (umap[movie].empty()) {
      umap.erase(movie);
    }
  }
  // 在指定商店返还 之前已借出 的指定电影
  void drop(int shop, int movie) {
    int price = dmap[movie][shop];
    unrented.insert({shop, movie, price});
    rented.erase({shop, movie, price});
    umap[movie].insert({shop, movie, price});
  }
  // 返回 最便宜的 5 部已借出电影 （可能有重复的电影 ID）
  vector<vector<int>> report() {
    vector<vector<int>> res;
    int cnt = 0;
    for (auto it = rented.begin(); it != rented.end() && cnt < 5; it++, cnt++) {
      vector<int> vec;
      vec.push_back(it->shop);
      vec.push_back(it->movie);
      res.push_back(vec);
    }
    return res;
  }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// 输出辅助函数
static string vec_to_str(const vector<int> &v) {
  string s = "[";
  for (size_t i = 0; i < v.size(); ++i) {
    s += std::to_string(v[i]);
    if (i + 1 != v.size())
      s += ",";
  }
  s += "]";
  return s;
}
static string mat_to_str(const vector<vector<int>> &m) {
  string s = "[";
  for (size_t i = 0; i < m.size(); ++i) {
    s += vec_to_str(m[i]);
    if (i + 1 != m.size())
      s += ", ";
  }
  s += "]";
  return s;
}

int main() {
  vector<vector<int>> entries = {{0, 1, 5}, {0, 2, 6}, {0, 3, 7},
                                 {1, 1, 4}, {1, 2, 7}, {2, 1, 5}};
  vector<string> outputs;
  outputs.push_back("null");
  MovieRentingSystem obj(3, entries);

  // search(1)
  outputs.push_back(vec_to_str(obj.search(1)));
  // rent(0,1)
  obj.rent(0, 1);
  outputs.push_back("null");
  // rent(1,2)
  obj.rent(1, 2);
  outputs.push_back("null");
  // report()
  outputs.push_back(mat_to_str(obj.report()));
  // drop(1,2)
  obj.drop(1, 2);
  outputs.push_back("null");
  // search(2)
  outputs.push_back(vec_to_str(obj.search(2)));

  // 打印最终结果
  cout << "[";
  for (size_t i = 0; i < outputs.size(); ++i) {
    cout << outputs[i];
    if (i + 1 != outputs.size())
      cout << ", ";
  }
  cout << "]\n";
  return 0;
}
