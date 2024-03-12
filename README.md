# Hospital-Management-Through-preority-queue

			
							
				



DSA Final Project : Hospital Management With 
                           Priority QUEUE
Introduction
 
Our code represents a simple yet functional hospital management system. This system is designed to manage patient queues in different departments within a hospital, including Cardiology Ward, Mental Ward, and General Medicine Ward. The program allows users to input patient details, add them to specific departments, and subsequently retrieve patients for treatment. Treated patients are then displayed in a separate queue.
 
The implementation employs object-oriented programming principles, with classes such as `Patient`, `Node`, and `Queue`. Each patient is characterized by essential attributes, and the queue structure is utilized to manage patient flow efficiently. The program features a user-friendly menu system, enabling users to perform operations such as adding patients, treating patients, and displaying both the current patient queue and the list of treated patients.
 
Key functionalities include prioritizing critical patients, error handling for user inputs, and modularization of code to enhance readability and maintainability. The system is structured to accommodate multiple departments, each with its own patient queue. Overall, this hospital management system serves as a foundation for handling patient data and treatment processes within distinct medical departments.
 






Objective
 
The objective is to implement a basic hospital management system that facilitates the organization and treatment of patients within different medical departments. The program aims to achieve the following key objectives:
 
1. Patient Management:
   Allow users to input essential details of a patient, including their first name, last name, social security number, contact details, reason for treatment, blood group, sex, and critical condition status.
 
2. Departmental Queues:
   Maintain separate queues for different medical departments, such as the Cardiology Ward, Mental Ward, and General Medicine Ward.
 
3. Queue Operations:
   Enable users to add patients to specific departments, considering critical condition status for priority.
   Facilitate the retrieval of patients from the queue for treatment, considering the critical condition status and maintaining a separate queue for treated patients.
 
4. User Interaction:
   Provide a user-friendly menu system for users to perform operations like adding patients, treating patients, and displaying the current patient queue and treated patients.
5. Modularization and Object-Oriented Design:
   - Organize the code into modular functions and classes, following object-oriented programming principles, to enhance code readability, maintainability, and reusability.
6. Departmental Selection:
   - Allow users to select different medical departments through a main menu, providing a versatile system that can handle patients in various healthcare settings.
7. Memory Management:
   Manage memory efficiently, avoiding memory leaks and unnecessary dynamic memory allocation, ensuring the robustness of the program.
 
Overall, the objective is to create a functional and extensible hospital management system that provides a foundation for handling patient data, treatment prioritization, and departmental organization within a healthcare environment.


Significance
 
1. Patient Organization:
   - The code allows for the systematic organization of patients into different medical departments. This is crucial for healthcare facilities that have specialized wards for various medical conditions.
 
2. Priority-Based Treatment:
   - Significantly, the code prioritizes the treatment of critical patients by placing them at the front of the queue. This ensures that patients with urgent medical needs receive prompt attention and care.
 
3. Queue Management:
   - The implementation of a queue data structure for each department streamlines the flow of patients. Queues are a fundamental concept in managing patient waiting times and maintaining order in the treatment process.
 
4. User-Friendly Interface:
   - The inclusion of a menu-driven interface enhances the user experience by providing a clear and intuitive way for users to interact with the system. This is particularly important for non-technical staff in a healthcare setting.
5. Memory Management:
   - Proper memory management practices, such as avoiding memory leaks and unnecessary dynamic memory allocation, contribute to the reliability and stability of the code. This is crucial in long-running applications like those used in healthcare settings.
6 .Modularization and Object-Oriented Design:
   - The use of modular functions and object-oriented design principles enhances the code's readability, maintainability, and scalability. This is significant for long-term software development, where updates and expansions may be required.

                         
 Requirements For the Project:

Patient Registration:
       Ø Information Capture:
