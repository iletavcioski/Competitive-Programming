#include <bits/stdc++.h>

typedef long long ll;

std::vector<int> par(100001, -1);
std::vector<std::vector<int> > graph;
std::vector<std::string> names;
ll res = 0;

std::map<std::string, int> dfs(int x, int prev) {
    if (graph[x].size() == 0) {
        std::map<std::string, int> map;
        map[names[x]]++;
        return map;
    }

    std::map<std::string, int> new_map;
    for (int i = 0; i < graph[x].size(); i++) {
        int nex = graph[x][i];
        std::map<std::string, int> map = dfs(nex, -1);
        res += map[names[x]];
        for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++) {
            new_map[it->first] += it->second;
        }
    }
    new_map[names[x]]++;
    return new_map;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();

    std::string str;
    std::cin >> str;

    
    int next_node = 0;
    int cur_node = -1;
    int i = 0;
    while (i < str.size()) {
        std::string name = "";
        while (str[i] != '.' && str[i] != ',' && str[i] != ':') {
            name += str[i];
            i++;
        }
        
        if (name.size() > 0) {
            par[next_node] = cur_node;
            cur_node = next_node;
            names.push_back(name);
            next_node++;
        }

        if (str[i] == ':' || str[i] == ',' ) {
            i++;
            continue;
        }

        if (str[i] == '.') {
            cur_node = par[cur_node];
            i++;
            continue;
        }
    }
    std::vector<int> vec;
    graph.insert(graph.begin(), next_node, vec);
    for (int i = 1; i < next_node; i++) {
        graph[par[i]].push_back(i);
    }
    
    dfs(0, -1);
    std::cout << res << "\n";
    return 0;
}