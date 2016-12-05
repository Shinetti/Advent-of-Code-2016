//Advent of Code 2016-01
//Author: Tommi Eriksson
//File: Advent01.cpp
//---------------------------------------------------------------
//Advent of Code day 01 source file
//---------------------------------------------------------------
//Date		Version		Author			Comment
//---------------------------------------------------------------
//3.12.2016	0.1			Tommi Eriksson	Created
//3.12.2016	1.0			Tommi Eriksson	Done & commented

#include "advent01.h"

#include <string>
#include <iostream>
#include <math.h>
#include <vector>

namespace advent01 
{
	
	void run() 
	{

		const std::string input = "R2, L3, R2, R4, L2, L1, R2, R4, R1, L4, L5, R5, R5, R2, R2, R1, L2, L3, L2, L1, R3, L5, R187, R1, R4, L1, R5, L3, L4, R50, L4, R2, R70, L3, L2, R4, R3, R194, L3, L4, L4, L3, L4, R4, R5, L1, L5, L4, R1, L2, R4, L5, L3, R4, L5, L5, R5, R3, R5, L2, L4, R4, L1, R3, R1, L1, L2, R2, R2, L3, R3, R2, R5, R2, R5, L3, R2, L5, R1, R2, R2, L4, L5, L1, L4, R4, R3, R1, R2, L1, L2, R4, R5, L2, R3, L4, L5, L5, L4, R4, L2, R1, R1, L2, L3, L2, R2, L4, R3, R2, L1, L3, L2, L4, L4, R2, L3, L3, R2, L4, L3, R4, R3, L2, L1, L4, R4, R2, L4, L4, L5, L1, R2, L5, L2, L3, R2, L2";
		
		bool nro_cont = false; //tracks if char before this one was integer
		std::string nro = ""; //keeps track of current number that is being read

		//tracks current coordinates
		int coord_x = 0;
		int coord_y = 0;

		//keeps track of visited coordinates for second part of day1
		std::vector<int> x_visited;
		std::vector<int> y_visited;

		int direction = 12; //remainder of 4 of direcion: north = 0, east = 1, south = 2, west = 3
		int direction_old = 12; //due to stupid design, have to keep track of the old direction too
		
		int mvmnt_amnt = 0; //tracks amount of movement to desired direction
		
		//variables needed for second part of day1
		int true_answer = 0;
		bool true_answer_found = false;

		//reads through input and does some magic
		for (char iter : input)
		{
			//turns right
			if (iter == 'R') 
			{
				direction_old = direction;
				direction++;
				nro_cont = false;
			}
			//turns left
			else if (iter == 'L') 
			{
				direction_old = direction;
				direction--;
				nro_cont = false;
			}
			//skips extras
			else if (iter == ',' || iter == ' ') 
			{
				nro_cont = false;
			}
			//in case we encounter a number
			else 
			{
				//if last char we encountered was also a number
				if (nro_cont == true) 
				{					
					nro += iter;
				}
				//if this is the first number we encounter
				else if (nro_cont == false && nro == "") 
				{
					nro += iter;
					nro_cont = true;
				}
				//if this is the first char of new number
				else
				{
					//moves the amount of last number to direction of variable old_direction
					//moves step by step
					mvmnt_amnt = atoi(nro.c_str());
					while (mvmnt_amnt > 0) 
					{
						switch (direction_old % 4) 
						{
						case 0:
							coord_y++;
							mvmnt_amnt--;
							break;
						case 1:
							coord_x++;
							mvmnt_amnt--;
							break;
						case 2:
							coord_y--;
							mvmnt_amnt--;
							break;
						case 3:
							coord_x--;
							mvmnt_amnt--;
							break;
						}
						//if the true HQ location has not been found yet iterates through all the steps 
						//we have made in the past
						//if we have already visited the same coordinates we are at.
						//WE HAVE FOUND THE HQ
						if (true_answer_found == false) 
						{
							int count = 0;
							for (auto iter : x_visited) 
							{
								if (iter == coord_x)
								{
									if (y_visited.at(count) == coord_y) 
									{
										true_answer = abs(coord_x) + abs(coord_y);
										true_answer_found = true;
									}
								}
								count++;
							}
						}
						//if these are totally new coordinates for us add them according vectors
						if (true_answer_found == false) 
						{
							x_visited.push_back(coord_x);
							y_visited.push_back(coord_y);
						}

					}
					
					//after the last number is read start reading of the new number
					nro = "";
					nro += iter;
					nro_cont = true;
				}
			}
		}
		//due to execution of the task and designers stupidness 
		//we have to add last movement outside the loop
		mvmnt_amnt = atoi(nro.c_str());
		switch (direction_old % 4) 
		{
		case 0:
			coord_y += mvmnt_amnt;
			break;
		case 1:
			coord_x += mvmnt_amnt;
			break;
		case 2:
			coord_y -= mvmnt_amnt;
			break;
		case 3:
			coord_x -= mvmnt_amnt;
			break;
		}
		//print out answer
		std::cout <<"last_hq distance: " << abs(coord_x)+abs(coord_y) << " true_hq distance: " << true_answer << std::endl;
		std::cin >> mvmnt_amnt;
	}
}
