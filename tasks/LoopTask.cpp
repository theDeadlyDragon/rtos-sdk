#include "LoopTask.hpp"
#include <esp_log.h>


LoopTask::LoopTask(std::string name, uint8_t priopirty): Task(name,6)
{
    printf("init \n");
}

LoopTask::~LoopTask()
{
}



void LoopTask::run(){

    on_loop();
    vTaskDelay(pdMS_TO_TICKS(2000));
}

