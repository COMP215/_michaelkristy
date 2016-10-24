#include <iostream>
#include <fstream>
#include <sstream>

class Mushroom_Calcs {
public:
	std::string title_line;
  std::string satchel;
  std::string satchel_size;
  std::string common_name1;
  std::string scientific_name1;
  std::string string_maitake_oz;
  std::string string_total_quantity_value1;
  int num_satchel_size;
  int maitake_oz;
  int maitake_total_price;
  int maitake_per_oz;
  int shiitake_oz;
  int shiitake_total_price;
  int shiitake_per_oz;
  int oyster_oz;
  int oyster_total_price;
  int oyster_per_oz;
  int shaggymane_oz;
  int shaggymane_total_price;
  int shaggymane_per_oz;
  int maitake_taken;
  int shiitake_taken;
  int oyster_taken;
  int shaggymane_taken;
  int satchel_total_price;

	Mushroom_Calcs();
	void assignDataFromFile();
	void findInformation();
	void printFindings();
};
