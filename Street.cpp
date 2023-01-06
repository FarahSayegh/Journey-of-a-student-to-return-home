#include "Street.h"

Street::Street() 
{
	this->distance = 0;
	this->canVehiclePass = false;
	this->busLineName = "-----";
	this->busSpeed = 0;
	this->taxiSpeed = 0;

}
Street::Street(float distance, bool canVehiclePass, std::string busLineName, float busSpeed, float taxiSpeed)
{
	this->distance = distance;
	this->canVehiclePass = canVehiclePass;
	this->busLineName = busLineName;
	this->busSpeed = busSpeed;
	this->taxiSpeed = taxiSpeed;

}
Street::Street(const Street& obj)
{
	this->distance = obj.distance;
	this->canVehiclePass = obj.canVehiclePass;
	this->busLineName = obj.busLineName;
	this->busSpeed = obj.busSpeed;
	this->taxiSpeed = obj.taxiSpeed;
}
Street::~Street()
{

}

void Street::setDistance(float distance)
{
	this->distance = distance;
}
void Street::setCanVehiclePass(bool canVehiclePass)
{
	this->canVehiclePass = canVehiclePass;
}
void Street::setBusLineName(std::string busLineName)
{
	this->busLineName = busLineName;
}
void Street::setBusSpeed(float busSpeed)
{
	this->busSpeed = busSpeed;
}
void Street::setTaxiSpeed(float taxiSpeed)
{
	this->taxiSpeed = taxiSpeed;
}

float Street::getDistance() const 
{
	return this->distance;
}
bool Street::getCanVehiclePass() const
{
	return this->canVehiclePass;
}
std::string Street::getBusLineName() const
{
	return this->busLineName;
}
float Street::getBusSpeed() const
{
	return this->busSpeed;
}
float Street::getTaxiSpeed() const
{
	return this->taxiSpeed;
}

void Street::print() const 
{
	std::cout << "---Street info---" << std::endl;
	std::cout << "The Distance is: " << this->getDistance() << std::endl;
	std::cout << "can the Vehicle pass: " << this->getCanVehiclePass() << std::endl;
	std::cout << "Bus line name is: " << this->getBusLineName() << std::endl;
	std::cout << "Bus Speed is: " << this->getBusSpeed() << std::endl;
	std::cout << "Taxi Speed is: " << this->getTaxiSpeed() << std::endl;
}

void Street::copyStreet(Street& copy,const Street& obj)
{
	copy.distance = obj.distance;
	copy.canVehiclePass = obj.canVehiclePass;
	copy.busLineName = obj.busLineName;
	copy.busSpeed = obj.busSpeed;
	copy.taxiSpeed = obj.taxiSpeed;
}