//Title: AgItem.cpp
//Author: Christina Dao
//Date: 4/11/2021
//Description: File holds function Bodies of AgItem class for Proj4
//E-mail: cdao1@umbc.edu
//Course Section: CMSC 202 section 50/52 (SP21)

#include "AgItem.h"


// Name: AgItem (Default constructor)
// Desc: Creates an AgItem with size 0, Base_Worth of 1 and not harvestable
// Preconditions:  Abstract class
// Postconditions: Abstract class so used with child classes only.
AgItem::AgItem(){
  m_size = 0;
  m_worth = BASE_WORTH;
  m_isHarvestable = false;
}


// Name: AgItem (Overloaded constructor)
// Desc: Creates an AgItem with size, worth, and IsHarvestable passed
// Preconditions:  Abstract class
// Postconditions: Abstract class so used with child classes only.
AgItem::AgItem(int i, int j, bool harvestable){
  m_size = i;
  m_worth = j;
  m_isHarvestable = harvestable;
}


// Name: ~AgItem (Destructor
// Desc: Deletes anything dynamically allocated
// Preconditions:  AgItem
// Postconditions: IS trivially implemented but required for subclass (tree)
AgItem::~AgItem(){}


// Name: GetSize
// Desc: Returns m_size
// Preconditions:  None
// Postconditions: None
int AgItem::GetSize(){
  return m_size;
}


// Name: GetWorth
// Desc: Returns m_worth
// Preconditions:  None
// Postconditions: None
int AgItem::GetWorth(){
  return m_worth;
}


// Name: GetIsHarvestable
// Desc: Returns m_isHarvestable
// Preconditions:  None
// Postconditions: None
bool AgItem::GetIsHarvestable(){
  return m_isHarvestable;
}


// Name: SetSize
// Desc: Sets the size of an AgItem
// Preconditions:  None
// Postconditions: m_size is set
void AgItem::SetSize(int size){
  m_size = size;
}


// Name: SetIsHarvestable
// Desc: Sets m_isHarvestable
// Preconditions:  None
// Postconditions: m_isHarvestable is set
void AgItem::SetIsHarvestable(bool isAlive){
  m_isHarvestable = isAlive;
}


// Name: SetWorth
// Desc: Sets m_worth
// Preconditions:  None
// Postconditions: m_worth is set
void AgItem::SetWorth(int worth){
  m_worth = worth;
}

