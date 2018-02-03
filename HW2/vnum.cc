#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>

using namespace std;

int bit_size;
char tag;
int num;

int get_size(){
    return bit_size;
}

char get_tag(){
    return tag;
}



char check_tag_num(int num){
    char temp_tag;
    if(num > numeric_limits<short>::min() && num < numeric_limits<short>::max()){
        temp_tag = 's';
    }
    if(num > numeric_limits<int>::min() && num < numeric_limits<int>::max()){
        temp_tag = 'i';
    }
    if(num > numeric_limits<long>::min() && num < numeric_limits<long>::max()){
        temp_tag = 'l';
    }
    return temp_tag;
}

int main(int argc, char **argv){
    
    for(int x = 1; x < argc; x++){
        
        ifstream in_file(argv[x]);
        if(!in_file){
            cerr << " Unable to open file: "<<argv[x];
        }
        string line;
        while (getline(in_file, line))
        {
            istringstream iss(line);
            cout << line<<'\n';
        }
    }
    

return 0;
}