#include<iostream>
using namespace std;
 
//Abstract Class for Command
class Command
{
	public:
		virtual void Execute() = 0;
};
 
//Invoker/Caller Class
class Switch
{
	public:			
		void Invoke(Command* cmd)
		{
			cmd->Execute();
		}
};
 
//Receiver Class
class Light
{
	public:
		void turnOn()
		{
			cout << "The light is on!" << endl;
		}
		void turnOff()
		{
			cout << "The light is off!" << endl;
		}
}; 
 
 
//The Command for turning on the light--Concrete Command Class#1
class FlipUpCommand : public Command
{
	Light* theLight;
	public:
		FlipUpCommand(Light* light) 
		{
			this->theLight=light;
		}			
		virtual void Execute()
		{
			theLight->turnOn();
		}
}; 

//The Command for turning off the light--Concrete Command Class#2
class FlipDownCommand : public Command
{
	Light* theLight;

	public:
		FlipDownCommand(Light* light) 
		{
			this->theLight=light;
		}			
		virtual void Execute()
		{
			theLight->turnOff();
		}
}; 
  
/* The test class or client */
int main()
{
	Light* lamp = new Light;
	Command* switchUp = new FlipUpCommand(lamp);
	Command* switchDown = new FlipDownCommand(lamp);
	
	Switch* mySwitch = new Switch;
	
	int option=1;
	switch(option) 
	{
		case 1:
			mySwitch->Invoke(switchUp);
		break;
		case 0:
			mySwitch->Invoke(switchDown);
		break;
		default:
			cout<<"Argument \"0\" or \"1\" is required."<<endl;
	}
	return 0;
}