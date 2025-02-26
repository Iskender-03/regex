#include <iostream>
#include <regex>
#include <string>

int main()
{
    std::string text = "now 22.02.2025 10:33, then 30.02.2025 25:61, and 23.02.2025 11:45.";

    std::regex pattern(R"((0[1-9]|[12][0-9]|3[01])\.(0[1-9]|1[0-2])\.\d{4} (0[0-9]|1[0-9]|2[0-3]):([0-5][0-9]))");

    std::smatch matches;
    std::string::const_iterator searchStart = text.cbegin();

    while (std::regex_search(searchStart, text.cend(), matches, pattern))
    {
        std::cout << "correct : " << matches[0] << std::endl;

        searchStart = matches.suffix().first;
    }

    return 0;
}