#include <iostream>
#include <conio.h>
#include <cstring>
#include <vector>

using namespace std;

#define FIRST_OPTION 1
#define SECOND_OPTION 2
#define THIRD_OPTION 3
#define FOURTH_OPTION 4
#define FIFTH_OPTION 5
#define LAST_OPTION 6

#define UP_ARROW_KEY 'w'
#define DOWN_ARROW_KEY 's'
#define ENTER_KEY 13

#define SEARCH_BY_NAME 1
#define SEARCH_BY_NUMBER 2
#define DELETE_PARTICULAR 1
#define DELETE_ALL 2

#define EXIT 5
#define FILE_NAME "contacts"
#define OPERATION_SUCCESFULL 1
#define OPERATION_FAILED 0

typedef struct{
	char name[21];
	char number[11];
	char email[31];
	char city[21];
}record;


class Phonebook{
    private:
        FILE *file;

    public:
        void addNewContact();
        record getNewContactRecord();
        void showPressAnyKeyToContinueDialogue();
        void showAllContacts();
        void displayRecords(vector<record>, int);
        void showNoContactsFound();
        void searchAndShowContacts();
        void showSearchContactsMenu();
        vector<record> getContactsbyName(char[]);
        vector<record> getContactsByNumber(char[]);
        void inputName(char[]);
        void inputNumber(char[]);
        void editContact();
        void deleteContacts();
        void showDeleteContactsMenu();
        void deleteParticularContact();
        void deleteAllContacts();

};

class Application{
    private:
        char line1[40],line2[40],line3[40],line4[40],line5[40],line6[40];
        char upper_boundry[30],lower_boundry[30],middle_boundry[30],hollow_boundry[30];
        char heading[30];
        const char arrow[6] = " <@==";
        Phonebook phonebook;

    public:
        Application(){
            initMainMenuBoundaries();
        }

        void run();

    private:
        void initMainMenuBoundaries();
        void clearConsole();
        void clearInputBuffer();
        void showHeader();
        void showMainMenuWith(int);
        void doTaskAssociatedWith(int);
        int getNewArrowPositionOnKeyPress(int, int);
        void setLines();
        void putArrowOn(int);
};

void Application :: run(){
    char pressedKey; // Use to Store Pressed Key
    int currentArrowPosition = FIRST_OPTION;
    //This Loop Will Keep Running Application Till User Wants To Exits
    while(true){
        clearConsole();
        clearInputBuffer();
        showHeader();
		showMainMenuWith(currentArrowPosition);
		pressedKey = getch();

		if(pressedKey == ENTER_KEY)
            doTaskAssociatedWith(currentArrowPosition);
        else if(pressedKey == UP_ARROW_KEY || pressedKey == DOWN_ARROW_KEY)
            currentArrowPosition = getNewArrowPositionOnKeyPress(pressedKey, currentArrowPosition);
	}
}

void Application :: clearConsole(){
    system("cls");
}

void Application :: clearInputBuffer(){
    cin.clear();
    fflush(stdin);
}

void Application :: showMainMenuWith(int currentArrowPosition){

    setLines();
    putArrowOn(currentArrowPosition);

    cout << upper_boundry;
	cout << heading;
	cout << middle_boundry;
	cout << hollow_boundry;
	cout << line1 << line2 << line3 << line4 << line5 << line6;
	cout << hollow_boundry;
	cout << lower_boundry;
}

void Application :: doTaskAssociatedWith(int currentArrowPosition){

   switch(currentArrowPosition){
        case FIRST_OPTION:
            phonebook.addNewContact();
            break;
        case SECOND_OPTION:
            phonebook.searchAndShowContacts();
            break;
        case THIRD_OPTION:
            phonebook.editContact();
            break;
        case FOURTH_OPTION:
            phonebook.deleteContacts();
            break;
        case FIFTH_OPTION:
            phonebook.showAllContacts();
            break;
        case LAST_OPTION:
            cout << "\n\n\t Bye, Have a nice day!\n\n";
            exit(0);
        }

    phonebook.showPressAnyKeyToContinueDialogue();
}

int Application ::getNewArrowPositionOnKeyPress(int pressedKey, int currentArrowPosition){
    if(pressedKey == UP_ARROW_KEY){ // When User Presses Up Arrow key

			if(currentArrowPosition == FIRST_OPTION){
				return LAST_OPTION;
			} else {
				return currentArrowPosition - 1;
			}

    } else { // When User Presses Down Arrow Key

			if(currentArrowPosition == LAST_OPTION){
				return FIRST_OPTION;
			} else {
				return currentArrowPosition + 1;
			}
    }
}

