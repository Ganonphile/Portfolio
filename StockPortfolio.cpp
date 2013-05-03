/* File:   StockPortfolio.cpp
 * Author: Greg Donaldson
 * Created on March 24, 2012, 7:45 PM
 */

#include "StockPortfolio.h"

StockPortfolio::StockPortfolio() //Constructs the Class. Sets all values to 0, Null, or
{                                //"" depending on variable.
  New = NULL;
  Start = NULL;
  End = NULL;
  FileName = "";
  Counter = 0;
  PortfolioValue = 0.00;
  AutoStockWorth = 0.00;
  ConStockWorth = 0.00;
  FinStockWorth = 0.00;
  IndStockWorth = 0.00;
  TechStockWorth = 0.00;
}

void StockPortfolio::DetectFile()       //This detects the file exists.
{
  ifstream File;
  string Name = "";
    
  cout << "What is the name of the file? ";
    
  cin >> Name;                        //Stores the name of the file.
    
  File.open(Name.c_str());            //Tests to see if the file works.
    
  while (!File)                       //If the file doesn't open for some reason...
    {
      cout << "File name is incorrect! Please choose a different file name! ";
        
      cin >> Name;                    //Accept a new name.
        
      File.clear();                   //Clear the flags on the File ifstream.
        
      File.open(Name.c_str());        //Test to see if the file works.
    }
    
  File.clear();                       //Clear the flags on the File ifstream.
    
  File.close();                       //Close the File.
    
  FileName = Name;                    //Set the FileName to working File.
}

void StockPortfolio::LoadStocks()       //Loads the stocks into a Linked List.
{
  ifstream File;
  char charTemp = ' ';    
    
  File.open(FileName.c_str());        //Open the File up.
    
  while (!File.eof())                 //While we haven't hit the end of the list...
    {
      New = new StockNode;            //Create a new node.

      File >> New -> Stock;           //Store the name of the stock.
        
      if (New -> Stock == "")         //If the name of the stock doesn't exist...
        {
	  break;                      //Break the loop.
        }
        
      File >> charTemp;                   //Store the next variable, a character.
        
      New -> Sector = toupper(charTemp);  //Convert the character to Upper Case,
      //then store in the Sector Variable.
      File >> New -> StockPrice;          //Store the next variable in the File.
      File >> New -> NumberofShares;      //Store the next variable in the File.
        
      if (Counter == 0)                   //Check to see if the Counter is 0.
        {
	  New -> Next = NULL;             //If so, this is the first Node in the
	  Start = New;                    //list. Treat as such.
	  End = New;
        }
      else                                //If the counter isn't 1...
        {
	  New -> Next = NULL;             //Set the pointer to 0.
	  End -> Next = New;              //Connect the linked list to the new Node.
	  End = New;                      //Reset the end of the list.
        }
        
      Counter++;                          //Increment the Counter variable.
    }
}

void StockPortfolio::PrintHeader()          //Prints a Header.
{
  cout << "Stock Name\t" << "  Number of\t" << "Current Share\t" << 
    "Total Stock" << endl; 
    
  cout << "\t\t" << "Shares Owned\t" << "    Value\t" << "   Value\t" << endl;
    
  cout << "----------\t" << "------------\t" << "-------------\t" <<
    "-----------\t";
    
  cout << endl;
}

void StockPortfolio::PrintALL()             //Prints out all the information.
{
  AutoStocks();
  ConStocks();
  FinStocks();
  IndStocks();
  TechStocks();
  PrintPortfolioValue();
}

void StockPortfolio::NameLength()           //Sets spacing based on the length of
{                                           //the Stock Name.
  if (New -> Stock.length() <= 7)
    {
      cout << "\t\t    ";
    }
  else
    {
      cout << "\t    ";
    }
}

void StockPortfolio::NumShareLength()       //Sets spacing based on the number
{                                           //of shares.
  if (New -> NumberofShares < 100)
    {
      cout << " ";
    }
}

void StockPortfolio::ValueLength()          //Sets spacing based on the worth of
{                                           //the stock.
  if (New -> StockPrice < 10.00)
    {
      cout << " ";
    }
}

void StockPortfolio::TotalLength()          //Sets spacing based on the total worth
{                                           //of the stock.
  if (New -> TotalValue < 10000)
    {
      cout << " ";
    }
  if (New -> TotalValue < 1000)
    {
      cout << " ";
    }
  if (New -> TotalValue < 100)
    {
      cout << " ";
    }
}

void StockPortfolio::PrintStock()           //Prints out all information regarding
{                                           //a stock.
  cout << setiosflags(ios::fixed);
    
  cout << setprecision(0) << New -> Stock;
    
  NameLength();
    
  NumShareLength();
    
  cout << New -> NumberofShares << "\t\t    ";
    
  ValueLength();
    
  cout << setprecision(2) << New -> StockPrice << "\t";
            
  TotalLength();
    
  cout << "$" << New -> TotalValue << endl;
}

void StockPortfolio::PrintPortfolioValue()              //Prints the Value of the
{                                                       //Portfolio.
  CalcPortfolioValue();
    
  cout << "\t\t\t\t\t       ----------" << endl;
    
  cout << "\t\t\tTotal Portfolio Value: $" << PortfolioValue << endl;
}

