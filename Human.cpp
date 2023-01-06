#include "Human.h"

int globalID = 0;

Human::Human()
{
	this->effort = 0;
	this->money = 0;
	this->time = 0;
	this->id = 0;
	this->parentId = -1;
	this->f = 0;
}
Human::Human(Station currentStation, float effort, float money, float time)
{
	this->currentStation = currentStation;
	this->effort = effort;
	this->money = money;
	this->time = time;
	this->id = 0;
	this->parentId = -1;
	this->f = 0;
}
Human::Human(const Human& obj)
{
	this->currentStation = obj.currentStation;
	this->effort = obj.effort;
	this->money = obj.money;
	this->time = obj.time;
	this->id = obj.id;
	this->parentId = obj.parentId;
	this->f = obj.f;
}
Human::~Human(){}

void Human::setCurrentStation(Station currentStation)
{
	this->currentStation = currentStation;
}
void Human::setEffort(float effort)
{
	this->effort = effort;
}
void Human::setMoney(float money)
{
	this->money = money;
}
void Human::setTime(float time)
{
	this->time = time;
}
void Human::setId(int id)
{
	this->id = id;
}
void Human::setParentId(int parentId)
{
	this->parentId = parentId;
}
void Human::setF(float f)
{
	this->f = f;
}



Station Human::getCurrentStation() const
{
	return this->currentStation;
}
float Human::getEffort() const
{
	return this->effort;
}
float Human::getMoney() const
{
	return this->money;
}
float Human::getTime() const
{
	return this->time;
}
int Human::getId() const
{
	return this->id;
}
int Human::getParentId() const
{
	return this->parentId;
}
float Human::getF() const
{
	return this->f;
}



void Human::print() const
{
	std::cout << "********** Human info **********" << std::endl;

	this->getCurrentStation().print();
	std::cout << "---human properties---" << std::endl;
	std::cout << "The effort is: " << this->getEffort() << std::endl;
	std::cout << "The money left is: " << this->getMoney() << std::endl;
	std::cout << "The time is: " << this->getTime() << std::endl;
	std::cout << "F is:" << this->getF() << std::endl;
	std::cout << "ID: " << this->getId() << std::endl;
	std::cout << "Parent ID: " << this->getParentId() << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << std::endl;

}
void Human::print(const std::list<Human>& objList)
{
	for (std::list<Human>::const_iterator itr = objList.cbegin(); itr != objList.cend(); itr++)
	{
		itr->print();
	}
}

void Human::copyHuman(Human& copy, const Human& obj)
{
	copy.currentStation = obj.currentStation;
	copy.effort = obj.effort;
	copy.money = obj.money;
	copy.time = obj.time;
	copy.id = obj.id;
	copy.parentId = obj.parentId;
	copy.f = obj.f;
}

float Human::busMoneyCost()
{
	return 400.0;
}
float Human::taxiMoneyCost(Path path)
{
	return 1000.0 * path.street.getDistance();
}
float Human::walkingMoneyCost()
{
	return 0.0;
}

float Human::busTimeCost(Path path)
{
	return float(path.street.getDistance()) / path.street.getBusSpeed() * 60.0;
}
float Human::taxiTimeCost(Path path)
{
	return float(path.street.getDistance()) / path.street.getTaxiSpeed() * 60.0;
}
float Human::walkingTimeCost(Path path)
{
	return float(path.street.getDistance()) / 5.5 * 60.0;
}

float Human::busEffortCost(Path path)
{
	return 5.0 * path.street.getDistance();
}
float Human::taxiEffortCost(Path path)
{
	return 5.0 * path.street.getDistance();
}
float Human::walkingEffortCost(Path path)
{
	return 10.0 * path.street.getDistance();
}

