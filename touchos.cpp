#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <time.h>
#include <stdio.h>
#include <dir.h>

void setDarkBlueColor() {
    textcolor(RED);
    textbackground(BLUE);
}

void resetColor() {
    textcolor(RED);
    textbackground(BLUE);
}

void displayMenu() {
    clrscr();
    setDarkBlueColor();
    cout << "===| TouchOS CE 4 |===\n";
    cout << "1 - Getting Started\n";
    cout << "2 - Text\n";
    cout << "3 - Clock\n";
    cout << "4 - Echo\n";
    cout << "5 - Changelog\n";
    cout << "6 - Exit\n";
    cout << "Enter an option: ";
    resetColor();
}

void openGettingStarted() {
    clrscr();
    ifstream inputFile("D:\\TOUCHOS\\GETTINGSTARTED.TXT");
    
    if (inputFile) {
        cout << "Opening Getting Started document...\n";
        char data[100];
        while (inputFile.getline(data, 100)) {
            cout << data << "\n";
        }
        inputFile.close();
    } else {
        cout << "Error: Unable to open Getting Started document\n";
    }
    getch();
}

void displayClock() {
    clrscr();
    time_t now = time(0);
    tm* ltm = localtime(&now);
    cout << "Date: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "\n";
    cout << "Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << "\n";
    getch();
}

void echoUserInput() {
    clrscr();
    char userInput[100];
    cin.ignore();
    cout << "Enter text: ";
    cin.getline(userInput, 100);
    cout << "ECHO-$ " << userInput << "\n";
    getch();
}

void displayChangelog() {
    clrscr();
    cout << "***| Changelog |***\n";
    cout << "- Added Getting Started\n";
    cout << "- Improved Text Manager\n";
    cout << "- Red text\n";
    cout << "- More stable build\n";
    getch();
}

void displayTextMenu() {
    clrscr();
    setDarkBlueColor();
    cout << "***| Text |***\n";
    cout << "1 - Open Document\n";
    cout << "2 - Edit Document\n";
    cout << "3 - List Documents\n";
    cout << "4 - Rename Document\n";
    cout << "5 - Back to Main Menu\n";
    cout << "Enter an option: ";
    resetColor();
}

void openDocument() {
    clrscr();
    char filename[100];
    cout << "Enter document name: ";
    cin >> filename;
    ifstream inputFile((string("D:\\TOUCHOS\\TEXT\\") + filename).c_str());

    if (inputFile) {
        cout << "Opening document...\n";
        char data[100];
        while (inputFile.getline(data, 100)) {
            cout << data << "\n";
        }
        inputFile.close();
    } else {
        cout << "Error: Unable to open document\n";
    }
    getch();
}

void editDocument() {
    clrscr();
    char filename[100];
    cout << "Enter document name: ";
    cin >> filename;
    ofstream outputFile((string("D:\\TOUCHOS\\TEXT\\") + filename).c_str(), ios::app);

    if (outputFile) {
        char userData[100];
        cin.ignore();
        cout << "Enter document contents: ";
        cin.getline(userData, 100);
        outputFile << userData << "\n";
        cout << "Saved to document\n";
        outputFile.close();
    } else {
        cout << "Error: Unable to edit document\n";
    }
    getch();
}

void listDocuments() {
    clrscr();
    cout << "Listing documents in D:\\TOUCHOS\\TEXT\\...\n";
    system("dir D:\\TOUCHOS\\TEXT\\ /b");
    getch();
}

void renameDocument() {
    clrscr();
    char oldName[100], newName[100];
    cout << "Enter current document name: ";
    cin >> oldName;
    cout << "Enter new document name: ";
    cin >> newName;
    if (rename((string("D:\\TOUCHOS\\TEXT\\") + oldName).c_str(), (string("D:\\TOUCHOS\\TEXT\\") + newName).c_str()) == 0) {
        cout << "Document renamed successfully\n";
    } else {
        cout << "Error: Unable to rename document\n";
    }
    getch();
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                openGettingStarted();
                break;
            case 2:
                int textChoice;
                do {
                    displayTextMenu();
                    cin >> textChoice;
                    switch (textChoice) {
                        case 1:
                            openDocument();
                            break;
                        case 2:
                            editDocument();
                            break;
                        case 3:
                            listDocuments();
                            break;
                        case 4:
                            renameDocument();
                            break;
                        case 5:
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            getch();
                    }
                } while (textChoice != 5);
                break;
            case 3:
                displayClock();
                break;
            case 4:
                echoUserInput();
                break;
            case 5:
                displayChangelog();
                break;
            case 6:
                cout << "Exiting TouchOS CE...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                getch();
        }
    } while (choice != 6);
    return 0;
}
