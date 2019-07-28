#include <iostream>
#include <random>
#include "TrafficLight.h"

/* Implementation of class "MessageQueue" */

template <typename T>
T MessageQueue<T>::receive()
{
    std::unique_lock<std::mutex> ulock(_mutex);
    _cndv.wait(ulock);
    T msg = _queue.back();
    _queue.pop_back();
    return msg;
}

template <typename T>
void MessageQueue<T>::send(T &&msg)
{
    std::lock_guard<std::mutex> lckg (_mutex);
    _queue.push_back(msg);
    _cndv.notify_one();
}

/* Implementation of class "TrafficLight" */
void TrafficLight::waitForGreen()
{
    while(true){
        if(messageQueue.receive() == TrafficLightPhase::green)return;
    }
}
void TrafficLight::simulate()
{
    threads.emplace_back(std::thread(&TrafficLight::cycleThroughPhases, this));
}

void TrafficLight::cycleThroughPhases()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(4, 6); // define the range
    int sleepTime = 0;
    while(true){
        sleepTime = distr(eng);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime*1000));
        //Toggle state after two cycles
        if(_toggleCycle){
            if(_currentPhase == TrafficLightPhase::green)_currentPhase = TrafficLightPhase::red;
            else _currentPhase = TrafficLightPhase::green;
            _toggleCycle = false;
        }else{
            _toggleCycle  = true;
        }
        messageQueue.send(std::move(_currentPhase));
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}