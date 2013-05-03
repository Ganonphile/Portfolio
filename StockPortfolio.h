/* 
 * File:   StockPortfolio.h
 * Author: Greg Donaldson
 * Created on March 24, 2012, 7:45 PM
 */

#ifndef STOCKPORTFOLIO_H
#define STOCKPORTFOLIO_H

#include <string.h>     //Strings here! Get your strings.
#include <fstream>      //Dealing with some files as well.
#include <iostream>     //This allows for cout and cin.
#include <iomanip>      //Manipulates the input/output.

using namespace std;    //This allows the string.h to actually work.

class StockPortfolio    //This is a class.
{
 public:
  StockPortfolio();           //Constructor for the class.
  void DetectFile();          //Function prototype...which seems to detect a file.
  void LoadStocks();          //Function prototype...Loads some stocks.
  void PrintHeader();         //Function prototype...Prints a Header.
  void PrintALL();            //Function prototype...Prints EVERYTHING.
  ~StockPortfolio();          //Deconstructor. 
 private:
  void PrintStock();          //Function prototype...Prints out all info on a Stock.
  void PrintPortfolioValue(); //Function prototype...Prints out portfolio value.
  void IncrementList();       //Function prototype...Increments down the Linked List.
  void AutoStocks();          //Function prototype...Deals with all the Auto Stocks.
  void ConStocks();           //Function prototype...Deals with all Consumer Stocks.
  void FinStocks();           //Function prototype...Deals with all Financial Stocks.
  void IndStocks();           //Function prototype...Deals with all Industrial Stocks.
  void TechStocks();          //Function prototype...Deals with all Technology Stocks.
  double CalcStockWorth();    //Function prototype...Calculates an individual stocks total worth.
  void CalcPortfolioValue();  //Function prototype...Calculates the Portfolios total value.
  void NameLength();          //Function prototype...Deals with the length of a name.
  void NumShareLength();      //Function prototype...Deals with the length of a number of shares.
  void ValueLength();         //Function prototype...Deals with the length of a Value.
  void TotalLength();         //Function prototype...Deals with the length of the total Worth.
  struct StockNode            //A struct for storing Stock information.
  {   
    string Stock;           //Stores the information of a given Stock.
    char Sector;            //Stores the information of the character representing a sector.
    double StockPrice;      //Stores the price of an individual stock.
    double NumberofShares;  //Stores the number of shares in a given stock.
    double TotalValue;      //Stores the total value of a given stock.
    StockNode *Next;        //A pointer to the next node.
  };
  StockNode *New;             //A pointer to a node. Used to create new nodes.
  StockNode *Start;           //A pointer to a node. Stores the start point.
  StockNode *End;             //A pointer to a node. Stores the last node.
  string FileName;            //Stores the Name of the File.
  int Counter;                //A counter.
  double PortfolioValue;      //Stores the value of the portfolio.
  double AutoStockWorth;      //Stores the worth of all Auto Stocks.
  double ConStockWorth;       //Stores the worth of all Consumer Stocks.
  double FinStockWorth;       //Stores the worth of all Financial Stocks.
  double IndStockWorth;       //Stores the worth of all Industrial Stocks.
  double TechStockWorth;      //Stores the worth of all Technology Stocks.
};

#endif/* STOCKPORTFOLIO_H */

