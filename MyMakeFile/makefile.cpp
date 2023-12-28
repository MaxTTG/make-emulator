#include "makefile.h"

MakeFile::MakeFile(const MakeFile &mf) : targets(mf.targets), done(mf.done) {}

MakeFile::MakeFile(const std::string & path) { *this = file_read(path); }

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
    if (makefile.hasCycle())
        throw std::runtime_error("Cycled refs");

    fin.close();
    return makefile;
}

bool MakeFile::hasCycle() const {
    std::unordered_set<std::string> visited, inStack;
    std::stack<std::string> dfsStack;
    for (const auto& target : targets) {
        if (visited.count(target.first))
            continue;
        dfsStack.push(target.first);

        while (!dfsStack.empty()) {
            auto cur = dfsStack.top();
            if (!visited.count(cur)) {
                visited.insert(cur);
                inStack.insert(cur);
            } else {
                inStack.erase(cur);
                dfsStack.pop();
            }

            for (const auto& next : targets.at(cur).first) {
                if (!visited.count(next))
                    dfsStack.push(next);
                else if (inStack.count(next))
                    return true;
            }
        }
    }
    return false;
}


void MakeFile::build(const std::string &target)
{
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