void StockPortfolio::IncrementList()            //Increments the linked list.
{
  if (End != New)                             //This is important. So long as we
    {                                           //haven't reached the end of the
      New = New -> Next;                      //list, this will keep incrementing.
    }                                           //Otherwise, this function does
}                                               //Nothing.

double StockPortfolio::CalcStockWorth()         //Calculates the total value of a
{                                               //stock. Caution: Math ahead.
  double ShareWorth = 0.00;
  double TotalStocks = 0;
  double TotalStockValue = 0.00;
    
  ShareWorth = New -> StockPrice;
    
  TotalStocks = New -> NumberofShares;
    
  TotalStockValue = ShareWorth*TotalStocks;
    
  return TotalStockValue;
}

void StockPortfolio::CalcPortfolioValue()               //Calculates the total
{                                                       //Portfolio value.
    PortfolioValue = AutoStockWorth + ConStockWorth + FinStockWorth + 
      IndStockWorth + TechStockWorth;
}

void StockPortfolio::AutoStocks()                       //This function looks for
{                                                       //all the Auto Stocks.
  New = Start;                                        //Set the New pointer to
  //the start of the list.
  cout << "Auto Sector" << endl;                      //Print out that this is
  //the Auto Sector.
  cout << "-----------" << endl;
    
  cout << endl;
    
  PrintHeader();                                //Print the header.
    
  while (New -> Next != NULL)                   //Make sure we haven't reached
    {                                             //the end of the list.
      if (New -> Sector == 'A')                 //Check to see if we have the
        {                                         //right stock.
	  New -> TotalValue = CalcStockWorth(); //Store the worth of the stock.
            
	  AutoStockWorth += New -> TotalValue;  //Add to the total amount of auto stocks.
            
	  PrintStock();                         //Print the stock.
        }
        
      IncrementList();                          //Increment the list.
    }
    
  cout << endl;
    
  cout << "\t\t\t\t\t\t --------" << endl;      
    
  cout << "\t\t\t  Total for Auto Sector: $" << AutoStockWorth << endl;
    
  cout << endl;
}

void StockPortfolio::ConStocks()                //Now we repeat, looking for the 
{                                               //consumer stocks.
  New = Start;
    
  cout << "Consumer Products Sector" << endl;
    
  cout << "------------------------" << endl;
    
  cout << endl;
    
  PrintHeader();
    
  while (New -> Next != NULL)
    {
      if (New -> Sector == 'C')
        {
	  New -> TotalValue = CalcStockWorth();
            
	  ConStockWorth += New -> TotalValue;
            
	  PrintStock();
        }
        
      IncrementList();
    }
    
  cout << endl;
    
  cout << "\t\t\t\t\t\t----------" << endl;
    
  cout << "\t    Total for Consumer Products Sector: $" << 
    ConStockWorth << endl;
    
  cout << endl;
}

void StockPortfolio::FinStocks()                //Repeat, looking for Financial/
{                                               //Insurance stocks.
  New = Start;
    
  cout << "Financial/Insurance Sector" << endl;
    
  cout << "--------------------------" << endl;
    
  cout << endl;
    
  PrintHeader();
    
  while (New -> Next != NULL)
    {
      if (New -> Sector == 'F')
        {
	  New -> TotalValue = CalcStockWorth();
            
	  FinStockWorth += New -> TotalValue;
            
	  PrintStock();
        }
        
      IncrementList();
    }
    
  cout << endl;
    
  cout << "\t\t\t\t\t\t------------" << endl;
    
  cout << "\t  Total for Financial/Insurance Sector: $" << 
    FinStockWorth << endl;
    
  cout << endl;
}

void StockPortfolio::IndStocks()                        //Repeat, looking for
{                                                       //Industrial Stocks.
  New = Start;
    
  cout << "Industrial Products Sector" << endl;
    
  cout << "--------------------------" << endl;
    
  cout << endl;
    
  PrintHeader();
    
  while (New -> Next != NULL)
    {
      if (New -> Sector == 'I')
        {
	  New -> TotalValue = CalcStockWorth();
            
	  IndStockWorth += New -> TotalValue;
            
	  PrintStock();
        }
        
      IncrementList();
    }
    
  cout << endl;
    
  cout << "\t\t\t\t\t\t----------" << endl;
    
  cout << "\t\t   Total for Industrial Sector: $" << IndStockWorth << endl;
    
  cout << endl;
}

void StockPortfolio::TechStocks()                       //Repeat, looking for
{                                                       //Technology Stocks.
  New = Start;
    
  cout << "Technology Sector" << endl;
    
  cout << "-----------------" << endl;
    
  cout << endl;
    
  PrintHeader();
    
  while (New -> Next != NULL)
    {
      if (New -> Sector == 'T')
        {
	  New -> TotalValue = CalcStockWorth();
            
	  TechStockWorth += New -> TotalValue;
            
	  PrintStock();
        }
        
      IncrementList();
    }
    
  cout << endl;
    
  cout << "\t\t\t\t\t\t----------" << endl;
    
  cout << "\t\t   Total for Technology Sector: $" << TechStockWorth << endl;
    
  cout << endl;
}

StockPortfolio::~StockPortfolio()                       //A deconstructor, should
{                                                       //I need it.
  New = Start;
    
  while (Counter != 0)
    {
      IncrementList();
        
      Start -> Next = NULL;
        
      delete Start;
        
      Start = New;
        
      Counter--;
    }
}
