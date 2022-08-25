#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <stdlib.h>
#include <queue>

using namespace std;

//Deine Mum

//Einkaufslisten-Menü Aufruf
void shopping_list_menu() {
    cout << "(1)    Do you want to add something to the shopping list? \n";
    cout << "(2)    Do you want to delete the shopping list?\n";
    cout << "(3)    Do you want to print the shopping list?\n";
    cout << "(Z)    back to WG-menu\n";
    cout << "(X)    to exit the program\n";
}
//Putz-Menü Aufruf
void cleaning_menu() {
    cout << "(1)    Do you want to know whose turn it is to clean? \n";
    cout << "(2)    Do you want to change the cleaning-status?\n";
    cout << "(Z)    back to WG-menu\n";
    cout << "(X)    to exit the program\n";
}
//Einkaufsliste löschen
void deleteList(string textfile) {
   ofstream out(textfile);
}
//Einkaufsliste laden
vector<string> loadShoppingList(string textfile) {
    vector<string> new_vector;
    string str;
    ifstream in(textfile);
    while(getline(in, str)) {
        if(str.size() >  0) {
            new_vector.push_back(str);
        }
    }
    return new_vector;
}
//Events laden
vector<string> loadEvents(string textfile) {
    vector<string> new_vector;
    string str;
    ifstream in(textfile);
    while(getline(in, str)) {
        if(str.size() > 0) {
            new_vector.push_back(str);
        }
    }
}
//Einkaufsliste speichern
void save_shoppingList(string name, vector<string> list) {
    ofstream output_file(name);
    ostream_iterator<string> output_iterator(output_file, "\n");
    copy(list.begin(), list.end(), output_iterator);
}
//Einkaufsliste ausgeben
void print_shoppingList(string textfile) {
    string list;
    ifstream input(textfile);
    while(input >> list) {
        cout << list << ", ";
    }
}
//Küche putzen Wechsel
void clean_kitchen(queue<string> kitchen) {
    kitchen.pop();
    if(kitchen.front() == "Alfred") {
        kitchen.push("Karl");
    } else kitchen.push("Alfred");
}
//Bad putzen Wechsel
void clean_bath(queue<string> bath) {
    bath.pop();
    if(bath.front() == "Alfred") {
        bath.push("Karl");
    } else bath.push("Alfred");
}
//Ausgabe putzen
string cleaning(queue<string> bath, queue<string> kitchen) {
    cout << "It's " + bath.front() + "'s turn to clean the bath. \n";
    cout << kitchen.front() + " needs to clean the kitchen.\n";
}
//WG-Menü Aufruf
void print_WG() {
    cout << "What do you want to do?\n";
    cout << "(1)    shopping_list\n";
    cout << "(2)    cleaning\n";
    cout << "(Z)    back to main menu\n";
    cout << "(X)    to exit the program\n";
}
//Hauptmenü Aufruf
string print_menu() {
    cout << "What do you want to do?\n";
    cout << "(1)    WG \n";
    cout << "(2)    calendar\n";
    cout << "(X)    to exit the program\n";

    string option;
    cin >> option;
    return option;
}
//Kalendermenü Aufruf
void calendar_menu() {
    cout << "What do you want to do?\n";
    cout << "(1)    add an event\n";
    //cout << "(2)    Ein Event l/224schen\n";
    cout << "(3)    which events are comming up\n";
    cout << "(Z)    back to main menu\n";
    cout << "(X)    to exit the program\n";
}
//Event zum Kalender hinzufügen
void addEvent(int day, int month, int year, string event, vector<string> events) {
    events.push_back(to_string(day) +"."+ to_string(month)+ "." + to_string(year)+" " + event);
}
//Event speichern
void save_event(string name, vector<string> lang) {
    ofstream output_file(name);
    ostream_iterator<string> output_iterator(output_file, "\n");
    copy(lang.begin(), lang.end(), output_iterator);
}
void UniMenu() {
    cout << "What do you want to do?\n";
    cout << "(1)    add an exam\n";
    cout << "(Z)    back to main menu\n";
    cout << "(X)    to exit the program\n";
}
int main() {

    queue<string> bath;
    bath.push("Alfred");
    bath.push("Karl");
    queue<string> kitchen;
    kitchen.push("Karl");
    kitchen.push("Alfred");
    vector<string> shoppingList = loadShoppingList("shopping_list.txt");
    vector<string> events;

    cout << "welcome to the taskmanager\n";

    int i = 0;
    while(i  < 100) {
        //WG
        string option = print_menu();
        if (option == "1") {
            print_WG();
            string wg_option;
            cin >> wg_option;
            if (wg_option == "1") {
                shopping_list_menu();
                string shopping_list_option;
                cin >> shopping_list_option;
                if (shopping_list_option == "1") {
                    cout << "Which item do you want to add?\n";
                    string item;
                    cin >> item;
                    shoppingList.push_back(item);
                    save_shoppingList("./shopping_list.txt", shoppingList);
                } else if (shopping_list_option == "2") {
                    cout << "Are you certain, you want to delete the shopping list?\n";
                    cout << "To confirm type: Yes\n";
                    string conformation;
                    cin >> conformation;
                    if(conformation == "Yes") {
                        deleteList("shopping_list.txt");
                    } else {
                        cout << "exiting program...\n";
                        exit(0);
                    }
                } else if(shopping_list_option == "3") {
                    print_shoppingList("shopping_list.txt");
                    exit(0);
                }
                else if (shopping_list_option == "Z") {
                    print_WG();
                } else if (shopping_list_option == "X") {
                    cout << "exit programm...";
                    exit(0);
                } else {
                    cout << "incorrect input\n";
                    shopping_list_menu();
                }
            } else if (wg_option == "2") {
                cleaning_menu();
                string cleaning_option;
                cin >> cleaning_option;
                if (cleaning_option == "1") {
                    cleaning(bath, kitchen);
                } else if (cleaning_option == "2") {
                    cout << "Which task have you done?\n";
                    cout << "(1)    bath\n";
                    cout << "(2)    kitchen\n";
                    string tmp;
                    cin >> tmp;
                    if(tmp == "1") {
                        clean_bath(bath);
                    } else if(tmp == "2") {
                        clean_kitchen(kitchen);
                    } else cout << "incorrect input!\n";
                } else if (cleaning_option == "Z") {
                    print_WG();
                } else if (cleaning_option == "X") {
                    cout << "exiting program...";
                    exit(0);
                } else {
                    cout << "incorrect input!\n";
                    cleaning_menu();
                }
            } else if (wg_option == "X") {
                cout << "exiting program...";
                exit(0);
            } else if (wg_option == "Z") {
                continue;
            } else {
                cout << "incorrect input\n";
            }
        }
        // KALENDER
        else if (option == "2") {
            calendar_menu();
            string calendar_option;
            cin >> calendar_option;
            if(calendar_option == "1") {
                cout << "Add an event:\n";
                cout << "day month year event\n";
                string day, month, year, event, ev;
                cin >> day >> month >> year >> event;
                ev.append(day);
                ev.append(".");
                ev.append(month);
                ev.append(".");
                ev.append(year);
                ev.append(" ");
                ev.append(event);
                events.push_back(ev);
                save_event("./events.txt", events);
            } else if(calendar_option == "2") {

            } else if(calendar_option == "3") {

            } else if(calendar_option == "Z") {
                continue;
            } else if(calendar_option == "X") {
                cout << "exiting program...\n";
                exit(0);
            }
        } else if(option == "3") {
            UniMenu();
        }
        //ABBRUCH
        else if (option == "X") {
            cout << "exiting program...";
            exit(0);
        } else {
            cout << "input incorrect\n";
        }
        i++;
    }
    return 0;
}