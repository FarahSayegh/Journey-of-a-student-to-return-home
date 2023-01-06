#pragma once
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<vector>
#include<list>
#include"Station.h"
#include"CostType.h"
#include"Path.h"
#include"CompareF.h"
#include"CompareF.cpp"

class Human
{
public:
	time_t begin, end;
	Station currentStation;
	float effort;
	float money;
	float time;
	int id;
	int parentId;
	float f;
	

	void setCurrentStation(Station currentStation);
	void setEffort(float effort);
	void setMoney(float money);
	void setTime(float time);
	void setId(int id);
	void setParentId(int parentId);
	void setF(float f);

	Station getCurrentStation() const;
	float getEffort() const;
	float getMoney() const;
	float getTime() const;
	int getId() const;
	int getParentId() const;
	float getF()const;

	void print() const;
	static void print(const std::list<Human>& objList);

	bool isFinal();

	static void copyHuman(Human& copy, const Human& obj);
	
	static float busMoneyCost();
	static float taxiMoneyCost(Path path);
	static float walkingMoneyCost();

	static float busTimeCost(Path path);
	static float taxiTimeCost(Path path);
	static float walkingTimeCost(Path path);

	static float busEffortCost(Path path);
	static float taxiEffortCost(Path path);
	static float walkingEffortCost(Path path);


	static bool canTakeBus(Human human,Path path);
	static bool canTakeTaxi(Human human, Path path);
	static bool canWalk(Human human, Path path);

	static void moveBus(Human& human, Path path);
	static void moveTaxi(Human& human, Path path);
	static void moveWalk(Human& human, Path path);

	static bool isEqual(Human& obj1, Human& obj2);
	static bool isEqual(Human& obj1, std::list<Human>& objList);

	

	static void possiblePaths(Human& human, std::vector<std::vector<Path>>paths, std::list<Path>& possiblePathsList);
	void checkPossibleMoves(std::list<Human>& possibleMoves, std::list<Path>possiblePathsList,CostType cost);
	static void findPath(const std::list<Human>& visitedList, std::list<Human>& path);

	static void Astar(Human& current,std::vector<std::vector<Path>>paths);

	
	
	Human();
	Human(Station station, float effort, float money, float time);
	Human(const Human& obj);
	~Human();
};