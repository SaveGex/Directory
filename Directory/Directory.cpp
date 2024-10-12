#include <iostream>
#include <string>
#include <vector>
using namespace std;


template<class T1>
vector<T1> directory(T1 dir);

int main() {
    string dir;

    cout << "Write directory: \n";
    getline(cin, dir);
    vector<string> processed = directory<string>(dir);
    for (auto i : processed) {
           cout << i << '\n';
    }

}




template<class T1>
vector<T1> directory(T1 dir) {
    vector<T1> array;
    if (!dir.empty()) {

        // version of task "a"
        string buffer;
        int index = 0;
        dir = dir.c_str();

        for (int i = 0; i < strlen(dir.c_str()); i++) {
            buffer.push_back(dir[i]);
            bool is_backslash_ahead = true;

            for (int j = buffer.length(); j < dir.length(); j++) {

                if (dir[j] == '\\' || dir[j] == '/') {
                    is_backslash_ahead = false;
                    break;
                }

            }

            if (is_backslash_ahead == true) {
                buffer.pop_back();
                array.push_back(buffer);
                break;
            }
            index++;

        }

        // version of task "b"
        string buffer2;
        for (int i = buffer.length(); i > 0; i--) {
            if (buffer[i] != '/' && buffer[i] != '\\') {
                buffer2.push_back(buffer[i]);
            }
            else {
                break;
            }
        }
        for (int i = 0; i < buffer2.length() / 2; i++) {
            swap(buffer2[i], buffer2[buffer2.length() - i - 1]);
        }
        array.push_back(buffer2);

        // version of task "c"
        buffer = dir;
        buffer.c_str();
        buffer2.clear();

        for (int i = buffer.size(); i > 0; i--) {

            if (buffer[i] != '/' && buffer[i] != '\\') {

                buffer2.push_back(buffer[i]);
            }
            else {
                break;

            }
        }

        for (int i = 0; i < buffer2.length() / 2; i++) {
            swap(buffer2[i], buffer2[buffer2.length() - i - 1]);
        }

        array.push_back(buffer2);
        
        // version of task "d"
        buffer = dir;
        buffer2.clear();
        if (dir.find(".") != string::npos) {
            for (int i = buffer.length(); i > 0; i--) {

                if (buffer[i] != '.') {

                    buffer2.push_back(buffer[i]);
                }
                else {
                    break;
                }
            }
        }
        else {
            buffer2 = "no extension in the directory to the file";
        }
        array.push_back(buffer2);

        // version of task "e"
        buffer = dir;
        buffer2.clear();
        if (dir.find(".") != string::npos) {
            bool extention_are = true;

            for (int i = buffer.length(); i > 0; i--) {

                if (buffer[i] == '.') {
                    extention_are = false;
                }
                buffer2.push_back(buffer[i]);
                
                if (!extention_are ) {
                    break;
                }

            }
        }
        for (int i = 0; i < buffer2.length() / 2; i++) {
            swap(buffer2[i], buffer2[buffer2.length() - i - 1]);
        }
        array.push_back(buffer2);


    }
    return array;

}