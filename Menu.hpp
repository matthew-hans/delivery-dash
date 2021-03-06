/************************************************
 * *Author: Matt Hans
 * *Date: 11/4/2018
 * *Description: menu class declaration used for general purpose menu creation
 * **********************************************/

#ifndef MENU_HPP
#define MENU_HPP


#include <iostream>
#include <string>
#include <vector>

class Menu {

private:
    std::vector<std::string> menuItems;
    std::string promptText;

public:
    Menu(std::vector<std::string> menuItems);
    Menu(std::string promptText, std::vector<std::string> menuItems);
    int showMenu();
    void setPromptText(std::string text);
    std::string getPromptText();
    void setMenuItems(std::vector<std::string> menuItems);
};


#endif
