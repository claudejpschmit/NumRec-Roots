#pragma once

#include <iostream>
#include <fstream>

namespace ROOTFINDER {

    class function {

        public:
            virtual ~function(){}
            virtual double evaluate(double x);
            virtual double first_derivative(double x);
            virtual double second_derivative(double x);
            void plot_over_range(double x_min, double x_max, int n_points, std::ofstream *output);
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

