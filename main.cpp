#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <stdlib.h>
#include <queue>

using namespace std;
//Einkaufslisten-Menü Aufruf
void shopping_list_menu() {
    cout << "(1)    Möchten Sie die Einkaufsliste erweitern? \n";
    cout << "(2)    Möchten Sie die Einkaufsliste löschen?\n";
    cout << "(3)    Möchten Sie die Einkaufsliste ausgegeben bekommen?\n";
    cout << "(Z)    zurück zum WG-Menü\n";
    cout << "(X)    um den Vorgang abzubrechen\n";

}
//Putz-Menü Aufruf
void cleaning_menu() {
    cout << "(1)    Möchten Sie wissen wer mit dem Putzen dran ist? \n";
    cout << "(2)    Möchten Sie den Putz-Status ändern?\n";
    cout << "(Z)    zurück zum WG-Menü\n";
    cout << "(X)    um den Vorgang abzubrechen\n";
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
string print_shoppingList(string textfile) {
    string list;
    string str;
    ifstream in(textfile);
    while(str.size() > 0) {
        list.append(str);
        list.append(", ");
    }
    return list;
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
    cout << "Aktuell muss " + bath.front() + "das Bad putzen. \n";
    cout << kitchen.front() + " ist für die Küche verantwortlich.\n";
}
//WG-Menü Aufruf
void print_WG() {
    cout << "Womit wollen Sie fortfahren?\n";
    cout << "(1)    Einkaufsliste\n";
    cout << "(2)    Putzen\n";
    cout << "(Z)    zurück zum Hauptmenü\n";
    cout << "(X)    um den Vorgang abzubrechen\n";

}
//Hauptmenü Aufruf
string print_menu() {
    cout << "Auf was möchten Sie zugreifen?\n";
    cout << "(1)    WG \n";
    cout << "(2)    Kalender\n";
    cout << "(X)    um den Vorgang abzubrechen\n";

    string option;
    cin >> option;
    return option;
}
//Kalendermenü Aufruf
void calendar_menu() {
    cout << "Was möchten Sie tun?\n";
    cout << "(1)    Ein Event hinzufügen\n";
    cout << "(2)    Ein Event löschen\n";
    cout << "(3)    Welche Events stehen an\n";
    cout << "(Z)    zurück zum Hauptmenü\n";
    cout << "(X)    Den Vorgang abbrechen\n";
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

int main() {

    queue<string> bath;
    bath.push("Alfred");
    bath.push("Karl");
    queue<string> kitchen;
    kitchen.push("Karl");
    kitchen.push("Alfred");
    vector<string> shoppingList = loadShoppingList("shopping_list.txt");
    vector<string> events;

    cout << "Willkommen im Taskmanager\n";

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
                    cout << "Was möchten Sie hinzufügen?\n";
                    string item;
                    cin >> item;
                    shoppingList.push_back(item);
                    save_shoppingList("./shopping_list.txt", shoppingList);
                } else if (shopping_list_option == "2") {
                    cout << "Sind Sie sicher, dass Sie die Liste löschen möchten?\n";
                    cout << "Zum bestätigen geben Sie bitte Ja ein\n";
                    string conformation;
                    cin >> conformation;
                    if(conformation == "Ja") {
                        deleteList("shopping_list.txt");
                    } else {
                        cout << "Der Vorgang wird abgebrochen.\n";
                        exit(0);
                    }
                } else if(shopping_list_option == "3") {
                    print_shoppingList("shopping_list.txt");
                }
                else if (shopping_list_option == "Z") {
                    print_WG();
                } else if (shopping_list_option == "X") {
                    cout << "Der Vorgang wurde abgebrochen";
                    exit(0);
                } else {
                    cout << "Die Eingabe war nicht korrekt!\n";
                    shopping_list_menu();
                }
            } else if (wg_option == "2") {
                cleaning_menu();
                string cleaning_option;
                cin >> cleaning_option;
                if (cleaning_option == "1") {
                    cleaning(bath, kitchen);
                } else if (cleaning_option == "2") {
                    cout << " Welche Aufgabe haben Sie erledigt?\n";
                    cout << "(1)    das Bad\n";
                    cout << "(2)    die Küche\n";
                    string tmp;
                    cin >> tmp;
                    if(tmp == "1") {
                        clean_bath(bath);
                    } else if(tmp == "2") {
                        clean_kitchen(kitchen);
                    } else cout << "Die Eingabe ist nicht korrekt!\n";
                } else if (cleaning_option == "Z") {
                    print_WG();
                } else if (cleaning_option == "X") {
                    cout << "Der Vorgang wurde abgebrochen";
                    exit(0);
                } else {
                    cout << "Die Eingabe war nicht korrekt!\n";
                    cleaning_menu();
                }
            } else if (wg_option == "X") {
                cout << "Der Vorgang wurde abgebrochen";
                exit(0);
            } else if (wg_option == "Z") {
                continue;
            } else {
                cout << "Die Eingabe war nicht korrekt!!\n";
            }
        }
        // KALENDER
        else if (option == "2") {
            calendar_menu();
            string calendar_option;
            cin >> calendar_option;
            if(calendar_option == "1") {
                cout << "Fügen Sie ein Event hinzu:\n";
                cout << "Tag Monat Jahr NameDesEvents\n";
                string day, month, year, event;
                cin >> day >> month >> year >> event;
                string ev = (day+"."+month+"."+ year+" "+event);
                events.push_back(ev);
                save_event("./events.txt", events);
            } else if(calendar_option == "2") {

            } else if(calendar_option == "3") {

            } else if(calendar_option == "Z") {
                continue;
            } else if(calendar_option == "X") {
                cout << "Der Vorgang wurde abgebrochen!\n";
                exit(0);
            }
        } else if(option == "3") {

        }
        //ABBRUCH
        else if (option == "X") {
            cout << "Der Vorgang wurde abgebrochen";
            exit(0);
        } else {
            cout << "Bitte überprüfen Sie, ob ihre Eingabe korrekt war!\n";
        }
        i++;
    }

    return 0;
}
