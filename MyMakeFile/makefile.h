#ifndef MAKEFILE_H
#define MAKEFILE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

class MakeFile {
public:
    MakeFile() = default;
    MakeFile(const MakeFile& mf);
    MakeFile(const std::string& path);

    void build(const std::string& target);

private:
    bool hasCycle() const;
    static MakeFile file_read(const std::string& path);

    using dependencies = std::vector<std::string>;
    using actions = std::vector<std::string>;
    std::unordered_map<std::string, std::pair<dependencies, actions>> targets;
};

#endif // MAKEFILE_H