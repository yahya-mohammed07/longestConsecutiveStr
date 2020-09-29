#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

auto longest (std::string dna, std::vector<std::string> str) -> void;

auto main() -> int
{
    std::ifstream input ("/media/yahya/E2AC5C31AC5BFE8B/vs code/cppProjects/longestConsecutiveStr/sequences/10.txt");
    std::string dna = "";
    if (input.is_open())
    {
        while (input.good())
        {
            std::getline(input, dna);
        }
        input.close();
    }
    else {std::cout << "error" << "\n";}
    std::vector<std::string> strs {"AATG", "AGATC", "GAAA", "GATA", "TATC", "TCTAG", "TCTG", "TTTTTTCT"};
    longest(dna, strs);
}
//
auto longest (std::string dna, std::vector<std::string> str) -> void
{
    std::map<std::string, int> result;
    long sizeDna = dna.size();
    // FIXME: not working on small databases (all strs shoulb be in the sequence to work)
    for (auto s: str)
    {
        int maxCount = 0;
        long sizeStr = s.size();
        int temp = 0;
        //
        long i = 0;
        while (i < sizeDna - sizeStr)
        {
            std::string next = "";
            for (int j = i; j < sizeStr + i; ++j)
            {
                next += dna[j];
            }
            if (next == s)
            {
                temp++;
                i += sizeStr;
            }
            else {++i;temp = 0;}
            //
            if (temp > maxCount)
            {
                maxCount = temp;
            }
        }
        result.insert({s, maxCount});
    }
    //
    for (auto const& i: result)
    {
        std::cout << i.first << " : " << i.second << "\n";
    }
    std::cout << '\n';
}