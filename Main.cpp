#include "Application.h"
#include "Globals.h"
#include "MemLeaks.h"

enum class main_states
{
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT
};

int main()
{
	ReportMemoryLeaks();

	int main_return = EXIT_FAILURE;
	main_states state = main_states::MAIN_CREATION;
	Application* App = nullptr;

	while (state != main_states::MAIN_EXIT)
	{
		switch (state)
		{
			case main_states::MAIN_CREATION:
			{
				LOG("Application Creation --------------\n");
				App = new Application();
				state = main_states::MAIN_START;
			}	break;

			case main_states::MAIN_START:
			{
				LOG("Application Start --------------\n");
				if(App->Init() == false)
				{
					LOG("Application Init exits with error -----\n");
					state = main_states::MAIN_EXIT;
				}
				else
				{
					state = main_states::MAIN_UPDATE;
				}
			}	break;

			case main_states::MAIN_UPDATE:
			{
				update_status status = App->Update();

				if (status == update_status::UPDATE_ERROR)
				{
					LOG("Application Update exits with error -----\n");
					state = main_states::MAIN_EXIT;
				}
				else if (status == update_status::UPDATE_STOP)
				{
					state = main_states::MAIN_FINISH;
				}
			}	break;

			case main_states::MAIN_EXIT:
			{
				LOG("Application Exit --------------\n");
				if (App->CleanUp() == true) {
					main_return = EXIT_SUCCESS;
					
				}
				else { main_return = EXIT_FAILURE; } //not necessary
			}	break;
			// TODO 1: Implement case MAIN_FINISH
			// Remember to quit the game with EXIT_SUCCESS if everything went well :)
		}
	}

	LOG("\nBye :)\n");

	// TODO 6: Remove ALL memory leaks
	delete App;

	//Returns EXIT_FAILURE = 0, EXIT_
	return main_return;
}