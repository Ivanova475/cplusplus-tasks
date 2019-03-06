#include<algorithm>

#include "hash_table.h"

const int hash_table_size = 1013;


int Hash1(const std::string& new_string)
{
    return 1 % hash_table_size;
}


int Hash2(const std::string& new_string)
{
    return new_string[0] - 0 % hash_table_size;
}


int Hash3(const std::string& new_string)
{
    int hash = 0;
    for (size_t i = 0; i < new_string.length(); i++)
    {
        hash += new_string[i] - 0;
    }
    return hash % hash_table_size;
}


int Hash4(const std::string& new_string)
{
    return new_string.length() % hash_table_size;
}


int Hash5(const std::string& new_string)
{
    int hash = 0;
    for (size_t i = 0; i < new_string.length(); i++)
    {
        hash += (new_string[i] << 2) * 179;
    }
    return hash % hash_table_size;
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
        return hash % hash_table_size;
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
    return Hash6(new_string);
}


const std::vector<std::vector<std::string>>& HashTable::GetData() const
{
    return data_;
}
