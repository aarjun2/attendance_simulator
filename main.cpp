#include "linked_node.h"

template <class T>
class Linked_list {
public:
    void read_from_file() {
        fstream infile;
        string line;
        string record_number;
        string ID;
        string first_name;
        string last_name;
        string email;
        string units;
        string program;
        string level;
        infile.open("classList.csv", ios::in);
        if (infile.is_open()) {
            getline(infile, line);// ignoring the header
            getline(infile, line);
            do {
                stringstream mystream(line);// to parse through the comma seperated line
                getline(mystream, record_number, ',');
                int record = stoi(record_number);
                getline(mystream, ID, ',');
                int id_number = stoi(ID);
                getline(mystream, first_name, ',');
                string temp = first_name.substr(1, first_name.length()-1);// to get rid of quotes
                first_name = temp;
                getline(mystream, last_name, ',');
                temp = last_name.substr(0, last_name.length() - 1);// to get rid of quotes
                last_name = temp;
                string full_name = last_name + ',' +first_name;
                getline(mystream, email, ',');
                getline(mystream, units, ',');
                getline(mystream, program, ',');
                getline(mystream, level, ',');
                Linked_node<T>* new_node = new Linked_node<T>;
                Data& mydata = new_node->get_data();
                mydata.set_data(record, id_number, full_name, email, units, program, level);
                new_node->set_data(mydata);
                insert_at_front(new_node);
                getline(infile, line);
            } while (!infile.eof());
            print_Linked_list();
        }
        infile.close();
    }
    /**********
function: mark absent
Date created: 4/11/2022
Date last modified:4/11/2022, 4/11/2022
Description: marks an absent for student based on actual date
Input parameters: none
Returns: none
preconditions:data must be inputted, the order of file must be read
postconditions: if executed right, this will set the absent stack and number of absent in the nodes in linked list
**/
    void mark_absent() {
        char answer;
        Linked_node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->get_name() << endl;
            cout << "is this student absent? y/n" << endl;
            cin >> answer;
            if (answer == 'y') {
                time_t t = time(0);   // get time now
                time_t rawtime = time(0);
                struct tm timeinfo;
                string my_date;
                //time(&rawtime);
                localtime_s(&timeinfo, &rawtime);
                my_date = std::to_string(timeinfo.tm_mon + 1) + '-' + std::to_string(timeinfo.tm_mday) + '-' + std::to_string(timeinfo.tm_year + 1900);
                temp->set_absence(my_date);
            }
            temp = temp->get_next();
        }
    }
    void generate_report_option_1() {
        Linked_node<T>* temp = head;
        while (temp != nullptr) {
            string &recent_absent = temp->recent_absence();
            if (recent_absent.length() > 0) {
                cout << temp->get_data() << endl;
                cout << recent_absent << endl;
            }
            temp = temp->get_next();
        }
    }
    void generate_report_option_2(int data_absent) {
        Linked_node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->get_no_absent() >= data_absent) {
                cout << temp->get_data() << endl;
            }
            temp = temp->get_next();
        }
    }
    void store_content() {
        fstream outfile;
        outfile.open("master.txt", ios::out);
        if (outfile.is_open()) {
            Linked_node<T>* temp = head;
            while (temp != nullptr) {
                outfile << temp->get_data();
                temp = temp->get_next();
                if (temp != nullptr) {
                    outfile << endl;
                }
            }
        }
        outfile.close();
    }
    void read_content() {
        fstream infile;
        string line;
        string record_number;
        string ID;
        string first_name;
        string last_name;
        string email;
        string units;
        string program;
        string level;
        string no_absent;
        string date_of_absent;
        infile.open("master.txt", ios::in);
        if (infile.is_open()) {
            while (!infile.eof()) {
                getline(infile, line);
                stringstream mystream(line);// to parse through the space seperated line
                getline(mystream, record_number, ' ');
                int record = stoi(record_number);
                getline(mystream, ID, ' ');
                int id_number = stoi(ID);
                getline(mystream, first_name, ',');
                getline(mystream, last_name, ' ');
                string full_name = last_name + ',' + first_name;
                getline(mystream, email, ' ');
                getline(mystream, units, ' ');
                getline(mystream, program, ' ');
                getline(mystream, level, ' ');
                getline(mystream, no_absent, ' ');
                int nAbsent = stoi(no_absent);
                Linked_node<T>* new_node = new Linked_node<T>;
                Data& mydata = new_node->get_data();
                mydata.set_data(record, id_number, full_name, email, units, program, level);
                for (; nAbsent > 0; nAbsent--) {
                    getline(mystream, date_of_absent, ' ');
                    mydata.set_absent(date_of_absent);
                }
                new_node->set_data(mydata);
                insert_at_front(new_node);
            }
        }
        infile.close();
    }
    Linked_list() {
        head = NULL;
    }
    void edit_absent() {
        Linked_node<T>* temp = head;
        temp = head;
        string target_name;
        string target_date;
        cout << "enter the student name you want to edit: " << endl;
        cin >> target_name;
        while (temp != nullptr) {
            if (temp->get_name() == target_name) {
                cout << "enter the date you want to edit: mm-dd-yyy" << endl;
                cin >> target_date;
                temp->edit_absent_node(target_date);
            }
            temp = temp->get_next();
        }

    }
    void insert_at_front(Linked_node<T>* node) {
        cout << endl << "insert: " << node->get_name();
        if (head == nullptr) {
            head = node;
            return;
        }
        node->set_next(head);
        head = node;
        return;
    }
    void print_Linked_list() {
        Linked_node<T>* temp = NULL;
        temp = head;
        while (temp != nullptr) {
            cout << temp->get_data();
            temp = temp->get_next();
        }
    }
    void clear_list() {
        Linked_node<T>* temp = nullptr;
        Linked_node<T>* node_to_delete = nullptr;

        temp = head;
        while (temp != nullptr) {
            temp->clear_data();
            node_to_delete = temp;
            temp = temp->get_next();
            free(node_to_delete);
        }
        head = nullptr;
    }
