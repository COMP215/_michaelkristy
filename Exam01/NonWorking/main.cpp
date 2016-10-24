#include <iostream>
#include "mushroom_calc.hpp"
using namespace std;

int main()
{

  Mushroom_Calcs mushroom_adventure;
  mushroom_adventure.assignDataFromFile();
  mushroom_adventure.findInformation();
  mushroom_adventure.printFindings();

	return 0;
}
