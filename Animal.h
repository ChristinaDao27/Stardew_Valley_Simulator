//Title: Animal.h
//Author: Jeremy Dixon
//Date: 3/15/2021
//Description: Describes the class Animal (parent AgItem)

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
#include <vector>
#include "AgItem.h"
using namespace std;

const string ANIMAL_SIZE[] = {"Born", "Infant", "Juvenile", "Adult"}; //Names of the animal sizes
const int ANIMAL_MAX_SIZE = 3; //Born = 0, Infant = 1, Juvenile = 2, Adult = 3

class Animal: public AgItem {
public:

  // Name: Animal (Default constructor)
  // Desc: Creates an Animal with size 0
  // Preconditions:  Uses AgItem default constructor
  // Postconditions: An animal (chicken) is created.
  Animal();

  // Name: Tick
  // Desc: A season passes is the animal's life (passed boolean if it was fed - eats "farm's food")
  // Preconditions: If farm has food, animal is automatically fed
  // Postconditions: One of the following occurs
  //    1. Animal is fed and size increases (not max yet)
  //    2. Animal is fed hits max size and is made harvestable
  //    3. Animal is not fed. Size does not increase. If second no feed, is harvested (small).
  virtual void Tick(bool);

  // Name: Harvest
  // Desc: If the animal is harvestable (adult), returns worth * size to increase farm's money
  // Preconditions:  IsHarvestable
  // Postconditions: Animal harvested and money is gained (worth * size)
  int Harvest();

  // Name: GetType
  // Desc: Returns the name of the subtype (Animal)
  // Preconditions:  None
  // Postconditions: Returns string name of the subtype (Animal)
  virtual string GetType();
  
  // Name: overloaded operator<<
  // Desc: Allows Animal objects to be outputted
  // Preconditions:  None
  // Postconditions: Returns output stream with this format:
  //                 Animal | Chicken | Not Harvestable | Born | Fed
  virtual ostream& operator<<(ostream&);
  
private:
  string m_name; //Name of the type of animal (chicken by default)
  bool m_IsHungry; //Keeps track if animal not fed previous season (true = not fed)
};

#endif 
