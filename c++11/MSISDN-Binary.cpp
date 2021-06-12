#include <iostream>       // std::cout
#include <string>       // std::cout
#include <iomanip>       // std::cout
#include <iostream>

#include <vector>
#include <cstdlib>

#include <sstream>

using namespace std;

int cnv_tbcd(const char *str, unsigned char* tbcd, int len) {
    int c = 0;
    int err = 0;
    for (c=0; c<len; c+=2) {
        tbcd[c] = (unsigned char)((((short(str[c])) << 4)& 0xf0) | short((str[c+1])));
        /*
           switch(str[c]) {
           case '*': tbcd[c]  = 0x0a; break;
           case '#': tbcd[c]  = 0x0b; break;
           case 'a': tbcd[c]  = 0x0c; break;
           case 'b': tbcd[c]  = 0x0d; break;
           case 'c': tbcd[c]  = 0x0e; break;
           default:  tbcd[c] = 0xff; err++;
           }
           */
    }
/*
    if (c % 2 == 0) {
        tbcd[c]   = 0x0f;
        tbcd[c+1] = 0;
    }
*/
    for(int i=0; i<11; i++) {
        cout << hex << setfill('0') << setw(2)<< tbcd[i];
    }
    return err;
}
std::string ToHex(const unsigned char* buffer, size_t size){
    	std::stringstream str;
	str.setf(std::ios_base::hex, std::ios::basefield);
	//str.unsetf(std::ios::showbase);
	//str.setf(std::ios::showbase);
	str.setf(std::ios_base::uppercase);
	str.fill('0');
	//str.width(2);

	for(size_t i=0; i<size; ++i){
		//str << std::hex << std::setw(2) << (unsigned short)(unsigned char)buffer[i];
		//str << (unsigned short)(unsigned char)buffer[i];
		str << std::setw(2) << (unsigned short)(unsigned char)buffer[i];
	}
	return str.str();
}


std::vector<unsigned char> HexToBytes(const std::string& hex){
	std::vector<unsigned char> bytes;

	for (unsigned int i = 0; i < hex.length(); i += 2){
		std::string byteString = hex.substr(i, 2);
		unsigned char byte = (char) strtol(byteString.c_str(), NULL, 16);
		bytes.push_back(byte);
	}

	return bytes;
}

int main() {

    std::string str{"91987654321"};
	unsigned char* tbcd = new unsigned char(20);
	memset(tbcd,0,20);
    cout << str << endl;
    cnv_tbcd(str.c_str(), tbcd, 11);
    cout << "==== " << endl;
	cout << ToHex(tbcd, 6) << endl;
    auto v = HexToBytes(str);
    string ss = "";
	for(std::vector<unsigned char>::size_type i = 0; i != v.size(); i++) {
		ss+=v[i];
	}
    memcpy(tbcd,ss.c_str(),6);
    cout << "==== " << endl;
	cout << ToHex(tbcd, 6) << endl;
	return 0;
}