bool Human::canTakeBus(Human human, Path path)
{
	if (!path.street.getCanVehiclePass())
		return false;
	else if (human.getMoney() - busMoneyCost() < 0 || human.getEffort() - busEffortCost(path) <= 0)
		return false;
	else
		return true;
}
bool Human::canTakeTaxi(Human human, Path path)
{
	if (!path.street.getCanVehiclePass())
		return false;
	else if (human.getMoney() - taxiMoneyCost(path) < 0)
		return false;
	else
		return true;
}
bool Human::canWalk(Human human, Path path)
{
	if (human.getEffort() - walkingEffortCost(path) <= 0)
		return false;
	else
		return true;
}

bool Human::isFinal()
{
	if (this->currentStation.getName() == "Home")
		return true;
	else
		return false;
}

void Human::moveBus(Human& human, Path path)
{
	if (canTakeBus(human,path))
	{
		human.setCurrentStation(path.station);
		human.setEffort(human.getEffort() - busEffortCost(path));
		human.setMoney(human.getMoney() - busMoneyCost());
		human.setTime(human.getTime() + busTimeCost(path));
	}
	else
		std::cout << "ERROR!!! in moveBus function" << std::endl;
}
void Human::moveTaxi(Human& human, Path path)
{
	if (canTakeTaxi(human, path))
	{
		human.setCurrentStation(path.station);
		human.setEffort(human.getEffort() + taxiEffortCost(path));
		human.setMoney(human.getMoney() - taxiMoneyCost(path));
		human.setTime(human.getTime() + taxiTimeCost(path));
	}
	else
		std::cout << "ERROR!!! in moveTaxi function" << std::endl;
}
void Human::moveWalk(Human& human, Path path)
{
	if (canWalk(human, path))
	{
		human.setCurrentStation(path.station);
		human.setEffort(human.getEffort() - walkingEffortCost(path));
		human.setMoney(human.getMoney() - walkingMoneyCost());
		human.setTime(human.getTime() + walkingTimeCost(path));
	}
	else
		std::cout << "ERROR!!! moveWalk function" << std::endl;
}

bool Human::isEqual(Human& obj1, Human& obj2)
{
	Station s1 = obj1.getCurrentStation();
	Station s2 = obj2.getCurrentStation();
	bool isSameStation = Station::isEqual(s1, s2);
	if (isSameStation)
	{
		if (
			obj1.getEffort() == obj2.getEffort() &&
			obj1.getMoney() == obj2.getMoney() &&
			obj1.getTime() == obj2.getTime())
			return true;
	}
	else
		return false;
}
bool Human::isEqual(Human& obj1, std::list<Human>& objList)
{
	for (std::list<Human>::iterator itr = objList.begin(); itr != objList.end(); itr++)
	{
		if (isEqual(obj1, *itr))
			return true;
	}
	return false;
}

void Human::possiblePaths(Human& human, std::vector<std::vector<Path>>paths, std::list<Path>&possiblePathsList)
{
	if (human.getCurrentStation().getName() == "Station1")
		for (int i = 0; i < paths[0].size(); i++)
		{
			possiblePathsList.push_back(paths[0][i]);
		}
	else if (human.getCurrentStation().getName() == "Station2")
		for (int i = 0; i < paths[1].size(); i++)
		{
			possiblePathsList.push_back(paths[1][i]);
		}
	else if (human.getCurrentStation().getName() == "Station3")
		for (int i = 0; i < paths[2].size(); i++)
		{
			possiblePathsList.push_back(paths[2][i]);
		}
	else if (human.getCurrentStation().getName() == "Station4")
		for (int i = 0; i < paths[3].size(); i++)
		{
			possiblePathsList.push_back(paths[3][i]);
		}
	else if (human.getCurrentStation().getName() == "Station5")
		for (int i = 0; i < paths[4].size(); i++)
		{
			possiblePathsList.push_back(paths[4][i]);
		}
	else
		std::cout << "NO Paths" << std::endl;
}

