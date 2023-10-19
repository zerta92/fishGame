#include <iostream>
#include "./Game/GameCommands.h"
#include "./Coordinates/CartPoint.h"
#include "./Coordinates/CartVector.h"
#include "View.h"
#include "InputHandling.h"

#include "Sharknado/Sharknado.h"

using namespace std;

int main()
{

    Model model = Model();
    GameCommands gc;
    model.show_status();
    View view;
    model.display(view);

    while (true)
    {
        char command;
        cout << "Enter Command: ";
        cin >> command;

        try
        {

            if (command != 'a' && command != 'e' && command != 'f' && command != 'g' && command != 'n' && command != 'r' && command != 'q' && command != 's' && command != 'z')
                throw InvalidInput("Not a valid command");

            switch (command)
            {
            case 's':
                gc.do_swim_command(model);
                model.display(view);
                break;

            case 'n':
                gc.handle_new_command(model);
                model.display(view);
                break;

            case 'a':
                gc.do_attack(model);
                model.display(view);
                break;

            case 'e':
                gc.do_eat_command(model);
                model.display(view);
                break;

            case 'f':
                gc.do_float_command(model);
                model.display(view);
                break;

            case 'z':
                gc.do_zoom_command(model);
                model.display(view);
                break;

            case 'g':
                cout << "Advancing one tick" << endl;
                gc.do_go_command(model);
                model.show_status();
                model.display(view);

                break;

            case 'r':
                cout << "Advancing next event" << endl;
                gc.do_run_command(model);
                model.show_status();
                model.display(view);

                break;

            case 'q':
                cout << "Terminating Program" << endl;
                return 0;
                // break;
            }
        }

        catch (InvalidInput &except)
        {
            // actions to be taken if the input is wrong
            cout << "Invalid input - " << except.msg_ptr << endl;
        }
        cin.clear();
        cin.ignore();
    }

    return 0;
}