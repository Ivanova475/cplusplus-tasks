#pragma once

#include <vector>
#include <string>


class HashTable
{
public:
    HashTable();
    void Add(const std::string& new_string);
    bool Has(const std::string& new_string) const;
    void Remove(const std::string& new_string);
    int GetHash(const std::string& new_string) const;
    const std::vector<std::vector<std::string>>& GetData() const;

private:
    std::vector<std::vector<std::string>> data_;
};

