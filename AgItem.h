//Title: AgItem.h
//Author: Jeremy Dixon
//Date: 3/19/2021
//Description: Describes the parent class (Agricultural Items - animals, vegetables, and trees)

#ifndef AG_ITEM_H
#define AG_ITEM_H
#include <iostream>
#include <string>
using namespace std;

const string CONCAT = " | ";
const int BASE_WORTH = 1;

class AgItem {
public:
  // Name: AgItem (Default constructor)
  // Desc: Creates an AgItem with size 0, Base_Worth of 1 and not harvestable
  // Preconditions:  Abstract class
  // Postconditions: Abstract class so used with child classes only.
  AgItem();

  // Name: AgItem (Overloaded constructor)
  // Desc: Creates an AgItem with size, worth, and IsHarvestable passed
  // Preconditions:  Abstract class
  // Postconditions: Abstract class so used with child classes only.
  AgItem(int, int, bool);
  
  // Name: ~AgItem (Destructor
  // Desc: Deletes anything dynamically allocated
  // Preconditions:  AgItem
  // Postconditions: Can be trivially implemented but required for subclass (tree)
  virtual ~AgItem();
  
  //Accessors
  
  // Name: GetSize
  // Desc: Returns m_size
  // Preconditions:  None
  // Postconditions: None
  int GetSize();

  // Name: GetWorth
  // Desc: Returns m_worth
  // Preconditions:  None
  // Postconditions: None
  int GetWorth();

  // Name: GetIsHarvestable
  // Desc: Returns m_isHarvestable
  // Preconditions:  None
  // Postconditions: None
  bool GetIsHarvestable();
  
  // Name: SetSize
  // Desc: Sets the size of an AgItem
  // Preconditions:  None
  // Postconditions: m_size is set
  void SetSize(int size);
  
  // Name: SetIsHarvestable
  // Desc: Sets m_isHarvestable
  // Preconditions:  None
  // Postconditions: m_isHarvestable is set
  void SetIsHarvestable(bool isAlive);

  // Name: SetWorth
  // Desc: Sets m_worth
  // Preconditions:  None
  // Postconditions: m_worth is set
  void SetWorth(int worth);
  
  // Name: Tick (Purely Virtual)
  // Desc: Calls Tick on the subtype (not implemented here)
  // Preconditions:  None
  // Postconditions: Implemented in child classes
  virtual void Tick(bool) = 0;

  // Name: Harvest (Purely Virtual)
  // Desc: Calls Harvest on the subtype (not implemented here)
  // Preconditions:  None
  // Postconditions: Implemented in child classes
  virtual int Harvest() = 0;

  // Name: GetType (Purely Virtual)
  // Desc: Returns the name of the subtype (not implemented here)
  // Preconditions:  None
  // Postconditions: Implemented in child classes
  virtual string GetType() = 0;
  
  // Name: overloaded operator<< (Purely Virtual)
  // Desc: Allows AgItems objects to be outputted
  // **NOTE** - Must be called with (*m_farm.at(i)) << cout << endl; (In this order)
  // Preconditions:  None
  // Postconditions: Implemented in child classes
  virtual ostream& operator<<(ostream& os) = 0;
  
 private:
  int m_size; //Current size
  int m_worth; //Worth of item
  bool m_isHarvestable; //Current status
};

#endif
