#include <iostream>
#include <string>
using namespace std;

/*ABSTRACT CLASSES*/

class Button
{
public:
	virtual void Push() = 0;
	virtual void Draw() = 0;
};
class Menu
{
public:
	virtual void Draw() = 0;
};


/*CONCRETE PRODUCT FAMILY 1*/

class WindowsButton : public Button
{
public:
	void Push()
	{
		printf("Windows button pushed");
	}
	void Draw()
	{
		printf("Windows button displayed");
	}
};
class WindowsMenu : public Menu
{
public:
	void Draw()
	{
		printf("Windows menu displayed");
	}
};


/*CONCRETE PRODUCT FAMILY 2*/

class LinuxButton : public Button
{
public:
	void Push()
	{
		printf("Linux button pushed");
	}
	void Draw()
	{
		printf("Linux button displayed");
	}
};
class LinuxMenu : public Menu
{
public:
	void Draw()
	{
		printf("Linux menu displayed");
	}
};


/*ABSTRACT FACTORY*/

class Factory {
public:
	virtual Button* CreateButton() = 0;
	virtual Menu* CreateMenu() = 0;
};

/*CONCRETE FACTORIES 1 AND 2*/

class WindowsFactory : public Factory
{
public:
	Button* CreateButton()
	{
		return new WindowsButton;
	}
	Menu* CreateMenu()
	{
		return new WindowsMenu;
	}
};
class LinuxFactory : public Factory
{
public:
	Button* CreateButton()
	{
		return new LinuxButton;
	}
	Menu* CreateMenu()
	{
		return new LinuxMenu;
	}
};


/*CLIENT*/

class Client
{
private:
	Factory* factory;

public:
	Client(Factory* f)
	{
		factory = f;
	}

	void DisplayMenu()
	{
		Menu* menu = factory->CreateMenu();
		menu->Draw();
	}

	void PushButton()
	{
		Button* button = factory->CreateButton();
		button->Push();
	}
};


/*MAIN*/

#define WINDOWS

int main()
{
	Factory* factory;
	string OS = "Windows";

#ifdef WINDOWS
	factory = new WindowsFactory;
#endif

#ifdef LINUX
	factory = new LinuxFactory;
#endif

	Client* client = new Client(factory);

	client->DisplayMenu();
	printf("\n");

	client->PushButton();
	printf("\n");
}