#include<iostream>
#include<string>
using namespace std;

int main () {
    //std::string sPei = std::string("imei-10310140000120");
    std::string sPei = std::string("imei-103101400000120");
       if (int pos = sPei.find("imei-") != std::string::npos) {
       std::cout << "pos: " << pos << std::endl;
       std::string subStr = sPei.substr(pos+5);
       char *end;
       unsigned long peiImei = std::strtoul(subStr.c_str(), &end, 10);
    //pInLuaStructurePtr->servedPeiImei = peiImei;
    std::cout << "pei: " << peiImei << std::endl;
    }else if (int pos = sPei.find("imeisv-") != std::string::npos) {
    std::string subStr = sPei.substr(pos+7);
    char *end;
    unsigned long peiImeisv = std::strtoul(subStr.c_str(), &end, 10);
    std::cout << "peiImeisv: " << peiImeisv << std::endl;
    // pInLuaStructurePtr->servedPeiImeiSv = peiImeisv;
    }else {
    std::string subStr = sPei.substr(5);
    unsigned short mac = std::stoi(subStr);
    std::cout << "mac: " << mac << std::endl;
    //pInLuaStructurePtr->servedPeiMac = mac;
    }
    std::string subId = std::string("imsi-405050000000620");
    if (int pos = subId.find("imsi-") != std::string::npos) {
        std::string imsiPrefix = subId.substr(0,4);
        std::string imsi = subId.substr(pos+5);
        std::cout << "imsiPre: " << imsiPrefix << std::endl;
        std::cout << "imsi: " << imsi << std::endl;
        //TODO: Need to check for filling of ImsiPrefix
        //            pInLuaStructurePtr->supiImsi = std::stoull(imsi);
    } else {
        pos = subId.find("@");
        std::string supiNai = subId.substr(0, pos-1);
        std::string supiNaiDomain = subId.substr(pos+1);
        //           strcpy((char*)pInLuaStructurePtr->supiNai.buff,supiNai.c_str());
        //          strcpy((char*)pInLuaStructurePtr->supiNaiDomain.buff,supiNaiDomain.c_str());
    }


}


