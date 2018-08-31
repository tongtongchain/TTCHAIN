#pragma once 
namespace thinkyoung { 
    namespace client { 
#ifndef ALP_TEST_NETWORK 
    static const std::vector<std::string> SeedNodes = {
"1.201.140.92:62896","13.70.1.63:62896","52.52.145.243:62896","18.184.132.63:62896"
 }; 
#else 
 static const std::vector<std::string> SeedNodes { }; 
#endif
} 
} // thinkyoung::client 
