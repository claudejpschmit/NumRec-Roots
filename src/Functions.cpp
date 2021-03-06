#include "Functions.hpp"

#include <math.h>
#include <assert.h>

namespace ROOTFINDER {


    double Function::evaluate(double x) 
    {
        // shuts warnings about unused parameters
        (void)x;
        return 0;
    }
    double Function::first_derivative(double x) 
    {
        // shuts warnings about unused parameters
        (void)x;
        return 0;
    }
    double Function::second_derivative(double x) 
    {
        // shuts warnings about unused parameters
        (void)x;
        return 0;
    }

    void Function::plot_over_range(double x_min, double x_max, int n_points, std::ofstream * output) 
    {
        // Requires the input to be valid.
        assert(x_min <= x_max);
        // Requires the output stream to be opened by user.
        assert(output->is_open());

        // Divides the range into n_points and puts data to the ouput stream.
        double x = x_min;
        double stepsize = (x_max - x_min)/(double)n_points;
        while (x <= x_max) {
            *output << x << " " << this->evaluate(x) << std::endl;
            x += stepsize;
        }
    }


    /* ****     f1      **** */

    f1::f1()
    {

    }


    double f1::evaluate(double x) 
    {
        return x * x * x - 2.1 * x * x - 7.4 * x + 10.2;
    }
    double f1::first_derivative(double x) 
    {
        return 3 * x * x - 4.2 * x - 7.4;
    }
    double f1::second_derivative(double x) 
    {
        return 6 * x - 4.2;
    }

    /* ****     f2      **** */

    f2::f2()
    {

    }

    double f2::evaluate(double x) 
    {
        return exp(x) - 2;
    }
    double f2::first_derivative(double x) 
    {
        return exp(x);
    }
    double f2::second_derivative(double x) 
    {
        return exp(x);
    }

}
