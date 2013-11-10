#pragma once

#include "Preamble.hpp"

namespace ROOTFINDER {

    class function {

        public:
            virtual double evaluate(double x) = 0;
            virtual double first_derivative(double x) = 0;
            virtual double second_derivative(double x) = 0;
            void plot_over_range(double x_min, double x_max, int n_points, ofstream *output);
    };

    class f1 : public function {

        public:
            f1();
            double evaluate(double x);
            double first_derivative(double x);
            double second_derivative(double x);
    };

    class f2 : public function {

        public:
            f2();
            double evaluate(double x);
            double first_derivative(double x);
            double second_derivative(double x);
    };

}