void Application :: setLines(){
    sprintf(line1,"\n\t%c   %c Add new contact     %c",186,35,186);
	sprintf(line2,"\n\t%c   %c Search Contact      %c",186,35,186);
	sprintf(line3,"\n\t%c   %c Edit contact        %c",186,35,186);
	sprintf(line4,"\n\t%c   %c Delete contact      %c",186,35,186);
	sprintf(line5,"\n\t%c   %c Show all contacts   %c",186,35,186);
	sprintf(line6,"\n\t%c   %c Exit                %c",186,35,186);
}

void Application :: initMainMenuBoundaries(){
    sprintf(heading,"\n\t%c         MainMenu        %c",186,186);
    sprintf(hollow_boundry,"\n\t%c                         %c",186,186);
	sprintf(upper_boundry,"\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,
         205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    sprintf(middle_boundry,"\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,
         205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    sprintf(lower_boundry,"\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,
         205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void Application :: putArrowOn(int currentArrowPosition){
    switch(currentArrowPosition){
        case FIRST_OPTION:
            strcat(line1,arrow);
            break;
        case SECOND_OPTION:
            strcat(line2,arrow);
            break;
        case THIRD_OPTION:
            strcat(line3,arrow);
            break;
        case FOURTH_OPTION:
            strcat(line4,arrow);
            break;
        case FIFTH_OPTION:
            strcat(line5,arrow);
            break;
        case LAST_OPTION:
            strcat(line6,arrow);
            break;
    }
}

void Application :: showHeader(){
    cout << "\t [ Contact Management System ] " << endl << endl;
    cout << "\t( Welcome to contact management system..." << endl;
    cout << "\t  press S to move down and press W to move up" << endl;
    cout << "\t  Press Enter to select the option! )" << endl;
}

void Phonebook :: addNewContact(){
    file = fopen(FILE_NAME,"ab");
    if(file == NULL){
        cout << "\n\n\t Sorry ! Unable to add contact !";
        return;
    }

    record newRecord = getNewContactRecord();
    //Function to Write record structure content in FILE
    fwrite(&newRecord,sizeof(record),1,file);
    fclose(file);

    cout << "\n\n\t Contact Added Successfully !";
    return;
}

record Phonebook :: getNewContactRecord(){
    record newRecord;

    cout << endl;
    cout << "\n\t (max 20 chars) Enter the name : ";
    cin >> newRecord.name;
    cout << "\t (max 10 chars) Enter the number : ";
    cin >> newRecord.number;
    cout << "\t (max 30 chars) Enter the email : ";
    cin >> newRecord.email;
    cout << "\t (max 30 chars) Enter the city : ";
    cin >> newRecord.city;

    return newRecord;
}

void Phonebook :: showPressAnyKeyToContinueDialogue(){
    cout << "\n\n\t (Press Any Key To Continue)";
    getch();
}

void Phonebook :: showAllContacts(){
    vector<record> records;
    record newRecord;
    file = fopen(FILE_NAME,"rb");
    if(file == NULL){
        showNoContactsFound();
    } else {
        while(fread(&newRecord,sizeof(record),1,file) != 0){ // This line will read each contact in contacts file line by line
            records.push_back(newRecord);
        }
        fclose(file);
        displayRecords(records, records.size());
    }
}

void Phonebook :: displayRecords(vector<record> records, int recordsSize){
    if(recordsSize == 0){
        showNoContactsFound();
    } else {
        char contacts_display_format[] = "\t| %-20s | %-10s | %-30s | %-20s |\n";
        char contacts_display_outer_boundry[] = "\t=============================================================================================";
        char contacts_display_middle_boundry[] = "\t|====================================================================|=======================";
        char contacts_display_titles_boundry[] = "\t|         Name         |   Number   |             Email              |         City         |";

        cout << "\n\n";

        cout << contacts_display_outer_boundry << endl;
        cout << contacts_display_titles_boundry << endl;
        cout << contacts_display_middle_boundry << endl;

    for(int i = 0; i < recordsSize; i++){
        printf(contacts_display_format,records[i].name,records[i].number,records[i].email,records[i].city);
    }

    cout << contacts_display_outer_boundry << endl;
    }
}

void Phonebook ::searchAndShowContacts(){

    showSearchContactsMenu();
    int choice;
    cin >> choice;

    switch(choice){
        case SEARCH_BY_NAME:
            {
                char name[31];
                inputName(name);
                vector<record> searchedRecords = getContactsbyName(name);
                displayRecords(searchedRecords,searchedRecords.size());
                break;
            }
        case SEARCH_BY_NUMBER:
            {
                char number[31];
                inputNumber(number);
                vector<record> searchedRecords = getContactsByNumber(number);
                displayRecords(searchedRecords,searchedRecords.size());
                break;
            }
        case 3 :
            break;
        default :
            cout << "\n\n\t Invalid Choice";
            break;
    }

}

void Phonebook ::showSearchContactsMenu(){
    cout << "\n";
    cout << "\n\t 1. Search By Name";
    cout << "\n\t 2. Search By Number";
    cout << "\n\t 3. Back";
    cout << "\n\t Enter your choice : ";
}

void Phonebook :: showNoContactsFound(){
    cout << "\n\n\t No Contacts Found !";
}

vector<record> Phonebook :: getContactsbyName(char name[]){
    vector<record> records;

    file = fopen(FILE_NAME,"rb");

    if(file == NULL){
        return records;
    }

    record tempRecord;

    while(fread(&tempRecord,sizeof(record),1,file) != 0){
        if(strcmp(tempRecord.name,name) == 0)
            records.push_back(tempRecord);
    }

    fclose(file);

    return records;
}

vector<record> Phonebook ::getContactsByNumber(char number[]){
    vector<record> records;

    file = fopen(FILE_NAME,"rb");

    if(file == NULL){
        return records;
    }

    record tempRecord;

    while(fread(&tempRecord,sizeof(record),1,file) != 0){
        if(strcmp(tempRecord.number,number) == 0)
            records.push_back(tempRecord);
    }

    fclose(file);

    return records;
}

void Phonebook :: inputName(char name[]){
    cout << "\n\n\t Enter the name : ";
    cin >> name;
}

void Phonebook :: inputNumber(char name[]){
    cout << "\n\n\t Enter the number : ";
    cin >> name;
}

void Phonebook :: deleteContacts(){
    showDeleteContactsMenu();
    int choice;
    cin >> choice;
    switch(choice){
        case DELETE_PARTICULAR:
            deleteParticularContact();
            break;
        case DELETE_ALL:
            deleteAllContacts();
            break;
        case 3:
            break;
        default:
            cout << "\n\n\t Invalid Choice !";
    }
}

void Phonebook :: showDeleteContactsMenu(){
    cout << "\n\n\t 1. Delete Particular Contacts";
    cout << "\n\t 2. Delete All Contacts";
    cout << "\n\t 3. Back";
    cout << "\n\t Enter your choice : ";
}

void Phonebook :: deleteParticularContact(){
    char name[31];
    inputName(name);
    vector<record> records = getContactsbyName(name);
    displayRecords(records, records.size());

    if(records.size() == 0)
        return;

    char number[11];
    inputNumber(number);

    file = fopen(FILE_NAME, "rb");

    if(file == NULL){
        showNoContactsFound();
        return;
    }

    FILE *tempRecordsFILE = fopen("temp","wb+");
    record tempRecord;

    while(fread(&tempRecord,sizeof(record),1,file) != 0){
        fwrite(&tempRecord,sizeof(record),1,tempRecordsFILE);
    }
    rewind(tempRecordsFILE);

    fclose(file);

    file = fopen(FILE_NAME,"wb");

    bool hasContactDeleted = false;

    while(fread(&tempRecord,sizeof(record),1,tempRecordsFILE) != 0){
        if(strcmp(name,tempRecord.name) == 0 && strcmp(number,tempRecord.number) == 0){
            hasContactDeleted = true;
            continue;
        }
        fwrite(&tempRecord,sizeof(record),1,file);
    }

    fclose(file);
    fclose(tempRecordsFILE);

    if(hasContactDeleted){
        cout << "\n\n\t Contact Deleted Successfully !";
    } else {
        showNoContactsFound();
    }

}

void Phonebook :: deleteAllContacts(){
    if(remove(FILE_NAME) == 0)
        cout << "\n\n\t All Contacts Deleted !";
    else
        cout << "\n\n\t No contacts to delete !";
}

void Phonebook :: editContact(){

    char name[31];
    inputName(name);
    vector<record> searchedContacts = getContactsbyName(name);
    displayRecords(searchedContacts,searchedContacts.size());

    if(searchedContacts.size() == 0)
        return;

    char number[11];
    inputNumber(number);
    bool hasContactEdited = false;
    record tempRecord;

    file = fopen(FILE_NAME, "rb+");

    if(file == NULL){
        showNoContactsFound();
        return;
    }

    while(fread(&tempRecord,sizeof(record),1,file) != 0){
        if(strcmp(tempRecord.name,name) == 0 && strcmp(tempRecord.number,number) == 0){
            tempRecord = getNewContactRecord();
            fseek(file,-sizeof(record),SEEK_CUR);
            fwrite(&tempRecord,sizeof(record),1,file);
            hasContactEdited = true;
            break;
        }
    }

    fclose(file);

    if(hasContactEdited){
        cout << "\n\n\t Contact Edited Successfully !";
    } else {
        showNoContactsFound();
    }
}

int main() {
    Application app;
    app.run();
    return 0;
}