The system captures vital patient information to ensure comprehensive records.
This includes:
· Personal Details: First name, last name, ID, contact details, blood group, and gender.
· Visit Details: Reason for the visit, crucial for medical staff to assess patient needs.
· Emergency Status: A critical indicator allowing immediate attention for urgent cases.
Ø User Interface Design:
The user interacts with the system through a console-based interface, where they input their details sequentially.
Features of the Console-Based Interface:
1. Sequential Information Input:
· Users are prompt to input patient details one by one in a sequential manner.
· Information such as first name, last name, ID, contact details, reason for visit, blood group, gender, and emergency status are enter through successive prompts.
2. Menu-Driven Interaction:
· The interface operates using a menu-driven approach where users select options by inputting corresponding numbers.
· Menus provide choices for actions like adding patients, treating patients, listing queues, displaying treated patients, and exiting the program.
3. Output Display:
· The interface displays information such as patient details, queue status, and treated patients in a structured format.
· Patient details shown in a structured manner including first name, last name, ID, contact details, reason for visit, blood group, gender, etc.
Queue Management:
Ø Queue Data Structure:
Implementation:
1. Linked List as Queue:
· The code implements a Queue using a linked list data structure.
· Nodes in this structure contain information about patients and maintain references to the next node in the queue.
2. Enqueue Operation:
· The system adds patients to the queue based on their emergency status, placing critical patients at the front and non-critical patients at the rear.
· This organization ensures that critical cases are address promptly, maintaining a priority-based queue.
3. Dequeue Operation:
· Patients are removed from the queue based on the dequeue operation.
· Critical patients treated with higher priority, ensuring immediate attention to urgent cases.
Ø Add/Remove Functionality:
1. Enqueue Function:
Priority-Based Addition:
· The system incorporates logic to add patients based on their criticality.
· Critical patients inserted at the front of the queue to ensure they receive priority treatment.
· Non-critical patients added to the rear of the queue, maintaining their sequence.
2. Dequeue Function:
Priority-Based Removal:
· Patients are dequeued based on their arrival and emergency status.
· Critical patients are dequeued first, allowing immediate treatment, while non-critical patients served subsequently.
Priority Handling
Ø Priority Levels:
Categorization of Patients:
Patients categorized into two groups based on their declared emergency status.
· Critical Patients: Those requiring immediate attention or having urgent medical needs.
· Non-Critical Patients: Those with less severe conditions or without an immediate need for urgent care.
Ø Benefits and System Logic:
1. Priority Treatment for Critical Cases:
· Critical patients handled with higher priority, ensuring they receive immediate attention from medical staff.
· This categorization streamlines the treatment process, addressing urgent cases promptly.
2. Efficient Resource Utilization:
· By automatically identifying and prioritizing critical cases, the system optimizes resource allocation, ensuring timely care for patients in urgent need.
Check-in Kiosks
Ø Self-Check-in Interface:
Console-based Interface:
· Patients interact with the system independently, providing their personal and medical information.
· The console interface prompts users for required details, allowing a self-check-in process.
Ø Information Input:
· Patients input various personal and medical details required for registration, enabling the hospital system to create accurate patient records.





Major Functionalities Of Code


Enqueue Function :
1. Creates a new node:
 
The function first allocates memory for a new Node object and initializes it with the provided patient data.
 Node* newNode = new Node(patient);
2. Checks if the queue is empty:
 
If the queue is empty (both the front and back pointers are null), the new node becomes the front and back of the queue.

    bool isEmpty() {
        return (front == NULL);
    }

3. Critical patients:
 
If the new patient is marked as critical (patient.isCritical), the function goes through the existing queue:
It starts with a queue and follows the previous node using prev.
As long as the current node exists and is also critical, it moves both pointers (previous and current) to the next element.
If the patient is the most critical (no critical patients ahead of it), the new node is inserted at the front of the queue.
Otherwise, the new node is inserted between the previous and current nodes, preserving the order of critical patients.
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
            }



4. Add’s non-critical patients:
 
