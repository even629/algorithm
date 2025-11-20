#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <utility>

using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::stack;
using std::pair;

template <class T> struct Arc {
    T val;   // 边权
    int vex; // 指向的节点索引
    struct Arc<T>* next;
};

template <class T, class V> struct Node {
    T val;
    struct Arc<V>* first;
};

template <class T, class V> struct AdjGraph {
    vector<Node<T, V>> vertices;
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries)
    {
        AdjGraph<string, double> graph;
        unordered_map<string, int> umap;
        vector<Arc<double>*> arcs;
        vector<double> res;

        int i, n = equations.size();
        string dividend, divisor;

        // ===== 构建图 =====
        for (i = 0; i < n; i++) {
            dividend = equations[i][0];
            divisor = equations[i][1];

            if (!umap.count(dividend)) {
                Node<string, double> node;
                node.val = dividend;
                node.first = nullptr;
                graph.vertices.push_back(node);
                umap[dividend] = graph.vertices.size() - 1;
            }
            if (!umap.count(divisor)) {
                Node<string, double> node;
                node.val = divisor;
                node.first = nullptr;
                graph.vertices.push_back(node);
                umap[divisor] = graph.vertices.size() - 1;
            }

            // 添加两条边：正向 + 反向
            Arc<double>* arc1 = new Arc<double>();
            arc1->val = values[i];
            arc1->vex = umap[divisor];
            arc1->next = graph.vertices[umap[dividend]].first;
            graph.vertices[umap[dividend]].first = arc1;
            arcs.push_back(arc1);

            Arc<double>* arc2 = new Arc<double>();
            arc2->val = 1.0 / values[i];
            arc2->vex = umap[dividend];
            arc2->next = graph.vertices[umap[divisor]].first;
            graph.vertices[umap[divisor]].first = arc2;
            arcs.push_back(arc2);
        }

        // ===== 查询阶段 =====
        n = queries.size();
        string start, target;
        int start_idx, target_idx;
        double ans;


        for (i = 0; i < n; i++) {
            start = queries[i][0];
            target = queries[i][1];

            if (!umap.count(start) || !umap.count(target)) {
                res.push_back(-1.0);
                continue;
            }

            start_idx = umap[start];
            target_idx = umap[target];

            if (start_idx == target_idx) {
                res.push_back(1.0);
                continue;
            }
            // index, prod
            // 节点索引，当前累乘

            stack<pair<int, double>> st;
            unordered_set<int> visited;
            
            st.push({start_idx, 1.0});

            ans = -1.0;
            // 深度优先遍历
            while (!st.empty()) {
                auto [curr, prod] = st.top();
                st.pop();

                if (curr == target_idx) {
                    ans = prod;
                    break;
                }

                if (visited.count(curr)){
                    continue;
                }
                
                visited.insert(curr);

                for (Arc<double>* p = graph.vertices[curr].first; p!=nullptr; p = p->next) {
                    if (!visited.count(p->vex)){
                        st.push({p->vex, prod * p->val});                        
                    }
                }
            }
            res.push_back(ans);
        }

        for (auto p : arcs)
            delete p;

        return res;
    }
};
