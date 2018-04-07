#ifndef SERIAL_H
#define SERIAL_H
#include<string>
using std::string;
class Serial
{
    public:
        Serial();
        void put(bool);
        void put(short);
        void put(int);
        void put(long);
        void put(char);
        void put(string);
        
        void get(bool &);
        void get(short &);
        void get(int &);
        void get(long &);
        void get(char &);
        void get(string &);

        string str();
        void str(string);

        bool empty();
        unsigned int size();
    private:
        string serStr;
        //int size;
};
#endif