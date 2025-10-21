#pragma once
#include <string>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include <functional>

class Thread
{
    using Function = std::function<void(void)>;

private:
    std::string _name;
    uint32_t _stack_size;
    UBaseType_t _priority;
    TaskHandle_t handle_;    
    const Function _user_function = nullptr;
public:
    Thread(std::string name, const Function &function, uint32_t stack = 4096, UBaseType_t priority = 5);
    ~Thread();
    void start();
    void stop();
    void next_loop();


    
    TaskHandle_t* gethandle();
private:
    static void entry(void* pvParameters);
};
