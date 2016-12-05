//Advent of Code 2016-02
//Author: Tommi Eriksson
//File: Advent02.cpp
//---------------------------------------------------------------
//Advent of Code day 02 source file
//---------------------------------------------------------------
//Date		Version		Author			Comment
//---------------------------------------------------------------
//3.12.2016	0.1			Tommi Eriksson	Created
//3.12.2016	1.0			Tommi Eriksson	Done & commented


#include "advent02.h"

#include <string>
#include <iostream>
#include <fstream>

namespace advent02 
{
	void run() 
	{

		std::string line = "";
		std::ifstream input;

		std::string code = "";
		
		//coordinates are:
		//1 2 3
		//4 5 6
		//7 8 9
		//for example (1,1) == 5
		int coord_x = 1;
		int coord_y = 1;

		//coordinates are:
		//  1
		// 234
		//56789
		// ABC
		//  D
		//for example (2,2) = 7
		int coord_x_internal = 2;
		int coord_y_internal = 2;

		//reads file and moves the coordinates accordingly
		input.open("advent02input.aoc");
		if (input.is_open()) 
		{
			while (std::getline(input, line)) 
			{
				for (char iter : line)
				{
					switch (iter)
					{
					case 'U':
						//moves up if possible
						if (coord_y > 0)
						{
							coord_y--;					
						}
						if (coord_x_internal + coord_y_internal > 2 && 
							(coord_x_internal != 4 || coord_y_internal != 2) && 
							(coord_x_internal != 3 || coord_y_internal != 1))
						{
							coord_y_internal--;
						}
						break;
					case 'R':
						//moves right if possible
						if (coord_x < 2) 
						{
							coord_x++;	
						}
						if ((coord_x_internal + coord_y_internal < 6 && 
							(coord_x_internal != 2 || coord_y_internal != 0)) && 
							(coord_x_internal != 3 || coord_y_internal != 1)) 
						{
							coord_x_internal++;
						}
						break;
					case 'D':
						//moves down if possible
						if (coord_y < 2) 
						{	
							coord_y++;					
						}
						if (coord_x_internal + coord_y_internal < 6 && 
							(coord_x_internal != 1 || coord_y_internal != 3) && 
							(coord_x_internal != 0 || coord_y_internal != 2)) 
						{						
							coord_y_internal++;
						}
						break;
					case 'L':
						//moves left if possible
						if (coord_x > 0) 
						{					
							coord_x--;			
						}
						if (coord_x_internal + coord_y_internal > 2 && 
							(coord_x_internal != 1 || coord_y_internal != 3) && 
							(coord_x_internal != 2 || coord_y_internal != 4)) 
						{
							coord_x_internal--;
						}
						break;
					}
				}
				//prints right numbers for the bathroom door
				std::cout << coord_x + coord_y * 3 + 1 << std::endl;
				//prints right coordinates for inner door
				std::cout << "(" << coord_x_internal << "," << coord_y_internal << ")" << std::endl;
			}
		}
		input.close();
		int pause;
		std::cin >> pause;
	}
}