If the patient is not critical, the new node is simply added to the end of the queue:
The next back pointer field is set to the new node, making it the last element.
The back pointer itself is then updated to point to the newly added node.
Overall, this queuing feature effectively adds a patient to the queue, prioritizing critical patients by placing them at the front of the queue while maintaining a first-come, first-served order for non-critical patients.
 
 



Dequeue Function : 
1.Checks for an empty queue:
It first checks if the queue is empty by checking if the front pointer is empty.
If it is empty, it will print the message that there are no patients and use the system ("pause") to potentially pause program execution (depending on the platform).
It then returns a dummy Patient object with all fields set to "Empty" and isCritical set to False.
 if (isEmpty()) {
        	cout<<" No , patient to take to treatement ............";
        	system("pause");
            return Patient(" Empty ", " Empty ", " Empty ", " Empty ", " Empty ", " Empty ", " Empty ", " Flase "); 
        }

 2. Removes and returns the front patient:
 
If the queue is not empty, it creates a temporary temp pointer that points to the current front node.
It then copies the data from the front node's data field into the Patient object.
The front pointer is then moved to point to the next node in the queue.
If the progression causes the front pointer to be empty, the back pointer is also set to null, indicating that the queue is now empty.
Finally, the temporary temporary node is removed and the copied Patient object is returned.
Overall, this dequeuing function effectively removes and returns the patient to the front of the queue and handles both empty and non-empty cases.
 
 
Variable declaration:   Patient inputPatient()
 
string firstName, lastName, id, contactDetails, reason, bloodGroup, gender;
bool isCritical = false;
Declare variables to store information about a patient. These include the patient's first name, last name, social security number (id), contact details, reason for visit (reason), blood group, gender, and a boolean flag isCritical to indicate whether the patient is in an emergency condition.
User input:
 
Use cout to prompt the user for new patient data.
Use cin to collect patient information, including first name, last name, ID, contact information, reason, blood type, and gender.
Entry for emergency conditions:
 
Ask the user if the patient is in an emergency by prompting for a "Y" or "N" response.
Use toupper to convert input to uppercase for case-insensitive comparison.
Set isCritical to true if the user types 'Y'.
Create and return a patient object:
 
Create a new patient object using the collected information and the detected critical condition status.
Return the newly created Patient object.
This function encapsulates the process of accepting user input to create a patient, including handling the emergency status.
 
3: Emergency Condition Input
char critical;
cout << "Is the patient in Emergency Condition? (Y/N): ";
cin >> critical;

if (toupper(critical) == 'Y') {
    isCritical = true;
}
Prompt the user to indicate whether the patient is in an emergency condition by inputting a character (Y/N).
Use toupper to convert the input to uppercase, making the check case-insensitive.
If the entered response indicates an emergency condition (if 'Y' is entered), set the isCritical flag to true.





displayTreatedPatients(): 
1: Check if the Queue is Empty:
if (isEmpty()) {
    cout << "\nNo treated patients to display" << endl;
    system("pause");
    return;
}
●If the queue is not empty, a pointer current is initialized to the front of the queue.
●A loop is used to traverse the queue. Inside the loop, patient information is displayed, including first name, last name, social security number, contact details, reason, blood group, and gender.
●After displaying information for each patient, the loop moves to the next node in the queue by updating the current pointer.




Main  Menu  loop:
 
Initializes a selection of variables a p to store user input and patient data.
It enters a loop that continues until the user chooses to exit (option 5).
1 Display the department menu:
 
Inside the loop, it starts by clearing the screen and displaying a menu with numbered options to add, treat, list queue, view treated patients, and exit.
2  Processing of user choices:
 
