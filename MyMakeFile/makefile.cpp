#include "makefile.h"

MakeFile MakeFile::file_read(const std::string &path) {
    MakeFile makefile;

    std::ifstream fin(path);
    if (!fin.is_open()) 
        throw std::runtime_error("Wrong path to file: " + path);

    // parse file
    auto cur = makefile.targets.end();
    for (std::string str; std::getline(fin, str);) {
        if (!isspace(str[0])) {
            std::istringstream iss(str);
            std::string name, dep;
            dependencies deps;
            iss >> name; name.pop_back();
            if (makefile.targets.find(name) != makefile.targets.end())
                throw std::runtime_error("Ambiguous target name: " + name);
            while (iss >> dep) deps.push_back(dep); 
            cur = makefile.targets.emplace(name, std::make_pair(deps, actions())).first;
        } else 
            cur->second.second.push_back(str);
    }

    fin.close();

    // Checking for undefined dependency
    for (const auto& t : makefile.targets)
        for (const auto& ref : t.second.first)
            if (!makefile.targets.count(ref))
                throw std::runtime_error("Existence of an undefined dependency" + ref);

    // Checking for cycled referencies
    std::unordered_set<std::string> v, s;
    for (auto& t : makefile.targets) {
        std::string start = t.first;
        if (!v.count(start) && makefile.dfs(start, v, s))
            throw std::runtime_error("Cycled refs: " + start);
    }

    fin.close();
    return makefile;
}

bool MakeFile::dfs(const std::string &target, std::unordered_set<std::string> &v, std::unordered_set<std::string>& s) const {
    v.insert(target);
    s.insert(target);
    const auto& deps = targets.at(target).first;
    for (const auto& dep : deps) {
        if (!v.count(dep)) {
            if (dfs(dep, v, s))
                return true;
        } else if (s.count(dep))
            return true;
    }
    s.erase(target);
    return false;
}


void MakeFile::build(const std::string& target) {
    auto t = targets.find(target);
    if (t == targets.end())
        throw std::invalid_argument("Target not found: " + target);

    for (const auto& dep : t->second.first)
        build(dep);
    
    if (done.count(target))
        return;

    std::cout << t->first << ':' << std::endl;
    for (const auto& act : t->second.second)
        std::cout << act << std::endl;
    done.insert(target);
}