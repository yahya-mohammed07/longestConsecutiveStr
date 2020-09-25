#include <iostream>

int longest (std::string dna, std::string str);

auto main() -> int
{
    std::string dna = "ACTTTATTGCGCCCACAGTGGCTTTTGTCTACTGATTCCATAGATAATGACAAATGTTCAAGGGGTTCTGGTACTTAGTCCGATCTCAGTGCGACTCGGGGGCGAACGTCGTGGTTATAAACTCGTCCAGATGCCGGCGCCAAACAAATATGATCCCATTGTGCACCCCCACTGGTCAGAACTCTCGGTGCTTAAGCGATACACGCGTCCGTGAGCATTCAACACCCAACTACTAGTCCGGTAATCTGAATGCACACGTGGCCCGGGTTACCGGGATGCCGAAAGAAAGAAAG";
    std::string pattren = "GAAA";
    std::cout << longest(dna, pattren) << std::endl;
}

auto longest (std::string dna, std::string pattren) -> int
{
    int maxCount = 0;
    int temp = 0;
    std::string next = "";
    std::string next2 = "";

    for (int i = 0; i < dna.size() - pattren.size(); i += pattren.size())
    {
        next = "";
        next2 = "";
        // to store string from 0 to len of str (key)
        for (int j = i; j < pattren.size() + i; ++j)
        {
            next += dna[j];
        }
        // if the temp str == the pattren then...
        if (next == pattren)
        {
            for (int k = i; k < pattren.size() + i; ++k)
            {
                next2 += dna[k];
            }
            if (next == next2)
            {
                temp++;
            }
            if (temp > maxCount)
            {
                maxCount = temp;
            }
        }
    }
    return maxCount;
}