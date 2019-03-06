#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "hash_table.h"


std::string TrimWord(const std::string& raw_word)
{
    size_t begin_pos = 0;
    size_t word_length = raw_word.npos;

    for (size_t i = 0; i < raw_word.size(); i++)
    {
        if (isalpha(raw_word[i]))
        {
            begin_pos = i;
            break;
        }
    }

    for (size_t i = begin_pos; i < raw_word.size(); i++)
    {
        if (!isalpha(raw_word[i]))
        {
            word_length = i - begin_pos;
            break;
        }
    }

    return raw_word.substr(begin_pos, word_length);
}


int main()
{
    std::ifstream in_stream("cano.txt");
    HashTable words_freqs;
    std::string word;

    for (std::string word; in_stream >> word; )
    {
        words_freqs.Add(TrimWord(word));
    }

    std::ofstream out_stream("result_6.txt");
    std::vector<std::vector<std::string>> result_table = words_freqs.GetData();

    for (size_t i = 0; i < result_table.size(); i++)
    {
        out_stream << result_table[i].size() << "\n";
    }
    
    return 0;
}

