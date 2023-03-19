#include "Application.h"
#include 	<conio.h>


Application::Application()
{
	modules[0] = new ModuleDummy();

	// TODO 7: Create your new module "DummyESC".
	ModuleDummy DummyESC;
	if (_kbhit() == 0 && _getch() == 
	// It should check if the player hits ESC key. Use _kbhit() and _getch().
}

// INIT all modules
bool Application::Init()
{
	for (int i = 0; i < NUM_MODULES; ++i)
	{
		bool state = modules[i]->Init();
		if (state == false) {return state;}
	}

	// TODO 5: Make sure that App exits correctly if Init/PreUpdate/Update/PostUpdate/CleanUp return exit

	return true;
}

update_status Application::Update()
{
	// TODO 2: Make sure all modules recieve its update

	for (int i = 0; i < NUM_MODULES; ++i)
	{
		update_status MrUpdate = modules[i]->PreUpdate();
		if (modules[i]->PreUpdate() != update_status::UPDATE_CONTINUE) { return MrUpdate; }
	}

	for (int i = 0; i < NUM_MODULES; ++i)
	{
		update_status MrUpdate = modules[i]->Update();
		if (modules[i]->Update() != update_status::UPDATE_CONTINUE) { return MrUpdate; }
	}

	for (int i = 0; i < NUM_MODULES; ++i)
	{
		update_status MrUpdate = modules[i]->PostUpdate();
		if (modules[i]->Update() != update_status::UPDATE_CONTINUE) { return MrUpdate; }
	}
	// TODO 4: Add PreUpdate and PostUpdate calls

	// TODO 5: Make sure that App exits correctly if Init/PreUpdate/Update/PostUpdate/CleanUp return exit

	return update_status::UPDATE_CONTINUE;
}
 
bool Application::CleanUp()
{
	// TODO 3: Make sure all modules have a chance to cleanup

	for (int i = 0; i < NUM_MODULES; ++i)
	{
		modules[i]->CleanUp();
	}

	return true;
}
