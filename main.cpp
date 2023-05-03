#include <iostream>
#include <unordered_set>
#include <vector>
#include <memory>

int main() {
    std::vector<int> vec = {100,101,1,95,0,23,95,4,24,23,6,0,5,5,67,100,99,1,4,7,23,2,2,2,3};

    auto newVec = std::make_unique<std::vector<int>>();

    auto foo = [](const std::vector<int>& vec)
    {
        auto tmpVec = std::make_unique<std::vector<int>>();
        std::unordered_set<int> set;

        for (auto tmp : vec) {
            set.insert(tmp);
        }
        for (auto tmp : set) {
            tmpVec->push_back(tmp);
        }
        return tmpVec;
    };

    newVec = foo(vec);
    for (auto p : *newVec)
    {
        std::cout << p << " ";
    }
    return 0;
}