#pragma once
#include "freertos/FreeRTOS.h"  // MUST come first
#include "freertos/task.h"       // then include task.h
#include <stdio.h>
#include <string>
#include "Thread.hpp"


struct task_handler;

class Task
{
private:
    TaskHandle_t handle_;
    std::string name_;
    Thread thread_;
public:
    Task(std::string name, uint8_t priopirty );
    ~Task();

    void start();
    void stop();
    void next();

    virtual void on_loop() = 0;
    
private:
    virtual void run();

};

