#pragma once

#include "Functions.hpp"
#include <iostream>

namespace ROOTFINDER {

    class Rootfinder {

        public:
            virtual ~Rootfinder() {}
            virtual double find_in_range(double x_min, double x_max, double precision) = 0;
            int get_stepcount();
        protected:
            function *f;
            int stepcount;
    };

    class BisectionMethod : public Rootfinder {

        public:
            BisectionMethod(function *f);
            double find_in_range(double x_min, double x_max, double precision);

        private:
            int sign(double number);
    };

    class NRMethod : public Rootfinder {

        public:
            NRMethod(function *f);
            double find_in_range(double x_min, double x_max, double precision);
    };
}
