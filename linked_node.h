#include "data.h"
// template for linked node, contains data class and stack class
template <class T>
class Linked_node {
public:
    Linked_node() {
        next = nullptr;
    }
    void set_data(T& x) {
        this->data = x;
    }
    T& get_data() {
        return this->data;
    }
    string get_name() {
        return this->data.get_name();
    }
    void set_next(Linked_node<T>* y) {
        this->next = y;
    }
    Linked_node<T>* get_next() {
        return this->next;
    }
    void set_absence(string& absence) {
        data.set_absent(absence);
    }
    string& recent_absence() {
        return data.recent_absent();
    }
    void clear_data() {
        data.clear_data();
    }
    void edit_absent_node(string target_date) {
        data.edit_absence(target_date);
    }
    int get_no_absent() {
        return data.get_absent();
    }
private:
    Data data;
    Linked_node<T>* next;
};

ostream& operator<<(ostream& outfile, Data& value) {
    outfile << value.get_record() << " ";
    outfile << value.get_id() << " ";
    outfile << value.get_name() << " ";
    outfile << value.get_email() << " ";
    outfile << value.get_unit() << " ";
    outfile << value.get_program() << " ";
    outfile << value.get_level() << " ";
    int absent_value = value.get_absent();
    outfile << absent_value;
    if (absent_value > 0) {
        value.print_stack(outfile);
    }
    return outfile;
}
