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


// Overload of output function
void output_cost_matrix_and_reference_plan(std::vector<std::vector<float>> &copyOfTable, std::vector<float> &copyOfManufacturers, std::vector<float> &copyOfConsumers) {
    std::cout << "\n";
    std::cout << "\tCost matrix:";
    for (int i = 0; i < copyOfTable.size() + 2; i++) {
        std::cout << "\t";
    }
    std::cout << "Reference plan:\n";

    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            if (copyOfTable[i][j] != 0) {
                std::cout << copyOfTable[i][j] << "\t";
            } else {
                std::cout << "-" << "\t";
            }
        }

        if (copyOfManufacturers[i] != 0) {
            std::cout << copyOfManufacturers[i] << "\t\t";
        } else  {
            std::cout << "-" << "\t\t";
        }

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

    for (int i = 0; i < copyOfConsumers.size(); i++) {
        if (copyOfConsumers[i] != 0) {
            std::cout << copyOfConsumers[i] << "\t";
        } else {
            std::cout << "-\t";
        }
    }

    std::cout << ".\t\t";

    for (int i = 0; i < tableOfConsumers.size(); i++) {
        std::cout << tableOfConsumers[i] << "\t";
    }
    std::cout << ".\n";

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


// Function to check if consumers and manufacturers arent empty
bool copies_arent_empty(std::vector<float> &copyOfTableManufacturers, std::vector<float> &copyOfTableConsumers) {
    for (int i = 0; i < copyOfTableConsumers.size(); i++) {
        if (copyOfTableConsumers[i] > 0) {
            return true;
        }
    }

    for (int i = 0; i < copyOfTableManufacturers.size(); i++) {
        if (copyOfTableManufacturers[i] > 0) {
            return true;
        }
    }

    return false;
}

// Function to find max
float find_max(int indexesOfMin[], std::vector<std::vector<float>> &copyOfTable) {
    float max = -1;

    for (int i = 0; i < copyOfTable.size(); i++) {
        for (int j = 0; j < copyOfTable[i].size(); j++) {
            if (copyOfTable[i][j] > max) {
                max = copyOfTable[i][j];
                indexesOfMin[0] = i;
                indexesOfMin[1] = j;
            }
        }
    }

    return max;
}


// Function to find min in cost of matrix
void find_min(int indexesOfMin[], std::vector<std::vector<float>> &copyOfTable) {
    float min = find_max(indexesOfMin, copyOfTable);

    for (int i = 0; i < copyOfTable.size(); i++) {
        for (int j = 0; j < copyOfTable[i].size(); j++) {
            if ((copyOfTable[i][j] < min) && (copyOfTable[i][j] != 0))  {
                min = copyOfTable[i][j];
                indexesOfMin[0] = i;
                indexesOfMin[1] = j;
            }
        }
    }
}


void finding_coefficient(int indexesOfMin[2], std::vector<std::vector<float>> &copyOfTable, std::vector<float> &copyOfTableManufacturers, std::vector<float> &copyOfTableConsumers) {
    referencePlan[indexesOfMin[0]][indexesOfMin[1]] = std::min(copyOfTableManufacturers[indexesOfMin[0]], copyOfTableConsumers[indexesOfMin[1]]);

    if (copyOfTableManufacturers[indexesOfMin[0]] == copyOfTableConsumers[indexesOfMin[1]]) {
        for (int i = 0; i < copyOfTable[0].size(); i++) {
            copyOfTable[indexesOfMin[0]][i] = 0;
        }
        for (int i = 0; i < copyOfTable.size(); i++) {
            copyOfTable[i][indexesOfMin[1]] = 0;
        }
    } else if (copyOfTableManufacturers[indexesOfMin[0]] < copyOfTableConsumers[indexesOfMin[1]]) {
        for (int i = 0; i < copyOfTable[0].size(); i++) {
            copyOfTable[indexesOfMin[0]][i] = 0;
        }
    } else {
        for (int i = 0; i < copyOfTable.size(); i++) {
            copyOfTable[i][indexesOfMin[1]] = 0;
        }
    }

    copyOfTableManufacturers[indexesOfMin[0]] -= referencePlan[indexesOfMin[0]][indexesOfMin[1]];
    copyOfTableConsumers[indexesOfMin[1]] -= referencePlan[indexesOfMin[0]][indexesOfMin[1]];
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
}


// Function to do northwest corner method
void northwest_corner_method() {
    // Creating iterators
    int i = 0, j = 0;

    // Creating same vectors to copy tables
    std::vector<float> copyOfTableManufacturers(tableOfManufacturers.size()),
        copyOfTableConsumers(tableOfConsumers.size());

    copy_tables_of_manufacturers_and_consumers(copyOfTableManufacturers, copyOfTableConsumers);

    std::vector<std::vector<float>> copyOfTable = table;

    output_cost_matrix_and_reference_plan(copyOfTable, copyOfTableManufacturers, copyOfTableConsumers);

    // Creating cycle
    for (int k = 0; k < table.size() + table[0].size() - 1; k++) {
        referencePlan[i][j] = std::min(copyOfTableManufacturers[i], copyOfTableConsumers[j]);

        copyOfTableManufacturers[i] -= referencePlan[i][j];
        copyOfTableConsumers[j] -= referencePlan[i][j];

        if (copyOfTableManufacturers[i] == 0) {
            for (int l = 0; l < table[0].size(); l++) {
                copyOfTable[i][l] = 0;
            }
            i++;
        } else {
            for (int l = 0; l < table.size(); l++) {
                copyOfTable[l][j] = 0;
            }
            j++;
        }

        output_cost_matrix_and_reference_plan(copyOfTable, copyOfTableManufacturers, copyOfTableConsumers);
    }

    std::cout << "\n\n";

    output_cost_matrix_and_reference_plan();

    output_result_of_function();
}


// Function to do minimum elements method
void minimum_elements_method() {
    // Creating same vectors to copy tables
    std::vector<float> copyOfTableManufacturers(tableOfManufacturers.size()),
            copyOfTableConsumers(tableOfConsumers.size());

    copy_tables_of_manufacturers_and_consumers(copyOfTableManufacturers, copyOfTableConsumers);

    std::vector<std::vector<float>> copyOfTable = table;

    output_cost_matrix_and_reference_plan(copyOfTable, copyOfTableManufacturers, copyOfTableConsumers);

    // Cycle
    int indexesOfMin[2];
    while (copies_arent_empty(copyOfTableManufacturers, copyOfTableConsumers)) {
        find_min(indexesOfMin, copyOfTable);

        finding_coefficient(indexesOfMin, copyOfTable, copyOfTableManufacturers, copyOfTableConsumers);

        output_cost_matrix_and_reference_plan(copyOfTable, copyOfTableManufacturers, copyOfTableConsumers);
    }

    std::cout << "\n\n";

    output_cost_matrix_and_reference_plan();

    output_result_of_function();
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

        fill_reference_plan();

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
