#pragma once
#include "Task.hpp"


class TestTask : public Task
{
private:
    /* data */
public:
    TestTask(int a);
    ~TestTask();

    void on_loop() override;
};


