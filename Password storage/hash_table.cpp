#include <algorithm>

#include "hash_table.h"

const int hash_table_size = 1013;


int Hash(const std::string& new_string)
{

    if (new_string.length() == 0)
    {
        return 1;
    }
    else
    {
        int hash = 0;
        for (size_t i = 0; i < new_string.length(); i++)
        {
            hash = (hash << 1) ^ new_string[i];
        }
        return hash;
    }
}


HashTable::HashTable()
{
    data_.resize(hash_table_size);
}


void HashTable::Add(const std::string& key,
                         const std::string& value)
{
    if (!Has(key))
    {
        data_[GetHash(key)].push_back({key, value});
    }
}


bool HashTable::Has(const std::string& key) const
{
    const int hash = GetHash(key);
    for (auto it = begin(data_[hash]); it != end(data_[hash]); it++)
    {
        if (it->first == key)
        {
            return true;
        }
    }

    return false;
}


void HashTable::Remove(const std::string& key)
{
    const int hash = GetHash(key);
    for (auto it = begin(data_[hash]); it != end(data_[hash]); it++)
    {
        if (it->first == key)
        {
            data_[hash].erase(it);
            break;
        }
    }
}


int HashTable::GetHash(const std::string& new_string) const
{
    return Hash(new_string) % hash_table_size;
}


const std::vector<std::vector<std::pair<std::string, std::string>>>& HashTable::GetData() const
{
    return data_;
}
