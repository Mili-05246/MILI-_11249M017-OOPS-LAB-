

#include <bits/stdc++.h>
using namespace std;

class Maze {
    vector<string> grid;
    int R = 0, C = 0;
    pair<int,int> S = {-1,-1}, E = {-1,-1};

public:
    Maze() = default;

    // Load maze from file; throws runtime_error on problems
    void loadFromFile(const string &file) {
        ifstream f(file);
        if (!f.is_open()) throw runtime_error("Cannot open maze file: " + file);

        string line;
        grid.clear();
        while (getline(f, line)) {
            // remove possible carriage return at line end (Windows files)
            if (!line.empty() && line.back() == '\r') line.pop_back();
            grid.push_back(line);
        }
        f.close();

        if (grid.empty()) throw runtime_error("Maze file is empty.");

        // Ensure all rows have same length; if not, pad with walls '#'
        C = 0;
        for (auto &r : grid) if ((int)r.size() > C) C = r.size();
        for (auto &r : grid) if ((int)r.size() < C) r += string(C - r.size(), '#');

        R = grid.size();

        // find S and E
        S = {-1,-1}; E = {-1,-1};
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 'S') S = {i,j};
                else if (grid[i][j] == 'E') E = {i,j};
            }
        }
        if (S.first == -1) throw runtime_error("Start 'S' not found in maze.");
        if (E.first == -1) throw runtime_error("Exit 'E' not found in maze.");
    }

    bool inBounds(int r, int c) const {
        return (r >= 0 && r < R && c >= 0 && c < C);
    }

    // safe getter: throws if out of bounds
    char get(int r, int c) const {
        if (!inBounds(r,c)) throw out_of_range("Maze::get out of bounds");
        return grid[r][c];
    }

    // safe setter: does nothing if target is S or E; throws if out of bounds
    void setp(int r, int c, char v) {
        if (!inBounds(r,c)) throw out_of_range("Maze::setp out of bounds");
        if (grid[r][c] == 'S' || grid[r][c] == 'E') return;
        grid[r][c] = v;
    }

    int rows() const { return R; }
    int cols() const { return C; }
    pair<int,int> start() const { return S; }
    pair<int,int> exitp() const { return E; }

    void display() const {
        for (const auto &row : grid) cout << row << "\n";
    }

    // Return a copy of the Maze (default copy is fine)
    Maze copy() const { return *this; }
};


// Abstract solver (base class)
class Solver {
protected:
    Maze &m;
    int visitedNodes = 0;

public:
    Solver(Maze &mz) : m(mz) {}
    virtual bool solve() = 0;
    int getVisited() const { return visitedNodes; }
    virtual ~Solver() {}
};


// BFS solver
class BFSSolver : public Solver {
public:
    BFSSolver(Maze &mz) : Solver(mz) {}

    bool solve() override {
        int R = m.rows(), C = m.cols();
        // visited and parent
        vector<vector<char>> visited(R, vector<char>(C, 0));
        vector<vector<pair<int,int>>> parent(R, vector<pair<int,int>>(C, {-1,-1}));

        auto S = m.start(), E = m.exitp();
        queue<pair<int,int>> q;

        // push start and mark parent of start as itself (sentinel)
        q.push(S);
        visited[S.first][S.second] = 1;
        parent[S.first][S.second] = S;

        int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int r = cur.first, c = cur.second;
            ++visitedNodes;

            if (r == E.first && c == E.second) {
                // reconstruct path using parent; parent[S] == S sentinel stops loop
                int cr = r, cc = c;
                while (!(cr == S.first && cc == S.second)) {
                    auto p = parent[cr][cc];
                    // safety check
                    if (p.first == -1) break;
                    // mark only path cells (not S/E)
                    try { m.setp(cr, cc, '*'); } catch (...) { /* ignore */ }
                    cr = p.first; cc = p.second;
                }
                return true;
            }

            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                char ch;
                try { ch = m.get(nr,nc); } catch (...) { continue; }
                if (!visited[nr][nc] && ch != '#') {
                    visited[nr][nc] = 1;
                    parent[nr][nc] = {r,c};
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }
};


// DFS solver (iterative)
class DFSSolver : public Solver {
public:
    DFSSolver(Maze &mz) : Solver(mz) {}

    bool solve() override {
        int R = m.rows(), C = m.cols();
        vector<vector<char>> visited(R, vector<char>(C,0));
        vector<vector<pair<int,int>>> parent(R, vector<pair<int,int>>(C, {-1,-1}));

        auto S = m.start(), E = m.exitp();
        stack<pair<int,int>> st;

        st.push(S);
        visited[S.first][S.second] = 1;
        parent[S.first][S.second] = S; // sentinel

        int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};

        while (!st.empty()) {
            auto cur = st.top(); st.pop();
            int r = cur.first, c = cur.second;
            ++visitedNodes;

            if (r == E.first && c == E.second) {
                int cr = r, cc = c;
                while (!(cr == S.first && cc == S.second)) {
                    auto p = parent[cr][cc];
                    if (p.first == -1) break;
                    try { m.setp(cr, cc, '*'); } catch (...) {}
                    cr = p.first; cc = p.second;
                }
                return true;
            }

            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                char ch;
                try { ch = m.get(nr,nc); } catch (...) { continue; }
                if (!visited[nr][nc] && ch != '#') {
                    visited[nr][nc] = 1;
                    parent[nr][nc] = {r,c};
                    st.push({nr,nc});
                }
            }
        }
        return false;
    }
};


int main(int argc, char** argv) {
    string fname = "maze.txt";
    if (argc >= 2) fname = argv[1];

    Maze base;
    try {
        base.loadFromFile(fname);
    } catch (const exception &ex) {
        cerr << "Error loading maze: " << ex.what() << "\n";
        return 1;
    }

    cout << "Original Maze:\n";
    base.display();

    // BFS on copy
    Maze m_bfs = base.copy();
    BFSSolver bfs(m_bfs);
    bool bfs_ok = false;
    try {
        bfs_ok = bfs.solve();
    } catch (const exception &ex) {
        cerr << "Runtime error during BFS: " << ex.what() << "\n";
        return 1;
    }

    cout << "\nBFS Result:\n";
    m_bfs.display();
    cout << "BFS visited nodes: " << bfs.getVisited() << "\n";
    cout << "BFS found path: " << (bfs_ok ? "YES" : "NO") << "\n";

    // DFS on copy
    Maze m_dfs = base.copy();
    DFSSolver dfs(m_dfs);
    bool dfs_ok = false;
    try {
        dfs_ok = dfs.solve();
    } catch (const exception &ex) {
        cerr << "Runtime error during DFS: " << ex.what() << "\n";
        return 1;
    }

    cout << "\nDFS Result:\n";
    m_dfs.display();
    cout << "DFS visited nodes: " << dfs.getVisited() << "\n";
    cout << "DFS found path: " << (dfs_ok ? "YES" : "NO") << "\n";

    return 0;
}
