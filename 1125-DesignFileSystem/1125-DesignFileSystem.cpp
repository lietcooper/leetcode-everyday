// Last updated: 12/8/2025, 11:26:29 PM
class FileSystem {
    class Trie {
    public:
        string name;
        int value;
        unordered_map<string, Trie*> path;
        Trie(string name, int value) : name(name), value(value) {}
        ~Trie() {
            for (auto& [name, p] : path) {
                delete p;
            }
        }
    };

    Trie root = Trie("root", 0);
public:
    FileSystem() {
        
    }
    
    vector<string> split(string path) {
        vector<string> res;
        string temp = "";
        for (int i = 1; i <= path.length(); ++i) {
            if (path[i] == '/' || i == path.length()) {
                res.push_back(temp);
                temp = "";
            } else {
                temp += path[i];
            }
        }
        return res;
    }

    bool createPath(string path, int value) {
        vector<string> paths = split(path);
        Trie* cur = &root;
        for (int i = 0; i < paths.size() - 1; ++i) {
            if (cur->path.find(paths[i]) == cur->path.end()) {
                return false;
            }
            cur = cur->path[paths[i]];
        }
        if (cur->path.find(paths.back()) != cur->path.end()) return false;
        cur->path[paths.back()] = new Trie(paths.back(), value); 
        return true;
    }
    
    int get(string path) {
        vector<string> paths = split(path);
        Trie* cur = &root;
        for (string& p : paths) {
            if (cur->path.find(p) == cur->path.end()) {
                return -1;
            }
            cur = cur->path[p];
        }
        return cur->value;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */