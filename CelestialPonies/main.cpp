#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include <limits>
#include "Sanctuary.h"
#include "Unicorn.h"
#include "Pegasus.h"
#include "Alicorn.h"

void ClearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

std::shared_ptr<Pony> CreatePony() {
    cout << "Choose type:\n";
    cout << "1) Unicorn\n";
    cout << "2) Pegasus\n";
    cout << "3) Alicorn\n";
    cout << "4) Basic Pony\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;
    if (cin.fail() || choice < 1 || choice > 4) {
        cout << "Invalid input. Cancelling creation.\n";
        ClearInput();
        return nullptr;
    }

    shared_ptr<Pony> pony;

    switch (choice) {
        case 1: {
            cout << "Creating a Unicorn...\n";
            pony = make_shared<Unicorn>();
            break;
        }
        case 2: {
            cout << "Creating a Pegasus...\n";
            pony = make_shared<Pegasus>();
            break;
        }
        case 3: {
            cout << "Creating an Alicorn...\n";
            pony = make_shared<Alicorn>();
            break;
        }
        case 4: {
		    cout << "Creating a Pony...\n";
            pony = make_shared<Pony>(); 
            break;
        }
    }
    cin >> *pony; // Use overloaded >> operator (console input)
    return pony;
}

int main() {
    Sanctuary* sanctuary = new Sanctuary;
    bool running = true;

    while (running) {
        //std::cout << "\n🦄 Welcome to the Sanctuary 🕊️\n";
        cout << "\n Welcome to the Sanctuary \n";
        cout << "1) Create\n";
        cout << "2) Display All\n";
        cout << "3) Display By Name\n";
        cout << "4) Display By Type\n";
        cout << "5) Load\n";
        cout << "6) Save\n";
        cout << "7) Quit\n";
        cout << "Choose an action: ";

        int action;
        cin >> action;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            ClearInput();
            continue;
        }

        switch (action) {
        case 1: {
            auto pony = CreatePony();
            if (pony) sanctuary->AddPony(pony);
            break;
        }
        case 2:
            sanctuary->DisplayAll();
            break;
        case 3: {
            cout << "Enter name: ";
            string name;
            cin.ignore(); // flush newline
            getline(cin, name);
            sanctuary->DisplayByName(name);
            break;
        }
        case 4: {
            cout << "Enter type (1: Unicorn, 2: Pegasus, 3: Alicorn, 4: Basic Pony): ";
            int type;
            cin >> type;
            if (cin.fail() || type < 1 || type > 4) {
                cout << "Invalid type.\n";
                ClearInput();
                break;
            }
            sanctuary->DisplayByType(static_cast<PonyType>(type));
            break;
        }
        case 5: {
            cout << "Enter filename to load: ";
            string file;
            cin >> file;
            sanctuary->Load(file);
            break;
        }
        case 6: {
            cout << "Enter filename to save: ";
            string file;
            cin >> file;
            sanctuary->Save(file);
            break;
        }
        case 7:
            running = false;
            break;
        default:
            cout << "Invalid option.\n";
        }
    }

    delete sanctuary;
    _CrtDumpMemoryLeaks();
    return 0;
}