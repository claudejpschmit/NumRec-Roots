#pragma once

#include "Functions.hpp"
#include <iostream>

namespace ROOTFINDER {
    
    /** \brief A scaffold class to build Rootfinders from. 
     * 
     *  Functions to be used by Rootfinders should derive 
     *  from this and their definition as well as first 
     *  and second derivatives should be specified.
     *
     */

    class Rootfinder {

        public:
            
            /** Virtual destructor is necessary to be able 
             *  to delete pointers to derived classes when 
             *  they go out of scope
             */
            virtual ~Rootfinder() {}

            /** \brief Function to be overloaded with the algorithm 
             *      which finds the root in given range up to a given 
             *      precision.
             *  \param x_min lower bound of the range.
             *  \param x_max upper bound of the range.
             *  \param precision how precise we want the result to be.
             */
            virtual double find_in_range(double x_min, double x_max, double precision) = 0;

            /// \brief Gets the Number of steps needed to produce the result.
            int get_stepcount();

        protected:

            /// pointer to the function for which the roots should be found.
            function *f;

            /// Number of steps needed to produce the result
            int stepcount;
    };

    /// \brief Defines the Bisection Method
    class BisectionMethod : public Rootfinder {

        public:

            /** \brief Constuctor that defines the function to be examined.
             *  \param f pointer to the function that is to be examined.
             */
            BisectionMethod(function *f);

            /** \brief Bisection Method algorithm to find a single root
             *      within a range up to a certain precision.
             *  \param x_min lower bound of the range.
             *  \param x_max upper bound of the range.
             *  \param precision how precise we want the result to be.
             */
            double find_in_range(double x_min, double x_max, double precision);

        private:
            
            /** \brief returns the sign of a number.
             *  \param number sign of which is returned.
             */
            int sign(double number);
    };

    /// \brief Defines the Newton Raphson Method
    class NRMethod : public Rootfinder {

        public:

            /** \brief Constructor that defines the function to be examined.
             *  \param f pointer to the function that is to be examined.
             */
            NRMethod(function *f);
            
            /** \brief Newton Raphson Method algorithm to find a single root
             *      within a range up to a certain precision. Initial guess 
             *      is taken to be the midpoint of the range
             *  \param x_min lower bound of the range.
             *  \param x_max upper bound of the range.
             *  \param precision how precise we want the result to be.
             */
            double find_in_range(double x_min, double x_max, double precision);
    };
}
