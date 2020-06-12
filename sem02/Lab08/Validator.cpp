#include <vector>

#include "Validator.hpp"

bool Validator::Validate(unsigned char** data)
{
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (data[i][j] != 'r' && data[i][j] != 'o' && data[i][j] != 'g' && data[i][j] != 'b' && data[i][j] != 'y' &&
				data[i][j] != 'w')
			{
				return false;
			}
		}
	}

	int* buffer = new int[6];
	for (int i = 0; i < 6; i++)
	{
		buffer[i] = 0;
	}

	bool flag = true;
	std::vector <std::pair <unsigned char, unsigned char>> reb;
	flag = check_rib(reb, data[0][7], data[2][1], flag, buffer);
	flag = check_rib(reb, data[0][5], data[3][1], flag, buffer);
	flag = check_rib(reb, data[0][1], data[5][7], flag, buffer);
	flag = check_rib(reb, data[0][3], data[1][1], flag, buffer);
	flag = check_rib(reb, data[1][5], data[2][3], flag, buffer);
	flag = check_rib(reb, data[2][5], data[3][3], flag, buffer);
	flag = check_rib(reb, data[3][5], data[5][5], flag, buffer);
	flag = check_rib(reb, data[5][3], data[1][3], flag, buffer);
	flag = check_rib(reb, data[4][1], data[2][7], flag, buffer);
	flag = check_rib(reb, data[4][3], data[1][7], flag, buffer);
	flag = check_rib(reb, data[4][5], data[3][7], flag, buffer);
	flag = check_rib(reb, data[4][7], data[5][1], flag, buffer);

	std::vector <std::pair <unsigned char, std::pair <unsigned char, unsigned char>>> cor;
	flag = check_corner(cor, data[0][6], data[1][2], data[2][0], flag, buffer);
	flag = check_corner(cor, data[0][8], data[2][2], data[3][0], flag, buffer);
	flag = check_corner(cor, data[1][8], data[2][6], data[4][0], flag, buffer);
	flag = check_corner(cor, data[2][8], data[3][6], data[4][2], flag, buffer);
	flag = check_corner(cor, data[0][2], data[3][2], data[5][8], flag, buffer);
	flag = check_corner(cor, data[0][0], data[1][0], data[5][6], flag, buffer);
	flag = check_corner(cor, data[1][6], data[4][6], data[5][0], flag, buffer);
	flag = check_corner(cor, data[3][8], data[4][8], data[5][2], flag, buffer);

	std::vector <unsigned char> centers;
	for (int i = 0; i < 6; ++i)
	{
		flag = check_center(centers, data[i][4], flag, buffer);
	}

	if (!flag)
	{
		return flag;
	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			if (buffer[i] > 9)
			{
				return false;
			}
		}
		return flag;
	}
}

bool Validator::check_rib(std::vector <std::pair <unsigned char, unsigned char>>& reb, unsigned char a, unsigned char b,
						  bool flag, int* mas)
{
	if (flag)
	{
		for (auto& i : reb)
		{
			if ((i.first == a && i.second == b) || (i.first == b && i.second == a) ||
					check_color(a, b))
			{
				return false;
			}
		}
		reb.emplace_back(a, b);
		return true;
	}
	else
	{
		return false;
	}
}

bool Validator::check_color(unsigned char a, unsigned char b)
{
	return (a == 'w' && b == 'y') || (a == 'y' && b == 'w') || (a == 'b' && b == 'g') || (a == 'g' && b == 'b') ||
		   (a == 'r' && b == 'o') || (a == 'o' && b == 'r') || a == b;
}

bool Validator::check_corner(std::vector <std::pair <unsigned char, std::pair <unsigned char, unsigned char>>>& cor,
							 unsigned char a, unsigned char b, unsigned char c, bool flag, int* mas)
{
	if (flag)
	{
		for (auto & i : cor)
		{
			std::pair <unsigned char, unsigned char> now = i.second;
			unsigned char first = i.first, second = now.first, third = now.second;
			if ((first == a && second == b && third == c) || (first == a && second == c && third == b) ||
				(first == b && second == a && third == c) || (first == b && second == c && third == a) ||
				(first == c && second == a && third == b) || (first == c && second == b && third == a) ||
					check_color(a, b) || check_color(a, c) || check_color(b, c))
			{
				return false;
			}
		}
		cor.push_back({a, {b, c}});
		return true;
	}
	else
	{
		return false;
	}
}

bool Validator::check_center(std::vector <unsigned char>& cen, unsigned char a, bool flag, int* mas)
{
	if (flag)
	{
		for (unsigned char i : cen)
		{
			if (i == a)
			{
				return false;
			}
		}
		cen.push_back(a);
		return true;
	}
	else
	{
		return false;
	}
}
