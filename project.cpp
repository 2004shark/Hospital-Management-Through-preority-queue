#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
using namespace std;

class Patient {
public:
    string FirstName;
    string LastName;
    string ID;
    string contactDetails;
    string reason;
    string bloodGroup;
    string gender;
    bool isCritical;

    Patient(string FirstName, string LastName, string ID, string contactDetails, string reason, string bloodGroup, string gender, bool isCritical = false) {
        this->FirstName = FirstName;
        this->LastName = LastName;
        this->ID = ID;
        this->contactDetails = contactDetails;
        this->reason = reason;
        this->bloodGroup = bloodGroup;
        this->gender = gender;
        this->isCritical = isCritical;
    }
};

class Node {
public:
    Patient data;
    Node* next;
    Node(Patient patient) : data(patient), next(NULL) {}
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        this->front = NULL;
        this->rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void enqueue(Patient patient) {
        Node* newNode = new Node(patient);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            if (patient.isCritical) {
                Node* current = front;
                Node* prev = NULL;

                while (current != NULL && current->data.isCritical) {
                    prev = current;
                    current = current->next;
                }

                if (prev == NULL) {
                    newNode->next = front;
                    front = newNode;
                } else {
                    newNode->next = current;
                    prev->next = newNode;
                }
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }
    }

    Patient dequeue() {
        if (isEmpty()) {
            cout << "No patient to take to treatment." << endl;
            return Patient("Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", false);
        }

        Node* temp = front;
        Patient patient = temp->data;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;

        return patient;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "\nQueue is empty" << endl;
            system("pause");
            return;
        }

        Node* current = front;
        cout << "\nPatients in the queue:" << endl;
        while (current != NULL) {
            cout << "----------------------------------------" << endl;
            cout << "First name: " << current->data.FirstName << endl;
            cout << "Last name: " << current->data.LastName << endl;
            cout << "Social security number: " << current->data.ID << endl;
            cout << "Contact details: " << current->data.contactDetails << endl;
            cout << "Reason: " << current->data.reason << endl;
            cout << "Blood group: " << current->data.bloodGroup << endl;
            cout << "Gender: " << current->data.gender << endl;
            cout << "----------------------------------------" << endl;
            current = current->next;
        }
        system("pause");
    }

    void displayTreatedPatients() {
        if (isEmpty()) {
            cout << "\nNo treated patients to display" << endl;
            system("pause");
            return;
        }

        Node* current = front;
        cout << "\nTreated patients:" << endl;
        while (current != NULL) {
            cout << "----------------------------------------" << endl;
            cout << "First name: " << current->data.FirstName << endl;
            cout << "Last name: " << current->data.LastName << endl;
            cout << "Social security number: " << current->data.ID << endl;
            cout << "Contact details: " << current->data.contactDetails << endl;
            cout << "Reason: " << current->data.reason << endl;
            cout << "Blood group: " << current->data.bloodGroup << endl;
            cout << "Gender: " << current->data.gender << endl;
            cout << "----------------------------------------" << endl;
            current = current->next;
        }
        system("pause");
    }
};

Patient inputPatient() {
    string firstName, lastName, id, contactDetails, reason, bloodGroup, gender;
    bool isCritical = false;
    cout << "\nPlease enter data for a new patient:\n";
    cout << "First name: ";
    cin >> firstName;
    cout << "Last name: ";
    cin >> lastName;
    cout << "Social security number: ";
    cin >> id;
    cout << "Contact details: ";
    cin >> contactDetails;
    cout << "Reason: ";
    cin >> reason;
    cout << "Blood group: ";
    cin >> bloodGroup;
    cout << "Gender (Male/Female): ";
    cin >> gender;

    char critical;
    cout << "Is the patient in Emergency Condition? (Y/N): ";
    cin >> critical;

    if (toupper(critical) == 'Y') {
        isCritical = true;
    }

    return Patient(firstName, lastName, id, contactDetails, reason, bloodGroup, gender, isCritical);
}

void departmentMenu(Queue* q, Queue* treatedPatients, const string& departmentName) {
    int choice = 0;
    Patient* p = NULL;

    while (choice != 5) {
        system("cls");
        cout << "\n----------------------------------------" << endl;
        cout << "Department: " << departmentName << endl;
        cout << "Please enter your choice:\n";
        cout << "1: Add a patient\n";
        cout << "2: Take out a patient for Treatment\n";
        cout << "3: List the queue\n";
        cout << "4: Display Treated Patients\n";
        cout << "5: Exit\n";
        cout << "----------------------------------------" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                p = new Patient(inputPatient());
                q->enqueue(*p);
                cout << "\nPatient added\n";
                break;
            case 2:
                *p = q->dequeue();
                if (p->FirstName != "Empty") {
                    treatedPatients->enqueue(*p);  // Enqueue into treatedPatients queue
                    cout << "\nPatient for treatment:\nFirst name: " << p->FirstName << "\nLast name: " << p->LastName << "\nSocial security number: " << p->ID << "\nContact details: " << p->contactDetails << "\nReason: " << p->reason << "\nBlood group: " << p->bloodGroup << "\nGender: " << p->gender << endl;
                    system("pause");
                } else {
                    cout << "\nThere is no patient for treatment.\n";
                }
                break;
            case 3:
                q->displayQueue();
                break;
            case 4:
                treatedPatients->displayTreatedPatients();  // Display treated patients from treatedPatients queue
                break;
            case 5:
                delete p;
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    }
}

void printMainMenu() {
    cout << "\n----------------------------------------" << endl;
    cout << "Welcome to Software City Hospital\n";
    cout << "Please enter your choice:\n";
    cout << "1: Cardiology Ward\n";
    cout << "2: Mental Ward\n";
    cout << "3: General Medicine Ward\n";
    cout << "4: Exit\n";
    cout << "----------------------------------------" << endl;
}

int selectDepartmentMenu(Queue departments[], int numDepartments) {
    int departmentChoice = 0;
    cin >> departmentChoice;

    switch (departmentChoice) {
        case 1:
            departmentMenu(&departments[0], &departments[numDepartments], "Cardiology Ward");
            break;
        case 2:
            departmentMenu(&departments[1], &departments[numDepartments], "Mental Ward");
            break;
        case 3:
            departmentMenu(&departments[2], &departments[numDepartments], "General Medicine Ward");
            break;
        case 4:
            // Exit
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
    }

    return departmentChoice;
}

void mainMenu() {
    const int numDepartments = 3;
    Queue departments[numDepartments + 1];  // An additional queue for treated patients
    departments[numDepartments] = Queue(); // Initialize the treated patients queue

    int menuChoice = 0;

    while (menuChoice != 4) {
        system("cls");

        printMainMenu();

        menuChoice = selectDepartmentMenu(departments, numDepartments);
    }
}

void startButton() {
    cout << "Press Enter to start the program...";
    _getch(); // Wait for the user to press any key
}

void displayMainMenu() {
    cout << "\n---------------------------------------" << endl;
    cout << "               1: Start\n";
    cout << "               2: Exit\n";
    cout << "---------------------------------------" << endl;
}

int main() {
    int menuChoice = 0;

    while (menuChoice != 2) {
        system("cls");
        displayMainMenu();
        cout << "Choose one option : ";
        cin >> menuChoice;

        switch (menuChoice) {
            case 1:
                startButton();
                mainMenu();
                break;
            case 2:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                system("pause");
        }
    }

    return 0;
}