It reads the user's choice and uses a switch statement to handle each case:
Case 1 (Add patient):
Creates a new Patient object by calling inputPatient(), which probably prompts the user for patient information.
Queues the newly created patient object q using the queue function.
Displays a confirmation message that the patient has been added.
Case 2 (patient treatment):
Dequeues the patient from q using the dequeue function and stores it in p.
Checks if the patient information is valid (not empty).
If valid, it will add the patient to the treatment patient queue and display their details.
If it is not valid, the message that no patient is available for treatment will be displayed.
Case 3 (list queue):
Calls the displayQueue function of queue q to display the list of patients waiting for treatment.
Case 4 (show treated patients):
Calls the displayTreatedPatients function of the treated patient queue to display a list of patients who have received treatment.
Case 5 (output):
Removes the p pointer to properly handle allocated memory.
Default:
If the user enters an invalid option, an error message will be displayed.



 
 
 Work  Distribution  Among the members : 
Coding :
1.HAMAD MOIZ CHODHRY:
●Enqueue 
●Dequeue
●Priority Handling
2.Muhammad Zohaib Zafar:
●Displaying Queue of Patients
●Displaying record of already treated patients
3.Muhammad Rafeh Babar:
●Department Menu
●Selection of Department
●mainMenu() function
●Whole code Representation

Documentation:
●Abdul Wahab
●Sohaib ur Rehman







Conclusion:

The completion of the DSA Final Project, a Hospital Management System utilizing Priority Queues, has provided valuable insights into various aspects of software development and data structure implementations. Here are the key conclusions drawn from the project:

1. Object-Oriented Design:
   - The project reinforced the importance of object-oriented design principles. The use of classes such as `Patient`, `Node`, and `Queue` contributed to a modular and organized structure, enhancing code readability and maintainability.

2. Queue Implementation:
   - The implementation of a priority queue using a linked list demonstrated the versatility of data structures in managing patient queues efficiently. The priority handling for critical patients showcased the strategic use of queues to optimize patient treatment processes.

3. User Interaction and Menu Systems:
   - The development of a console-based user interface and menu system highlighted the significance of providing a user-friendly experience. The sequential input of patient details and menu-driven interactions demonstrated how effective user interfaces can enhance system usability.

4. Error Handling:
   - The project incorporated error handling mechanisms, such as checking for an empty queue before dequeuing and displaying appropriate messages when needed. This practice is crucial for creating robust and user-friendly software.

5. Memory Management:
   - Proper memory management practices were emphasized throughout the project. Efficient allocation and deallocation of memory were crucial for preventing memory leaks and ensuring the stability of the program.

6. Departmental Organization:
   - The implementation allowed for the organization of patients into different medical departments. This feature is essential for real-world hospital scenarios where specialized treatment is provided in distinct wards.

7. Priority-Based Treatment:
   - The introduction of priority levels for patients, especially critical cases, demonstrated the system's ability to streamline treatment processes. Prioritizing critical patients ensures prompt attention and optimal resource utilization.

8. Documentation Skills:
   - The documentation of the project, including objectives, significance, major functionalities, and work distribution, reflects a comprehensive understanding of the project requirements and effective communication of the project's purpose and structure.

9. Collaborative Work:
   - The distribution of work among team members showcased the importance of collaboration in software development. Each team member's contribution to specific functionalities and documentation collectively resulted in a well-rounded project.

10. Software Engineering Practices:
    - The project reinforced the importance of adhering to software engineering practices, such as modularization, code organization, and adherence to coding standards. These practices contribute to the maintainability and scalability of the software.

11. Practical Application of Data Structures:
    - The practical application of data structures, specifically linked lists and queues, provided hands-on experience in solving real-world problems. Understanding how to choose and implement appropriate data structures is crucial for efficient algorithm design.

In conclusion, the DSA Final Project served as a practical and educational endeavor, integrating various concepts learned throughout the course. It provided a holistic view of software development, from problem-solving and algorithm design to implementation and documentation. The project's success lies not only in achieving its functional objectives but also in the collaborative effort and application of best practices in software development.
Whole Code:
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

Main Menu










Patients in Queue After Entering:


Taking First Patient to Treatment According to priority :









List of treated patients:




