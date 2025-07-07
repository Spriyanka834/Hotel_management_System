#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_FLOORS 5
#define ROOMS_PER_FLOOR 20
#define MAX_ROOMS (NUM_FLOORS * ROOMS_PER_FLOOR)
#define STANDARD_PRICE 1000
#define DELUXE_PRICE 1500
#define SUITE_PRICE 2000

// Structure for customer details
struct Customer {
    char name[20];
    char address[50];
    char email_id[30];
    char nationality[25];
    int roomno;
    char roomtype[20];
    int billprice;
    char program[20];
};

typedef struct Customer Customer;

// Structure for the Player
struct Player {
    char name[20];
    int inhand_cash;
};

typedef struct Player Player;

// Function to initialize a new customer
Customer createCustomer() {
    Customer newCustomer;
    newCustomer.roomno = 0;
    newCustomer.billprice = 0;
    strcpy(newCustomer.program, "notchosen");
    return newCustomer;
}

// Function to initialize room availability
void initializeRoomAvailability(int* roomAvailability, int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        roomAvailability[i] = 0; // 0 represents available, 1 represents booked
    }
}

// Function to display room availability as a table
void displayRoomAvailability(const int* roomAvailability, int numRooms) {
    printf("\n--- Room Availability Table ---\n");
    printf("Floor | Room Availability\n");
    printf("------+----------------------\n");
    for (int floor = 1; floor <= NUM_FLOORS; floor++) {
        printf("  %d   |", floor);
        for (int room = 1; room <= ROOMS_PER_FLOOR; room++) {
            int index = (floor - 1) * ROOMS_PER_FLOOR + room - 1;
            printf(" %s |", roomAvailability[index] ? "B" : "A");
        }
        printf("\n");
    }
}

// Function to book a room for a customer with room type selection
void bookRoom(Customer* customer, int* roomAvailability, int numRooms) {
    if (customer->roomno == 0) {
        // Simulate the process of booking a room
        int floorNumber, roomNumber;
        printf("Enter the floor number to book (1-%d): ", NUM_FLOORS);
        scanf("%d", &floorNumber);

        if (floorNumber < 1 || floorNumber > NUM_FLOORS) {
            printf("Invalid floor number.\n");
            return;
        }

        printf("Enter the room number to book (1-%d): ", ROOMS_PER_FLOOR);
        scanf("%d", &roomNumber);

        if (roomNumber < 1 || roomNumber > ROOMS_PER_FLOOR) {
            printf("Invalid room number.\n");
            return;
        }

        int index = (floorNumber - 1) * ROOMS_PER_FLOOR + roomNumber - 1;

        if (roomAvailability[index] == 1) {
            printf("Room %d on floor %d is already booked. Choose another room.\n", roomNumber, floorNumber);
            return;
        }

        roomAvailability[index] = 1; // Mark the room as booked

        // Allow the customer to choose the room type
        printf("Select room type:\n");
        printf("1. Standard\n2. Deluxe\n3. Suite\n");
        int roomTypeChoice;
        scanf("%d", &roomTypeChoice);

        char roomType[20];
        int roomPrice = 0;

        switch (roomTypeChoice) {
            case 1:
                strcpy(roomType, "Standard");
                roomPrice = STANDARD_PRICE;
                break;
            case 2:
                strcpy(roomType, "Deluxe");
                roomPrice = DELUXE_PRICE;
                break;
            case 3:
                strcpy(roomType, "Suite");
                roomPrice = SUITE_PRICE;
                break;
            default:
                printf("Invalid room type choice.\n");
                return;
        }

        customer->roomno = floorNumber * 100 + roomNumber; // Unique room number combining floor and room
        strcpy(customer->roomtype, roomType);
        customer->billprice += roomPrice; // Adjust the price according to room type
        printf("Room %d on floor %d (%s) is booked. Enjoy your stay!\n", roomNumber, floorNumber, roomType);
    } else {
        printf("You have already booked a room.\n");
    }
}

