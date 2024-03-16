#pragma once
#include "PriceChecker.h"
#include "TransformationDatabase.h"
class Controller
{
private:
	PriceChecker pc;
	TransformationDatabase transformDB;
	bool exitFlag = true;
	enum class Menu : int
	{
		listMats=1,
		listTransformation,
		exitMenu
	};
public:
	void makeOrBuy(std::string);
	float calcCostofTransformation(Transformation);
	float getCraftingFee(Transformation);
	void run();
	void menuItems(Menu);
	void printMenu();
	int getEingabe();
	void executeMenu(int);
	void setExitFlag();
};

