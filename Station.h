#pragma once
#include<iostream>

class Station
{
public:

	void setName(std::string name);
	void setBusTimeWaite(float busTimeWaite);
	void setTaxiTimeWaite(float taxiTimeWaite);
	void setHomeDistance(float homeDistance);

	std::string getName() const;
	float getBusTimeWaite() const;
	float getTaxiTimeWaite() const;
	float getHomeDistance() const;

	void print() const;

	static void copyStation(Station& copy, const Station& obj);

	static bool isEqual(Station& obj1, Station& obj2);

	Station();
	Station(std::string name,float busTimeWaite,float taxiTimeWaite,float homeDistance);
	Station(const Station& obj);
	~Station();

private:
	std::string name;
	float busTimeWaite;
	float taxiTimeWaite;
	float homeDistance;
};