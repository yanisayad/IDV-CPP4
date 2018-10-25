//
// Created by Nassim EL HORMI on 28/09/2018.
//

#include "TimeManager.h"
#include <chrono>
#include <iostream>

TimeManager *TimeManager::instance = nullptr;
using namespace std::chrono;

high_resolution_clock::time_point started, updated, previous_updated, lastUpdated;

void TimeManager::Start() {
    started = std::chrono::high_resolution_clock::now();
    TimeManager::start++;
}

void TimeManager::Update() {
    lastUpdated = std::chrono::high_resolution_clock::now();
    if (TimeManager::update == 0)
    {
        updated = std::chrono::high_resolution_clock::now();
        previous_updated = lastUpdated;
        TimeManager::update++;
        return;
    }
    if (TimeManager::update >= 1)
    {
        previous_updated = updated;
        updated = std::chrono::high_resolution_clock::now();
        TimeManager::update++;
        return;
    }
}

unsigned int TimeManager::GetElapsedTime() const {
    if (TimeManager::update == 0)
    {
        return (0);
    }
    else
    {
        return static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::milliseconds>(updated - previous_updated).count());
    }
}

unsigned int TimeManager::GetStartedTime() const {
    if (TimeManager::start == 0 && TimeManager::update == 0)
    {
        return (0);
    }
    return static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::milliseconds>(lastUpdated - started).count());
}


TimeManager::~TimeManager() {
    TimeManager::update = 0;
    TimeManager::start = 0;
}


