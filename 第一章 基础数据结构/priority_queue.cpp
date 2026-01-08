#include <vector>
#include <iostream>

class priority_queue {
public:
    priority_queue() = default; // 不再需要哨兵

    void push(int x) {
        v.push_back(x);
        int i = static_cast<int>(v.size()) - 1; // 新元素下标
        while (i > 0) {
            int p = (i - 1) / 2;                // 父节点
            if (v[i] >= v[p]) break;            // 小顶堆：子 >= 父 就满足
            std::swap(v[i], v[p]);
            i = p;
        }
    }
    // 弹出并返回堆顶（最小值）
    int pop() {
        int res = v[0];
        int last = static_cast<int>(v.size()) - 1;
        v[0] = v[last];
        v.pop_back();
        int n = static_cast<int>(v.size());
        int i = 0;
        while (true) {
            int l = 2 * i + 1;
            if (l >= n) break;                  // 没有孩子了

            int r = l + 1;
            int son = l;
            if (r < n && v[r] < v[l]) son = r;  // 选更小的孩子

            if (v[son] < v[i]) {
                std::swap(v[i], v[son]);
                i = son;
            }
            else {
                break;
            }
        }
        return res;
    }

    int top() const {
        if (empty()) throw std::out_of_range("top from empty heap");
        return v[0];
    }

    void foreach() const {
        for (int x : v) {
            std::cout << x << "\n";
        }
    }

    bool empty() const { return v.empty(); }
    int size() const { return static_cast<int>(v.size()); }

private:
    std::vector<int> v;
};