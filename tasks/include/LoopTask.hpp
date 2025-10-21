#pragma once
#include "Task.hpp"

class LoopTask : public Task
{
private:
    /* data */
public:
    LoopTask(std::string name, uint8_t priopirty);
    ~LoopTask();


    void run() override;
};

