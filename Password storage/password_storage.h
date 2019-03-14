#pragma once

#include <vector>
#include <string>
#include <utility>

#include "hash_table.h"


std::string EncodeString(const std::string& string_to_encode);
std::string DecodeString(const std::string& string_to_decode);


class PasswordStorage
{
public:
    std::string GetPassword(const std::string& login) const;

    int GetPasswordHash() const;

    void Add(const std::string& login, const std::string& password);
    void Print();
    void ChangePassword(const std::string& new_password);

private:
    HashTable data_;
    int password_hash_ = 6123165;
};
