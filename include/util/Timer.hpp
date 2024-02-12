#pragma once
#include <chrono>


namespace th {


    class Timer {

        private:            
            std::chrono::duration<double> duration;
            std::chrono::system_clock::time_point startTime;
            bool isRunning_;

        public:
            Timer(double duration);
            void stop();
            void start();
            bool tick();
            bool isRunning();

    };

    
} // namespace th
