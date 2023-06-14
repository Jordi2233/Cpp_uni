#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>


int main()
{
    std::vector<std::string> marks = {"!", "@", "#", "$", "%", "^", "&", "*", "(", ")", "{", "}", "[", "]", ";", ":", ",", ".", "/"};
    // loading book - Lalka
    std::ifstream file("lalka.txt");

    // creating vector of string - words
    std::vector<std::string> words;
    std::string line;

    // adding to vector every word from Lalka
    while (getline(file, line))
    {
        std::stringstream iss(line);
        std::string word;
        while (iss >> word)
        {
            for (auto& ch: word)
            {
                std::ispunct(ch);
            }
            words.push_back(word);
        }
    }
    std::cout << words.size() << "\n";
    // sorting vector of words from Lalka
    std::sort(words.begin(), words.end());

    // creating a map that key is word, value is number of occurrences
    std::map<std::string, int> words_map;
    // adding to map if doesnt exits else add to value +1
    for (size_t i = 0; i < words.size(); ++i)
    {
        auto res = words_map.find(words[i]);
        if (res == words_map.end())
        {
            words_map.insert({words[i], 1});
        }
        else
        {
            res->second = res->second + 1;
        }
    }

    // print keys and values
    for (auto &el : words_map)
    {
        std::cout << "Word: " << el.first << "\tCount: " << el.second << "\n";
    }

    // print map size
    std::cout << words_map.size() << "\n";

    return 0;
}
