#include <iostream>
#include <fstream>
using namespace std;


struct Node {
    int data;
    Node *ptr_to_next = nullptr;
    Node *ptr_to_prev = nullptr;
};


struct List {
    Node *ptr_to_first = nullptr;
    Node *ptr_to_last = nullptr;


    void init() {
        ptr_to_first = nullptr;
        ptr_to_last = nullptr;
    }


    bool is_empty() {
        return ptr_to_first == nullptr;
    }


    int get_length() {
        if (is_empty()) {
            return 0;
        }
        else {
            Node *tmp = new Node;
            int counter = 1;
            tmp = ptr_to_first;
            while (tmp -> ptr_to_next != nullptr) {
                counter++;
                tmp = tmp -> ptr_to_next;
            }
            return counter;
        }
    }


    void push_back(int value) {
        Node *tmp = new Node;
        tmp -> data = value;
        if (is_empty()) {
            ptr_to_first = tmp;
            ptr_to_last = tmp;
        }
        else {
            ptr_to_last -> ptr_to_next = tmp;
            tmp -> ptr_to_prev = ptr_to_last;
            ptr_to_last = tmp;
        }
    }


    int pop(int index) {
        int list_length = get_length();
        if (!(is_empty()) && index < list_length && index >= 0) {
            Node *tmp = ptr_to_first;
            for (int i = 0; i < index; i++) {
                tmp = tmp -> ptr_to_next;
            }
            if (index == 0) {
                if (list_length == 1) {
                    ptr_to_first = nullptr;
                    ptr_to_last = nullptr;
                }
                else {
                    tmp -> ptr_to_next -> ptr_to_prev = tmp -> ptr_to_prev;
                    ptr_to_first = tmp -> ptr_to_next;
                    
                }
            }
            else if (index == list_length - 1) {
                tmp -> ptr_to_prev -> ptr_to_next = tmp -> ptr_to_next;
                ptr_to_last = tmp -> ptr_to_prev;
            }
            else {
                tmp -> ptr_to_prev -> ptr_to_next = tmp -> ptr_to_next;
                tmp -> ptr_to_next -> ptr_to_prev = tmp -> ptr_to_prev;
            }
            int deleted_value = tmp -> data;
            delete tmp;
            return deleted_value;
        }
        cout << "�� ������� �������� ������ �� ������� �������. ���������� �������� 0." << endl;
        return 0;
    }


    void add_value_by_position(int pos) {
        Node *new_node = new Node;
        Node *tmp = ptr_to_first;
        int list_length = get_length();
        if (pos <= list_length + 1 && pos > 0) {
            int index = pos - 1;
            for (int i = 0; i < index; i++) {
                tmp = tmp -> ptr_to_next;
            }
            int value;
            cout << "������� �������� ��������:" << endl;
            cin >> value;
            new_node -> data = value;
            if (index == 0 && is_empty()) {
                ptr_to_first = new_node;
                ptr_to_last = new_node;
            }
            else if (index == 0) {
                ptr_to_first -> ptr_to_prev = new_node;
                new_node -> ptr_to_next = ptr_to_first;
                ptr_to_first = new_node;
            }
            else if (index == list_length) {
                ptr_to_last -> ptr_to_next = new_node;
                new_node -> ptr_to_prev = ptr_to_last;
                ptr_to_last = new_node;
            }
            else {
                new_node -> ptr_to_prev = tmp -> ptr_to_prev;
                new_node -> ptr_to_next = tmp;
                tmp -> ptr_to_prev -> ptr_to_next = new_node;
                tmp -> ptr_to_prev = new_node;
            }
        } 
    }


    void write_in_file() {
        int list_length = get_length();
        ofstream out;
        out.open("file_11_2.txt");
        if (out.is_open()) {
            for (int i = 0; i < list_length; i++) {
                out << pop(0) << endl;
            }
        }
        out.close();
    }


    void resotre_from_file(List list) {
        ifstream in; 
        in.open("file_11_2.txt");
        int value;
        while (in >> value) {
            push_back(value);
        }
        in.close();
    }


    void show_list() {
        if (is_empty()) {
            cout << "������ ������." << endl;
        }
        else {
            Node *tmp = ptr_to_first;
            cout << tmp -> data;
            int list_length = get_length();
            if (list_length > 1) {
                for (int i = 1; i < list_length; i++) {
                    tmp = tmp -> ptr_to_next; 
                    cout << " " << tmp -> data;
                }
            }
            cout << endl;
        }
    }
};





int main() {
    setlocale(LC_ALL, "RUS");
    List *list_of_nums = new List;
    list_of_nums -> init();
    int number_of_values, new_value;
    cout << "������� ���������� ��������, ������� ����� ����������� � ������:" << endl;
    cin >> number_of_values;
    for (int i = 0; i < number_of_values; i++) {
        cout << "������� ��������:" << endl;
        cin >> new_value;
        list_of_nums -> push_back(new_value);
    }

    cout << "������ ����� ����������:" << endl;
    list_of_nums -> show_list();

    int number_of_changes, pos;
    cout << "������� ����� K - ���������� ���������, ������� ����� �������/���������:" << endl;
    cin >> number_of_changes;
    cout << "������� ����� ��������, � �������� ����� ������� K ���������:" << endl;
    cin >> pos;
    for (int i = 0; i < number_of_changes; i++) {
        cout << "������� �������: " << list_of_nums -> pop(pos - 1) << endl;
    }
    
    cout << "������ ����� �������� K ���������:" << endl;
    list_of_nums -> show_list();

    cout << "������� ����� ��������, � �������� ����� �������� K ���������:" << endl;
    cin >> pos;
    for (int i = 0; i < number_of_changes; i++) {
        list_of_nums -> add_value_by_position(pos);
        pos++;
    }
    
    cout << "������ ����� ���������� K ���������:" << endl;
    list_of_nums -> show_list();

    list_of_nums -> write_in_file();
    delete list_of_nums;
    cout << "������ ������� � ���� � ������ �� ������." << endl;

    cout << "���������� �����:" << endl;
    ifstream in("file_11_2.txt");
    if (in.is_open()) {
        int x;
        while (in >> x) {
            cout << x << " ";
        }
        cout << endl;
    }
    in.close();

    List *restored_list_of_nums = new List;
    restored_list_of_nums -> init();
    cout << "������ ����� ������." << endl;

    restored_list_of_nums -> resotre_from_file(*restored_list_of_nums);
    cout << "���������� ������, ����� ������ ������ �� �����:" << endl;
    restored_list_of_nums -> show_list();

    return 0;
}