// Function to choose a program for a customer
void chooseProgram(Customer* customer) {
    if (strcmp(customer->program, "notchosen") == 0) {
        int p;
        printf("Which program do you want to choose?\n");
        printf("1. Jungle Walk\n2. Jungle Jeep Drive\n3. Canoe Ride\n4. Cultural Show\n");
        scanf("%d", &p);
        switch (p) {
            case 1:
                printf("You choose Jungle Walk\n");
                strcpy(customer->program, "Jungle Walk");
                customer->billprice += 1000;
                break;
            case 2:
                printf("You choose Jungle Jeep Drive\n");
                strcpy(customer->program, "Jeep Drive");
                customer->billprice += 2000;
                break;
            case 3:
                printf("You choose Canoe Ride\n");
                customer->billprice += 800;
                strcpy(customer->program, "Canoe Ride");
                break;
            case 4:
                printf("You choose Cultural Show\n");
                customer->billprice += 1000;
                strcpy(customer->program, "Cultural Show");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } else {
        printf("You have already chosen a program.\n");
    }
}

// Function to calculate and display the total bill
void showDetails(Customer* customer) {
    printf("\n--- Customer Details ---\n");
    printf("Name: %s\n", customer->name);
    printf("Address: %s\n", customer->address);
    printf("Email: %s\n", customer->email_id);
    printf("Nationality: %s\n", customer->nationality);
    printf("Room No: %d\n", customer->roomno);
    printf("Room Type: %s\n", customer->roomtype);
    printf("Program: %s\n", customer->program);
    printf("Bill Price: %d\n", customer->billprice);

    int totalBill = customer->billprice;
    if (strcmp(customer->program, "Jungle Walk") == 0) {
        totalBill += 1000;
    } else if (strcmp(customer->program, "Jeep Drive") == 0) {
        totalBill += 2000;
    } else if (strcmp(customer->program, "Canoe Ride") == 0) {
        totalBill += 800;
   

 } else if (strcmp(customer->program, "Cultural Show") == 0) {
        totalBill += 1000;
    }

    printf("Total Bill Price: %d\n", totalBill);
}

// Function to create a new player
Player createPlayer() {
    Player newPlayer;
    newPlayer.inhand_cash = 0;
    return newPlayer;
}

// Function to play the Guess Game
void GuessGame(int* inhand_cash, Player* player)
{
    char num[3] = { 'N', 'R', 'N' };
    printf("Wait !! number is shuffling its position...\n");
    srand((unsigned)time(NULL));
    int i, x, y, temp;

    for (i = 0; i < 5; i++) {
        x = rand() % 3;
        y = rand() % 3;
        temp = num[x];
        num[x] = num[y];
        num[y] = temp;
    }

    int PlayerGuess;
    printf("You may now guess the number in which 'R' is present: ");
    scanf("%d", &PlayerGuess);

    if (num[PlayerGuess - 1] == 'R') {
        (*inhand_cash) += 2 * player->inhand_cash;
        printf("You win! The numbers are: \"%c %c %c\"\n", num[0], num[1], num[2]);
        printf("Your inhand cash is now: %d\n", *inhand_cash);
    } else {
        (*inhand_cash) -= player->inhand_cash;
        printf("You lose! The numbers are: \"%c %c %c\"\n", num[0], num[1], num[2]);
        printf("Your inhand cash is now: %d\n", *inhand_cash);
    }
}
void displayRoomAvailability(const int* roomAvailability, int numRooms);

void deallocateRoom(Customer* customer, int* roomAvailability) {
    if (customer->roomno != 0) {
        int floorNumber = customer->roomno / 100;
        int roomNumber = customer->roomno % 100;

        int index = (floorNumber - 1) * ROOMS_PER_FLOOR + roomNumber - 1;
        roomAvailability[index] = 0; // Mark the room as available again

        printf("Room %d on floor %d is deallocated.\n", roomNumber, floorNumber);

        // Reset customer details related to the room
        customer->roomno = 0;
        strcpy(customer->roomtype, "");
        customer->billprice = 0;
        strcpy(customer->program, "notchosen");
    } else {
        printf("Customer has not booked a room.\n");
    }
}

int main() {
    Customer* customerList = NULL;
    Player* playerList = NULL;
    int inhand_cash = 0;
    int numPlayers = 0;

    // Initialize room availability
    int roomAvailability[MAX_ROOMS];
    initializeRoomAvailability(roomAvailability, MAX_ROOMS);

    while (1) {
        int choice;
        printf("===== Hotel Management System =====\n");
        printf("1. Check-in a customer\n");
        printf("2. Book a room\n");
        printf("3. Choose a program\n");
        printf("4. Show customer details\n");
        printf("5. Submit complaints/suggestions\n");
        printf("6. Mini Casino\n");
        printf("7. Deallocate room\n");
        printf("8. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        Customer newCustomer;
        displayRoomAvailability(roomAvailability, MAX_ROOMS);

        switch (choice) {
        case 1:
            // Check-in a customer
            newCustomer = createCustomer();
            printf("Please enter your name: ");
            scanf("%19s", newCustomer.name);
            printf("Enter your address: ");
            scanf("%49s", newCustomer.address);
            printf("Enter your nationality: ");
            scanf("%24s", newCustomer.nationality);
            printf("Enter your email id: ");
            scanf("%29s", newCustomer.email_id);
            customerList = (Customer*)realloc(customerList, (sizeof(Customer) * (1 + 1)));
            customerList[0] = newCustomer;
            break;
        case 2:
            // Book a room for a customer
            if (customerList) {
                printf("Enter customer's name: ");
                char customerName[20];
                scanf("%19s", customerName);
                int customerIndex = -1;
                for (int i = 0; i < 1; i++) {
                    if (strcmp(customerList[i].name, customerName) == 0) {
                        customerIndex = i;
                        break;
                    }
                }
                if (customerIndex != -1) {
                    bookRoom(&customerList[customerIndex], roomAvailability, MAX_ROOMS);
                }
                else {
                    printf("Customer not found.\n");
                }
            }
            else {
                printf("No customers checked in.\n");
            }
            break;
        case 3:
            // Choose a program
            if (customerList) {
                printf("Enter customer's name: ");
                char customerName[20];
                scanf("%19s", customerName);
                int customerIndex = -1;
                for (int i = 0; i < 1; i++) {
                    if (strcmp(customerList[i].name, customerName) == 0) {
                        customerIndex = i;
                        break;
                    }
                }
                if (customerIndex != -1) {
                    chooseProgram(&customerList[customerIndex]);
                }
                else {
                    printf("Customer not found.\n");
                }
            }
            else {
                printf("No customers checked in.\n");
            }
            break;
        case 4:
            // Show customer details
            if (customerList) {
                printf("Enter customer's name: ");
                char customerName[20];
                scanf("%19s", customerName);
                int customerIndex = -1;
                for (int i = 0; i < 1; i++) {
                    if (strcmp(customerList[i].name, customerName) == 0) {
                        customerIndex = i;
                        break;
                    }
                }
                if (customerIndex != -1) {
                    showDetails(&customerList[customerIndex]);
                }
                else {
                    printf("Customer not found.\n");
                }
            }
            else {
                printf("No customers checked in.\n");
            }
            break;
        case 5:
            // Submit complaints/suggestions
            printf("Please enter your complaints or suggestions: ");
            char complain[500];
            fflush(stdin);
            gets(complain);
            FILE* fpt = fopen("complaint.txt", "w+");
            if (fpt == NULL) {
                printf("File can't be opened for writing.\n");
            }
            else {
                fputs(complain, fpt);
                fclose(fpt);
                printf("Thank you for your valuable suggestions!\n");
            }
            break;
        case 6:
            // Mini Casino game
            if (numPlayers < 1) {
                playerList = (Player*)realloc(playerList, (sizeof(Player) * (numPlayers + 1)));
                Player newPlayer = createPlayer();
                printf("Enter your player name: ");
                scanf("%19s", newPlayer.name);
                printf("Enter the inhand_cash you have right now: ");
                scanf("%d", &newPlayer.inhand_cash);
                playerList[numPlayers] = newPlayer;
                numPlayers++; // Increment the player count
            }

            if (numPlayers > 0) {
                // Only play the game if there are players available
                printf("---- Mini Casino ----\n");
                int playerIndex = numPlayers - 1; // Use the last player in the list
                if (playerList[playerIndex].inhand_cash <= 0) {
                    printf("Sorry, you don't have enough cash to play.\n");
                    printf("Do come next time.\n");
                }
                else {
                    GuessGame(&inhand_cash, &playerList[playerIndex]);
                }
            }
            else {
                printf("No players available.\n");
            }
break;
        
case 7:
    // RoomDeallocate
    if (customerList) {
        printf("Enter customer's name: ");
        char customerName[20];
        scanf("%19s", customerName);
        int customerIndex = -1;
        for (int i = 0; i < 1; i++) {
            if (strcmp(customerList[i].name, customerName) == 0) {
                customerIndex = i;
                break;
            }
        }
        if (customerIndex != -1) {
            deallocateRoom(&customerList[customerIndex], roomAvailability);
        } else {
            printf("Customer not found.\n");
        }
    } else {
        printf("No customers checked in.\n");
    }
    break;

 case 8:
                // Exit the program
                if (customerList) {
                    free(customerList);
                }
                if (playerList) {
                    free(playerList);
                }
                printf("Thank you for using the Hotel Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }

        // Display room availability after each operation
        displayRoomAvailability(roomAvailability, MAX_ROOMS);
    }

    return 0;
}





/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for customer details
struct Customer {
    char name[20];
    char address[50];
    char email_id[30];
    char nationality[25];
    int roomno;
    char *roomtype;
    int billprice;
    char *program;
    struct Customer* next;
};

typedef struct Customer Customer;

// Structure for the HashTable
struct HashTable {
    int size;
    Customer** table;
};

typedef struct HashTable HashTable;

// Function to initialize a new customer
Customer* createCustomer() {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    if (newCustomer == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newCustomer->roomno = 0;
    newCustomer->billprice = 0;
    newCustomer->program = "notchosen";
    newCustomer->next = NULL;
    return newCustomer;
}

void inputCustomerDetails(Customer *customer) {
    printf("Please enter your name: ");
    scanf("%19s", customer->name);
    printf("Enter your address: ");
    scanf("%49s", customer->address);
    printf("Enter your nationality: ");
    scanf("%24s", customer->nationality);
    printf("Enter your email_id: ");
    scanf("%29s", customer->email_id);
}

void displayCustomerDetails(Customer *customer) {
    printf("\n--- Customer Details ---\n");
    printf("Name: %s\n", customer->name);
    printf("Address: %s\n", customer->address);
    printf("Email: %s\n", customer->email_id);
    printf("Nationality: %s\n", customer->nationality);
    printf("Room No: %d\n", customer->roomno);
    printf("Room Type: %s\n", customer->roomtype);
    printf("Program: %s\n", customer->program);
    printf("Bill Price: %d\n\n", customer->billprice);
}

void freeHashTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        Customer* current = hashTable->table[i];
        while (current != NULL) {
            Customer* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable->table);
    free(hashTable);
}

// Function to initialize a new hash table
HashTable* createHashTable(int size) {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    if (hashTable == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    hashTable->size = size;
    hashTable->table = (Customer**)malloc(sizeof(Customer*) * size);
    if (hashTable->table == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Function to add a customer to the hash table
void addCustomerToHashTable(HashTable* hashTable, Customer* customer) {
    int roomNumber = customer->roomno;
    int index = roomNumber % hashTable->size;

    // Add the customer to the beginning of the linked list at the calculated index
    customer->next = hashTable->table[index];
    hashTable->table[index] = customer;
}

// Function to book a room for a customer
void bookRoom(HashTable* hashTable, Customer* customer) {
    if (customer->roomno == 0) {
        // Simulate the process of booking a room and allocate it in the hash table
        int roomNumber;
        printf("\nEnter the room number to book: ");
        scanf("%d", &roomNumber);

        if (roomNumber < 0 || roomNumber >= hashTable->size) {
            printf("Invalid room number.\n");
            return;
        }

        customer->roomno = roomNumber;
        customer->roomtype = "basic"; // You can add logic to choose room type
        customer->billprice += 1000; // Adjust the price according to room type
        addCustomerToHashTable(hashTable, customer);
        printf("Room %d is booked. Enjoy your stay!\n", roomNumber);
    } else {
        printf("You have already booked a room.\n");
    }
}

void program(Customer* customer) {
    if (customer->program == "notchosen") {
        int p;
        printf("\nWhich program do you want to choose?\n");
        printf("1. Jungle Walk\n2. Jungle Jeep Drive\n3. Canoe Ride\n4. Cultural Show\n");
        scanf("%d", &p);
        switch (p) {
            case 1:
                printf("\nYou choose jungle walk\n");
                customer->program = "Jungle walk";
                customer->billprice += 1000;
                break;
            case 2:
                printf("\nYou choose jungle jeep drive\n");
                customer->program = "Jeep Drive";
                customer->billprice += 2000;
                break;
            case 3:
                printf("\nYou choose canoe ride\n");
                customer->billprice += 800;
                customer->program = "Canoe Ride";
                break;
            case 4:
                printf("\nYou choose cultural show\n");
                customer->billprice += 1000;
                customer->program = "Cultural show";
                break;
            default:
                printf("Invalid choice.\n");
        }
    } else {
        printf("You have already chosen a program.\n");
    }
}

void showDetails(HashTable* hashTable, Customer* customer) {
    system("cls");
    printf("Customer Details:\n");

    // Calculate index based on room number
    int index = customer->roomno % hashTable->size;

    // Search for the customer in the hash table
    Customer* current = hashTable->table[index];
    while (current != NULL) {
        if (strcmp(current->name, customer->name) == 0) {
            printf("Name: %s\n", current->name);
            printf("Nationality: %s\n", current->nationality);
            printf("Email id: %s\n", current->email_id);
            printf("Address: %s\n", current->address);
            printf("Roomno: %d\n", current->roomno);
            printf("Roomtype: %s\n", current->roomtype);
            if (strcmp(current->program, "notchosen") != 0) {
                printf("Program: %s\n", current->program);
                printf("Program Price: ");
                if (strcmp(current->program, "Jungle walk") == 0) {
                    printf("1000\n");
                } else if (strcmp(current->program, "Jeep Drive") == 0) {
                    printf("2000\n");
                } else if (strcmp(current->program, "Canoe Ride") == 0) {
                    printf("800\n");
                } else if (strcmp(current->program, "Cultural show") == 0) {
                    printf("1000\n");
                }
            }
            printf("Bill price: %d\n", current->billprice);
            if (strcmp(current->program, "notchosen") != 0) {
                printf("Total Bill Price: %d\n", current->billprice +
                       ((strcmp(current->program, "Jungle walk") == 0) ? 1000 :
                        (strcmp(current->program, "Jeep Drive") == 0) ? 2000 :
                        (strcmp(current->program, "Canoe Ride") == 0) ? 800 :
                        (strcmp(current->program, "Cultural show") == 0) ? 1000 : 0));
            } else {
                printf("Total Bill Price: %d\n", current->billprice);
            }
            break;  // Customer found, no need to continue
        }
        current = current->next;
    }

    printf("Press any key to return to the main menu.");
    getchar();  // Use getchar() instead of getch()
}

void complaintsSuggestions(Customer* customer) {
    system("cls");
    char complain[500];
    FILE* fpt;
    printf("Please enter your complaints or suggestions: ");
    fflush(stdin);
    gets(complain);

    fpt = fopen("complain.txt", "w+");
    if (fpt == NULL) {
        printf("File can't be opened for writing.\n");
    } else {
        fputs(complain, fpt);
        fclose(fpt);
        printf("Sorry for the inconvience. We will work on it.\n");
    }
}

int main() {
    int hashTableSize = 100; // Adjust the size as needed

    HashTable* roomAllocationTable = createHashTable(hashTableSize);

    printf(".............WELCOME TO GHUMTEE RIVIERA RESTAURANT AND LODGE..............\n");
    printf("Please enter your details before moving to the main page!\n");
    Customer* customer = createCustomer();
    inputCustomerDetails(customer);

    while (1) {
        int decide;
        printf("\n-----------------------HOME PAGE--------------------------\n");
        printf("\n            HOW CAN WE HELP YOU?\n\n");
        printf("1. Book a room\n2. Program\n3. Show my details\n4. Complaints or suggestions\n5. Check out\n6. About us\n");
        scanf("%d", &decide);

        switch (decide) {
            case 1:
                bookRoom(roomAllocationTable, customer);
                break;
            case 2:
                program(customer);
                break;
            case 3:
                showDetails(roomAllocationTable, customer);
                break;
            case 4:
                complaintsSuggestions(customer);
                break;
            case 5:
                printf("Visit again!\n");
                printf("Thank you for trusting our service.\n");
                freeHashTable(roomAllocationTable);
                free(customer);
                return 0;
            case 6:
                printf("GHUMTEE RIVERA RESORT:\n");
                // About us details
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}*/


/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for customer details
struct Customer {
    char name[20];
    char address[50];
    char email_id[30];
    char nationality[25];
    char roomtype[20];
    int billprice;
    char program[20];
    int roomno;
    struct Customer* next;
};

typedef struct Customer Customer;

// Structure for the HashTable
struct HashTable {
    int size;
    Customer** table;
};

typedef struct HashTable HashTable;

// Function to initialize a new customer
Customer* createCustomer() {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    if (newCustomer == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newCustomer->roomtype, "notchosen");
    newCustomer->billprice = 0;
    strcpy(newCustomer->program, "notchosen");
    newCustomer->next = NULL;
    return newCustomer;
}

// Function to initialize a new hash table
HashTable* createHashTable(int size) {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    if (hashTable == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    hashTable->size = size;
    hashTable->table = (Customer**)malloc(sizeof(Customer*) * size);
    if (hashTable->table == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Function to add a customer to the hash table
void addCustomerToHashTable(HashTable* hashTable, Customer* customer, int roomNumber) {
    int index = roomNumber % hashTable->size;

    // Add the customer to the beginning of the linked list at the calculated index
    customer->next = hashTable->table[index];
    hashTable->table[index] = customer;
}

// Function to display allocated rooms based on the hash table
void displayAllocatedRooms(HashTable* hashTable) {
    printf("\n--- Allocated Room Details ---\n");
    for (int i = 0; i < hashTable->size; i++) {
        printf("Room Number %d:\n", i);
        Customer* current = hashTable->table[i];
        while (current != NULL) {
            printf("Name: %s\n", current->name);
            printf("Room Type: %s\n", current->roomtype);
            printf("Bill Price: %d\n\n", current->billprice);
            current = current->next;
        }
    }
}

// Function to book a room for a customer
void bookRoom(HashTable* hashTable, Customer* customer, int roomNumber) {
    if (customer->roomno == 0) {
        // Room has not been booked
        printf("\nWhat type of room do you want to book?\n");
        printf("1. Basic Room    Rs 1000\n2. Medium Room   Rs 2000\n3. Deluxe Room   Rs 3000\n");
        int type_of_rooms;
        scanf("%d", &type_of_rooms);
        
        switch (type_of_rooms) {
            case 1:
                strcpy(customer->roomtype, "Basic");
                customer->billprice += 1000;
                break;
            case 2:
                strcpy(customer->roomtype, "Medium");
                customer->billprice += 2000;
                break;
            case 3:
                strcpy(customer->roomtype, "Deluxe");
                customer->billprice += 3000;
                break;
            default:
                printf("Invalid choice.\n");
                return;
        }
        
        printf("Your room no is %d\n", roomNumber);
        customer->roomno = roomNumber;  // Set the room number for the customer
        addCustomerToHashTable(hashTable, customer, roomNumber);
        printf("Room %d is booked. Enjoy your stay!\n");
    } else {
        printf("You have already booked a room.\n");
    }
}


void program(Customer* customer) {
    if (strcmp(customer->program, "notchosen") == 0) {
        int p;
        printf("\nWhich program do you want to choose?\n");
        printf("1. Jungle Walk\n2. Jungle Jeep Drive\n3. Canoe Ride\n4. Cultural Show\n");
        scanf("%d", &p);
        switch (p) {
            case 1:
                printf("\nYou choose jungle walk\n");
                strcpy(customer->program, "Jungle walk");
                customer->billprice += 1000;
                break;
            case 2:
                printf("\nYou choose jungle jeep drive\n");
                strcpy(customer->program, "Jeep Drive");
                customer->billprice += 2000;
                break;
            case 3:
                printf("\nYou choose canoe ride\n");
                customer->billprice += 800;
                strcpy(customer->program, "Canoe Ride");
                break;
            case 4:
                printf("\nYou choose cultural show\n");
                customer->billprice += 1000;
                strcpy(customer->program, "Cultural show");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } else {
        printf("You have already chosen a program.\n");
    }
}

void showDetails(HashTable* hashTable, Customer* customer) {
    system("cls");
    printf("Customer Details:\n");

    // Search for the customer by name
    Customer* current = hashTable->table[0];
    while (current != NULL) {
        if (strcmp(current->name, customer->name) == 0) {
            printf("Name: %s\n", current->name);
            printf("Nationality: %s\n", current->nationality);
            printf("Email id: %s\n", current->email_id);
            printf("Address: %s\n", current->address);
            printf("Roomno: %d\n", current->roomno);
            printf("Roomtype: %s\n", current->roomtype);
            if (strcmp(current->program, "notchosen") != 0) {
                printf("Program: %s\n", current->program);
            }
            printf("Bill price: %d\n", current->billprice);
            break;  // Customer found, no need to continue
        }
        current = current->next;
    }

    printf("Press any key to return to the main menu.");
    getchar();  // Use getchar() instead of getch()
}

void complaintsSuggestions(Customer* customer) {
    system("cls");
    char complain[500];
    FILE* fpt;
    printf("Please enter your complaints or suggestions: ");
    fflush(stdin);
    gets(complain);

    fpt = fopen("complain.txt", "w+");
    if (fpt == NULL) {
        printf("File can't be opened for writing.\n");
    } else {
        fputs(complain, fpt);
        fclose(fpt);
        printf("Thank you for your valuable suggestions!\n");
    }
}

int main() {
    int maxRooms = 100;  // Adjust the number of rooms as needed

HashTable* roomAllocationTable = createHashTable(maxRooms);
Customer* customer = createCustomer();

while (1) {
    int decide;
    int roomNumber;  // Declare roomNumber here
    printf("\n-----------------------HOME PAGE--------------------------\n");
    printf("\n            HOW CAN WE HELP YOU?\n\n");
    printf("1. Book a room\n2. Program\n3. Show my details\n4. Show allocated rooms\n5. Check out\n6. About us\n");
    scanf("%d", &decide);

    switch (decide) {
        case 1:
            printf("\nEnter the room number to book: ");
            scanf("%d", &roomNumber);
            
            if (roomNumber < 0 || roomNumber >= maxRooms) {
                printf("Invalid room number.\n");
            } else if (strcmp(customer->roomtype, "notchosen") != 0) {
                printf("You have already chosen a room type.\n");
            } else {
                bookRoom(roomAllocationTable, customer, roomNumber);
            }
            break;

        case 2:
            program(customer);
            break;

        case 3:
            showDetails(roomAllocationTable, customer);
            break;

        case 4:
            displayAllocatedRooms(roomAllocationTable);
            break;

        case 5:
            printf("Checking out...\n");
            if (strcmp(customer->roomtype, "notchosen") == 0) {
                printf("You have not booked any room. Nothing to check out.\n");
            } else {
                // Calculate the bill
                int bill = 0;
                int index = customer->roomno % maxRooms;
                Customer* current = roomAllocationTable->table[index];
                while (current != NULL) {
                    if (strcmp(current->name, customer->name) == 0) {
                        bill = current->billprice;
                        break;
                    }
                    current = current->next;
                }

                // Display the bill
                printf("Your bill is: Rs %d\n", bill);

                // Free the room, mark it as unallocated
                customer->roomno = 0;
                strcpy(customer->roomtype, "notchosen");
                customer->billprice = 0;
                strcpy(customer->program, "notchosen");

                // Remove the customer from the hash table
                current = roomAllocationTable->table[index];
                if (current == customer) {
                    roomAllocationTable->table[index] = current->next;
                    free(current);
                } else {
                    while (current->next != NULL) {
                        if (current->next == customer) {
                            Customer* temp = current->next;
                            current->next = temp->next;
                            free(temp);
                            break;
                        }
                        current = current->next;
                    }
                }

                printf("Thank you for staying with us! Your room is checked out.\n");
            }
            break;

        case 6:
            printf("GHUMTEE RIVERA RESORT:\n");
            // Add about us details here
            break;

        default:
            printf("Invalid choice.\n");
    }
}
}*/
