#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>

auto longest(const std::string_view dna, const auto &str) -> void;

auto main(int argc, char *argv[]) -> int {
  if ( argc < 2 || argc > 2) {
    std::cout << "usage ./main sequences/xx.txt";
    return 1;
  }
  std::ifstream input(argv[1]);
  std::string dna{};
  if (input.is_open()) {
    while (input.good())
      std::getline(input, dna);

    input.close();
  } else {
    std::cerr << "- failed to open file...";
    return 2;
  }
  //
  constexpr std::array<std::string_view, 8> strs = {
      "AATG", "AGATC", "GAAA", "GATA", "TATC", "TCTAG", "TCTG", "TTTTTTCT"};
  longest(dna, strs);
}
//
auto longest(const std::string_view dna, const auto &str) -> void {
  std::unordered_map<std::string_view, std::size_t> result;
  std::size_t sizeDna = dna.size();
  //
  for (auto &&s : str) {
    std::size_t temp = {};
    std::size_t count = {};
    const std::size_t sizeStr = s.size();
    std::size_t i = {};
    while (i < sizeDna - sizeStr) {
      if (dna.substr(i, sizeStr) == s) {
        temp++;
        i += sizeStr;
      } else {
        ++i;
        temp = 0;
      }
      if (temp > count) {
        count = temp;
      }
    }
    result.insert(std::make_pair(s, count));
  }
  //
  for (  auto &&[key,val] : result) {
    std::cout << " { " << key << ": "
    << val << " }\n";
  }
}
