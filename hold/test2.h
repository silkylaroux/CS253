#ifndef TESTDRIVER
#define TESTDRIVER


    std::vector<std::string> parse(std::string str);

    //char check_tag_num(long num);
    //std::string string_from_num(long input);
    std::string print_vector(std::vector<std::string> vec);
    
    class Vnum{
        public:
            std::string get_vnum();
            Vnum(std::string str);
        private:
            
            std::string vnum;
            void make_vnum(std::string str);
            
        };


#endif