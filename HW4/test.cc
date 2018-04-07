#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <vector> 
#include "handler.h"
#include "runner.h"
#include "unserParser.h"
#include "hw4.h"
#include <string>
#include <cassert>
using namespace std;

int main(){
	//hw4 E;
    short case01 = 5;						//"s" "\x05"
	ostringstream oss;
	serialize(case01,oss);
	assert(oss.str() == "s\x05");
	cout << oss.str() << '\n';
	oss.str("");

	bool case02	= true;					//	"t"
	serialize(case02,oss);
	assert(oss.str() == "t");
	cout << oss.str() << '\n';
	oss.str("");

	bool case03	= false;					//	"f"
	serialize(case03,oss);
	assert(oss.str() == "f");
	cout << oss.str() << '\n';
	oss.str("");

	short case04 = -12;						//"s" "\x1f\xf4"
	serialize(case04,oss);
	assert(oss.str() == "s" "\x1f\xf4");
	cout << oss.str() << '\n';
	oss.str("");

	short	case05 = 32767;					//	"s" "\x20\x7f\xff"
	serialize(case05,oss);
	assert(oss.str() == "s" "\x20\x7f\xff");
	cout << oss.str() << '\n';
	oss.str("");

	short	case06 = -32768;					//	"s" "\x2f\x80\x0"s
	serialize(case06,oss);
	assert(oss.str() == "s" "\x2f\x80\x0"s);
	cout << oss.str() << '\n';
	oss.str("");

	short	case07 = 0;						//"s" "\x0"s
	serialize(case07,oss);
	assert(oss.str() == "s" "\x0"s);
	cout << oss.str() << '\n';
	oss.str("");

	int case08 = 2147483647;					//"i" "\x40\x7f\xff\xff\xff"
	serialize(case08,oss);
	assert(oss.str() == "i" "\x40\x7f\xff\xff\xff");
	cout << oss.str() << '\n';
	oss.str("");

	int	case09 = -2147483648;					//"i" "\x4f\x80\x0\x0\x0"s
	serialize(case09,oss);
	assert(oss.str() == "i" "\x4f\x80\x0\x0\x0"s);
	cout << oss.str() << '\n';
	oss.str("");
	
	int	case10 = 32768;						//"i" "\x20\x80\x0"s
	serialize(case10,oss);
	cout <<"testing" "s" "\x2f\x80\x0"s << "case10 " << oss.str() << '\n';
	assert(oss.str() == "i" "\x20\x80\x0"s);
	oss.str("");

	int	case11 = -32769;						//"i" "\x2f\x7f\xff"
	serialize(case11,oss);
	assert(oss.str() == "i" "\x2f\x7f\xff");
	cout << oss.str() << '\n';
	oss.str("");

	int	case12 = 111222333;					//"i" "\x36\xa1\x1e\3d"
	serialize(case12,oss);
	assert(oss.str() == "i" "\x36\xa1\x1e\x3d");
	cout << oss.str() << '\n';
	oss.str("");
	
	long	case13 = 9223372036854775807;		//		"l" "\x80\x7f\xff\xff\xff\xff\xff\xff\xff"
	serialize(case13,oss);
	assert(oss.str() == "l" "\x80\x7f\xff\xff\xff\xff\xff\xff\xff");
	cout << oss.str() << '\n';
	oss.str("");

	long	case14 = (-9223372036854775807 - 1);	//			"l" "\x8f\x80\x0\x0\x0\x0\x0\x0\x0"s
	serialize(case14,oss);
	assert(oss.str() == "l" "\x8f\x80\x0\x0\x0\x0\x0\x0\x0"s);
	cout << oss.str() << '\n';
	oss.str("");

	long	case15 = 1222333444555;			//		"l" "\x51\x1c\x98\xc0\x31\xcb"
	serialize(case15,oss);
	cout<<"case15 " << oss.str() << '\n';
	string t15 = "l" "\x51\x1c\x98\xc0\x31\xcb";
	cout << "testing "<< t15 << '\n';
	assert(oss.str() == "l" "\x51\x1c\x98\xc0\x31\xcb");
	cout<<"case15 " << oss.str() << '\n';
	oss.str("");

	char	case16 = ' ';					//"c" "\x20"
	serialize(case16,oss);
	assert(oss.str() == "c" "\x20");
	cout<<"case16 " << oss.str() << '\n';
	oss.str("");

	char	case17 = '	';					//"c" "\x09"
	serialize(case17,oss);
	assert(oss.str() == "c" "\x09");
	cout<<"case17 " << oss.str() << '\n';
	oss.str("");

	char	case18 = '^';						//"c" "\x5e"
	serialize(case18,oss);
	assert(oss.str() == "c" "\x5e");
	cout <<"case18 " << oss.str() << '\n';
	oss.str("");

	string	case19 = "TESTING string1.";		//		"S" "\x10\x10" "TESTING string1."
	string	case20 = "TESTING string with tab	.";//		"S" "\x10\x19" "TESTTING string with tab	."
	
    
}


