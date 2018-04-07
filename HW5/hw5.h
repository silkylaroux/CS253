#ifndef HW5
#define HW5
    #include<string>
    void serialize(const std::string& , std::ostream& );
    void serialize(char , std::ostream& );
    void serialize(long , std::ostream& );
    void serialize(int , std::ostream& );
    void serialize(short , std::ostream& );
    void serialize(bool , std::ostream& );
    void unserialize(std::istream&, short&);
    void unserialize(std::istream&, long&);
    void unserialize(std::istream&, int&);
    void unserialize(std::istream&, char&);
    void unserialize(std::istream&, bool&);

#endif