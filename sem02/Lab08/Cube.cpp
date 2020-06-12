#include <iostream>
#include <vector>
#include <ctime>
#include "Cube.hpp"

Cube::Cube()
{
	data = new unsigned char* [sizeof(unsigned char*) * 6];
	for (int i = 0; i < 6; ++i)
	{
		data[i] = new unsigned char[sizeof(unsigned char) * 9];
		for (int j = 0; j < 9; ++j)
		{
			if (i == 0)
			{
				data[i][j] = 'y';
			}
			else if (i == 1)
			{
				data[i][j] = 'r';
			}
			else if (i == 2)
			{
				data[i][j] = 'g';
			}
			else if (i == 3)
			{
				data[i][j] = 'o';
			}
			else if (i == 4)
			{
				data[i][j] = 'w';
			}
			else
			{
				data[i][j] = 'b';
			}
		}
	}
	path = "";
}

void Cube::ManualControl()
{
	std::cout << "Rotate Cubes sides manually using following commands:" << std::endl;
	std::cout << "YL to rotate Yellow side to the left or YR to rotate to the right" << std::endl;
	std::cout << "RL to rotate Red side to the left or RR to rotate to the right" << std::endl;
	std::cout << "GL to rotate Green side to the left or GR to rotate to the right" << std::endl;
	std::cout << "OL to rotate Orange side to the left or OR to rotate to the right" << std::endl;
	std::cout << "YL to rotate Yellow side to the left or YR to rotate to the right" << std::endl;
	std::cout << "YL to rotate Yellow side to the left or YR to rotate to the right" << std::endl;
	std::cout << "Enter . to exit" << std::endl;
	char color, direction;
	while (true)
	{
		std::cin >> color;
		if (color == '.')
		{
			break;
		}
		else
		{
			std::cin >> direction;
			if (color == 'R')
			{
				if (direction == 'R')
				{
					RedRight();
				}
				else if (direction == 'L')
				{
					RedLeft();
				}
			}
			else if (color == 'B')
			{
				if (direction == 'R')
				{
					BlueRight();
				}
				else if (direction == 'L')
				{
					BlueLeft();
				}
			}
			else if (color == 'G')
			{
				if (direction == 'R')
				{
					GreenRight();
				}
				else if (direction == 'L')
				{
					GreenLeft();
				}
			}
			else if (color == 'O')
			{
				if (direction == 'R')
				{
					OrangeRight();
				}
				else if (direction == 'L')
				{
					OrangeLeft();
				}
			}
			else if (color == 'Y')
			{
				if (direction == 'R')
				{
					YellowRight();
				}
				else if (direction == 'L')
				{
					YellowLeft();
				}
			}
			else if (color == 'W')
			{
				if (direction == 'R')
				{
					WhiteRight();
				}
				else if (direction == 'L')
				{
					WhiteLeft();
				}
			}
			else
			{
				std::cout << "Bad color." << std::endl;
			}
			if (direction != 'R' && direction != 'L')
			{
				std::cout << "Bad rotation." << std::endl;
			}

		}
		//show();
	}
}

void Cube::Print()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j += 3)
		{
			if (i == 0 || i == 4 || i == 5)
			{
				std::cout << "        ";
			}
			if (i == 1)
			{
				std::cout << data[i][j] << " " << data[i][j + 1] << " " << data[i][j +
																				   2]
						  << " | " << data[i + 1][j] << " " << data[i + 1][j + 1] << " " << data[i + 1][j + 2] << " | "
						  << data[i + 2][j] << " " << data[i + 2][j + 1] << " " << data[i + 2][j + 2] << "\n"
						  << data[i][j + 3] << " " << data[i][j + 4] << " " << data[i][j + 5] << " | "
						  << data[i + 1][j + 3] << " " << data[i + 1][j + 4] << " " << data[i + 1][j + 5] << " | "
						  << data[i + 2][j + 3] << " " << data[i + 2][j + 4] << " " << data[i + 2][j + 5] << "\n"
						  << data[i][j + 6] << " " << data[i][j + 7] << " " << data[i][j + 8] << " | "
						  << data[i + 1][j + 6] << " " << data[i + 1][j + 7] << " " << data[i + 1][j + 8] << " | "
						  << data[i + 2][j + 6] << " " << data[i + 2][j + 7] << " " << data[i + 2][j + 8] << "\n";
				i += 2;
				break;
			}
			else
			{
				std::cout << data[i][j] << " " << data[i][j + 1] << " " << data[i][j + 2] << "\n";
			}
		}
		if (i == 0 || i == 3 || i == 4)
		{
			std::cout << "        -----\n";
		}
	}
}

void Cube::Generate()
{
	srand(time(nullptr));
	int count = rand() % 1000;
	for (int i = 0; i < count; ++i)
	{
		int action = rand() % 12;
		if (action == 0)
		{
			YellowRight();
		}
		else if (action == 1)
		{
			YellowLeft();
		}
		else if (action == 2)
		{
			RedRight();
		}
		else if (action == 3)
		{
			RedLeft();
		}
		else if (action == 4)
		{
			GreenRight();
		}
		else if (action == 5)
		{
			GreenLeft();
		}
		else if (action == 6)
		{
			OrangeRight();
		}
		else if (action == 7)
		{
			OrangeLeft();
		}
		else if (action == 8)
		{
			WhiteRight();
		}
		else if (action == 9)
		{
			WhiteLeft();
		}
		else if (action == 10)
		{
			BlueRight();
		}
		else if (action == 11)
		{
			BlueLeft();
		}
	}
}

void Cube::ReturnPath()
{
	std::cout << path + '.' << std::endl;
}

