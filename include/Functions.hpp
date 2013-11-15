#pragma once

#include <iostream>
#include <fstream>

namespace ROOTFINDER {

    /** \brief A scaffold class to build functions from. 
     * 
     *  Functions to be used by Rootfinders should derive 
     *  from this and their definition as well as first 
     *  and second derivatives should be specified.
     *
     */
    class Function {

        public:
            /** Virtual destructor is necessary to be able 
             *  to delete pointers to derived classes when 
             *  they go out of scope
             */
            virtual ~Function(){}

            /** \brief Contains the definition of f(x), to be 
             *      overloaded by the derived classes.
             *  \param x value for which the function is to be 
             *      evaluated.
             */
            virtual double evaluate(double x);

            /** \brief Contains the definition of the first derivative
             *      of the function. To be overloaded by the derived
             *      classes.
             *  \param x value for which the first derivative is to
             *      be evaluated.
             */
            virtual double first_derivative(double x);

            /** \brief Contains the definition of the second derivative
             *      of the function. To be overloaded by the derived
             *      classes.
             *  \param x value for which the second derivative is to be
             *      evaluated.
             */
            virtual double second_derivative(double x);
            
            /** \brief Writes the values of a function to the specified 
             *      output stream over some range in a format that is
             *      readable by plotCurve.py.
             *  \param x_min lower bound of the range that is to be plotted.
             *  \param x_max upper bound of the range that is to be plotted.
             *  \param n_points number of points that are to be plotted in
             *      the range specified.
             *  \param output pointer to the output stream that is to contain
             *      the data to be plotted.
             */
            void plot_over_range(double x_min, double x_max, int n_points, std::ofstream *output);
    };

    /// \brief First function for which the roots should be found
    class f1 : public Function {

        public:
            f1();
            /** \brief defines f(x) = x³ - 2.1 x² - 7.4 x + 10.2
             *  \param x free parameter in f.
             */
            double evaluate(double x);

            /** \brief defines f'(x) = 3 x² - 4.2 x - 7.4
             *  \param x free parameter in f'.
             */
            double first_derivative(double x);

            /** \brief defines f''(x) = 6 x - 4.2 
             *  \param x free parameter in f''.
             */
            double second_derivative(double x);
    };

    /// \brief Second function for which the roots should be found
    class f2 : public Function {

        public:
            f2();

            /** \brief defines f(x) = exp(x) - 2
             *  \param x free parameter in f.
             */
            double evaluate(double x);

            /** \brief defines f'(x) = exp(x)
             *  \param x free parameter in f'.
             */
            double first_derivative(double x);
            
            /** \brief defines f''(x) = exp(x)
             *  \param x free parameter in f''.
             */
            double second_derivative(double x);
    };

}

