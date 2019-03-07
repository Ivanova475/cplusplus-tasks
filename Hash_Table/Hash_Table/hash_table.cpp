#include<algorithm>

#include "hash_table.h"

const int hash_table_size = 1013;


int Hash1(const std::string& new_string)
{
    return 1;
}


int Hash2(const std::string& new_string)
{
    return new_string[0];
}


int Hash3(const std::string& new_string)
{
    int hash = 0;
    for (size_t i = 0; i < new_string.length(); i++)
    {
        hash += new_string[i];
    }
    return hash;
}


int Hash4(const std::string& new_string)
{
    return new_string.length();
}


int Hash5(const std::string& new_string)
{
    int hash = 0;
    for (size_t i = 0; i < new_string.length(); i++)
    {
        hash += (new_string[i] << 2) * 179;
    }
    return hash;
}


int Hash6(const std::string& new_string)
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


void HashTable::Add(const std::string& new_string)
{
    if (!Has(new_string))
    {
        data_[GetHash(new_string)].push_back(new_string);
    }
}


bool HashTable::Has(const std::string& new_string) const
{
    int hash = GetHash(new_string);
    auto it = std::find(begin(data_[hash]), end(data_[hash]), new_string);
    if (it == end(data_[hash]))
    {
        return false;
    }
    else
    {
        return true;
    }
}


void HashTable::Remove(const std::string& new_string)
{
    int hash = GetHash(new_string);
    auto it = std::find(begin(data_[hash]), end(data_[hash]), new_string);
    data_[hash].erase(it);
}


int HashTable::GetHash(const std::string& new_string) const
{
    return Hash4(new_string) % hash_table_size;
}


const std::vector<std::vector<std::string>>& HashTable::GetData() const
{
    return data_;
}
