#pragma once
#include<iostream>

class Street
{
public:
	void setDistance(float distance);
	void setCanVehiclePass(bool canVehiclePass);
    void setBusLineName(std::string busLineName);
	void setBusSpeed(float busSpeed);
	void setTaxiSpeed(float taxiSpeed);

	float getDistance() const;
	bool getCanVehiclePass() const;
	std::string getBusLineName() const;
	float getBusSpeed() const;
	float getTaxiSpeed() const;

	void print() const;

	static void copyStreet(Street& copy, const Street& obj);

	Street();
	Street(float distance, bool canVehiclePass, std::string busLineName, float busSpeed, float taxiSpeed);
	Street(const Street& obj);
	~Street();


private:
	float distance;
	bool canVehiclePass;
	std::string busLineName;
	float busSpeed;
	float taxiSpeed;
};