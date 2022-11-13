#include <stdio.h>
#include <vector>
#include <stack>
#include <map>
 
int portals[200002];
bool visited[200002];
int scc[200002];
int index_[200002];
int pos_[200002];
bool in_portal[200002];
int scc_size_node[200002];

std::vector<std::vector<int> > rgraph;
std::stack<int> stack;
void topological(int x) {
    if (visited[x]) {
        return;
    }
    visited[x] = true;
    topological(portals[x]);
    stack.push(x);
    return;
}
 
std::vector<int> scc_vec;
void dfs(int x, int scc_num) {
    if (scc[x]) {
        return;
    }
 
    scc[x] = scc_num;
    for (int i = 0; i < rgraph[x].size(); i++) {
        dfs(rgraph[x][i], scc_num);
    }
    scc_vec.push_back(x);
    index_[x] = scc_num - 1;
    pos_[x] = (int)scc_vec.size() - 1;
    return;
}
 
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
 
    std::vector<int> vec;
    rgraph.insert(rgraph.begin(), n + 1, vec);
    std::vector<int> in_portal(n + 1, 0);
 
    for (int i = 1; i <= n; i++) {
        scanf("%d", &portals[i]);
        in_portal[portals[i]] = true;
        rgraph[portals[i]].push_back(i);
    }
 
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) 
            topological(i);
    }
 
    int counter = 0;
 
    std::vector<std::vector<int> > scc_s;
    std::vector<int> starting_points;

    while (!stack.empty()) {
        int x = stack.top();
        stack.pop();
        if (!scc[x]) {
            counter++;
            scc_vec.clear();
            dfs(x, counter);
            scc_s.push_back(scc_vec);
        }
        scc_size_node[x] = scc_s[index_[x]].size();
        if (scc_size_node[x] == 1 && portals[x] != x) {
            scc_size_node[x] = 0;
        }
        if (in_portal[x] == 0) {
            starting_points.push_back(x);
        }
    }
 
 
    int idx = 0;
    std::vector<std::vector<int> > lists;
 
 
    for (int i = 0; i < starting_points.size(); i++) {
        int start_node = starting_points[i];
        std::vector<int> vec;
        while (scc_size_node[start_node] == 0) {
            index_[start_node] = idx;
            pos_[start_node] = (int)vec.size();
            vec.push_back(start_node);
            start_node = portals[start_node];
        }
        vec.push_back(start_node);
        idx++;
        lists.push_back(vec);
    }
 
    for (int i = 0; i < q; i++) {
        int query;
        int step;
        scanf("%d %d", &query, &step);
 
        if (scc_size_node[query] == 0) {
            int index = index_[query];
            int pos = pos_[query];
 
            pos += step;
            if (pos >= lists[index].size()) {
                step = pos - (int)lists[index].size() + 1;
                query = lists[index][lists[index].size() - 1];
 
                index = index_[query];
                pos = pos_[query];

                printf("%d\n", scc_s[index][(pos + step) % ((int)scc_s[index].size())]);
            } else {
                printf("%d\n", lists[index][pos]);
            }
        } else {
            int index = index_[query];
            int pos = pos_[query];
            printf("%d\n", scc_s[index][(pos + step) % ((int)scc_s[index].size())]);
        }
    }
    return 0;
}
