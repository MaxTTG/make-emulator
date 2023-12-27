#ifndef MAKEFILE_H
#define MAKEFILE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class MakeFile {
public:
    MakeFile() = default;

    static MakeFile file_read(const std::string& path);

    void build(const std::string& target);

private:
    bool dfs(const std::string& target, std::unordered_set<std::string>& v, std::unordered_set<std::string>& s) const;

    typedef std::vector<std::string> dependencies;
    typedef std::vector<std::string> actions;
    std::unordered_map<std::string, std::pair<dependencies, actions>> targets;
    std::unordered_set<std::string> done;
};

#endif // MAKEFILE_H