bool Cube::FindPath()
{
	auto** buffer = new unsigned char* [sizeof(unsigned char*) * 6];
	for (int i = 0; i < 6; ++i)
	{
		buffer[i] = new unsigned char[sizeof(unsigned char) * 9];
		for (int j = 0; j < 9; ++j)
		{
			buffer[i][j] = data[i][j];
		}
	}
	MakeWhiteCross();
	MakeWhiteCorners();
	CompleteFirstLayer();
	CompleteSecondLayer();
	bool is_valid = TryYellowCross();
	if (is_valid)
	{
		is_valid = TryYellowCorners();
		if (is_valid)
		{
			FinishCorners();
			while (data[2][0] != 'g')
			{
				path += "YR ";
				YellowRight();
			}
			is_valid = TryFinishThirdLayer();
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			data[i][j] = buffer[i][j];
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		delete[] buffer[i];
	}
	delete[] buffer;
	return is_valid;
}

Cube::~Cube()
{
	for (int i = 0; i < 6; i++)
	{
		delete[]data[i];
	}
	delete[]data;
}

void Cube::panel_right_turn(int turn)
{
	unsigned char buffer;
	buffer = data[turn][0];
	data[turn][0] = data[turn][6];
	data[turn][6] = data[turn][8];
	data[turn][8] = data[turn][2];
	data[turn][2] = buffer;
	buffer = data[turn][1];
	data[turn][1] = data[turn][3];
	data[turn][3] = data[turn][7];
	data[turn][7] = data[turn][5];
	data[turn][5] = buffer;
}

void Cube::panel_left_turn(int turn)
{
	unsigned char buffer;
	buffer = data[turn][0];
	data[turn][0] = data[turn][2];
	data[turn][2] = data[turn][8];
	data[turn][8] = data[turn][6];
	data[turn][6] = buffer;
	buffer = data[turn][1];
	data[turn][1] = data[turn][5];
	data[turn][5] = data[turn][7];
	data[turn][7] = data[turn][3];
	data[turn][3] = buffer;
}

void Cube::YellowRight()
{
	unsigned char buffer;
	panel_right_turn(0);
	buffer = data[5][6];
	data[5][6] = data[1][2];
	data[1][2] = data[2][2];
	data[2][2] = data[3][2];
	data[3][2] = buffer;
	buffer = data[5][8];
	data[5][8] = data[1][0];
	data[1][0] = data[2][0];
	data[2][0] = data[3][0];
	data[3][0] = buffer;
	buffer = data[5][7];
	data[5][7] = data[1][1];
	data[1][1] = data[2][1];
	data[2][1] = data[3][1];
	data[3][1] = buffer;
}

void Cube::YellowLeft()
{
	unsigned char buffer;
	panel_left_turn(0);
	buffer = data[5][6];
	data[5][6] = data[3][2];
	data[3][2] = data[2][2];
	data[2][2] = data[1][2];
	data[1][2] = buffer;
	buffer = data[5][8];
	data[5][8] = data[3][0];
	data[3][0] = data[2][0];
	data[2][0] = data[1][0];
	data[1][0] = buffer;
	buffer = data[5][7];
	data[5][7] = data[3][1];
	data[3][1] = data[2][1];
	data[2][1] = data[1][1];
	data[1][1] = buffer;
}

void Cube::RedRight()
{
	unsigned char buffer;
	panel_right_turn(1);
	buffer = data[0][0];
	data[0][0] = data[5][0];
	data[5][0] = data[4][0];
	data[4][0] = data[2][0];
	data[2][0] = buffer;
	buffer = data[0][6];
	data[0][6] = data[5][6];
	data[5][6] = data[4][6];
	data[4][6] = data[2][6];
	data[2][6] = buffer;
	buffer = data[0][3];
	data[0][3] = data[5][3];
	data[5][3] = data[4][3];
	data[4][3] = data[2][3];
	data[2][3] = buffer;
}

void Cube::RedLeft()
{
	unsigned char buffer;
	panel_left_turn(1);
	buffer = data[0][0];
	data[0][0] = data[2][0];
	data[2][0] = data[4][0];
	data[4][0] = data[5][0];
	data[5][0] = buffer;
	buffer = data[0][6];
	data[0][6] = data[2][6];
	data[2][6] = data[4][6];
	data[4][6] = data[5][6];
	data[5][6] = buffer;
	buffer = data[0][3];
	data[0][3] = data[2][3];
	data[2][3] = data[4][3];
	data[4][3] = data[5][3];
	data[5][3] = buffer;
}

void Cube::GreenRight()
{
	unsigned char buffer;
	panel_right_turn(2);
	buffer = data[0][6];
	data[0][6] = data[1][8];
	data[1][8] = data[4][2];
	data[4][2] = data[3][0];
	data[3][0] = buffer;
	buffer = data[0][8];
	data[0][8] = data[1][2];
	data[1][2] = data[4][0];
	data[4][0] = data[3][6];
	data[3][6] = buffer;
	buffer = data[0][7];
	data[0][7] = data[1][5];
	data[1][5] = data[4][1];
	data[4][1] = data[3][3];
	data[3][3] = buffer;
}

void Cube::GreenLeft()
{
	unsigned char buffer;
	panel_left_turn(2);
	buffer = data[0][6];
	data[0][6] = data[3][0];
	data[3][0] = data[4][2];
	data[4][2] = data[1][8];
	data[1][8] = buffer;
	buffer = data[0][8];
	data[0][8] = data[3][6];
	data[3][6] = data[4][0];
	data[4][0] = data[1][2];
	data[1][2] = buffer;
	buffer = data[0][7];
	data[0][7] = data[3][3];
	data[3][3] = data[4][1];
	data[4][1] = data[1][5];
	data[1][5] = buffer;
}

void Cube::OrangeRight()
{
	unsigned char buffer;
	panel_right_turn(3);
	buffer = data[0][2];
	data[0][2] = data[2][2];
	data[2][2] = data[4][2];
	data[4][2] = data[5][2];
	data[5][2] = buffer;
	buffer = data[0][8];
	data[0][8] = data[2][8];
	data[2][8] = data[4][8];
	data[4][8] = data[5][8];
	data[5][8] = buffer;
	buffer = data[0][5];
	data[0][5] = data[2][5];
	data[2][5] = data[4][5];
	data[4][5] = data[5][5];
	data[5][5] = buffer;
}

void Cube::OrangeLeft()
{
	unsigned char buffer;
	panel_left_turn(3);
	buffer = data[0][2];
	data[0][2] = data[5][2];
	data[5][2] = data[4][2];
	data[4][2] = data[2][2];
	data[2][2] = buffer;
	buffer = data[0][8];
	data[0][8] = data[5][8];
	data[5][8] = data[4][8];
	data[4][8] = data[2][8];
	data[2][8] = buffer;
	buffer = data[0][5];
	data[0][5] = data[5][5];
	data[5][5] = data[4][5];
	data[4][5] = data[2][5];
	data[2][5] = buffer;
}

void Cube::WhiteRight()
{
	unsigned char buffer;
	panel_right_turn(4);
	buffer = data[5][0];
	data[5][0] = data[3][8];
	data[3][8] = data[2][8];
	data[2][8] = data[1][8];
	data[1][8] = buffer;
	buffer = data[5][2];
	data[5][2] = data[3][6];
	data[3][6] = data[2][6];
	data[2][6] = data[1][6];
	data[1][6] = buffer;
	buffer = data[5][1];
	data[5][1] = data[3][7];
	data[3][7] = data[2][7];
	data[2][7] = data[1][7];
	data[1][7] = buffer;
}

void Cube::WhiteLeft()
{
	unsigned char buffer;
	panel_left_turn(4);
	buffer = data[5][0];
	data[5][0] = data[1][8];
	data[1][8] = data[2][8];
	data[2][8] = data[3][8];
	data[3][8] = buffer;
	buffer = data[5][2];
	data[5][2] = data[1][6];
	data[1][6] = data[2][6];
	data[2][6] = data[3][6];
	data[3][6] = buffer;
	buffer = data[5][1];
	data[5][1] = data[1][7];
	data[1][7] = data[2][7];
	data[2][7] = data[3][7];
	data[3][7] = buffer;
}

void Cube::BlueRight()
{
	unsigned char buffer;
	panel_right_turn(5);
	buffer = data[0][0];
	data[0][0] = data[3][2];
	data[3][2] = data[4][8];
	data[4][8] = data[1][6];
	data[1][6] = buffer;
	buffer = data[0][2];
	data[0][2] = data[3][8];
	data[3][8] = data[4][6];
	data[4][6] = data[1][0];
	data[1][0] = buffer;
	buffer = data[0][1];
	data[0][1] = data[3][5];
	data[3][5] = data[4][7];
	data[4][7] = data[1][3];
	data[1][3] = buffer;
}

void Cube::BlueLeft()
{
	unsigned char buffer;
	panel_left_turn(5);
	buffer = data[0][0];
	data[0][0] = data[1][6];
	data[1][6] = data[4][8];
	data[4][8] = data[3][2];
	data[3][2] = buffer;
	buffer = data[0][2];
	data[0][2] = data[1][0];
	data[1][0] = data[4][6];
	data[4][6] = data[3][8];
	data[3][8] = buffer;
	buffer = data[0][1];
	data[0][1] = data[1][3];
	data[1][3] = data[4][7];
	data[4][7] = data[3][5];
	data[3][5] = buffer;
}

void Cube::rotate_while_white(int position)
{
	while (data[4][position] == 'w')
	{
		path += "WR ";
		WhiteRight();
	}
}

void Cube::make_cross()
{
	for (int i = 0; i < 6; i++)
	{
		if (i != 4)
		{
			for (int j = 1; j < 9; j += 2)
			{
				if (data[i][j] == 'w')
				{
					if (i == 0)
					{
						if (j == 1)
						{
							rotate_while_white(7);
							path += "BR BR ";
							BlueRight();
							BlueRight();
						}
						else if (j == 3)
						{
							rotate_while_white(3);
							path += "RR RR ";
							RedRight();
							RedRight();
						}
						else if (j == 5)
						{
							rotate_while_white(5);
							path += "OR OR ";
							OrangeRight();
							OrangeRight();
						}
						else if (j == 7)
						{
							rotate_while_white(1);
							path += "GR GR ";
							GreenRight();
							GreenRight();
						}
					}
					else if (i == 1)
					{
						if (j == 1)
						{
							rotate_while_white(3);
							path += "RR WR GL ";
							RedRight();
							WhiteRight();
							GreenLeft();
						}
						else if (j == 3)
						{
							rotate_while_white(7);
							path += "BR ";
							BlueRight();
						}
						else if (j == 5)
						{
							rotate_while_white(1);
							path += "GL ";
							GreenLeft();
						}
						else if (j == 7)
						{
							path += "RL WR GL ";
							RedLeft();
							WhiteRight();
							GreenLeft();
						}
					}
					else if (i == 2)
					{
						if (j == 1)
						{
							rotate_while_white(1);
							path += "GR WR OL ";
							GreenRight();
							WhiteRight();
							OrangeLeft();
						}
						else if (j == 3)
						{
							rotate_while_white(3);
							path += "RR ";
							RedRight();
						}
						else if (j == 5)
						{
							rotate_while_white(5);
							path += "OR ";
							OrangeLeft();
						}
						else if (j == 7)
						{
							path += "GL WR OL ";
							GreenLeft();
							WhiteRight();
							OrangeLeft();
						}
					}
					else if (i == 3)
					{
						if (j == 1)
						{
							rotate_while_white(5);
							path += "OR WR BL ";
							OrangeRight();
							WhiteRight();
							BlueLeft();
						}
						else if (j == 3)
						{
							rotate_while_white(1);
							path += "GR ";
							GreenRight();
						}
						else if (j == 5)
						{
							rotate_while_white(7);
							path += "BL ";
							BlueLeft();
						}
						else if (j == 7)
						{
							path += "OL WR BL ";
							OrangeLeft();
							WhiteRight();
							BlueLeft();
						}
					}
					else if (i == 5)
					{
						if (j == 1)
						{
							path += "BR WL OR ";
							BlueRight();
							WhiteLeft();
							OrangeRight();
						}
						else if (j == 3)
						{
							rotate_while_white(3);
							path += "BL ";
							RedLeft();
						}
						else if (j == 5)
						{
							rotate_while_white(5);
							path += "OR ";
							OrangeRight();
						}
						else if (j == 7)
						{
							rotate_while_white(7);
							path += "BL WL OR ";
							BlueLeft();
							WhiteLeft();
							OrangeRight();
						}
					}
				}
			}
		}
	}
}

void Cube::MakeWhiteCross()
{
	while (true)
	{
		if (data[4][1] == 'w' && data[4][3] == 'w' && data[4][5] == 'w' && data[4][7] == 'w')
		{
			break;
		}
		else
		{
			make_cross();
		}
	}
}

int Cube::count_correct_edges()
{
	int count = 0;
	if (data[2][4] == data[2][7])
	{
		count++;
	}
	if (data[1][4] == data[1][7])
	{
		count++;
	}
	if (data[3][4] == data[3][7])
	{
		count++;
	}
	if (data[5][4] == data[5][1])
	{
		count++;
	}
	return count;
}

void Cube::MakeWhiteCorners()
{
	int count = count_correct_edges();
	while (count < 2)
	{
		path += "WR ";
		WhiteRight();
		count = count_correct_edges();
	}
	if (count == 2)
	{
		if (data[2][4] == data[2][7] && data[5][4] == data[5][1])
		{
			path += "OR WR WR OL WL WL OR ";
			OrangeRight();
			WhiteRight();
			WhiteRight();
			OrangeLeft();
			WhiteLeft();
			WhiteLeft();
			OrangeRight();
		}
		else if (data[1][4] == data[1][7] && data[3][4] == data[3][7])
		{
			path += "GR WR WR GL WL WL GR ";
			GreenRight();
			WhiteRight();
			WhiteRight();
			GreenLeft();
			WhiteLeft();
			WhiteLeft();
			GreenRight();
		}
		else if (data[3][4] == data[3][7] && data[5][4] == data[5][1])
		{
			path += "GR WR GL WL GR ";
			GreenRight();
			WhiteRight();
			GreenLeft();
			WhiteLeft();
			GreenRight();
		}
		else if (data[3][4] == data[3][7] && data[2][4] == data[2][7])
		{
			path += "RR WR RL WL RR ";
			RedRight();
			WhiteRight();
			RedLeft();
			WhiteLeft();
			RedRight();
		}
		else if (data[1][4] == data[1][7] && data[2][4] == data[2][7])
		{
			path += "BR WR BL WL BR ";
			BlueRight();
			WhiteRight();
			BlueLeft();
			WhiteLeft();
			BlueRight();
		}
		else if (data[1][4] == data[1][7] && data[5][4] == data[5][1])
		{
			path += "OR WR OL WL OR ";
			OrangeRight();
			WhiteRight();
			OrangeLeft();
			WhiteLeft();
			OrangeRight();
		}
	}
}

void Cube::rotate_while_incorrect_corners(int position)
{
	if (position == 0)
	{
		while (data[4][0] != 'w' || data[2][6] != 'g')
		{
			path += "GR YR GL YL ";
			GreenRight();
			YellowRight();
			GreenLeft();
			YellowLeft();
		}
	}
	else if (position == 2)
	{
		while (data[4][2] != 'w' || data[3][6] != 'o')
		{
			path += "OR YR OL YL ";
			OrangeRight();
			YellowRight();
			OrangeLeft();
			YellowLeft();
		}
	}
	else if (position == 6)
	{
		while (data[4][6] != 'w' || data[1][6] != 'r')
		{
			path += "RR YR RL YL ";
			RedRight();
			YellowRight();
			RedLeft();
			YellowLeft();
		}
	}
	else
	{
		while (data[4][8] != 'w' || data[5][2] != 'b')
		{
			path += "BR YR BL YL ";
			BlueRight();
			YellowRight();
			BlueLeft();
			YellowLeft();
		}
	}
}

void Cube::R6perebor()
{
	path += "RR YR RL YL ";
	RedRight();
	YellowRight();
	RedLeft();
	YellowLeft();
}

void Cube::G6perebor()
{
	path += "GR YR GL YL ";
	GreenRight();
	YellowRight();
	GreenLeft();
	YellowLeft();
}

void Cube::O6perebor()
{
	path += "OR YR OL YL ";
	OrangeRight();
	YellowRight();
	OrangeLeft();
	YellowLeft();
}

void Cube::B6perebor()
{
	path += "BR YR BL YL ";
	BlueRight();
	YellowRight();
	BlueLeft();
	YellowLeft();
}

void Cube::make_corners()
{
	for (int i = 0; i < 6; i++)
	{
		if (i != 4)
		{
			for (int j = 0; j < 9; j += 2)
			{
				if (data[i][j] == 'w')
				{
					if (i == 0)
					{
						if (j == 0)
						{
							if (data[1][0] == 'b')
							{
								rotate_while_incorrect_corners(6);
							}
							else if (data[1][0] == 'r')
							{
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(0);
							}
							else if (data[1][0] == 'o')
							{
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(8);
							}
							else
							{
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(2);
							}
						}
						else if (j == 2)
						{
							if (data[3][2] == 'b')
							{
								rotate_while_incorrect_corners(8);
							}
							else if (data[3][2] == 'o')
							{
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(2);
							}
							else if (data[3][2] == 'r')
							{
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(6);
							}
							else
							{
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(0);
							}
						}
						else if (j == 6)
						{
							if (data[2][0] == 'r')
							{
								rotate_while_incorrect_corners(0);
							}
							else if (data[2][0] == 'g')
							{
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(2);
							}
							else if (data[2][0] == 'b')
							{
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(6);
							}
							else
							{
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(8);
							}
						}
						else if (j == 8)
						{
							if (data[2][2] == 'o')
							{
								rotate_while_incorrect_corners(2);
							}
							else if (data[2][2] == 'g')
							{
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(0);
							}
							else if (data[2][2] == 'b')
							{
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(8);
							}
							else
							{
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(6);
							}
						}
					}
					else if (i == 1)
					{
						if (j == 0)
						{
							if (data[0][0] == 'r')
							{
								rotate_while_incorrect_corners(6);
							}
							else if (data[0][0] == 'b')
							{
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(8);
							}
							else if (data[0][0] == 'g')
							{
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(0);
							}
							else
							{
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(2);
							}
						}
						else if (j == 2)
						{
							if (data[0][6] == 'r')
							{
								rotate_while_incorrect_corners(0);
							}
							else if (data[0][6] == 'g')
							{
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(2);
							}
							else if (data[0][6] == 'b')
							{
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(6);
							}
							else
							{
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(8);
							}
						}
						else if (j == 6)
						{
							if (data[4][6] == 'b')
							{
								rotate_while_incorrect_corners(6);
							}
							else if (data[4][6] == 'r')
							{
								R6perebor();
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(0);
							}
							else if (data[4][6] == 'o')
							{
								R6perebor();
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(8);
							}
							else
							{
								R6perebor();
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(2);
							}
						}
						else if (j == 8)
						{
							if (data[2][6] == 'r')
							{
								rotate_while_incorrect_corners(0);
							}
							else if (data[2][6] == 'g')
							{
								G6perebor();
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(2);
							}
							else if (data[2][6] == 'b')
							{
								G6perebor();
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(6);
							}
							else
							{
								G6perebor();
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(8);
							}
						}
					}
					else if (i == 2)
					{
						if (j == 0)
						{
							if (data[0][6] == 'g')
							{
								rotate_while_incorrect_corners(0);
							}
							else if (data[0][6] == 'r')
							{
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(6);
							}
							else if (data[0][6] == 'o')
							{
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(2);
							}
							else
							{
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(8);
							}
						}
						else if (j == 2)
						{
							if (data[0][8] == 'g')
							{
								rotate_while_incorrect_corners(2);
							}
							else if (data[0][8] == 'r')
							{
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(0);
							}
							else if (data[0][8] == 'o')
							{
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(8);
							}
							else
							{
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(6);
							}
						}
						else if (j == 6)
						{
							if (data[4][0] == 'r')
							{
								rotate_while_incorrect_corners(0);
							}
							else if (data[4][0] == 'g')
							{
								G6perebor();
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(2);
							}
							else if (data[4][0] == 'b')
							{
								G6perebor();
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(6);
							}
							else
							{
								G6perebor();
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(8);
							}
						}
						else if (j == 8)
						{
							if (data[4][2] == 'o')
							{
								rotate_while_incorrect_corners(2);
							}
							else if (data[4][2] == 'g')
							{
								O6perebor();
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(0);
							}
							else if (data[4][2] == 'b')
							{
								O6perebor();
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(8);
							}
							else
							{
								O6perebor();
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(6);
							}
						}
					}
					else if (i == 3)
					{
						if (j == 0)
						{
							if (data[2][2] == 'g')
							{
								rotate_while_incorrect_corners(2);
							}
							else if (data[2][2] == 'r')
							{
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(0);
							}
							else if (data[2][2] == 'o')
							{
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(8);
							}
							else
							{
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(6);
							}
						}
						else if (j == 2)
						{
							if (data[0][2] == 'o')
							{
								rotate_while_incorrect_corners(8);
							}
							else if (data[0][2] == 'g')
							{
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(2);
							}
							else if (data[0][2] == 'b')
							{
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(6);
							}
							else
							{
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(0);
							}
						}
						else if (j == 6)
						{
							if (data[2][8] == 'o')
							{
								rotate_while_incorrect_corners(2);
							}
							else if (data[2][8] == 'g')
							{
								O6perebor();
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(0);
							}
							else if (data[2][8] == 'b')
							{
								O6perebor();
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(8);
							}
							else
							{
								O6perebor();
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(6);
							}
						}
						else if (j == 8)
						{
							if (data[4][8] == 'b')
							{
								rotate_while_incorrect_corners(8);
							}
							else if (data[4][8] == 'o')
							{
								B6perebor();
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(2);
							}
							else if (data[4][8] == 'r')
							{
								B6perebor();
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(6);
							}
							else
							{
								B6perebor();
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(0);
							}
						}
					}
					else if (i == 5)
					{
						if (j == 0)
						{
							if (data[4][6] == 'r')
							{
								rotate_while_incorrect_corners(6);
							}
							else if (data[4][6] == 'g')
							{
								R6perebor();
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(0);
							}
							else if (data[4][6] == 'b')
							{
								R6perebor();
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(8);
							}
							else
							{
								R6perebor();
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(2);
							}
						}
						else if (j == 2)
						{
							if (data[4][8] == 'o')
							{
								rotate_while_incorrect_corners(8);
							}
							else if (data[4][8] == 'b')
							{
								B6perebor();
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(6);
							}
							else if (data[4][8] == 'g')
							{
								B6perebor();
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(2);
							}
							else
							{
								B6perebor();
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(0);
							}
						}
						else if (j == 6)
						{
							if (data[1][0] == 'r')
							{
								rotate_while_incorrect_corners(6);
							}
							else if (data[1][0] == 'b')
							{
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(8);
							}
							else if (data[1][0] == 'g')
							{
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(0);
							}
							else
							{
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(2);
							}
						}
						else if (j == 8)
						{
							if (data[3][2] == 'o')
							{
								rotate_while_incorrect_corners(8);
							}
							else if (data[3][2] == 'b')
							{
								path += "YL ";
								YellowLeft();
								rotate_while_incorrect_corners(6);
							}
							else if (data[3][2] == 'g')
							{
								path += "YR ";
								YellowRight();
								rotate_while_incorrect_corners(2);
							}
							else
							{
								path += "YR YR ";
								YellowRight();
								YellowRight();
								rotate_while_incorrect_corners(0);
							}
						}
					}
				}
			}
		}
	}
	if (data[1][6] != 'r')
	{
		path += "RR YR RL YL ";
		RedRight();
		YellowRight();
		RedLeft();
		YellowLeft();
	}
	else if (data[2][6] != 'g')
	{
		path += "GR YR GL YL ";
		GreenRight();
		YellowRight();
		GreenLeft();
		YellowLeft();
	}
	else if (data[3][6] != 'o')
	{
		path += "OR YR OL YL ";
		OrangeRight();
		YellowRight();
		OrangeLeft();
		YellowLeft();
	}
	else if (data[5][2] != 'b')
	{
		path += "BR YR BL YL ";
		BlueRight();
		YellowRight();
		BlueLeft();
		YellowLeft();
	}
}

void Cube::blue_edge()
{
	if (data[0][1] == 'o')
	{
		path += "YL OL YR OR YR BR YL BL ";
		YellowLeft();
		OrangeLeft();
		YellowRight();
		OrangeRight();
		YellowRight();
		BlueRight();
		YellowLeft();
		BlueLeft();
	}
	else
	{
		path += "YR RR YL RL YL BL YR BR ";
		YellowRight();
		RedRight();
		YellowLeft();
		RedLeft();
		YellowLeft();
		BlueLeft();
		YellowRight();
		BlueRight();
	}
}

void Cube::red_edge()
{
	if (data[0][3] == 'b')
	{
		path += "YL BL YR BR YR RR YL RL ";
		YellowLeft();
		BlueLeft();
		YellowRight();
		BlueRight();
		YellowRight();
		RedRight();
		YellowLeft();
		RedLeft();
	}
	else
	{
		path += "YR GR YL GL YL RL YR RR ";
		YellowRight();
		GreenRight();
		YellowLeft();
		GreenLeft();
		YellowLeft();
		RedLeft();
		YellowRight();
		RedRight();
	}
}

void Cube::green_edge()
{
	if (data[0][7] == 'r')
	{
		path += "YL RL YR RR YR GR YL GL ";
		YellowLeft();
		RedLeft();
		YellowRight();
		RedRight();
		YellowRight();
		GreenRight();
		YellowLeft();
		GreenLeft();
	}
	else
	{
		path += "YR OR YL OL YL GL YR GR ";
		YellowRight();
		OrangeRight();
		YellowLeft();
		OrangeLeft();
		YellowLeft();
		GreenLeft();
		YellowRight();
		GreenRight();
	}
}

void Cube::orange_edge()
{
	if (data[0][5] == 'g')
	{
		path += "YL GL YR GR YR OR YL OL ";
		YellowLeft();
		GreenLeft();
		YellowRight();
		GreenRight();
		YellowRight();
		OrangeRight();
		YellowLeft();
		OrangeLeft();
	}
	else
	{
		path += "YR BR YL BL YL OL YR OR ";
		YellowRight();
		BlueRight();
		YellowLeft();
		BlueLeft();
		YellowLeft();
		OrangeLeft();
		YellowRight();
		OrangeRight();
	}
}

void Cube::make_edges()
{
	for (int j = 1; j < 9; j += 2)
	{
		if (data[0][1] != 'y' && data[5][7] != 'y')
		{
			if (data[5][7] == 'g')
			{
				path += "YR YR ";
				YellowRight();
				YellowRight();
				green_edge();
			}
			else if (data[5][7] == 'r')
			{
				path += "YL ";
				YellowLeft();
				red_edge();
			}
			else if (data[5][7] == 'o')
			{
				path += "YR ";
				YellowRight();
				orange_edge();
			}
			else
			{
				blue_edge();
			}
		}
		else if (data[0][5] != 'y' && data[3][1] != 'y')
		{
			if (data[3][1] == 'g')
			{
				path += "YR ";
				YellowRight();
				green_edge();
			}
			else if (data[3][1] == 'r')
			{
				path += "YR YR ";
				YellowRight();
				YellowRight();
				red_edge();
			}
			else if (data[3][1] == 'o')
			{
				orange_edge();
			}
			else
			{
				path += "YL ";
				YellowLeft();
				blue_edge();
			}
		}
		else if (data[0][3] != 'y' && data[1][1] != 'y')
		{
			if (data[1][1] == 'g')
			{
				path += "YL ";
				YellowLeft();
				green_edge();
			}
			else if (data[1][1] == 'r')
			{
				red_edge();
			}
			else if (data[1][1] == 'o')
			{
				path += "YR YR ";
				YellowRight();
				YellowRight();
				orange_edge();
			}
			else
			{
				path += "YR ";
				YellowRight();
				blue_edge();
			}
		}
		else if (data[0][7] != 'y' && data[2][1] != 'y')
		{
			if (data[2][1] == 'g')
			{
				green_edge();
			}
			else if (data[2][1] == 'r')
			{
				path += "YR ";
				YellowRight();
				red_edge();
			}
			else if (data[2][1] == 'o')
			{
				path += "YL ";
				YellowLeft();
				orange_edge();
			}
			else
			{
				path += "YR YR ";
				YellowRight();
				YellowRight();
				blue_edge();
			}
		}
	}
	if ((data[1][5] != 'r' || data[2][3] != 'g') && data[1][5] != 'y' && data[2][3] != 'y')
	{
		path += "GR YL GL YL RL YR RR ";
		GreenRight();
		YellowLeft();
		GreenLeft();
		YellowLeft();
		RedLeft();
		YellowRight();
		RedRight();
	}
	else if ((data[2][5] != 'g' || data[3][3] != 'o') && data[2][5] != 'y' && data[3][3] != 'y')
	{
		path += "OR YL OL YL GL YR GR ";
		OrangeRight();
		YellowLeft();
		OrangeLeft();
		YellowLeft();
		GreenLeft();
		YellowRight();
		GreenRight();
	}
	else if ((data[3][5] != 'o' || data[5][5] != 'b') && data[3][5] != 'y' && data[5][5] != 'y')
	{
		path += "BR YL BL YL OL YR OR ";
		BlueRight();
		YellowLeft();
		BlueLeft();
		YellowLeft();
		OrangeLeft();
		YellowRight();
		OrangeRight();
	}
	else if ((data[5][3] != 'b' || data[1][3] != 'r') && data[5][3] != 'y' && data[1][3] != 'y')
	{
		path += "RR YL RL YL BL YR BR ";
		RedRight();
		YellowLeft();
		RedLeft();
		YellowLeft();
		BlueLeft();
		YellowRight();
		BlueRight();
	}
}

void Cube::CompleteFirstLayer()
{
	while (true)
	{
		if (data[4][0] == 'w' && data[4][2] == 'w' && data[4][6] == 'w' && data[4][8] == 'w' && data[1][6] == 'r' &&
			data[1][8] == 'r' && data[2][6] == 'g' && data[2][8] == 'g' && data[3][6] == 'o' && data[3][8] == 'o' &&
			data[5][0] == 'b' && data[5][2] == 'b')
		{
			break;
		}
		else
		{
			make_corners();
		}
	}
}

void Cube::CompleteSecondLayer()
{
	while (true)
	{
		if (data[2][3] == 'g' && data[2][5] == 'g' && data[1][3] == 'r' && data[1][5] == 'r' && data[3][3] == 'o' &&
			data[3][5] == 'o' && data[5][3] == 'b' && data[5][5] == 'b')
		{
			break;
		}
		else
		{
			make_edges();
		}
	}
}

void Cube::goy_oyg(int count)
{
	for (int i = 0; i < count; ++i)
	{
		path += "GR OR YR OL YL GL ";
		GreenRight();
		OrangeRight();
		YellowRight();
		OrangeLeft();
		YellowLeft();
		GreenLeft();
	}
}

void Cube::rgy_gyr(int count)
{
	for (int i = 0; i < count; ++i)
	{
		path += "RR GR YR GL YL RL ";
		RedRight();
		GreenRight();
		YellowRight();
		GreenLeft();
		YellowLeft();
		RedLeft();
	}
}

bool Cube::TryYellowCross()
{
	if (data[0][1] != 'y' && data[0][3] != 'y' && data[0][5] != 'y' && data[0][7] != 'y')
	{
		rgy_gyr(2);
		goy_oyg(1);
	}
	else if (data[0][1] == 'y' && data[0][3] == 'y' && data[0][5] != 'y' && data[0][7] != 'y')
	{
		path += "YR ";
		YellowRight();
		rgy_gyr(2);
	}
	else if (data[0][1] == 'y' && data[0][3] != 'y' && data[0][5] == 'y' && data[0][7] != 'y')
	{
		rgy_gyr(2);
	}
	else if (data[0][1] != 'y' && data[0][3] != 'y' && data[0][5] == 'y' && data[0][7] == 'y')
	{
		path += "YL ";
		YellowLeft();
		rgy_gyr(2);
	}
	else if (data[0][1] != 'y' && data[0][3] == 'y' && data[0][5] != 'y' && data[0][7] == 'y')
	{
		path += "YR YR ";
		YellowRight();
		YellowRight();
		rgy_gyr(2);
	}
	else if (data[0][1] == 'y' && data[0][3] != 'y' && data[0][5] != 'y' && data[0][7] == 'y')
	{
		rgy_gyr(1);
	}
	else if (data[0][1] != 'y' && data[0][3] == 'y' && data[0][5] == 'y' && data[0][7] != 'y')
	{
		path += "YR ";
		YellowRight();
		rgy_gyr(1);
	}
	else if (data[0][1] == 'y' && data[0][3] == 'y' && data[0][5] == 'y' && data[0][7] == 'y')
	{
		//std::cout << "Yellow cross!!!" << std::endl;
	}
	else
	{
		return false;
	}
	return true;
}

void Cube::helicopter_trick()
{
	path += "OR YL YL OL OL YL OR OR YL OL OL YL YL OR ";
	OrangeRight();
	YellowLeft();
	YellowLeft();
	OrangeLeft();
	OrangeLeft();
	YellowLeft();
	OrangeRight();
	OrangeRight();
	YellowLeft();
	OrangeLeft();
	OrangeLeft();
	YellowLeft();
	YellowLeft();
	OrangeRight();
}

void Cube::ears_trick()
{
	path += "GR OR BL OL GL OR BR OL ";
	GreenRight();
	OrangeRight();
	BlueLeft();
	OrangeLeft();
	GreenLeft();
	OrangeRight();
	BlueRight();
	OrangeLeft();
}

void Cube::nose_trick()
{
	path += "OL GL RL GR OR GL RR GR ";
	OrangeLeft();
	GreenLeft();
	RedLeft();
	GreenRight();
	OrangeRight();
	GreenLeft();
	RedRight();
	GreenRight();
}

void Cube::eyes_trick()
{
	path += "OR OR WR OL YR YR OR WL OL YR YR OL ";
	OrangeRight();
	OrangeRight();
	WhiteRight();
	OrangeLeft();
	YellowRight();
	YellowRight();
	OrangeRight();
	WhiteLeft();
	OrangeLeft();
	YellowRight();
	YellowRight();
	OrangeLeft();
}

void Cube::triple_pif_paf_trick()
{
	path += "GR ";
	GreenRight();
	for (int i = 0; i < 3; i++)
	{
		path += "OR YR OL YL ";
		OrangeRight();
		YellowRight();
		OrangeLeft();
		YellowLeft();
	}
	GreenLeft();
	path += "GL ";
}

void Cube::right_fish_trick()
{
	path += "OR YR OL YR OR YR YR OL ";
	OrangeRight();
	YellowRight();
	OrangeLeft();
	YellowRight();
	OrangeRight();
	YellowRight();
	YellowRight();
	OrangeLeft();
}

void Cube::left_fish_trick()
{
	path += "RL YL RR YL RL YL YL RR ";
	RedLeft();
	YellowLeft();
	RedRight();
	YellowLeft();
	RedLeft();
	YellowLeft();
	YellowLeft();
	RedRight();
}

bool Cube::TryYellowCorners()
{
	if (data[1][0] == 'y' && data[1][2] == 'y' && data[2][2] == 'y' && data[5][8] == 'y')
	{
		helicopter_trick();
	}
	else if (data[3][0] == 'y' && data[1][2] == 'y' && data[5][6] == 'y' && data[5][8] == 'y')
	{
		path += "YL ";
		YellowLeft();
		helicopter_trick();
	}
	else if (data[1][0] == 'y' && data[2][0] == 'y' && data[2][2] == 'y' && data[3][2] == 'y')
	{
		path += "YR ";
		YellowRight();
		helicopter_trick();
	}
	else if (data[3][0] == 'y' && data[3][2] == 'y' && data[2][0] == 'y' && data[5][6] == 'y')
	{
		path += "YR YR ";
		YellowRight();
		YellowRight();
		helicopter_trick();
	}
	else if (data[1][2] == 'y' && data[3][0] == 'y' && data[0][0] == 'y' && data[0][2] == 'y')
	{
		ears_trick();
	}
	else if (data[2][2] == 'y' && data[5][8] == 'y' && data[0][0] == 'y' && data[0][6] == 'y')
	{
		path += "YR ";
		YellowRight();
		ears_trick();
	}
	else if (data[5][6] == 'y' && data[2][0] == 'y' && data[0][8] == 'y' && data[0][2] == 'y')
	{
		path += "YL ";
		YellowLeft();
		ears_trick();
	}
	else if (data[3][2] == 'y' && data[1][0] == 'y' && data[0][8] == 'y' && data[0][6] == 'y')
	{
		path += "YR YR ";
		YellowRight();
		YellowRight();
		ears_trick();
	}
	else if (data[5][8] == 'y' && data[1][2] == 'y' && data[0][0] == 'y' && data[0][8] == 'y')
	{
		nose_trick();
	}
	else if (data[1][0] == 'y' && data[2][2] == 'y' && data[0][2] == 'y' && data[0][6] == 'y')
	{
		path += "YR ";
		YellowRight();
		nose_trick();
	}
	else if (data[5][6] == 'y' && data[3][0] == 'y' && data[0][2] == 'y' && data[0][6] == 'y')
	{
		path += "YL ";
		YellowLeft();
		nose_trick();
	}
	else if (data[2][0] == 'y' && data[3][2] == 'y' && data[0][0] == 'y' && data[0][8] == 'y')
	{
		path += "YR YR ";
		YellowRight();
		YellowRight();
		nose_trick();
	}
	else if (data[2][0] == 'y' && data[2][2] == 'y' && data[0][0] == 'y' && data[0][2] == 'y')
	{
		eyes_trick();
	}
	else if (data[3][0] == 'y' && data[3][2] == 'y' && data[0][0] == 'y' && data[0][6] == 'y')
	{
		path += "YR ";
		YellowRight();
		eyes_trick();
	}
	else if (data[1][0] == 'y' && data[1][2] == 'y' && data[0][8] == 'y' && data[0][2] == 'y')
	{
		path += "YL ";
		YellowLeft();
		eyes_trick();
	}
	else if (data[5][6] == 'y' && data[5][8] == 'y' && data[0][6] == 'y' && data[0][8] == 'y')
	{
		path += "YR YR ";
		YellowRight();
		YellowRight();
		eyes_trick();
	}
	else if (data[5][6] == 'y' && data[5][8] == 'y' && data[2][0] == 'y' && data[2][2] == 'y')
	{
		triple_pif_paf_trick();
	}
	else if (data[1][0] == 'y' && data[1][2] == 'y' && data[3][0] == 'y' && data[3][2] == 'y')
	{
		path += "YR ";
		YellowRight();
		triple_pif_paf_trick();
	}
	else if (data[0][6] == 'y' && data[2][2] == 'y' && data[3][2] == 'y' && data[5][6] == 'y')
	{
		right_fish_trick();
	}
	else if (data[0][8] == 'y' && data[1][2] == 'y' && data[3][2] == 'y' && data[5][6] == 'y')
	{
		path += "YR ";
		YellowRight();
		right_fish_trick();
	}
	else if (data[0][0] == 'y' && data[2][2] == 'y' && data[3][2] == 'y' && data[1][2] == 'y')
	{
		path += "YL ";
		YellowLeft();
		right_fish_trick();
	}
	else if (data[0][2] == 'y' && data[2][2] == 'y' && data[1][2] == 'y' && data[5][6] == 'y')
	{
		path += "YR YR ";
		YellowRight();
		YellowRight();
		right_fish_trick();
	}
	else if (data[0][8] == 'y' && data[2][0] == 'y' && data[1][0] == 'y' && data[5][8] == 'y')
	{
		left_fish_trick();
	}
	else if (data[0][2] == 'y' && data[2][0] == 'y' && data[1][0] == 'y' && data[3][0] == 'y')
	{
		path += "YR ";
		YellowRight();
		left_fish_trick();
	}
	else if (data[0][6] == 'y' && data[3][0] == 'y' && data[1][0] == 'y' && data[5][8] == 'y')
	{
		path += "YL ";
		YellowLeft();
		left_fish_trick();
	}
	else if (data[0][0] == 'y' && data[2][0] == 'y' && data[3][0] == 'y' && data[5][8] == 'y')
	{
		path += "YR YR ";
		YellowRight();
		YellowRight();
		left_fish_trick();
	}
	else if (data[0][6] == 'y' && data[0][2] == 'y' && data[0][0] == 'y' && data[0][8] == 'y')
	{

	}
	else
	{
		return false;
	}
	return true;
}

void Cube::have_pair_trick()
{
	path += "GR YR GL YL GL RR GR GR YL GL YL GR YR GL RL ";
	GreenRight();
	YellowRight();
	GreenLeft();
	YellowLeft();
	GreenLeft();
	RedRight();
	GreenRight();
	GreenRight();
	YellowLeft();
	GreenLeft();
	YellowLeft();
	GreenRight();
	YellowRight();
	GreenLeft();
	RedLeft();
}

void Cube::not_pair_trick()
{
	path += "RR GR YL GL YL GR YR GL RL GR YR GL YL GL RR GR RL ";
	RedRight();
	GreenRight();
	YellowLeft();
	GreenLeft();
	YellowLeft();
	GreenRight();
	YellowRight();
	GreenLeft();
	RedLeft();
	GreenRight();
	YellowRight();
	GreenLeft();
	YellowLeft();
	GreenLeft();
	RedRight();
	GreenRight();
	RedLeft();
}

void Cube::FinishCorners()
{
	if (data[5][6] == data[5][8] && data[1][0] != data[1][2])
	{
		have_pair_trick();
	}
	else if (data[1][0] == data[1][2] && data[2][0] != data[2][2])
	{
		path += "YR ";
		YellowRight();
		have_pair_trick();
	}
	else if (data[3][0] == data[3][2] && data[2][0] != data[2][2])
	{
		path += "YL ";
		YellowLeft();
		have_pair_trick();
	}
	else if (data[2][0] == data[2][2] && data[1][0] != data[1][2])
	{
		path += "YR YR ";
		YellowRight();
		YellowRight();
		have_pair_trick();
	}
	else if (data[1][0] == data[1][2] && data[3][0] == data[3][2])
	{

	}
	else
	{
		not_pair_trick();
	}
}

void Cube::last_green_left()
{
	path += "RL YR RL YL RL YL RL YR RR YR RR RR ";
	RedLeft();
	YellowRight();
	RedLeft();
	YellowLeft();
	RedLeft();
	YellowLeft();
	RedLeft();
	YellowRight();
	RedRight();
	YellowRight();
	RedRight();
	RedRight();
}

void Cube::last_green_right()
{
	path += "OR YL OR YR OR YR OR YL OL YL OL OL ";
	OrangeRight();
	YellowLeft();
	OrangeRight();
	YellowRight();
	OrangeRight();
	YellowRight();
	OrangeRight();
	YellowLeft();
	OrangeLeft();
	YellowLeft();
	OrangeLeft();
	OrangeLeft();
}

void Cube::last_orange_left()
{
	path += "GL YR GL YL GL YL GL YR GR YR GR GR ";
	GreenLeft();
	YellowRight();
	GreenLeft();
	YellowLeft();
	GreenLeft();
	YellowLeft();
	GreenLeft();
	YellowRight();
	GreenRight();
	YellowRight();
	GreenRight();
	GreenRight();
}

void Cube::last_orange_right()
{
	path += "BR YL BR YR BR YR BR YL BL YL BL BL ";
	BlueRight();
	YellowLeft();
	BlueRight();
	YellowRight();
	BlueRight();
	YellowRight();
	BlueRight();
	YellowLeft();
	BlueLeft();
	YellowLeft();
	BlueLeft();
	BlueLeft();
}

void Cube::last_blue_left()
{
	path += "OL YR OL YL OL YL OL YR OR YR OR OR ";
	OrangeLeft();
	YellowRight();
	OrangeLeft();
	YellowLeft();
	OrangeLeft();
	YellowLeft();
	OrangeLeft();
	YellowRight();
	OrangeRight();
	YellowRight();
	OrangeRight();
	OrangeRight();
}

void Cube::last_blue_right()
{
	path += "RR YL RR YR RR YR RR YL RL YL RL RL ";
	RedRight();
	YellowLeft();
	RedRight();
	YellowRight();
	RedRight();
	YellowRight();
	RedRight();
	YellowLeft();
	RedLeft();
	YellowLeft();
	RedLeft();
	RedLeft();
}

void Cube::last_red_left()
{
	path += "BL YR BL YL BL YL BL YR BR YR BR BR ";
	BlueLeft();
	YellowRight();
	BlueLeft();
	YellowLeft();
	BlueLeft();
	YellowLeft();
	BlueLeft();
	YellowRight();
	BlueRight();
	YellowRight();
	BlueRight();
	BlueRight();
}

void Cube::last_red_right()
{
	path += "GR YL GR YR GR YR GR YL GL YL GL GL ";
	GreenRight();
	YellowLeft();
	GreenRight();
	YellowRight();
	GreenRight();
	YellowRight();
	GreenRight();
	YellowLeft();
	GreenLeft();
	YellowLeft();
	GreenLeft();
	GreenLeft();
}

bool Cube::TryFinishThirdLayer()
{
	if (data[2][1] == 'r' && data[1][1] == 'o' && data[3][1] == 'g' && data[5][7] == 'b')
	{
		last_green_left();
	}
	else if (data[2][1] == 'o' && data[1][1] == 'g' && data[3][1] == 'r' && data[5][7] == 'b')
	{
		last_green_right();
	}
	else if (data[2][1] == 'b' && data[1][1] == 'r' && data[3][1] == 'g' && data[5][7] == 'o')
	{
		last_orange_left();
	}
	else if (data[2][1] == 'o' && data[1][1] == 'r' && data[3][1] == 'b' && data[5][7] == 'g')
	{
		last_orange_right();
	}
	else if (data[2][1] == 'g' && data[1][1] == 'o' && data[3][1] == 'b' && data[5][7] == 'r')
	{
		last_blue_right();
	}
	else if (data[2][1] == 'g' && data[1][1] == 'b' && data[3][1] == 'r' && data[5][7] == 'o')
	{
		last_blue_left();
	}
	else if (data[2][1] == 'r' && data[1][1] == 'b' && data[3][1] == 'o' && data[5][7] == 'g')
	{
		last_red_left();
	}
	else if (data[2][1] == 'b' && data[1][1] == 'g' && data[3][1] == 'o' && data[5][7] == 'r')
	{
		last_red_right();
	}
	else if (data[1][1] == 'o' && data[2][1] == 'b' && data[3][1] == 'r' && data[5][7] == 'g')
	{
		last_orange_left();
		last_green_left();
	}
	else if (data[1][1] == 'g' && data[2][1] == 'r' && data[3][1] == 'b' && data[5][7] == 'o')
	{
		last_orange_right();
		last_green_right();
	}
	else if (data[1][1] == 'b' && data[2][1] == 'o' && data[3][1] == 'g' && data[5][7] == 'r')
	{
		last_orange_left();
		last_blue_left();
	}
	else if (data[1][1] == 'r' && data[2][1] == 'g' && data[3][1] == 'o' && data[5][7] == 'b')
	{

	}
	else
	{
		return false;
	}
	return true;
}

unsigned char** Cube::GetCube()
{
	return data;
}
