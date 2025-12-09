// Last updated: 12/8/2025, 11:28:19 PM
class Path {
private:
    unordered_map<string, Path*> path;
    string name;
    bool file;
    string content = "";
public:
    Path(string name, bool file) : name(name), file(file) {};
    bool isFile() { return file; }

    void setFile(bool isSet) {
        this->file = isSet;
    }

    bool setName(string name) { 
        if (this->name == name) return false;
        this->name = name; 
        return true;
    }

    bool addContent(string content) {
        if (!isFile()) return false;
        this->content += content;
        return true;
    }

    string readContent() { return content; }

    bool addPath(string pathName) {
        if (isFile()) return false;
        path[pathName] = new Path(pathName, false);
        return true;
    }

    vector<string> getList() {
        if (isFile()) return {name};
        vector<string> res;
        for (auto& [name, p] : path) {
            res.push_back(name);
        }
        sort(res.begin(), res.end());
        return res;
    }

    Path* getPath(string pathName) {
        if (path.find(pathName) == path.end()) return nullptr;
        else return path[pathName];
    }
};


class FileSystem {
private:
    Path *root;

    Path* findPath(string filepath, bool isMake) {
        Path* cur = root;
        string temp = "";
        for (int i = 1; i <= filepath.length(); ++i) {
            if (filepath[i] == '/' || i == filepath.length() && !temp.empty()) {
                if (cur->getPath(temp) == nullptr) {
                    if (isMake) {
                        cur->addPath(temp);
                    }
                }
                cur = cur->getPath(temp);
                temp = "";
            } else if (isalpha(filepath[i])) {
                temp += filepath[i];
            }
        }
        return cur;
    }

public:
    FileSystem() {
        root = new Path("root", false);
    }
    
    vector<string> ls(string path) {
        return findPath(path, false)->getList();
    }
    
    void mkdir(string path) {
        findPath(path, true);
    }
    
    void addContentToFile(string filePath, string content) {
        Path* file = findPath(filePath, true);
        file->setFile(true);
        file->addContent(content);
    }
    
    string readContentFromFile(string filePath) {
        return findPath(filePath, false)->readContent();
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */