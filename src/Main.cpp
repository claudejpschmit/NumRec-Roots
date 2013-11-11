#include "Functions.hpp"
#include "Rootfinders.hpp"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>


int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "This program should be run as: " 
            << argv[0] << " number_of_digits_of_precision" << std::endl;
        return -1;
    }
   
    int n_digits = std::stoi(argv[1],NULL);
   
    if (n_digits < 1 || n_digits > 15) {
        std::cout << "The number of digits need to range between 1 and 15 to adhere to the double range."
            << std::endl;
        return -1;
    }

    std::cout << std::setprecision(n_digits);
    double precision = 1.0 / pow(10.0, (double)n_digits);
        
    ROOTFINDER::f1 f1_object;
    ROOTFINDER::f2 f2_object;
    std::ofstream f1_plot, f2_plot;
    f1_plot.open("f1_plot.txt");
    f1_object.plot_over_range(-3.0,4.0,100,&f1_plot);
    f1_plot.close();

    f2_plot.open("f2_plot.txt");
    f2_object.plot_over_range(-3.0,3.0,100,&f2_plot);
    f2_plot.close();
    

    ROOTFINDER::BisectionMethod BM_f1(&f1_object);
    ROOTFINDER::BisectionMethod BM_f2(&f2_object);

    std::cout << "-------- Using BISECTION METHOD ----------" 
        << std::endl << std::endl;
    std::cout << "Root of f1 between -3 and -2 is " 
        << BM_f1.find_in_range(-3.0, -2.0, precision) << std::endl; 
    std::cout << "Bisction method needed " 
        << BM_f1.get_stepcount() << " steps." << std::endl;
    std::cout << "Root of f1 between 1 and 2 is " 
        << BM_f1.find_in_range(1.0, 2.0, precision) << std::endl; 
    std::cout << "Bisction method needed " 
        << BM_f1.get_stepcount() << " steps." << std::endl;
    std::cout << "Root of f1 between 3 and 4 is " 
        << BM_f1.find_in_range(3.0, 4.0, precision) << std::endl; 
    std::cout << "Bisction method needed " 
        << BM_f1.get_stepcount() << " steps." << std::endl;
    std::cout << "Root of f2 between 0 and 1 is " 
        << BM_f2.find_in_range(0.0, 1.0, precision) << std::endl; 
    std::cout << "Bisction method needed " 
        << BM_f2.get_stepcount() << " steps." << std::endl;

    ROOTFINDER::NRMethod NRM_f1(&f1_object);
    ROOTFINDER::NRMethod NRM_f2(&f2_object);
    
    std::cout << "-------- Using NEWTON-RAPHSON METHOD ----------" 
        << std::endl << std::endl;
    std::cout << "Root of f1 between -3 and -2 is " 
        << NRM_f1.find_in_range(-3.0, -2.0, precision) << std::endl; 
    std::cout << "Newton-Raphson method needed " 
        << NRM_f1.get_stepcount() << " steps." << std::endl;
    std::cout << "Root of f1 between 1 and 2 is " 
        << NRM_f1.find_in_range(1.0, 2.0, precision) << std::endl; 
    std::cout << "Newton-Raphson method needed " 
        << NRM_f1.get_stepcount() << " steps." << std::endl;
    std::cout << "Root of f1 between 3 and 4 is " 
        << NRM_f1.find_in_range(3.0, 4.0, precision) << std::endl; 
    std::cout << "Newton-Raphson method needed " 
        << NRM_f1.get_stepcount() << " steps." << std::endl;
    std::cout << "Root of f2 between 0 and 1 is " 
        << NRM_f2.find_in_range(0.0, 1.0, precision) << std::endl; 
    std::cout << "Newton Raphson method needed " 
        << NRM_f2.get_stepcount() << " steps." << std::endl;


    return 0;
}
