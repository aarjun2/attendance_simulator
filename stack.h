#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <time.h>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
// vector stack with different functions
class absent_Stack {
public:
    void push(string value) {
        Stack.push_back(value);
    }
    string pop() {
        Stack.pop_back();
    }
    bool isEmpty() {
        return Stack.empty();
    }
    string& peek() {
        if (Stack.size() != 0) {
            return Stack.back();
        }
        else {
            string temp = "";
            return temp;
        }
    }
    void clear_stack() {
        Stack.clear();
    }
    void print_stack(ostream& outfile) {
        for (int i = 0; i < Stack.size(); i++) {
            outfile << " ";
            outfile << Stack.at(i);
        }
    }
    /**********
function: edit absent
Date created: 4/11/2022
Date last modified:4/11/2022, 4/11/2022
Description: sets data for all data values except absent counts
Input parameters: string of target date
Returns: none
preconditions:data must be inputted, the order of file must be read, and absences should be marked
postconditions: if executed right, this will target the node entered by user
**/
    void edit_absent(string target_date) {
        vector<string>::iterator it1;
        for (it1 = Stack.begin(); it1 != Stack.end(); ++it1) {
            if (*it1 == target_date) {
                Stack.erase(it1);
                return;
            }
        }
    }
private:
    std::vector<string> Stack;
};
