#include "helpers.hpp"

namespace ROOTFINDER {

    /* 
       double function::evaluate(double x) {

       }
       double function::first_derivative(double x) {

       }
       double function::second_derivative(double x) {

       }*/

    void function::plot_over_range(double x_min, double x_max, int n_points, ofstream * output) {

        double x = x_min;
        double stepsize = (x_max - x_min)/(double)n_points;
        while (x <= x_max) {
            *output << this->evaluate(x) << endl;
            x += stepsize;
        }
    }


    /* ****     f1      **** */

    f1::f1()
    {

    }


    double f1::evaluate(double x) {
        return x * x * x - 2.1 * x * x - 7.4 * x + 10.2;
    }
    double f1::first_derivative(double x) {
        return 3 * x * x - 4.2 * x - 7.4;
    }
    double f1::second_derivative(double x) {
        return 6 * x - 4.2;
    }

    /* ****     f2      **** */

    f2::f2(){

    }

    double f2::evaluate(double x) {
        return exp(x) - 2;
    }
    double f2::first_derivative(double x) {
        return exp(x);
    }
    double f2::second_derivative(double x) {
        return exp(x);
    }

}
