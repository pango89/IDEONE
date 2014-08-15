#include <iostream>
#include <string>
using namespace std;

/* Abstract base class */
// The abstract Coffee class defines the functionality of Coffee implemented by decorator
class Coffee 
{
	public:
	  virtual double getCost() = 0; // Returns the cost of the coffee
	  virtual string getIngredients() = 0; // Returns the ingredients of the coffee
	  virtual ~Coffee() = 0;
};
inline Coffee::~Coffee()
{
}
 
/* SimpleCoffee class. */
// Extension of a simple coffee without any extra ingredients
class SimpleCoffee : public Coffee 
{
	public: 
		double getCost() 
		{
			return 1.0;
		}
		string getIngredients() 
		{
			return "Coffee";
		}
};
 
/* Decorators */
// Decorator Milk that adds milk to coffee.
struct MilkDecorator : Coffee 
{
	private:
	  Coffee* basicCoffee_;
	public: 
	  MilkDecorator (Coffee* basicCoffee)
	  {
	  	basicCoffee_ = basicCoffee; 
	  }	 
	  double getCost() 
	  { 
		// Providing methods defined in the abstract superclass
		return basicCoffee_->getCost() + 0.5;
	  }	 
	  string getIngredients() 
	  {
		return basicCoffee_->getIngredients() + ", " + "Milk";
	  }	
};
 
// Decorator Whip that adds whip to coffee
struct WhipDecorator : Coffee 
{
	private:
	  Coffee* basicCoffee_;
	public:
	  WhipDecorator (Coffee* basicCoffee)
	  {
	  	basicCoffee_ = basicCoffee;
	  }	 
	  double getCost() 
	  {
		return basicCoffee_->getCost() + 0.7;
	  }
	  string getIngredients() 
	  {
		return basicCoffee_->getIngredients() + ", " + "Whip";
	  } 
};
 
/* Test program */
int main() 
{
  SimpleCoffee s;
  cout << "Cost: " << s.getCost() << "; Ingredients: " << s.getIngredients() << endl;
 
  MilkDecorator m(&s);
  cout << "Cost: " << m.getCost() << "; Ingredients: " << m.getIngredients() << endl;
 
  WhipDecorator w(&s);
  cout << "Cost: " << w.getCost() << "; Ingredients: " << w.getIngredients() << endl;
 
  // Note that you can stack decorators:
  MilkDecorator m2(&w);
  cout << "Cost: " << m2.getCost() << "; Ingredients: " << m2.getIngredients() << endl;
}
/*
THE OUTPUT OF THIS PROGRAM IS GIVEN BELOW:

COST: 1.0; INGREDIENTS: COFFEE
COST: 1.5; INGREDIENTS: COFFEE, MILK
COST: 1.7; INGREDIENTS: COFFEE, WHIP
COST: 2.2; INGREDIENTS: COFFEE, WHIP, MILK
*/