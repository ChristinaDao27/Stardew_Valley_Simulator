//Title: Farm.cpp
//Author: Christina Dao
//Date: 4/11/2021
//Description: File holds function Bodies of Farm class for Proj4
//E-mail: cdao1@umbc.edu
//Course Section: CMSC 202 section 50/52 (SP21)

#include "Farm.h"

const int init_Food = 6;

// Name: Farm (Default constructor)
// Desc: Creates a Farm (with 6 food, 0 money, season = 1)
// Preconditions:  None
// Postconditions: A farm is created
Farm::Farm(){
  m_food = init_Food;
  m_money = 0;
  m_season = 1;
}


// Name: Farm (Destructor)
// Desc: Deallocates everything in the farm
// Preconditions:  None
// Postconditions: The farm is cleared out
Farm::~Farm(){
  // Deallocate everything in farm
  for(unsigned int i =0; i < m_farm.size(); i++){
    delete m_farm[i];
  }
}


// Name: ChooseItem
// Desc: Allows the user to choose either an animal, vegetable, or tree
// Preconditions:  None
// Postconditions: returns 1 (animal), 2 (vegetable), or 3 (tree) (reprompts for anything else)
int Farm::ChooseItem(){
  int item = 0;
  //Ask User which item they want to add.
  while( item < 1 || item > 5 ){
    cout << "Which Agricultural item are you interested in?" << endl;
    cout << "1. Animal" << endl;
    cout << "2. Vegetable" << endl;
    cout << "3. Tree" << endl;
    //Input Validation
    cin >> item;
  }
  return item;
}


// Name: AddItem (int type, int quantity)
// Desc: Dynamically allocates new animals, vegetables, or trees and adds to m_farm
// Preconditions:  None
// Postconditions: Adds 1 (animal), 2 (vegetable), or 3 (tree) to m_farm
void Farm::AddItem(int type, int quantity){
  //Add an x amount of an item to the farm
  for( int i = 0; i < quantity; i++){
    // Adding new Animal to m_farm vector
    if(type == 1){
      AgItem *newAnimal = new Animal;
      m_farm.push_back(newAnimal);
      cout << "New Animal added to the farm." << endl;

    }
    //Adding new Vegetable to m_farm vector
    else if(type == 2){
      AgItem *newVegetable = new Vegetable;
      m_farm.push_back(newVegetable);
      cout << "New Vegetable added to the farm." << endl;
    }
    //Adding new Tree to m_farm vector
    else if(type == 3){
      AgItem *newTree = new Tree;
      m_farm.push_back(newTree);
      cout << "New Tree added to the farm." << endl;
    }
  }
}


// Name: Tick (int season)
// Desc: Simulates a specific number of seasons and Displays Status automatically
// Preconditions:  None
// Postconditions: Time passes
void Farm::Tick(int seasons){
  //Simulate seasons
  for( int i = 0; i < seasons; i++ ){
    cout << "SEASON: " << m_season << endl;
    // Tick each items
    for( unsigned int j = 0; j < m_farm.size(); j++ ){
      //See if food is available to feed animals
      if(m_food > 0){
	m_farm.at(j)->Tick(true);

	if(m_farm.at(j)->GetType() == "Animal"){
	  //Deduct food
	  m_food -= 1;
	}
      }
      //Animal m_IsHungry will be hungry (false) because no food.
      else{
	m_farm.at(j)->Tick(false);
      }
      //Harvest fruits of mature trees and add to farm's m_food
      if(m_farm.at(j)->GetType() == "Tree" and m_farm.at(j)->GetSize() == 3){
	m_food += m_farm.at(j)->Harvest();
      }
      //Harvesting
      if(m_farm.at(j)->GetIsHarvestable()){
	if(m_farm.at(j)->GetType() == "Animal"){
	  // Inc money when harvesting Animals
	  m_money += m_farm.at(j)->Harvest();

	}
	else if(m_farm.at(j)->GetType() == "Vegetable"){
	  // Inc food when Harvesting Food
	  m_food += m_farm.at(j)->Harvest();
	  cout << "The Vegetable was harvested" << endl;
	}
	else if(m_farm.at(j)->GetType() == "Tree"){
	  // This returns zero, tree is dead and is harvested.
	  m_food += m_farm.at(j)->Harvest();
	  cout << "The Tree was Harvested" << endl;
	}
	// Delete and deallocate Harvested items
	delete m_farm.at(j);

	m_farm.erase(m_farm.begin() + j);

	// Readjust index
	j -= 1;
      }
    }
    //Display Status and increment m_seasons.
    Status();
    cout << endl;
    m_season += 1;
  }
}


// Name: Menu
// Desc: Displays a menu with the following:
//     1. Add Item to Farm (adds a single item to m_farm)
//     2. Add Two of Each Item to Farm (Adds two of each item to m_farm)
//     3. Simulate Time (Asks the user how many seasons to simulate)
//     4. Farm Status (Displays the status of the farm)
//     5. Quit (Quits the simulation)
// Preconditions:  None
// Postconditions:  If returns 5, quits
int Farm::Menu(){
  int choice = 0;
  //Input Validation, Displaying simulation options
  while(choice < 1 || choice > 5){
    cout << "1. Add Item to Farm" << endl;
    cout << "2. Add Two of Each Item to Farm" << endl;
    cout << "3. Simulate Time" << endl;
    cout << "4. Farm Status" << endl;
    cout << "5. Quit" << endl;
    cin >> choice;
  }
  return choice;
}


// Name: StartSimulation
// Desc: Manages the introduction, menu, and quitting
// Preconditions:  Displays welcome message
// Postconditions: As long as menu doesn't return 5, keeps running
void Farm::StartSimulation(){
  cout << "Welcome to Stardew Valley Simulator" << endl;
  int choice = 0;
  do{
    choice = Menu();

    switch ( choice ){
    //Add to an item
    case 1:{
      int item = ChooseItem();
      
      if( item == 1 ){
	AddItem(1, 1);
      }
      else if( item == 2 ){
	AddItem(2, 1);
      }
      else if( item == 3 ){
	AddItem(3, 1);
      }
      break;
    }

    //Add two of each item
    case 2:{
      AddItem(1, 2);
      AddItem(2, 2);
      AddItem(3, 2);
      break;
    }

    // User chooses to Simulate a number of seasons
    case 3:{
      int seasons = 0;
      cout << "How many seasons to simulate?" << endl;
      //Input Validation
      while( seasons < 1 ){
	cin >> seasons;
      }

      Tick(seasons);
      break;
    }
      
    case 4:{
      Status();
      break;
    }
      
    case 5:{
      break;
    }
    }
  //Exit Program if player chooses to exit.
  }while( choice != 5 );
  cout << "Thank you for simulating Stardew Valley!" << endl;
}


// Name: Status
// Desc: Displays farm food, money, season, and each agricultural item
// Preconditions:  None
// Postconditions: Displays farm data
void Farm::Status(){
  cout << "**** Farm Status ****" << endl;
  cout << "Food: " << m_food << endl;
  cout << "Money: " << m_money << endl;
  cout << "Season: " << m_season << endl;
  cout << "Agricultural Items:" << endl;
  //loops through farm items and outputs farm items info
  for( unsigned int i = 0; i < m_farm.size(); i++){
    (*m_farm.at(i)) << cout << endl;
  }
}
