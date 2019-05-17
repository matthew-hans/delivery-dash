/************************************************
 * *Author: Matt Hans
 * *Date: 11/4/2018
 * *Description: menu class implementation used for generation of general purpose menus through vectors
 * **********************************************/

#include "Menu.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

Menu::Menu(vector<string> items)
{
    setMenuItems(items);
    setPromptText("");
}

Menu::Menu(string text, vector<string> items)
{
    setMenuItems(items);
    setPromptText(text);
}

void Menu::setMenuItems(vector<string> items)
{
    menuItems.clear();
    for (string i : items) {
        menuItems.push_back(i);
    }
}

void Menu::setPromptText(string text)
{
    promptText = text;
}

string Menu::getPromptText()
{
    return promptText;
}

int Menu::showMenu()
{
    unsigned int choice = 0;
    if (getPromptText() != "") {
        cout << "\n" << getPromptText() << "\n";
    }
    for (unsigned int i = 0; i < menuItems.size(); i++) {
        cout << i + 1 << ". " << menuItems[i] << "\n";
    }

    cin >> choice;
    while (cin.fail()|| (choice < 1 || choice > menuItems.size())) {
        cin.clear();
        cin.ignore(999,'\n');
        cout << "I'm sorry, that's not a valid choice. Please enter a choice between 1 and " << menuItems.size() << endl;
        cin >> choice;
    }
    return choice;
}
