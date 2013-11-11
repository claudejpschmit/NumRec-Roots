#include "Rootfinders.hpp"

#include <iostream>
#include <assert.h>
#include <cmath>

namespace ROOTFINDER {

    int Rootfinder::get_stepcount()
    {
        return stepcount;
    }

    /* ****     BisectionMethod     **** */

    BisectionMethod::BisectionMethod(function *f)
    {
        this->f = f;
    }

    int BisectionMethod::sign(double number)
    {
        if (number < 0) return -1;
        else return 1;
    }

    double BisectionMethod::find_in_range(double x_min, double x_max, double precision) 
    {

        assert(x_min < x_max);
        stepcount = 0;
        double x1 = x_min; 
        double x2 = x_max; 
        double x_centre = (x2 + x1) / 2.0;
        while ((x2 - x1) > precision) {
            if (sign(f->evaluate(x1)) == sign(f->evaluate(x_centre)))
                x1 = x_centre;
            else
                x2 = x_centre;
            x_centre = (x2 + x1) / 2.0;

            ++stepcount;
            
        }

        return x_centre;

    }

    /* ****     Newton-Raphson Method   **** */

    NRMethod::NRMethod(function *f) 
    {
        this->f = f;
    }

    double NRMethod::find_in_range(double x_min, double x_max, double precision)
    {
        stepcount = 0;
        double x_0 = (x_max + x_min) / 2.0;
        double d = - f->evaluate(x_0) / f->first_derivative(x_0);
        while (std::abs(d) > precision) {
            
            x_0 += d;
            d = - f->evaluate(x_0) / f->first_derivative(x_0);
            ++stepcount;
        }

        return x_0;
    }
}
