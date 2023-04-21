#ifndef UI_H
#define UI_H

#include <vector>
#include <string>
#include <array>

bool check_for_exit(std::string);
int get_menu_choice(const std::array<std::string, 4>& choices);
std::vector<std::string> get_lines(std::string);

#endif