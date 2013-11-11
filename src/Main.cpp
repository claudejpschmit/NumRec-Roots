#include "Functions.hpp"
#include "Rootfinders.hpp"

#include <iostream>
#include <fstream>


int main(int argc, char *argv[])
{
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
    
    std::cout << "Root of f1 between -3 and -2 is " << BM_f1.find_in_range(-3.0, -2.0, 0.00001) << std::endl; 
    std::cout << "Found after " << BM_f1.get_stepcount() << " steps." << std::endl;
    std::cout << "Root of f1 between 1 and 2 is " << BM_f1.find_in_range(1.0, 2.0, 0.00001) << std::endl; 
    std::cout << "Found after " << BM_f1.get_stepcount() << " steps." << std::endl;
    std::cout << "Root of f1 between 3 and 4 is " << BM_f1.find_in_range(3.0, 4.0, 0.00001) << std::endl; 
    std::cout << "Found after " << BM_f1.get_stepcount() << " steps." << std::endl;
    std::cout << "Root of f2 between 0 and 1 is " << BM_f2.find_in_range(0.0, 1.0, 0.00001) << std::endl; 
    std::cout << "Found after " << BM_f2.get_stepcount() << " steps." << std::endl;


    return 0;
}
