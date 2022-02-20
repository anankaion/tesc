#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> split_string(std::string string, char delim){
    std::vector<std::string> strings;
    std::string element;
    int prev = 0;

    for (int i = 0; i < string.length(); i++) {
        if (string.at(i) == delim) {
            element.clear();

            for (int j = prev; j < i; j++) {
                if (string[j] != delim) {
                    element.push_back(string[j]);
                }
            }

            strings.push_back(element);
            prev = i;
        }
    }

    element.clear();
    for (int i = prev+1; i < string.length(); i++) {
            element.push_back(string[i]);
    }

    strings.push_back(element);

    return strings;
}
