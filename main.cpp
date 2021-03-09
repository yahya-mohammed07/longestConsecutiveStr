#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

auto longest (const std::string& , const std::vector<std::string>& ) -> void;

auto main(int argc, char *argv[]) -> int
{
    if ( argc != 2 )
    {
        std::cout << "usage ./main sequences/xx.txt...";
        return -1;
    }
    std::ifstream input (argv[1]);
    std::string dna = "";
    if ( input.is_open() )
    {
        while ( input.good() )
            std::getline(input, dna);

        input.close();
    }
    else { std::cerr << "- failed to open file..."; return 1;}
    //
    const std::vector<std::string> strs {"AATG", "AGATC", "GAAA", "GATA", "TATC", "TCTAG", "TCTG", "TTTTTTCT"};
    longest (dna, strs);
}
//
auto longest (const std::string& dna, const std::vector<std::string>& str) -> void
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
        while (i < sizeDna - sizeStr)
        {
            if (dna.substr(i, sizeStr) == s)
            {
                temp++;
                i += sizeStr;
            }
            else {++i; temp = 0;}
            if (temp > count) {count = temp;}
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
