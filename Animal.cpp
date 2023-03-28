//Title: Animal.cpp
//Author: Christina Dao
//Date: 4/11/2021
//Description: File holds function Bodies of Animal class for Proj4
//E-mail: cdao1@umbc.edu
//Course Section: CMSC 202 section 50/52 (SP21)

#include "Animal.h"


// Name: Animal (Default constructor)
// Desc: Creates an Animal with size 0
// Preconditions:  Uses AgItem default constructor
// Postconditions: An animal (chicken) is created.
Animal::Animal(){
  m_name = "chicken";
  m_IsHungry = true;
}


// Name: Tick
// Desc: A season passes is the animal's life (passed boolean if it was fed - eats "farm's food")
// Preconditions: If farm has food, animal is automatically fed
// Postconditions: One of the following occurs
//    1. Animal is fed and size increases (not max yet)
//    2. Animal is fed hits max size and is made harvestable
//    3. Animal is not fed. Size does not increase. If second no feed, is harvested (small).
void Animal::Tick(bool fed){
  //Animal has been fed
  if( fed == true ){
    m_IsHungry = false;
    // Check if animal is maxed size, ready to harvest
    if( GetSize() == ANIMAL_MAX_SIZE ){
      SetIsHarvestable(true);
    }
    //Animal Grows if fed and not already maxed size
    else{
      SetSize( GetSize() + 1 );
      SetWorth( BASE_WORTH * GetSize() );
    }
  }
  // Animal becomes huingry because there is no food to feed it
  else if( fed == false && m_IsHungry == false ){
    m_IsHungry = true;
  }
  else if( fed == false && m_IsHungry == true ){
    //two seasons not fed; Harvest it
    SetIsHarvestable(true);
    SetWorth( BASE_WORTH * GetSize() );
  }
}


// Name: Harvest
// Desc: If the animal is harvestable (adult), returns worth * size to increase farm's money
// Preconditions:  IsHarvestable
// Postconditions: Animal harvested and money is gained (worth * size)
int Animal::Harvest(){
  if(GetIsHarvestable() == true){
    // Check if it was harvested for its size or because it wasn't fed two consecutive seasons
    if(GetSize() != ANIMAL_MAX_SIZE){
      cout << "The Animal was Harvested (small)" << endl;
      return GetWorth();
    }
    else{
      cout << "The Animal was Harvested" << endl;
      return GetWorth();
    }
  }
  //Animal is not Harvestable
  else{
    return 0;
  }
  return 0;
}


// Name: GetType
// Desc: Returns the name of the subtype (Animal)
// Preconditions:  None
// Postconditions: Returns string name of the subtype (Animal)
string Animal::GetType(){
  return "Animal";
}


// Name: overloaded operator<<
// Desc: Allows Animal objects to be outputted
// Preconditions:  None
// Postconditions: Returns output stream with this format:
//                 Animal | Chicken | Not Harvestable | Born | Fed
ostream& Animal::operator<<(ostream& output){
  string hunger;
  // Display whether or not animal was fed
  if(m_IsHungry){
    hunger = "Not Fed";
  }
  else{
    hunger = "Fed";
  }

  return output << GetType() << CONCAT << m_name << CONCAT << "Not Harvestable" << CONCAT << ANIMAL_SIZE[GetSize()] << CONCAT << hunger << endl;
}
