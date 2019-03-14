#pragma once

#include <vector>
#include <string>
#include <utility>


int Hash(const std::string& new_string);


class HashTable
{
public:
    HashTable();
    void Add(const std::string& key, const std::string& value);
    bool Has(const std::string& key) const;
    void Remove(const std::string& key);
    int GetHash(const std::string& new_string) const;
    const std::vector<std::vector<std::pair<std::string, std::string>>>&
    GetData() const;

private:
    std::vector<std::vector<std::pair<std::string, std::string>>> data_;
};
