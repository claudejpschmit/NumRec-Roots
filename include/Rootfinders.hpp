#pragma once

#include <iostream>

namespace ROOTFINDER {

    class Rootfinder {

        public:
            virtual double foo() = 0;
    };

    class BisectionMethod : public Rootfinder {

        public:
            BisectionMethod();
            double foo();
    };

    class NRMethod : public Rootfinder {

        public:
            NRMethod();
            double foo();
    };
}
