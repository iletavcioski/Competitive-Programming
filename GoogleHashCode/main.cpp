#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;
struct skill {
    string name;
    int level;
};

struct prog {
    string name;
    int days;
    int score;
    int best;
    vector<skill> skills;
};

bool compare1(const skill &a, const skill &b) {
    return a.level > b.level;
}

bool compare2(pair<string, vector<skill> > &a, pair<string, vector<skill> > &b) {
    
    
    return (a.second[0].level + a.second[a.second.size() - 1].level)  > (b.second[0].level + b.second[b.second.size() - 1].level);
    
}

bool compare3(const prog &a, const prog &b) {
    
    return a.score > b.score;
    
}

int main() {

    freopen("b.txt", "r", stdin);
    freopen("bo.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    //cout << m << endl;
    vector<pair<string, vector<skill> > > developers;
    //cout << "vleze" << endl;
    for (int i = 0; i < n; i++) {
        string s2;
        int t;
        cin >> s2 >> t;
        vector<skill> vec;
        for (int j = 0; j < t; j++) {
            string s1;
            int num;
            cin >> s1 >> num;
            vec.push_back({s1, num});
        }
        sort(vec.begin(), vec.end(), compare1);
       
        developers.push_back({s2, vec});
    }
   
    //cout << m << endl;
    sort(developers.begin(), developers.end(), compare2);
   // cout << m << endl;
    vector<int> vis(n, 0);
    vector<prog> projects;
    //cout << "vleze" << endl;
    //cout << m << endl;
    for (int i = 0; i < m; i++) {
         //cout << "vleze" << i << endl;
        string name;
        int d, s2, b, t;
        cin >> name >> d >> s2 >> b >> t;
        prog g;
        g.name = name;
        g.days = d;
        g.score = s2;
        g.best = b;
        for (int j = 0; j < t; j++) {
            string s1;
            int num;
            cin >> s1 >> num;
            g.skills.push_back({s1, num});
        }
        //sort(g.skills.begin(), g.skills.end());
        projects.push_back(g);
    }
    //cout << "vleze" << endl;

    sort(projects.begin(), projects.end(), compare3);
    for (int i = 0; i < projects.size(); i++) {
        for (int j = i + 1; j < projects.size(); j++) {
                bool cc = false;
                if (j - i == 1)
            for (int k = 0; k < projects[i].skills.size(); k++) {
                for (int l = 0; l < projects[j].skills.size(); l++) {
                    if (projects[i].skills[k].name == projects[j].skills[l].name) {
                        swap(projects[j], projects[projects.size() - 1]);
                        cc = true;
                        break;
                    }
                }
                if (cc) {
                    break;
                }
            }
        }
    }
    vector<pair<string, vector<string> > >res;

    //cout << m << endl;
    vector<int> dev(developers.size(), 0);
    for (int i = 0; i < projects.size(); i++) {
        vector<string> people;
        vector<int> viss(projects[i].skills.size(), 0);
        int treba = projects[i].skills.size();
        vector<int> visd(developers.size(), 0);
        for (int j = 0; j < projects[i].skills.size(); j++) {
            for (int k = 0; k < developers.size(); k++) {
                if (viss[j]) {
                    break;
                }

                for (int kk = 0; kk < developers[k].second.size(); kk++) {
                    if (!visd[k] && !viss[j] && developers[k].second[kk].name == projects[i].skills[j].name  && developers[k].second[kk].level >= projects[i].skills[j].level) {
                        people.push_back(developers[k].first);
                        viss[j] = true;
                        visd[k] = true;
                        treba--;
                        break;
                    } 
                }

            }
        }
        if (treba == 0) {
            res.push_back({projects[i].name, people});
        }
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << endl;
        for (int j = 0; j < res[i].second.size(); j++) {
            if (j) {
                cout << " ";
            }
            cout << res[i].second[j];
        }
        cout << endl;
    }


    return 0;
}