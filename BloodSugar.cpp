// Matthew Sundberg
// COSC 2030-01
// 3-26-2018

#include <iostream>
#include <string>
#include "BigFloat.h"
#include "LinkedList.h"
#include "Node.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	int dayCounter = 0, 
		weekCounter = 0, 
		totalCounter = 0, 
		temp = 0, 
		day = 1,
		week = 1,
		delta = 0, 
		deltaDay = 0;
	int dayCount[7], weekCount[2], weekDelta[2];
	BigFloat daySum[14], weekSum[2], dayMax[14], weekMax[2], dayMin[14], weekMin[2];
	BigFloat value = 0;
	const float breaker = -99;
	string tempString;
	List dayList;
	List weekList;
	List totalList;

		while (1)
		{
			cout << "Please enter" << endl << "1 to input a value or" << endl << "2 to check day/week summary and/or to switch days and" << endl << "3 to exit the program." << endl << endl;
			cin >> temp;
			cout << endl << endl;

			if (temp == 1)
			{
				// Entering a value while loop.
				while (1)
				{
					cout << "Please enter a value (Enter -99 to go back): ";
					cin >> value;

					if (value == breaker)
					{
						cout << endl;
						break;
					}
					else if (value <= 0)
					{
						cin.clear();
						cin.ignore();
						continue;
					}
					else
					{
						dayList.insertAsFirst(value);
						weekList.insertAsFirst(value);
						dayCounter++;
						weekCounter++;
						cout << "Value " << value << " entered." << endl << endl;
						continue;
					}
				}
				cin.clear();
				cin.ignore();
			}
			else if (temp == 2)
			{
				// Showing day/week information or changing to next day.
				while (1)
				{
					cout << "Please enter D/Day, W/Week, or N/Next." << endl << "Enter B/Back to go back: ";
					cin >> tempString;

					if (tempString == "D" || tempString == "Day")
					{
						if (dayList.empty())
						{
							cout << "No values have been entered in today." << endl << endl;
							continue;
						}
						else
						{
							cout << "Values entered today: " << endl;
							cout << dayList << endl;
							cout << "Max and min values: " << endl;
							cout << "Max: " << dayList.max() << endl << "Min: " << dayList.min() << endl;
							cout << "Sum: " << dayList.sum() << endl;
							cout << "Number of inputs today: " << dayCounter << endl << endl;
						}
					}
					else if (tempString == "W" || tempString == "Week")
					{
						if (weekList.empty())
						{
							cout << "No values have been entered in this week." << endl << endl;
							continue;
						}
						else
						{
							cout << "Values entered so far this week: " << endl;
							cout << weekList << endl;
							cout << "Max and min values: " << endl;
							cout << "Max: " << weekList.max() << endl << "Min: " << weekList.min() << endl;
							cout << "Sum: " << weekList.sum() << endl;
							cout << "Number of inputs so far this week: " << weekCounter << endl;
							cout << "Greatest change in inputs is on day " << deltaDay << " with a change of " << delta << "." << endl << endl;
						}
					}
					else if (tempString == "N" || tempString == "Next")
					{
						dayCount[day - 1] = dayCounter;
						dayMax[day - 1] = dayList.max();
						dayMin[day - 1] = dayList.min();
						daySum[day - 1] = dayList.sum();

						if (delta < abs(dayCount[day - 1] - dayCount[day - 2]) && day >= 2)
						{
							delta = abs(dayCount[day - 1] - dayCount[day - 2]);
							deltaDay = day;
						}

						day++;
						

						if (day == 8)
						{
							weekList.insert(totalList);

							weekCount[week - 1] = weekCounter;
							weekMax[week - 1] = weekList.max();
							weekMin[week - 1] = weekList.min();
							weekSum[week - 1] = weekList.sum();
							weekDelta[week - 1] = delta;

							while (!weekList.empty())
							{
								weekList.removeFirst();
							}

							totalCounter = totalCounter + weekCounter;

							week++;

							cout << "Values entered over the first week: " << endl;
							cout << totalList << endl;
							cout << "Max and min values: " << endl;
							cout << "Max: " << totalList.max() << endl << "Min: " << totalList.min() << endl;
							cout << "Sum: " << totalList.sum() << endl;
							cout << "Number of inputs for this week: " << totalCounter << endl;
							cout << "Greatest change of inputs this week is on day " << deltaDay << " with a change of " << delta << "." << endl << endl;

							for (int i = 0; i < 7; i++)
							{
								dayCount[i] = 0;
							}

							cout << "Now starting day 8/14." << endl << endl;
						}
						else if (day == 15)
						{
							weekList.insert(totalList);
							totalCounter = totalCounter + weekCounter;

							weekCount[week - 1] = weekCounter;
							weekMax[week - 1] = weekList.max();
							weekMin[week - 1] = weekList.min();
							weekSum[week - 1] = weekList.sum();
							weekDelta[week - 1] = delta;

							cout << "Values entered over the two weeks (total): " << endl;
							cout << totalList << endl;
							cout << "Max and min values: " << endl;
							cout << "Maxes: " << totalList.max() << endl << "Mins: " << totalList.min() << endl;
							cout << "Sums: " << totalList.sum() << endl;
							cout << "Number of inputs over the two week: " << totalCounter << endl << endl;
							cout << "Greatest chang of inputs this week is on day " << deltaDay << " with a change of " << delta << "." << endl << endl;

							cout << "Values of all counts per day: " << endl;
							for (int i = 0; i < 14; i++)
							{
								cout << i + 1 << ": " << dayCount[i] << endl;
							}
							cout << endl;
							cout << "Values of all counts per week: " << endl;
							for (int i = 0; i < 2; i++)
							{
								cout << i + 1 << ": " << weekCount[i] << endl;
							}
							cout << endl;
							cout << "Values of all maxes per day: " << endl;
							for (int i = 0; i < 14; i++)
							{
								cout << i + 1 << ": " << dayMax[i] << endl;
							}
							cout << endl;
							cout << "Values of all maxes per week: " << endl;
							for (int i = 0; i < 2; i++)
							{
								cout << i + 1 << ": " << weekMax[i] << endl;
							}
							cout << endl;
							cout << "Values of all mins per day: " << endl;
							for (int i = 0; i < 14; i++)
							{
								cout << i + 1 << ": " << dayMin[i] << endl;
							}
							cout << endl;
							cout << "Values of all mins per week: " << endl;
							for (int i = 0; i < 2; i++)
							{
								cout << i + 1 << ": " << weekMin[i] << endl;
							}
							cout << endl;
							cout << "Values of all sums per day: " << endl;
							for (int i = 0; i < 14; i++)
							{
								cout << i + 1 << ": " << daySum[i] << endl;
							}
							cout << endl;
							cout << "Values of all sums per week: " << endl;
							for (int i = 0; i < 2; i++)
							{
								cout << i + 1 << ": " << weekSum[i] << endl;
							}
							cout << endl;
							cout << "Values of greatest change in count per week: " << endl;
							for (int i = 0; i < 2; i++)
							{
								cout << i + 1 << ": " << weekDelta[i] << endl;
							}
							cout << endl;


							system("pause");
							return 0;
						}
						else
						{
							cout << "Values entered today: " << endl;
							cout << dayList << endl;
							cout << "Max and min values: " << endl;
							cout << "Max: " << dayList.max() << endl << "Min: " << dayList.min() << endl;
							cout << "Sum: " << dayList.sum() << endl;
							cout << "Number of inputs today: " << dayCounter << endl << endl;

							while (!dayList.empty())
							{
								dayList.removeFirst();
							}

							cout << endl << "Now starting day: " << day << "/14." << endl << endl;
							dayCounter = 0;
						}
					}
					else if (tempString == "B" || tempString == "Back")
					{
						cout << endl;
						break;
					}
					else
					{
						continue;
					}
				}
			}
			else if (temp == 3)
			{
				return 0;
			}
			else
			{
				cin.clear();
				cin.ignore();
				continue;
			}
		}
}