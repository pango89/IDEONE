#include<iostream>
#include<vector>
using namespace std;
//SUPER CLASS
class Stooge
{
  public:
    // Factory Method
    static Stooge *make_stooge(int choice);
    virtual void slap_stick() = 0;
};
//SUB CLASS 1
class Larry: public Stooge
{
  public:
    void slap_stick()
    {
        cout << "Larry: poke eyes\n";
    }
};
//SUB CLASS 2
class Moe: public Stooge
{
  public:
    void slap_stick()
    {
        cout << "Moe: slap head\n";
    }
};
//SUB CLASS 3
class Curly: public Stooge
{
  public:
    void slap_stick()
    {
        cout << "Curly: suffer abuse\n";
    }
};
//FACTORY METHOD DEFINTION
Stooge *Stooge::make_stooge(int choice)
{
  if (choice == 1)
    return new Larry;
  else if (choice == 2)
    return new Moe;
  else
    return new Curly;
}
//MAIN FUNCTION
int main()
{
	//CREATE AN ARRAY OF STOOGES
	vector<Stooge*> roles;
	int choice;
	while (true)
	{
		cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
		cin >> choice;
		if (choice == 0)
			break;
		roles.push_back(Stooge::make_stooge(choice));
	}
	for (int i = 0; i < roles.size(); i++)
		roles[i]->slap_stick();
	for (int i = 0; i < roles.size(); i++)
		delete roles[i];
	return 0;
}
