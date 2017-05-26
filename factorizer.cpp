#include <iostream>
#include <vector>
#include <limits.h>
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace std;


template<class T>
std::ostream & operator<<(std::ostream & out, const  std::vector<T>&  write){
    for(int i = 0; i < write.size(); i++){
       out << "" << write[i] << "," << std::flush;
    }
    out << std::endl;
    return out;
}

std::string get_file_contents(const char *filename)
{
  std::FILE *fp = std::fopen(filename, "rb");
  if (fp)
  {
    std::string contents;
    std::fseek(fp, 0, SEEK_END);
    contents.resize(std::ftell(fp));
    std::rewind(fp);
    std::fread(&contents[0], 1, contents.size(), fp);
    std::fclose(fp);
    return(contents);
  }
  
}

template<class T>
inline bool isPrime(T primeCheck){
    if(primeCheck % 2 == 0){
        return false;
    }else{
       for(T i = 2; i <= primeCheck / 2; i++){
            if((primeCheck % i) == 0){
                return false;
            }
        }
    }
    return true;
}

int main()
{

    const int REFRESH_RATE = 50000;
    std::fstream primesFile;


    std::stringstream out(get_file_contents("MyPrimes.txt"));
	//std::string CurrentIndex = "Current Index:[0-9]*";
    std::cin.get();
    std::vector<unsigned long long int> primes;
    std::cout << "Crunching numbers...";
    int counter = 0;


    for(unsigned long long int i = 0; i < ULLONG_MAX; i++){
        if(isPrime<unsigned long long int>(i)){
            primes.push_back(i);
        }
        if(counter >= REFRESH_RATE){
            int result = std::remove("MyPrimes.txt"); // delete file


            primesFile.open("MyPrimes.txt", std::ofstream::out | std::ofstream::trunc);
            out.str(std::string());
            out << primes;
            out << "Found:" << primes.size() << "\tCurrent Index:" << i << "\tBuffer Size:" << primes.size() * sizeof(unsigned long long int) << "bytes" << std::endl;
            primesFile << out.str();
            primesFile.close();

            std::cout << string( 80, '-' );
            std::cout << out.str();
            std::cout << string( 80, '-' );
            std::cout << "Crunching numbers... Safe to Close...";

            counter = 0;
        }
        counter++;

    }

   return 0;
}



