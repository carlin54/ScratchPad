#include <iostream>
#include <ctime>


using namespace std;

class A {
public:
    inline void Func(){

    }
};

class B {
public:
    virtual void Func() = 0;
};

class C : public B {
public:
    virtual void Func(){

    }
};

int main(){

    std::cout << "Test A: " << std::flush;
    A a;
    clock_t aStartTime = clock();
    for(unsigned i = 1; i != 0; i++){
		a.Func();
    }
    clock_t aEndTime = clock();
    std::cout << aEndTime - aStartTime << std::endl;


    std::cout << "Test B: " << std::flush;
    C c;
    clock_t cStartTime = clock();
    for(unsigned i = 1; i != 0; i++){
        c.Func();
    }
    clock_t cEndTime = clock();
    std::cout << cEndTime - cStartTime << std::endl;
    
    std::cout << "Result: " << (float(aEndTime - aStartTime) / float(cEndTime - cStartTime)) * 100.0f << "%" << std::endl;
    std::cin.get();
    std::cin.get();
	
	
	
    return 0;
}
