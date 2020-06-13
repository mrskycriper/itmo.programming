#include <iostream>
#include "Menu.hpp"


void Menu::ShowMainMenu()
{
	std::cout << "+-----------------------------------------------------+" << std::endl;
	std::cout << "| Available actions, enter actions number to execute: |" << std::endl;
	std::cout << "|  1) Read or Write Cube                              |" << std::endl;
	std::cout << "|  2) Validate current Cube                           |" << std::endl;
	std::cout << "|  3) Show current Cube                               |" << std::endl;
	std::cout << "|  4) Manual spinning                                 |" << std::endl;
	std::cout << "|  5) Generate Cube                                   |" << std::endl;
	std::cout << "|  6) Find path to complete current Cube              |" << std::endl;
	std::cout << "|  7) Exit program                                    |" << std::endl;
	std::cout << "+-----------------------------------------------------+" << std::endl;
	read_action();
}

void Menu::read_action()
{
	int buffer;
	std::cin >> buffer;
	if (buffer != 1 && buffer != 2 && buffer && buffer != 3 && buffer != 4 && buffer != 5 && buffer != 6 && buffer != 7)
	{
		std::cout << "Invalid action" << std::endl;
	}
	else
	{
		current_action = buffer;
	}
}

int Menu::ReturnCurrentAction() const
{
	return current_action;
}

void Menu::ShowSubmenu()
{
	std::cout << "+-----------------------------------------------------+" << std::endl;
	std::cout << "| Available actions, enter actions number to execute: |" << std::endl;
	std::cout << "|  1) Write current Cube state                        |" << std::endl;
	std::cout << "|  2) Read Cube state from file                       |" << std::endl;
	std::cout << "+-----------------------------------------------------+" << std::endl;
	read_sub_action();
}

void Menu::read_sub_action()
{
	int buffer;
	std::cin >> buffer;
	if (buffer != 1 && buffer != 2)
	{
		std::cout << "Invalid subaction" << std::endl;
	}
	else
	{
		current_action = buffer;
	}
}
