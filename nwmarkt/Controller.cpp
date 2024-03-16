#include "Controller.h"

void Controller::makeOrBuy(std::string itemName) {	
	float marketPrice = pc.getItemPrice(itemName);	
	std::vector<Transformation> inputTransformations = transformDB.getTransformations(itemName);
	std::cout << "Marktpreis von " << itemName << " = " << marketPrice << std::endl;
	if (inputTransformations.empty())
	{
		std::cout << "Item not found makeOrBuy() \n";
	}
	else
	{
		Transformation currentBestTransformation;
		float costOfCurrentBestTransformation = marketPrice *2; //initialisiert mit Kosten > Markpreis
		for (Transformation transf : inputTransformations) {			
			float cost = calcCostofTransformation(transf);
			if (cost < costOfCurrentBestTransformation)
			{
				currentBestTransformation = transf;
				costOfCurrentBestTransformation = cost;				
			}
		}
		std::cout << "Herstellkosten ohne Crafting Fee: " << costOfCurrentBestTransformation << std::endl;
		std::cout << "Herstellkosten mit  Crafting Fee: " << costOfCurrentBestTransformation + getCraftingFee(currentBestTransformation) << std::endl;
	}
}

float Controller::calcCostofTransformation(Transformation t) {
	float cost{ 0.0f };
	std::map<std::string, int> inputFactors = t.inputs;
	for (auto& s : inputFactors)
	{
		float inputPrice = pc.getItemPrice(s.first);
		std::cout << "    " << s.first << " x " << s.second << " = " << inputPrice * s.second << "\n";
		cost += inputPrice * s.second;

	}
	std::cout <<"____________________________________\n" << std::endl;
	return cost;
}

float Controller::getCraftingFee(Transformation t) {
	return t.craftingTax;
}

void Controller::run() {
	std::cout << "__________________________________________\n" << "Menu \n";
	std::cout << "Choose Number to navigate menu \n";
	int eingabe;
	do
	{
		printMenu();
		eingabe = getEingabe();
		executeMenu(eingabe);
		
	} while (exitFlag);
}

void Controller::printMenu() {
	std::cout << "\n";
	for (int i = static_cast<int>(Menu::listMats); i <= static_cast<int>(Menu::exitMenu); ++i) {
		Menu menuItem = static_cast<Menu>(i);
		menuItems(menuItem);
	}
}

void Controller::menuItems(Menu i) {
	std::cout << "  " << static_cast<int>(i) <<". ";
	switch (i)
	{
	case Controller::Menu::listMats:
		std::cout << "Liste der Materialien\n";
		break;
	case Controller::Menu::listTransformation:
		std::cout << "Liste der Transformationen\n";
		break;
	case Controller::Menu::exitMenu:
		std::cout << "Exit\n";
		break;
	default:
		std::cout << "Ungültige Eingabe\n";
		break;
	}
}

int Controller::getEingabe() {
	int eingabe;
	
	std::cout << "Enter Number: ";
	std::cin >> eingabe;
	return eingabe;
}

void Controller::executeMenu(int eingabe) {
	Menu menuItem = static_cast<Menu>(eingabe);
	std::string itemName;
	switch (menuItem)
	{
	case Controller::Menu::listMats:
		transformDB.listAllMaterials();
		break;
	case Controller::Menu::listTransformation:
		
		std::cout << "Which Item Name?: " << std::endl;
		std::getline(std::cin, itemName);

		std::cout << itemName;
		transformDB.printTransformations("Prismatic Ingot");
		break;
	case Controller::Menu::exitMenu:
		setExitFlag();
		break;
	default:
		setExitFlag();
		std::cout << "Wrong Input\n";
		break;
	}
}

void Controller::setExitFlag() {
	exitFlag = false;
}