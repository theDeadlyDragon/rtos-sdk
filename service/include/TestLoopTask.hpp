#pragma once
#include "LoopTask.hpp"


class TestLoopTask : public LoopTask
{
private:
    /* data */
public:
    TestLoopTask(int a);
    ~TestLoopTask();

    void on_loop() override;
};


