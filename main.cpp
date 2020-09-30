#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

auto longest (std::string dna, std::vector<std::string> str) -> void;

auto main() -> int
{
    std::ifstream input ("sequences/20.txt");
    std::string dna = "";
    if (input.is_open())
    {
        while (input.good())
        {
            std::getline(input, dna);
        }
        input.close();
    }
    else {std::cout << "error" << "\n"; return 1;}
    //
    std::vector<std::string> strs {"AATG", "AGATC", "GAAA", "GATA", "TATC", "TCTAG", "TCTG", "TTTTTTCT"};
    longest (dna, strs);
}
//
auto longest (std::string dna, std::vector<std::string> str) -> void
{
    std::map<std::string, std::uint64_t> result;
    std::uint64_t sizeDna = dna.size();
    //
    for (const auto& s: str)
    {
        std::uint64_t temp = 0;
        std::uint64_t count = 0;
        const std::uint64_t sizeStr = s.size();
        std::uint64_t i = 0;
        while (i < sizeDna)
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
                if (temp > count) {count = temp;}
            }
            else {++i; temp = 0;}
        }
        result.insert({s, count});
    }
    //
    std::cout << '\n';
    for (auto const& i: result)
    {
        std::cout <<" { "<< i.first << ": ";
        std::cout << i.second << " }\n";
    }
    std::cout << '\n';
}