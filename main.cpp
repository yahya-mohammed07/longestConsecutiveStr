#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

auto longest (std::string dna, std::vector<std::string> str) -> void;

auto main() -> int
{
    std::ifstream input ("sequences/5.txt");
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
    //
    std::vector<std::string> strs {"AATG", "AGATC", "GAAA", "GATA", "TATC", "TCTAG", "TCTG", "TTTTTTCT"};
    longest (dna, strs);
}
//
auto longest (std::string dna, std::vector<std::string> str) -> void
{
    std::map<std::string, long> result;
    long sizeDna = dna.size();
    // FIXME: not works on small sequences
    long temp = 0;
    for (const auto& s: str)
    {
        long count = 0;
        const long sizeStr = s.size();
        long i = 0;
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
            else {++i;temp = 0;}
        }
        result.insert({s, count});
    }
    //
    for (auto const& i: result)
    {
        std::cout << i.first << ": " << i.second << "\n";
    }
    std::cout << '\n';
}