void Human::checkPossibleMoves(std::list<Human>& possibleMoves, std::list<Path>possiblePathsList,CostType cost)
{
	Human next;
	for (std::list<Path>::iterator itr = possiblePathsList.begin(); itr != possiblePathsList.end(); itr++)
	{
		copyHuman(next, *this);
		if (canTakeBus(*this, *itr))
		{
			moveBus(next,*itr);
			next.setParentId(this->getId());
			globalID++;
			next.setId(globalID);

			if (cost == one)
				next.setF(busMoneyCost() + this->getCurrentStation().getHomeDistance());
			else if (cost == two)
				next.setF(busEffortCost(*itr) + this->getCurrentStation().getHomeDistance());
			else
				next.setF(busMoneyCost()+ busEffortCost(*itr)+busTimeCost(*itr) +this->getCurrentStation().getHomeDistance());
			
			possibleMoves.push_back(next);
		}

		copyHuman(next, *this);
		if (canTakeTaxi(*this, *itr))
		{
			moveTaxi(next, *itr);
			next.setParentId(this->getId());
			globalID++;
			next.setId(globalID);

			if (cost == one)
				next.setF(taxiMoneyCost(*itr) + this->getCurrentStation().getHomeDistance());
			else if (cost == two)
				next.setF(-1*taxiEffortCost(*itr) + this->getCurrentStation().getHomeDistance());
			else
				next.setF(taxiMoneyCost(*itr) -taxiEffortCost(*itr) + taxiTimeCost(*itr) + this->getCurrentStation().getHomeDistance());

			possibleMoves.push_back(next);
		}

		copyHuman(next, *this);
		if (canWalk(*this, *itr))
		{
			moveWalk(next, *itr);
			next.setParentId(this->getId());
			globalID++;
			next.setId(globalID);

			if(cost == one)
				next.setF( walkingMoneyCost() + this->getCurrentStation().getHomeDistance());
			else if (cost == two)
				next.setF(walkingEffortCost(*itr) + this->getCurrentStation().getHomeDistance());
			else 
				next.setF(walkingMoneyCost() + walkingEffortCost(*itr) + walkingTimeCost(*itr) + this->getCurrentStation().getHomeDistance());
			possibleMoves.push_back(next);
		}
	}
}

void Human::findPath(const std::list<Human>& visitedList, std::list<Human>& path)
{
	path.push_back(visitedList.back());
	for (std::list<Human>::const_reverse_iterator itr = visitedList.crbegin(); itr != visitedList.crend(); itr++)
	{
		if (itr->getId() != path.back().getParentId())
			continue;
		else
			path.push_back(*itr);
	}
	path.reverse();
}

void Human::Astar(Human& current,std::vector<std::vector<Path>> paths)
{
	int countPop = 0;
	double difference = 0;
	time_t(&current.begin);

	std::list<Path> possiblePathsList;
	std::list<Human> possibleMoves;
	std::list<Human> visitedList;
	std::list<Human> path;
	
	visitedList.push_back(current);
	do
	{
		possiblePaths(current, paths, possiblePathsList);
		current.checkPossibleMoves(possibleMoves, possiblePathsList,two);
		possibleMoves.sort(CompareF<Human>());

		if (possibleMoves.size() != 0)
		{
			copyHuman(current, possibleMoves.front());
			possibleMoves.pop_front();
			countPop++;
			while (isEqual(current, visitedList) && possibleMoves.size() != 0)
			{
				copyHuman(current, possibleMoves.front());
				possibleMoves.pop_front();
				countPop++;
			}
			visitedList.push_back(current);
		}
		else
		{
			std::cout << "A* could not find a solution." << std::endl;
		}

	} while (!current.isFinal());
	time_t(&current.end);
	std::cout << "A* has found a solution." << std::endl;

	std::cout << "Number of Pops: " << countPop << std::endl;

	difference = difftime(current.end, current.begin);
	printf("Execution time = %f\n", difference);

	findPath(visitedList, path);
	std::cout << "Number of steps to solution: " << path.size()-1 << std::endl;
	std::cout << "The path is: " << std::endl;
	print(path);

	
	path.clear();
	visitedList.clear();
	possibleMoves.clear();
	possiblePathsList.clear();

	globalID = 0;
}