#include <iostream>
#include <vector>


std::vector<std::vector<float>> table;
std::vector<float> tableOfManufacturers;
std::vector<float> tableOfConsumers;
std::vector<std::vector<float>> referencePlan;


// Function to input required info
void input_info() {
    std::cout << "Input sides of rectangle in cost matrix!\n";
    std::cout << "\nExample:\n";
    std::cout << " Cost matrix:\n";
    std::cout << " 6\t5\t8\t7\t14\n";
    std::cout << " 3\t6\t4\t2\t12\n";
    std::cout << " 9\t1\t3\t6\t8\n";
    std::cout << " 10\t14\t6\t4\n";
    std::cout << "\nSides of rectangle inside:\n";
    std::cout << "5 4\n\n";

    std::cout << "Input your values of sides:\n";
    int length, width;
    std::cin >> length >> width;

    table.resize(width-1);
    referencePlan.resize(width-1);
    tableOfManufacturers.resize(width-1);
    tableOfConsumers.resize(length-1);


    std::cout << "\nInput whole cost of matrix:\n";
    for (int i = 0; i < width - 1; i++) {
        table[i].resize(length-1);
        referencePlan[i].resize(length-1);
        for (int j = 0; j < length - 1; j++) {
            std::cin >> table[i][j];
        }
        std::cin >> tableOfManufacturers[i];
    }

    for (int i = 0; i < length - 1; i++) {
        std::cin >> tableOfConsumers[i];
    }
}


// Function to do northwest corner method
void northwest_corner_method() {

}


// Function to do minimum elements method
void minimum_elements_method() {

}


// Function to do Q factor method
void Q_factor_method() {

}


int main() {
    // Greetings
    std::cout << "\n Optimal solutions for manufacturers\n\n\n";


    // Requiring information
    input_info();


    while (true) {
        int choice;
        std::cout << "\n\nWhat method would you choose?\n";
        std::cout << " 1 - northwest corner method\n";
        std::cout << " 2 - minimum elements method\n";
        std::cout << " 3 - Q factor method\n";
        std::cout << " 4 - exit the program\n";

        std::cout << "\nInput your choice:\n";
        std::cin >> choice;

        // Check if choice is to exit the program
        if (choice == 4)
            break;

        // Check choice method
        switch (choice) {
            case 1:
                northwest_corner_method();
                break;
            case 2:
                minimum_elements_method();
                break;
            case 3:
                Q_factor_method();
                break;
            default:
                std::cout << "Wrong input!\n";
                std::cout << "Try again!\n";
        }

        // Check if wrong input
        if (choice > 3)
            continue;
    }

    std::cout << "\n Program exit";
}
