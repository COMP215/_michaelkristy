#include <iostream>

using namespace std;

int main()
{
  string title_line;
  string satchel;
  string satchel_size;
  string common_name1;
  string scientific_name1;
  string string_maitake_oz;
  string string_total_quantity_value1;
  int num_satchel_size;
  int maitake_oz = 5;
  int maitake_total_price = 50;
  int maitake_per_oz = maitake_total_price/maitake_oz;
  int shiitake_oz = 10;
  int shiitake_total_price = 60;
  int shiitake_per_oz = shiitake_total_price/shiitake_oz;
  int oyster_oz = 12;
  int oyster_total_price = 60;
  int oyster_per_oz = oyster_total_price/oyster_oz;
  int shaggymane_oz = 20;
  int shaggymane_total_price = 120;
  int shaggymane_per_oz = shaggymane_total_price/shaggymane_oz;
  int maitake_taken = 0;
  int shiitake_taken = 0;
  int oyster_taken = 0;
  int shaggymane_taken = 0;

  int satchel_total_price = 0;

  fstream myfile;
  myfile.open ("mushrooms_1.csv");
  getline(myfile,title_line);
  getline(myfile, satchel, ',');
  getline(myfile, satchel_size, '\n');
  stringstream convert(satchel_size);
  if ( !(convert >> num_satchel_size) )
    num_satchel_size = 0;
  getline(myfile, common_name1, ',');
  getline(myfile, scientific_name1, ',');
  getline(myfile, string_maitake_oz, ',');
  stringstream convert1(string_maitake_oz);
  if ( !(convert1 >> maitake_oz) )
    maitake_oz = 0;
  getline(myfile, string_total_quantity_value1, ',');
  stringstream convert2(string_total_quantity_value1);
  if ( !(convert2 >> maitake_total_price) )
    maitake_total_price = 0;

  if(maitake_oz >= num_satchel_size  && num_satchel_size != 0){
    satchel_total_price = num_satchel_size * maitake_per_oz + satchel_total_price;
    maitake_taken = num_satchel_size;
    num_satchel_size = 0;
  }
  else if(maitake_oz < num_satchel_size){
    num_satchel_size = num_satchel_size - maitake_oz;
    maitake_taken = maitake_oz;
    satchel_total_price = satchel_total_price + maitake_total_price;
  }

  if(shiitake_oz >= num_satchel_size && num_satchel_size != 0){
    satchel_total_price = num_satchel_size * shiitake_per_oz + satchel_total_price;
    shiitake_taken = num_satchel_size;
    num_satchel_size = 0;
  }
  else if(shiitake_oz < num_satchel_size){
    num_satchel_size = num_satchel_size - shiitake_oz;
    shiitake_taken = shiitake_oz;
    satchel_total_price = satchel_total_price + shiitake_total_price;
  }

  if(shaggymane_oz >= num_satchel_size  && num_satchel_size != 0){
    satchel_total_price = num_satchel_size * shaggymane_per_oz + satchel_total_price;
    shaggymane_taken = num_satchel_size;
    num_satchel_size = 0;
  }
  else if(shaggymane_oz < num_satchel_size){
    num_satchel_size = num_satchel_size - shaggymane_oz;
    shaggymane_taken = shaggymane_oz;
    satchel_total_price = satchel_total_price + shaggymane_total_price;
  }

  if(oyster_oz >= num_satchel_size && num_satchel_size != 0){
    satchel_total_price = num_satchel_size * oyster_per_oz;
    oyster_taken = num_satchel_size;
    num_satchel_size = 0;
  }
  else if(oyster_oz < num_satchel_size){
    num_satchel_size = num_satchel_size - oyster_oz;
    oyster_taken = oyster_oz;
    satchel_total_price = satchel_total_price + oyster_total_price;
  }

  cout << maitake_taken << " ounces of "<< common_name1 << scientific_name1 << " mushrooms." << endl;
  cout << shiitake_taken << " ounces of Shiitake (Lentinula edodes) mushrooms." << endl;
  cout << shaggymane_taken << " ounces of Shaggy Mane (Coprinus comatus) mushrooms." << endl;
  cout << oyster_taken << " ounces of Oyster (Pleuratus ostreatus) mushrooms." << endl;
  cout << "---------------------------------" << endl;
  cout << "Total Value: $" << satchel_total_price << endl;

	return 0;
}