private:
    Linked_node<T>* head;
};

int main(void) {
    Linked_list<Data> mylinked_list;
    int option = 0;
    int option_report = 0;
    int amount_absent = 0;
   while (option != 7) {
       cout << "choose an option: " << endl;
       cout << "option 1: Import course list" << endl;
       cout << "option 2: Load master list" << endl;
       cout << "option 3: Store master list" << endl;
       cout << "option 4: Mark absences" << endl;
       cout << "option 5: BONUS: Edit absences" << endl;
       cout << "option 6: Generate report" << endl;
       cout << "option 7: Exit" << endl;
       cin >> option;
        switch (option) {
        case 1:
            mylinked_list.clear_list();
            mylinked_list.read_from_file();
            break;
        case 2:
            mylinked_list.clear_list();
            mylinked_list.read_content();
            mylinked_list.print_Linked_list();
            break;
        case 3:
            mylinked_list.store_content();
            break;
        case 4:
            mylinked_list.mark_absent();
            mylinked_list.print_Linked_list();
            break;
        case 5:
            mylinked_list.edit_absent();
            mylinked_list.print_Linked_list();
            break;
        case 6:
            cout << endl;
            cout << "1. recent absent" << endl;
            cout << "2. absent of desired number" << endl;
            cout << "which report do you want to choose: 1/2 ";
            cin >> option_report;
            if (option_report == 1) {
                mylinked_list.generate_report_option_1();
            }
            if (option_report == 2) {
                cout << endl;
                cout << "enter no of absences to search: ";
                cin >> amount_absent;
                if (amount_absent >= 0) {
                    mylinked_list.generate_report_option_2(amount_absent);
                }
            }
            break;
        case 7:
            break;
        }
    }
    return 0;
}