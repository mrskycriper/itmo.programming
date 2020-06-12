#include <iostream>
#include "Menu.hpp"
#include "Cube.hpp"
#include "IO.hpp"
#include "Validator.hpp"


int main()
{
	Menu NewMenu{};
	Cube NewCube;
	int ActionNumber;
	do
	{
		NewMenu.ShowMainMenu();
		ActionNumber = NewMenu.ReturnCurrentAction();
		if (ActionNumber == 1)
		{
			int SubActionNumber;
			NewMenu.ShowSubmenu();
			SubActionNumber = NewMenu.ReturnCurrentAction();
			if (SubActionNumber == 1)
			{
				std::cout << "Enter file name:" << std::endl;
				std::string Name;
				std::cin >> Name;
				IO::Write(Name, NewCube.GetCube());
			}
			else if (SubActionNumber == 2)
			{
				std::cout << "Enter file name:" << std::endl;
				std::string Name;
				std::cin >> Name;
				IO::Read(Name, NewCube.GetCube());
			}
		}
		else if (ActionNumber == 2)
		{
			bool isValid = Validator::Validate(NewCube.GetCube());
			if (!isValid)
			{
				std::cout << "Invalid Cube" << std::endl;
			}
			else
			{
				isValid = NewCube.FindPath();
				if (isValid)
				{
					std::cout << "Correct Cube" << std::endl;
				}
				else
				{
					std::cout << "Invalid Cube" << std::endl;
				}
			}
		}
		else if (ActionNumber == 3)
		{
			NewCube.Print();
		}
		else if (ActionNumber == 4)
		{
			NewCube.ManualControl();
		}
		else if (ActionNumber == 5)
		{
			NewCube.Generate();
		}
		else if (ActionNumber == 6)
		{
			bool is_valid = Validator::Validate(NewCube.GetCube());
			if (is_valid)
			{
				is_valid = NewCube.FindPath();
				if (is_valid)
				{
					NewCube.ReturnPath();
				}
				else
				{
					std::cout << "Invalid Cube" << std::endl;
				}
			}
			else
			{
				std::cout << "Invalid Cube" << std::endl;
			}
		}

	} while (ActionNumber != 7);
	return 0;
}
