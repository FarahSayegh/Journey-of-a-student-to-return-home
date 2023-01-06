#include "Station.h"

Station::Station()
{
	this->name = "-----";
	this->busTimeWaite = 0;
	this->taxiTimeWaite = 0;
	this->homeDistance = 0;
}
Station::Station(std::string name, float busTimeWaite, float taxiTimeWaite,float homeDistance)
{
	this->name = name;
	this->busTimeWaite = busTimeWaite;
	this->taxiTimeWaite = taxiTimeWaite;
	this->homeDistance = homeDistance;
}
Station::Station(const Station& obj)
{
	this->name = obj.name;
	this->busTimeWaite = obj.busTimeWaite;
	this->taxiTimeWaite = obj.taxiTimeWaite;
	this->homeDistance = obj.homeDistance;
}
Station::~Station()
{}

void Station::setName(std::string name)
{
	this->name = name;
}
void Station::setBusTimeWaite(float busTimeWaite)
{
	this->busTimeWaite = busTimeWaite;
}
void Station::setTaxiTimeWaite(float taxiTimeWaite)
{
	this->taxiTimeWaite = taxiTimeWaite;
}
void Station::setHomeDistance(float homeDistance)
{
	this->homeDistance = homeDistance;
}

std::string Station::getName() const
{
	return this->name;
}
float Station::getBusTimeWaite() const
{
	return this->busTimeWaite;
}
float Station::getTaxiTimeWaite() const
{
	return this->taxiTimeWaite;
}
float Station::getHomeDistance() const
{
	return this->homeDistance;
}

void Station::print() const
{
	std::cout << "---Station info---" << std::endl;
	std::cout << "Station name is: " << this->getName() << std::endl;
	std::cout << "The bus time waite is: " << this->getBusTimeWaite() << std::endl;
	std::cout << "The taxi time waite is: " << this->getTaxiTimeWaite() << std::endl;
	std::cout << "The approximate distance to home: " << this->getHomeDistance() << std::endl;
}

void Station::copyStation(Station& copy, const Station& obj)
{
	copy.name = obj.name;
	copy.busTimeWaite = obj.busTimeWaite;
	copy.taxiTimeWaite = obj.taxiTimeWaite;
	copy.homeDistance = obj.homeDistance;
}

bool Station::isEqual(Station& obj1, Station& obj2)
{
	if (obj1.getName() == obj2.getName() &&
		obj1.getBusTimeWaite() == obj2.getBusTimeWaite() &&
		obj1.getTaxiTimeWaite() == obj2.getTaxiTimeWaite())
		return true;
	else
		return false;
}