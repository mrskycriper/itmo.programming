#pragma once

class Validator
{
public:
	static bool Validate(unsigned char** data);
private:
	static bool
	check_rib(std::vector <std::pair <unsigned char, unsigned char>>& reb, unsigned char a, unsigned char b, bool flag,
			  int* mas);
	static bool check_color(unsigned char a, unsigned char b);
	static bool
	check_corner(std::vector <std::pair <unsigned char, std::pair <unsigned char, unsigned char>>>& cor, unsigned char a,
				 unsigned char b, unsigned char c, bool flag, int* mas);
	static bool check_center(std::vector <unsigned char>& cen, unsigned char a, bool flag, int* mas);
};

