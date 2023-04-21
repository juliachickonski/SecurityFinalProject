#include <iostream>
#include <array>
#include <vector>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
/*
bool check_for_exit(std::string question) {
    // Ask if they want to leave and leave on "n"
    // Returns true if they want to exit, false if still want to continue
    std::string leave = "n";
    std::cout << "\nDo you have more to your order? ";
    std::cin >> leave;
    if (leave[0] == 'n' || leave[0] == 'N') {
        return true;
    }
    return false;
}


int get_menu_choice(const std::array<std::string, 4>& choices) {
    // This will print and return the menu choice
    int choice = 3;

    for (int i = 0; i < choices.size(); i++) {
        std::cout << "[" << i << "] " << choices[i] << "\n";
    }
    std::cout << "Please select your action from the menu: ";
    std::cin >> choice;
    return choice;
}

std::vector<std::string> get_lines(string filename) {
    std::vector<string> lines{};

    // create file stream for reading
    std::ifstream infile{ 'menu.csv' };

    if (!infile) {
        std::cout << "... annoying";
    }
    while (infile) {
        string line{};
        std::getline(infile, line);
        lines.push_back(line);
    }

    return lines;
}
*/