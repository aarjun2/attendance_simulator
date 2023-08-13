#include "stack.h"

class Data {
public:
    Data() {
        this->record_number = 0;
        this->id = 0;
        this->name = "";
        this->email = "";
        this->units = "";
        this->program = "";
        this->level = "";
        this->no_abcenses = 0;
        this->mystack.clear_stack();
    }
    /**********
function: set data
Date created: 4/11/2022
Date last modified:4/11/2022, 4/11/2022
Description: sets data for all data values except absent counts
Input parameters: variables for each data value
Returns: none
preconditions:data must be inputted, the order of file must be read
postconditions: if executed right, this will set data to be used in linked node
**/
    void set_data(int record, int id, string name, string email, string unit, string program, string level) {
        this->record_number = record;
        this->id = id;
        this->name = name;
        this->email = email;
        this->units = unit;
        this->program = program;
        this->level = level;
    }
    int get_record() {
        return this->record_number;
    }
    int get_id() {
        return this->id;
    }
    string get_name() {
        return this->name;
    }
    string get_email() {
        return this->email;
    }
    string get_unit() {
        return this->units;
    }
    string get_program() {
        return this->program;
    }
    string get_level() {
        return this->level;
    }
    int get_absent() {
        return this->no_abcenses;
    }
    void set_no_abcenses(int absences) {
        this->no_abcenses = absences;
    }
    void set_absent(string& absence) {
        mystack.push(absence);
        no_abcenses = no_abcenses + 1;
    }
    absent_Stack get_stack() {
        return this->mystack;
    }
    string& recent_absent() {
        return mystack.peek();
    }
    /**********
function: print stack
Date created: 4/11/2022
Date last modified:4/11/2022, 4/11/2022
Description: calls the print function from vector stack
Input parameters: ostream file pointer
Returns: none
preconditions:data must be inputted, the order of file must be read
postconditions: if executed right, this will print the absent stack
**/
    void print_stack(ostream& outfile) {
        mystack.print_stack(outfile);
    }
    void clear_data() {
        this->record_number = 0;
        this->id = 0;
        this->name = "";
        this->email = "";
        this->units = "";
        this->program = "";
        this->level = "";
        this->no_abcenses = 0;
        this->mystack.clear_stack();
    }
    void edit_absence(string target_date) {
        mystack.edit_absent(target_date);
        no_abcenses = no_abcenses - 1;
    }
private:
    int record_number;
    int id;
    string name;
    string email;
    string units;
    string program;
    string level;
    int no_abcenses;
    absent_Stack mystack;
};

