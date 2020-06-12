#pragma once

class Menu
{
public:
	Menu() = default;
	void ShowMainMenu();
	void ShowSubmenu();
	[[nodiscard]] int ReturnCurrentAction() const;
private:
	void read_action();
	void read_sub_action();
	int current_action;
};

