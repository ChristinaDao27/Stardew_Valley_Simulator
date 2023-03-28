//Title: Tree.cpp
//Author: Christina Dao
//Date: 4/11/2021
//Description: File holds function Bodies of Tree class for Proj4
//E-mail: cdao1@umbc.edu
//Course Section: CMSC 202 section 50/52 (SP21)

#include "Tree.h"

//My own local constances.
const int SEEDLING = 0;
const int SAPLING = 1;
const int POLE = 2;
const int MATURE = 3;


// Name: Tree (Default constructor)
// Desc: Creates a tree with size 0 and age of 0
// Preconditions:  Uses AgItem default constructor
// Postconditions: A tree is created.
Tree::Tree(){
  m_age = 0;
}


// Name: ~Tree
// Desc: Destructor for tree (and importantly fruit)
// Preconditions:  Tree exists
// Postconditions: All fruit is purged from tree.
Tree::~Tree(){
  // Deallocate memory of fruits of tree
  for( unsigned int i = 0; i < m_fruit.size(); i++ ){
    delete m_fruit[i];
  }
}


// Name: Tick
// Desc: A season passes is the tree's life (always fed)
// Preconditions: Tree exists
// Postconditions: Returns amount of fruit harvested each season.
// One of the following occurs:
//    1. Tree is not Mature yet and ages. Every 4 seasons, size increases til age 12 when fruits
//    2. Tree is Mature and grows a one fruit a season. Fruit is harvested every season.
//    3. Tree is 60 seasons old and is cut down (IsHarvesteable)
void Tree::Tick(bool fed = true){
  // Age inc by one per season
  m_age += 1;
  // Check if tree is dead/ is harvestable
  if(m_age == SEASONS_TO_HARVEST ){
    SetIsHarvestable(true);
    return;
  }
  // Determine the size of tree based on the age of the tree
  if(m_age / SEASONS_TO_SIZE == SEEDLING){
    SetSize(SEEDLING);
  }
  else if(m_age / SEASONS_TO_SIZE == SAPLING){
    SetSize(SAPLING);
  }
  else if(m_age / SEASONS_TO_SIZE == POLE){
    SetSize(POLE);
  }
  else if(m_age / SEASONS_TO_SIZE == MATURE){
    SetSize(MATURE);
  }
  //add a fruit to tree every season IF tree is MATURE
  if(GetSize() == MATURE && m_age < SEASONS_TO_HARVEST){
    // Create new fruit object and add to tree fruit vector.
    Fruit *newFruit = new Fruit;
    m_fruit.push_back(newFruit);
  }
}


// Name: Harvest
// Desc: If there is fruit, removes last fruit and returns 1. If 60 seasons old, returns 0
// Preconditions:  Tree exists
// Postconditions: Fruit is returned(1 farm food) or dead tree (0 worth and 0 farm food)
int Tree::Harvest(){
  // Dead Tree
  if( GetIsHarvestable() == true ){
    return 0;
  }
  // Mature tree, harvesting it's fruit
  else{
    //deallocate fruit, becomes nullPtr 
    delete m_fruit[m_fruit.size() - 1];
    // delete the nullPtr/ last element
    m_fruit.pop_back();
    // adding 1 to farm m_food
    return 1;
  }
}


// Name: GetType
// Desc: Returns the name of the subtype (Tree)
// Preconditions:  None
// Postconditions: Returns string name of the subtype (Tree)
string Tree::GetType(){
  return "Tree";
}


// Name: overloaded operator<<
// Desc: Allows Tree objects to be outputted
// Preconditions:  None
// Postconditions: Returns output stream with this format:
//                 Tree  | Seedling | Not Harvestable | Not Fruiting | Fruit Count: 0
ostream& Tree::operator<<(ostream& output){
  output << GetType() << CONCAT << TREE_SIZE[GetSize()] << CONCAT << "Not Harvestable" << CONCAT;
  // Figure out if tree is or is not fruiting, based on its' age
  if(m_age < SEASONS_TO_FRUIT){
    output << "Not Fruiting" << CONCAT << "Fruit Count: " << m_fruit.size() << endl;
  }
  else{
    output << "Fruiting" << CONCAT << "Fruit Count: " << m_fruit.size() << endl;
  }

  return output;
}

