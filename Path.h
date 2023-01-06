#pragma once
#include<list>
#include"Station.h"
#include"Street.h"

struct Path
{
	Street street;
	Station station;

	Path()
	{
	}

	Path(Street street, Station station)
	{
		this->street = street;
		this->station = station;
	}

	Path(const Path& obj)
	{
		this->street = obj.street;
		this->station = obj.station;
	}
	
	void print() const
	{
		std::cout << "********** Path info **********" << std::endl;

		this->street.print();
		std::cout << "------------------------------" << std::endl;

		this->station.print();
		std::cout << "------------------------------" << std::endl;

		std::cout << std::endl;
	}

	static void print(const std::list<Path> objList)
	{
		for (std::list<Path>::const_iterator itr = objList.cbegin(); itr != objList.cend(); itr++)
		{
			itr->print();
		}
	}
};