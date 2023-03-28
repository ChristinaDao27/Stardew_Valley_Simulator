//Title: Vegetable.cpp
//Author: Christina Dao
//Date: 4/11/2021
//Description: File holds function Bodies of Vegetable class for Proj4
//E-mail: cdao1@umbc.edu
//Course Section: CMSC 202 section 50/52 (SP21)

#include "Vegetable.h"


// Name: Vegetable (Default constructor)
// Desc: Creates a vegetable with size 0
// Preconditions:  Uses AgItem default constructor
// Postconditions: A vegetable is created.
Vegetable::Vegetable(){}


// Name: Harvest
// Desc: If the vegetable is harvestable (fully mature), returns size to increase farm's food
// Preconditions:  IsHarvestable
// Postconditions: Returns integer size of vegetable for food
int Vegetable::Harvest(){
  return GetSize();
}


// Name: Tick
// Desc: A season passes in the vegetable's life if they are fully mature, IsHarvestable flipped
// Preconditions:  If the size is less than the maximum vegetable size, increases size
// Postconditions: Vegetable either grows or becomes harvestable
// Assume that a vegetable is always fed.
void Vegetable::Tick(bool fed = true){ //Vegetables are always "fed"
  // Make Vegetable harvestable if fully grown
  if( GetSize() == MAX_VEG_SIZE ){
    SetIsHarvestable(true);
  }
  // Icrease vegetable size +1 each season until harvestable
  else{
    SetSize( GetSize() + 1 );
  }
}


// Name: GetType
// Desc: Returns the name of the subtype (Vegetable)
// Preconditions:  None
// Postconditions: Returns string name of the subtype (Vegetable)
string Vegetable::GetType(){
  return "Vegetable";
}


// Name: overloaded operator<<
// Desc: Allows Vegetable objects to be outputted
// Preconditions:  None
// Postconditions: Returns output stream with this format
//                 Vegetable | Not Harvestable | Seedling
ostream& Vegetable::operator<<(ostream& output){
  return output << GetType() << CONCAT << "Not Harvestable" << CONCAT << Veg_Size[GetSize()] << endl;
}
