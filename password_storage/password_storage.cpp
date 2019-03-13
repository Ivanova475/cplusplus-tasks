#include <iostream>
#include <iomanip>

#include "password_storage.h"


std::string EncodeString(const std::string& string_to_encode)
{
    std::string encoded_string = string_to_encode;
    for (size_t i = 0; i < encoded_string.size(); i++)
    {

        encoded_string[i] += (i + 1);
    }
    return encoded_string;
}


std::string DecodeString(const std::string& string_to_decode)
{
    std::string decoded_string = string_to_decode;
    for (size_t i = 0; i < decoded_string.size(); i++)
    {
        decoded_string[i] -= (i + 1);
    }
    return decoded_string;
}


std::string PasswordStorage::GetPassword(const std::string& login) const
{
    if (!data_.Has(login))
    {
        return "This login doesn't exist. Try again.";
    }
    auto password_storage_table = data_.GetData();
    int hash = data_.GetHash(login);
    for (const auto& item : password_storage_table[hash])
    {
        if (item.first == login)
        {
            return DecodeString(item.second);
        }
    }
}


int PasswordStorage::GetPasswordHash() const
{
    return password_hash_;
}


void PasswordStorage::Add(const std::string& login,
                          const std::string& password)
{
    data_.Add(login, EncodeString(password));
}


void PasswordStorage::Print()
{
    auto password_storage_table = data_.GetData();
    for (const auto& item: password_storage_table)
    {
        for (const auto& it: item)
        {
            std::cout << "login: " << std::setw(10) << it.first
                      << " - password: " << std::setw(10)
                      << DecodeString(it.second) << std::endl;
        }
    }
}


void PasswordStorage::ChangePassword(const std::string& new_password)
{
    password_hash_ = Hash(new_password);
}
