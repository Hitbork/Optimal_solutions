#include <iostream>
#include <vector>


std::vector<std::vector<float>> table;
std::vector<float> tableOfManufacturers;
std::vector<float> tableOfConsumers;
std::vector<std::vector<float>> referencePlan;


// Function to fill reference plan
void fill_reference_plan() {
    for (int i = 0; i < referencePlan.size(); i++) {
        for (int j = 0; j < referencePlan[i].size(); j++) {
            referencePlan[i][j] = -1;
        }
    }
}


// Function to output cost matrix and reference plan
void output_cost_matrix_and_reference_plan() {
    std::cout << "\tCost matrix:";
    for (int i = 0; i < table.size() + 2; i++) {
        std::cout << "\t";
    }
    std::cout << "Reference plan:\n";

    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            std::cout << table[i][j] << "\t";
        }
        std::cout << tableOfManufacturers[i] << "\t\t";

        for (int j = 0; j < referencePlan[i].size(); j++) {
            if (referencePlan[i][j] == -1) {
                std::cout << ".";
            } else {
                std::cout << referencePlan[i][j];
            }
            std::cout << "\t";
        }

        std::cout << tableOfManufacturers[i] << "\n";
    }

    for (int c = 0; c < 2; c++) {
        for (int i = 0; i < tableOfConsumers.size(); i++) {
            std::cout << tableOfConsumers[i] << "\t";
        }
        std::cout << ".\t\t";
    }

    std::cout << "\n\n";
}


// Function to output result of function
void output_result_of_function() {
    // Greetings
    std::cout << "\n";
    std::cout << "F(x) =";

    // Creating var to calculate summary
    float Fx = 0;
    bool isFirst = true;
    int counter = 0;

    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            if (referencePlan[i][j] != -1) {
                Fx += referencePlan[i][j] * table[i][j];
                if (counter == 3) {
                    std::cout << "\n";
                    counter = 0;
                }
                if (isFirst) {
                    isFirst = false;
                    std::cout << " ";
                } else {
                    std::cout << " + ";
                }
                std::cout << table[i][j] << " * " << referencePlan[i][j];
                counter++;
            }
        }
    }
    std::cout << " = " << Fx;
    std::cout << "\n\n";
}


// Function to copy manufacturers and consumers
void copy_tables_of_manufacturers_and_consumers(std::vector<float> &copyOfManufacturers, std::vector<float> &copyOfConsumers) {
    copyOfManufacturers = tableOfManufacturers;
    copyOfConsumers = tableOfConsumers;
}

// Function to input required info
void input_info() {
    std::cout << "Input sides of rectangle in cost matrix!\n";
    std::cout << "\nExample:\n";
    std::cout << "\tCost matrix:\n";
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

    fill_reference_plan();
}


// Function to do northwest corner method
void northwest_corner_method() {
    // Creating iterators
    int i = 0, j = 0;

    // Creating same vectors to copy tables
    std::vector<float> copyOfTableManufacturers(tableOfManufacturers.size()),
        copyOfTableConsumers(tableOfConsumers.size());

    copy_tables_of_manufacturers_and_consumers(copyOfTableManufacturers, copyOfTableConsumers);

    // Creating cycle
    for (int k = 0; k < table.size() + table[0].size() - 1; k++) {
        referencePlan[i][j] = std::min(copyOfTableManufacturers[i], copyOfTableConsumers[j]);

        copyOfTableManufacturers[i] -= referencePlan[i][j];
        copyOfTableConsumers[j] -= referencePlan[i][j];

        if (copyOfTableManufacturers[i] == 0) {
            i++;
        } else {
            j++;
        }
    }

    std::cout << "\n\n";

    output_cost_matrix_and_reference_plan();

    output_result_of_function();
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
