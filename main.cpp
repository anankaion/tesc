#include <iostream>
#include <fstream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

#include "split_string.h"

std::list<std::string> read_file(std::string filename){
    std::ifstream file(filename);
    std::list<std::string> file_contents;
    std::string line;

    while (getline(file, line)) {
        file_contents.push_back(line);
    }

    file.close();

    return file_contents;
}

void write_file(std::string filename, std::list<std::string>& file_contents){
    std::ofstream file(filename);
    std::list<std::string>::iterator it;

    for (it = file_contents.begin(); it != file_contents.end(); it++) {
        file << *it << "\n";
    }

    file.close();
}

void add(std::string& string, int& pos, std::list<std::string>& file_contents){
    std::list<std::string>::iterator it = file_contents.begin();

    for (int i = 0; i < pos; i++) {
        it++;
    }

    file_contents.insert(it, string);
    pos++;
}

void rm(int& pos, std::list<std::string>& file_contents){
    std::list<std::string>::iterator it = file_contents.begin();

    for (int i = 0; i < pos-1; i++) {
        it++;
    }

    file_contents.erase(it);
    pos--;
}

void parse_instruction(std::string& instruction, int &pos, std::list<std::string>& file_contents){
    std::vector<std::string> parts;

    if (instruction.at(0) == 'r' && instruction.at(1) == 'm') {
        rm(pos, file_contents);
    } else {
        parts = split_string(instruction, ' ');

        if (parts.at(0) == "add") {
        add(parts[1], pos, file_contents);
        } else if (parts.at(0) == "set") {
            pos = stoi(parts.at(1));
        }
    }
}

void process_instructions(std::list<std::string>& instructions, int& pos, std::list<std::string>& file_contents){
    std::list<std::string>::iterator it;

    for (it = instructions.begin(); it != instructions.end(); it++) {
        parse_instruction(*it, pos, file_contents);
    }
}

int main(){
    std::list<std::string> file_contents;
    std::list<std::string> instructions;
    int pos = 0;

    std::string filename = "test.txt";

    file_contents = read_file(filename);
    instructions = read_file("instructions.txt");

    process_instructions(instructions, pos, file_contents);

    write_file(filename, file_contents);
}