// int main(){
//     cout << "serialized!\n";
//     ostringstream oss; 
//     bool t = true;
//     serialize(t,oss);
//     assert(oss.str()=="t");

//     ostringstream osssh; 
//     serialize(short(8), osssh);		  // ctor “cast”
//     assert(osssh.str() == "s" "\x10\x08");

//     ostringstream ossi;
//     serialize(int(8),ossi);
//     assert(ossi.str() == "i" "\x10\x08");

//     oss.str("");
//     serialize(0x123456789abcdef0L, oss);
//     assert(oss.str() == "l\x80\x12\x34\x56\x78\x9a\xbc\xde\xf0"s);

//     oss.str("");
//     serialize('c',oss);
//     assert(oss.str() == "\x63\x63"s);

//     oss.str("");
//     string str = "Jack";
//     serialize(str,oss);
//     assert(oss.str() == "\x53\x04\x4a\x61\x63\x6b"s);
    
//     cout << "\nunserialized!\n";
//     bool b1, b2;
//     istringstream iss;
//     iss.str("tf");
//     unserialize(iss, b1); unserialize(iss, b2); assert(b1 && !b2);

//     istringstream isss;
//     string st;
//     isss.str("S\x10\x0c"s "kakistocracy");
//     unserialize(isss, st); assert(st == "kakistocracy");

//     istringstream issc;
//     char c;
//     issc.str("\x63\x21"s);
//     unserialize(issc, c); assert (c == '!');

//     istringstream iss2;
//     int i;
//     iss2.str({'i', '\x2e', '\x1d', '\xc0'});
//     unserialize(iss2, i); assert(i == -123456);
    
//     istringstream iss3;
//     short s;
//     iss3.str({'s', '\x1f','\xac'});
//     unserialize(iss3, s); assert(s == -84);

//     //6c 41 c8 f6 5a 34
//     istringstream iss4;
//     long l;
//     iss4.str({'l', '\x41', '\xc8', '\xf6', '\x5a', '\x34'});
//     unserialize(iss4, l); assert(l == 7666555444);
//     //iss.str("");


// }
    // bool	case21 = "f" "s"s "\x05";			//		0
	// short	case22 = 5
	// bool	case01 = "t" "s"s "\x1f\xf4";		//		1
	// short							//-12
	// short	"s"s "\x20\x7f\xff";		//		32767
	// short 	"s" "\x2f\x80\x0"s;		//		-32768
	// short	"s" "\x0"s;				//	0
	// int	"i" "\x40\x7f\xff\xff\xff";	//		2147483647
	// int	"i" "\x4f\x80\x0\x0\x0"s;	//		-2147483648
	// int	"i" "\x20\x80\x0"s;			//	32768
	// int	"i" "\x2f\x7f\xff";  		//	-32769
	// int	"i" "\x37\x5b\xcd\x15";		//		123456789
	// long	"l" "\x80\x7f\xff\xff\xff\xff\xff\xff\xff";	//9223372036854775807
	// long	"l" "\x8f\x80\x0\x0\x0\x0\x0\x0\x0"s;		//-9223372036854775808
	// long	"l" "\x8f\xf2\x1f\xae\x74\x50\x49\x11\xcc";	//-999888777666555444
	// char	"c" "\x7e";				//	'~'
	// char	"c" "\x7c";				//	'|'
	// char	"c" "\x2f";				//	'/'
	// string	"S" "\x05" "test.";		//		"test."
	// string	"S" "\x10\x19" "testing STRING with tab	.";	//"testing STRING with tab	."
	// lessbyte"i" "\x30\x09\xfb";				//<error msg : insufficient bytes>		actual bytes : "\x30\x09\xfb\xf1"
	// wrg tag	"s" "\x30\x09\xfb\xf1";			//	<error msg : wrong tag>				actual tag : "i"