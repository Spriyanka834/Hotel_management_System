/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct FoodItem {
    char name[20];
    int price;
};

typedef struct FoodItem FoodItem;

void displayFoodMenu() {
    printf("===== Food Menu =====\n");
    printf(" Italian Cuisine:\n");
    printf("1. - Pizza Margherita - 700\n");
    printf("2.   - Spaghetti Bolognese - 550\n");
    printf("3. - Risotto with Porcini Mushrooms - 430\n");
    printf(" American Cuisine:\n");
    printf("4.  - Classic Cheeseburger - 320\n");
    printf("5.  - BBQ Chicken Wings - 310\n");
    printf("6.   - Caesar Salad - 280\n");
    printf(" Japanese Cuisine:\n");
    printf("7.  - Sushi Platter - 800\n");
    printf("8. - Ramen Noodles - 720\n");
    printf("9. - Teriyaki Chicken - 800\n");
    printf(" Indian Cuisine:\n");
    printf("10.- Chicken Curry - 650\n");
    printf("11. - Vegetable Biryani - 750\n");
    printf("12.- Palak Paneer - 400\n");
    printf("=====================\n");
}


// Structure for customer details
struct Customer {
    char name[20];
    char address[50];
    char email_id[30];
    char nationality[25];
    int roomno;
    char roomtype[20];
    int billprice;
    char program[100];
    FoodItem orderedItems[10];
    int numOrderedItems;
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

// Function to book a room for a customer
void bookRoom(Customer* customer) {
    if (customer->roomno == 0) {
        // Simulate the process of booking a room
        int roomNumber;
        printf("Enter the room number to book: ");
        scanf("%d", &roomNumber);
        if (roomNumber < 0 || roomNumber >= 100) {
            printf("Invalid room number.\n");
            return;
        }
        customer->roomno = roomNumber;
        strcpy(customer->roomtype, "basic"); // You can add logic to choose room type
        customer->billprice += 1000; // Adjust the price according to room type
        printf("Room %d is booked. Enjoy your stay!\n", roomNumber);
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

// Function to order food for a customer
void orderFood(Customer* customer) {
    displayFoodMenu();
    int foodChoice;
    printf("Enter the number of the food item you want to order (0 to finish): ");
    scanf("%d", &foodChoice);

    while (foodChoice != 0) {
        if (customer->numOrderedItems < 10) {
            // Add the selected food item to the customer's ordered items
            switch (foodChoice) {
                case 1:
                    strcpy(customer->orderedItems[customer->numOrderedItems].name, "Pizza Margherita");
                    customer->orderedItems[customer->numOrderedItems].price = 700;
                    break;
                case 2:
                    strcpy(customer->orderedItems[customer->numOrderedItems].name, "Spaghetti Bolognese");
                    customer->orderedItems[customer->numOrderedItems].price = 550;
                    break;
                case 3:
                    strcpy(customer->orderedItems[customer->numOrderedItems].name, "Risotto with Porcini Mushrooms");
                    customer->orderedItems[customer->numOrderedItems].price = 430;
                    break;
                case 4:
                    strcpy(customer->orderedItems[customer->numOrderedItems].name, " Classic Cheeseburger");
                    customer->orderedItems[customer->numOrderedItems].price = 320;
                    break;
                case 5:
                    strcpy(customer->orderedItems[customer->numOrderedItems].name, "BBQ Chicken Wings");
                    customer->orderedItems[customer->numOrderedItems].price = 310;
                    break;
                case 6:
                    strcpy(customer->orderedItems[customer->numOrderedItems].name, " Caesar Salad");
                    customer->orderedItems[customer->numOrderedItems].price = 280;
                    break;
                case 7:
                    strcpy(customer->orderedItems[customer->numOrderedItems].name, "Sushi Platter");
                    customer->orderedItems[customer->numOrderedItems].price = 800;
                    break;
                case 8:
                    strcpy(customer->orderedItems[customer->numOrderedItems].name, "Ramen Noodles");
                    customer->orderedItems[customer->numOrderedItems].price = 720;
                    break;
                case 9:
                    strcpy(customer->orderedItems[customer->numOrderedItems].name, "Teriyaki Chicken");
                    customer->orderedItems[customer->numOrderedItems].price = 800;
                    break;
                case 10:
                    strcpy(customer->orderedItems[customer->numOrderedItems].name, "Chicken Curry");
                    customer->orderedItems[customer->numOrderedItems].price = 650;
                    break;
                case 11:
                    strcpy(customer->orderedItems[customer->numOrderedItems].name, "Vegetable Biryani");
                    customer->orderedItems[customer->numOrderedItems].price = 750;
                    break;
                case 12:
                    strcpy(customer->orderedItems[customer->numOrderedItems].name, "Palak Paneer");
                    customer->orderedItems[customer->numOrderedItems].price = 400;
                    break;
                default:
                    printf("Invalid food choice.\n");
                    break;

            }
            // Increment the number of ordered items
            customer->numOrderedItems++;
        } else {
            printf("You can only order up to 10 items.\n");
        }

        // Ask for the next food item or finish ordering
        printf("Enter the number of the next food item you want to order (0 to finish): ");
        scanf("%d", &foodChoice);
    }

    printf("Food ordered successfully!\n");
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

    // Display ordered food items and their prices
    if (customer->numOrderedItems > 0) {
        printf("Food Ordered:\n");
        for (int i = 0; i < customer->numOrderedItems; i++) {
            printf("   - %s - $%d\n", customer->orderedItems[i].name, customer->orderedItems[i].price);
        }
    }

    // Display program-related costs
    int programCost = 0;
    if (strcmp(customer->program, "Jungle Walk") == 0) {
        programCost = 1000;
    } else if (strcmp(customer->program, "Jeep Drive") == 0) {
        programCost = 2000;
    } else if (strcmp(customer->program, "Canoe Ride") == 0) {
        programCost = 800;
    } else if (strcmp(customer->program, "Cultural Show") == 0) {
        programCost = 1000;
    }

    // Display and add food-related costs
    int foodCost = 0;
    for (int i = 0; i < customer->numOrderedItems; i++) {
        foodCost += customer->orderedItems[i].price;
    }

    // Calculate and display total bill
    int totalBill = customer->billprice + programCost + foodCost;
    printf("Program Cost: $%d\n", programCost);
    printf("Food Cost: $%d\n", foodCost);
    printf("Total Bill Price: $%d\n", totalBill);
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

int main() {
    Customer* customerList = NULL;
    Player* playerList = NULL;
    int inhand_cash = 0;
int numPlayers = 0;

    while (1) {
        int choice;

        printf("===== Hotel Management System =====\n");
        printf("1. Check-in a customer\n");
        printf("2. Book a room\n");
        printf("3. Choose a program\n");
        printf("4. Order food\n");
        printf("5. Show customer details\n");
        printf("6. Submit complaints/suggestions\n");
        printf("7. Mini Casino\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        Customer newCustomer;

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
                        bookRoom(&customerList[customerIndex]);
                    } else {
                        printf("Customer not found.\n");
                    }
                } else {
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
                    } else {
                        printf("Customer not found.\n");
                    }
                } else {
                    printf("No customers checked in.\n");
                }
                break;
            case 4:
                // Order food for a customer
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
                        orderFood(&customerList[customerIndex]);
                    } else {
                        printf("Customer not found.\n");
                    }
                } else {
                    printf("No customers checked in.\n");
                }
                break;
            case 5:
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
                    } else {
                        printf("Customer not found.\n");
                    }
                } else {
                    printf("No customers checked in.\n");
                }
                break;
            case 6:
                // Submit complaints/suggestions
                printf("Please enter your complaints or suggestions: ");
                char complain[500];
                fflush(stdin);
                gets(complain);
                FILE* fpt = fopen("complaint.txt", "w+");
                if (fpt == NULL) {
                    printf("File can't be opened for writing.\n");
                } else {
                    fputs(complain, fpt);
                    fclose(fpt);
                    printf("Thank you for your valuable suggestions!\n");
                }
                break;
            // Add a global variable to keep track of the number of players


// Inside the main function
case 7:
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
        } else {
            GuessGame(&inhand_cash, &playerList[playerIndex]);
        }
    } else {
        printf("No players available.\n");
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
    }

    return 0;
}
*/


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