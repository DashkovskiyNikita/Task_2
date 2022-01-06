#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
string get_value(const string message);
void console_output(int* const numbers,const int n,const int col);
void file_output(int* const numbers, const int n, const int col);

void read_file(int& n) {
    string path = get_value("Enter file path : ");
    ifstream input(path);
    if (input.fail()) {
        cout << "Wrong file path,try again" << endl;
        read_file(n);
    }
    input >> n;
    input.close();
}
string get_value(const string message) {
    string path;
    cout << message;
    cin >> path;
    return path;
}
char get_output_type() {
    char value;
    cout << "Enter type of result output : ";
    cin >> value;
    return value;
}
int get_col_number() {
    int value;
    cout << "Enter number of columns in output table : ";
    cin >> value;
    return value;
}
void find_prime_numbers(int* const numbers,const int n) {
    cout << "Searching prime numbers..." << endl;
    for (int i = 0; i < n + 1; i++) numbers[i] = i;
    numbers[1] = 0;
    for (int i = 2; i < n + 1; i++) {
        if (numbers[i]) {
            for (int p = i * 2; p < n + 1; p += i) {
                numbers[p] = 0;
            }
        }
    }
    cout << "Searching finished" << endl;
}
// c - console output
// f - file output
void result_output(int* const numbers,const int n) {
    char type = get_output_type();
    int col = get_col_number();
    switch (type) {
    case 'c': 
        console_output(numbers,n,col);
        break;
    case 'f' :
        file_output(numbers,n,col);
        break;
    }
}
void console_output(int* const numbers,const int n,const int col) {
    int num = 0;
    cout << left;
    for (int i = 0; i <= n; i++) {
        int value = numbers[i];
        if (value) {
            num++;
            cout << setw(10) << value;
            if (col == num) {
                cout << "\n" << left;
                num = 0;
            }
        }
    }
}
void file_output(int* const numbers, const int n, const int col) {
    int num = 0;
    string write_path = get_value("Enter write path : ");
    string file_name = get_value("Enter file name : ");
    ofstream out(write_path + "\\" + file_name);
    out << left;
    for (int i = 0; i <= n; i++) {
        int value = numbers[i];
        if (value) {
            num++;
            out << setw(10) << value;
            if (col == num) {
                out << "\n" << left;
                num = 0;
            }
        }
    }
    cout << "Result succesfully wrote in file" << endl;
}
int main()
{
    //test read file 
    //C:\Users\PC-Home\Desktop\testfile.txt
    //test write file path
    //C:\Users\PC-Home\Documents
    //test write file name
    //fileoutput.txt
    int N = 0;
    while (true) {
        read_file(N);
        int* numbers = new int[N + 1];
        find_prime_numbers(numbers, N);
        result_output(numbers, N);
        string input;
        cout << "Do you want to exit? Yes/No? : ";
        cin >> input;
        if (input == "Yes") exit(1);
    }
}
