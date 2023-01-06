#include<iostream>
#include<vector>
#include<stdlib.h>  
#include"Station.h"
#include"Street.h"
#include"Path.h"
#include"Human.h"


//Station(std::string name, float busTimeWaite, float taxiTimeWaite,float homeDistance)
//Street(float distance, bool canVehiclePass, std::string busLineName, float busSpeed, float taxiSpeed);
//Human::Human(Station currentStation, int effort, int money, int time)
int main()
{
	Station station1("Station1", 7, 3, 8);
	Station station2("Station2", 9, 4, 4);
	Station station3("Station3", 14, 8, 7);
	Station station4("Station4", 20, 13, 7);
	Station station5("Station5", 16, 10, 8);
	Station home("Home", 0, 0, 0);

	Street street1(5, true, "street1", 20, 40);
	Street street2(4, false, "-------", 0, 0);
	Street street3(3, true, "street3", 17, 33);
	Street street4(7, true, "street4", 15, 30);
	Street street5(9, false, "-------", 0, 0);
	Street street6(8, true, "street6", 35, 55);
	Street street7(11, false,"-------", 0, 0);
	Street street8(6, true, "street8", 25, 50);


	Path path1(street1, station3);
	Path path2(street2, station4);

	Path path3(street6, station4);
	Path path4(street5, station5);
	Path path5(street8, home);

	Path path6(street1, station1);
	Path path7(street3, station4);
	Path path8(street7, home);

	Path path9(street2, station1);
	Path path10(street6, station2);
	Path path11(street3, station3);
	Path path12(street4, station5);

	Path path13(street5, station2);
	Path path14(street4, station4);

	std::vector<std::vector<Path>> paths{ {path1,path2},
						                  {path3,path4,path5},
						                  {path6,path7,path8},
				                          {path9,path10,path11,path12},
						                  {path13,path14} };

	Human h(station1, 100, 100000, 0);
	Human h1(station2,100,45000,0);


	Human::Astar(h, paths);
	return 0;
}