#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

const std::string upp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string low = "abcdefghijklmnopqrstuvwxyz";
const std::string dig = "0123456789";
const std::string spe = "!@#$%^&*_";

class PassGenerate{
  std::random_device ran{};
public:
  std::string generate_password(size_t len, bool f_uppercase, bool f_lowercase, bool f_digits, bool f_specials){
    srand(time(nullptr));
    std::string pass = "";
    for (size_t i = 0 ; i < len / 2 + len % 2 ; i++){
      if (f_uppercase) pass += upp[rand() % upp.size()];
      if (f_lowercase) pass += low[rand() % low.size()];
      if (f_digits) pass += dig[rand() % dig.size()];
      if (f_specials) pass += spe[rand() % spe.size()];
    }

    std::random_shuffle(pass.begin(), pass.end());
    return pass.substr(0, len);
  }
};

int main(){
  PassGenerate pass;
  std::string password = pass.generate_password(15, 1, 1, 1, 1);
  std::cout << password;
}
