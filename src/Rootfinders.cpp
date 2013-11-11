#include "Rootfinders.hpp"

#include <iostream>
#include <assert.h>

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
        return 0;
    }
}
