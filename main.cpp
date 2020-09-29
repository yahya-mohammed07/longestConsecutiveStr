#include <iostream>

auto longest (std::string dna, std::string str) -> int;

auto main() -> int
{
    std::cout << "-enter the DNA sequence: ";
    std::string dna = "";
    std::cin >> dna;
    std::cout << "-enter the STR to search for: ";
    std::string str = "";
    std::cin >> str;
    std::cout << str <<": " <<longest(dna, str) << std::endl;
}
//
auto longest (std::string dna, std::string str) -> int
{
    long sizeDna = dna.size(), sizeStr = str.size();
    //
    int maxCount = 0;
    int temp = 0;
    //
    int i = 0;
    while (i < sizeDna - sizeStr)
    {
        std::string next = "";
        std::string next2 = "";
        for (int j = i; j < sizeStr + i; ++j)
        {
            next += dna[j];
        }
        if (next == str)
        {
            for (int k = i; k < sizeStr + i; ++k)
            {
                next2 += dna[k];
            }
            if (next2 == next)
            {
                temp++;
                i += sizeStr;
            }
        }
        else {++i;temp = 0;}
        if (temp > maxCount)
        {
            maxCount = temp;
        }
    }
    return maxCount;
}