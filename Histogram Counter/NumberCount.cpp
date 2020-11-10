// Matthew Erikson

#include <iostream>
#include <string>

using namespace std;

class NumberCount
{
private:
  int *numList;
  int MAX, MIN;
  string errorList;

public:

//constructor
NumberCount(int MIN, int MAX)
{
  //create the numList using the parameters given by the user
  numList = new int[MAX - MIN + 1];

  //initialize array 
  for (int i = 0; i < (MAX - MIN + 1); i++) {
      numList[i] = 0;
  }
  this->MAX = MAX;
  this->MIN = MIN;
}

//destructor
~NumberCount()
{
//delete the dynamically allocated array
  delete [] numList;
}

//add element
void addElement(int newElement)
{
  if(newElement <= MAX && newElement >= MIN)
  {
    //add the element to the correct location
    numList[newElement-MIN]++;
  }
  else
  {
    //add the out of bounds element to the error list
    errorList = errorList + to_string(newElement) + " out of range; ";
  }
}

//remove element
bool removeElement(int remElement)
{
  //check bounds
  if(remElement <= MAX && remElement >= MIN)
  {
    //check to see if there is a number to removeElement
    if(numList[remElement-MIN] > 0)
    {
      numList[remElement-MIN]--;
      return true;
    }
    else
    {
      //indicate the lack of number in error list
      errorList = errorList + to_string(remElement) + " not present; ";
      return false;
    }
  }
  else
  {
    //indicate range error in error list
    errorList = errorList + to_string(remElement) + " out of range; ";
    return false;
  }
}

void display()
  {
    //output error list
    cout << errorList << endl;

    //output histogram
    for (int i = 0; i < (MAX-MIN+1); i++)
    {
      cout << (MIN+i) << ":";
      if ((MIN + i) < 10) {
          cout << " ";
      }
      for (int j = 0; j < numList[i]; j++)
      {
        cout << "*";
      }
      cout << endl;
    }
  }
};

//main to demonstrate NumberCount functions
int main()
{
  //create the number list
  NumberCount A(5, 11);

  //add and remove elements
  A.addElement(5); A.addElement(4); A.addElement(5); A.addElement(6);
  A.addElement(5); A.removeElement(5); A.removeElement(7); A.addElement(13);
  A.addElement(8); A.addElement(9); A.addElement(9); A.addElement(10);

  //display list via histogram
  A.display();

  return 0;
}
