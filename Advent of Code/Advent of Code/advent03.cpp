//Advent of Code 2016-03
//Author: Tommi Eriksson
//File: Advent03.cpp
//---------------------------------------------------------------
//Advent of Code day 03 source file
//---------------------------------------------------------------
//Date		Version		Author			Comment
//---------------------------------------------------------------
//3.12.2016	0.1			Tommi Eriksson	Created
//3.12.2016	0.2			Tommi Eriksson	Part 1 complete. No
//										comments yet :/

#include "advent03.h"

#include <string>
#include <iostream>
#include <fstream>

namespace advent03 
{
	void run() 
	{

		std::string line = "";
		std::ifstream input;

		int count = 0;
		std::string number = "";
		int side_01 = 0;
		int side_02 = 0;
		int side_03 = 0;

		bool is_triangle = true;

		//reads file and does magic
		input.open("advent03input.aoc");
		if (input.is_open())
		{
			while (std::getline(input, line)) 
			{
				side_01 = 0;
				side_02 = 0;
				side_03 = 0;
				for (char iter : line) 
				{
					if (isdigit(iter)) 
					{
						number += iter;
					}
					else
					{
						if (number != "")
						{
							if (side_01 == 0)
							{
								
								side_01 = stoi(number);
							}
							else if (side_02 == 0)
							{
								
								side_02 = stoi(number);
							}
							else
							{
								std::cout << "ERROR: OVER THREE NUMBERS ON SAME ROW!!!!!!" << std::endl;
							}
							number = "";
						}
						else
						{
							number = "";
						}
					}
				}
				side_03 = std::stoi(number);
				if (side_01 + side_02 <= side_03) 
				{
					is_triangle = false;
				}
				else if (side_02 + side_03 <= side_01) 
				{
					is_triangle = false;
				}
				else if (side_01 + side_03 <= side_02)
				{
					is_triangle = false;
				}
				if (is_triangle)
				{
					count++;
				}
				is_triangle = true;
				number = "";
			}
		}
		std::cout << "Number of triangles horizontally: " << count << std::endl;
		input.close();
		int pause;
		std::cin >> pause;
	}
}