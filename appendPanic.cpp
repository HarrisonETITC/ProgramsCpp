#include <iostream>
#include <string>
#include <algorithm>
#include <set>

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::set<char> unique_chars(input.begin(), input.end());

    int result_length = input.size() - unique_chars.size();

    std::cout << result_length << std::endl;

    return 0;
}