//Source: http://arsenmk.blogspot.in/2012/07/command-pattern-implementation.html
#include<iostream>
using namespace std;

//Abstract Class for Command
class Command
{
	public:
		virtual void Execute() = 0;
};

//Receiver Class
class Receiver
{
	public:
		void Action()
		{
			std::cout << "Command received" << std::endl;
			// don't forget to include <iostream> header
		}
};

//Invoker/Caller Class
class Invoker
{
	Command *m_command;	
	public:
		Invoker(Command *cmd = 0) : m_command(cmd)
		{
		}		
		void SetCommad(Command *cmd)
		{
			m_command = cmd;
		}		
		void Invoke()
		{
			if (0 != m_command)
			{
				m_command->Execute();
			}
		}
};

//Concrete Command Class
class MyCommand : public Command
{
	Receiver *m_receiver;

	public:
		MyCommand(Receiver *rcv = 0) : m_receiver(rcv)
		{
		}		
		void SetReceiver(Receiver *rcv)
		{
			m_receiver = rcv;
		}		
		virtual void Execute()
		{
			if (0 != m_receiver)
			{
				m_receiver->Action();
			}
		}
};

int main()
{
	//Receiver Object
	Receiver r;
	
	//Command Object
	MyCommand cmd(&r);
	
	//Invoker/Caller Object
	Invoker caller(&cmd);
	
	//Invoke method of Caller Object
	caller.Invoke();
	
	return 0;
}