#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <mutex>
#include <deque>
#include <condition_variable>
#include "TrafficObject.h"

// forward declarations to avoid include cycle
class Vehicle;
enum class TrafficLightPhase {red,green};

template <class T>
class MessageQueue
{
public:
    void send(T&&);
    T receive();
private:
    std::deque<T> _queue;
    std::condition_variable _cndv;
    std::mutex _mutex;
};

class TrafficLight: public TrafficObject, public std::enable_shared_from_this<TrafficLight>
{
public:
    TrafficLight()
    {
        _currentPhase = TrafficLightPhase::red;
    }
    void waitForGreen();
    void simulate();
    TrafficLightPhase getCurrentPhase(){return _currentPhase;};
private:
    TrafficLightPhase _currentPhase;
    void cycleThroughPhases();
    std::condition_variable _condition;
    std::mutex _mutex;
    MessageQueue<TrafficLightPhase> messageQueue;
};

#endif