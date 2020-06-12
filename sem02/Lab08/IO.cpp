#include <iostream>
#include <fstream>
#include "IO.hpp"

void IO::Read(const std::string& Name, unsigned char** data)
{
	std::ifstream input(Name, std::ios_base::in);
	unsigned char buffer;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			input >> buffer;
			if (buffer == '-' || buffer == '|')
			{
				--j;
			}
			else if (i == 0 || i == 4 || i == 5)
			{
				data[i][j] = buffer;
			}
			else if (i == 1)
			{
				data[i][j] = buffer;
				input >> buffer;
				data[i][j + 1] = buffer;
				input >> buffer;
				data[i][j + 2] = buffer;
				input >> buffer;
				input >> buffer;
				data[i + 1][j] = buffer;
				input >> buffer;
				data[i + 1][j + 1] = buffer;
				input >> buffer;
				data[i + 1][j + 2] = buffer;
				input >> buffer;
				input >> buffer;
				data[i + 2][j] = buffer;
				input >> buffer;
				data[i + 2][j + 1] = buffer;
				input >> buffer;
				data[i + 2][j + 2] = buffer;
				input >> buffer;
				data[i][j + 3] = buffer;
				input >> buffer;
				data[i][j + 4] = buffer;
				input >> buffer;
				data[i][j + 5] = buffer;
				input >> buffer;
				input >> buffer;
				data[i + 1][j + 3] = buffer;
				input >> buffer;
				data[i + 1][j + 4] = buffer;
				input >> buffer;
				data[i + 1][j + 5] = buffer;
				input >> buffer;
				input >> buffer;
				data[i + 2][j + 3] = buffer;
				input >> buffer;
				data[i + 2][j + 4] = buffer;
				input >> buffer;
				data[i + 2][j + 5] = buffer;
				input >> buffer;
				data[i][j + 6] = buffer;
				input >> buffer;
				data[i][j + 7] = buffer;
				input >> buffer;
				data[i][j + 8] = buffer;
				input >> buffer;
				input >> buffer;
				data[i + 1][j + 6] = buffer;
				input >> buffer;
				data[i + 1][j + 7] = buffer;
				input >> buffer;
				data[i + 1][j + 8] = buffer;
				input >> buffer;
				input >> buffer;
				data[i + 2][j + 6] = buffer;
				input >> buffer;
				data[i + 2][j + 7] = buffer;
				input >> buffer;
				data[i + 2][j + 8] = buffer;
				i += 2;
				break;
			}
		}
	}
	input.close();
}

void IO::Write(const std::string& Name, unsigned char** data)
{
	std::ofstream output(Name, std::ios_base::out);
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 9; j += 3)
		{
			if (i == 0 || i == 4 || i == 5)
			{
				output << "        ";
			}
			if (i == 1)
			{
				output << data[i][j] << " " << data[i][j + 1] << " " << data[i][j + 2] << " | " << data[i + 1][j] << " "
					   << data[i + 1][j + 1] << " " << data[i + 1][j + 2] << " | " << data[i + 2][j] << " "
					   << data[i + 2][j + 1] << " " << data[i + 2][j + 2] << "\n" << data[i][j + 3] << " "
					   << data[i][j + 4] << " " << data[i][j + 5] << " | " << data[i + 1][j + 3] << " "
					   << data[i + 1][j + 4] << " " << data[i + 1][j + 5] << " | " << data[i + 2][j + 3] << " "
					   << data[i + 2][j + 4] << " " << data[i + 2][j + 5] << "\n" << data[i][j + 6] << " "
					   << data[i][j + 7] << " " << data[i][j + 8] << " | " << data[i + 1][j + 6] << " "
					   << data[i + 1][j + 7] << " " << data[i + 1][j + 8] << " | " << data[i + 2][j + 6] << " "
					   << data[i + 2][j + 7] << " " << data[i + 2][j + 8] << "\n";
				i += 2;
				break;
			}
			else
			{
				output << data[i][j] << " " << data[i][j + 1] << " " << data[i][j + 2] << "\n";
			}
		}
		if (i == 0 || i == 3 || i == 4)
		{
			output << "        -----\n";
		}
	}
	output.close();
}
