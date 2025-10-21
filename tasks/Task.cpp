#include "Task.hpp"
#include <stdio.h>
#include <esp_log.h>

Task::Task(std::string name, uint8_t priopirty): name_(name), thread_(
    name_, std::bind(&Task::run, this)
)
{

printf("created \n");
}

Task::~Task()
{
}

void Task::start(){
    this->thread_.start();
}

void Task::run(){
    while (true)
    {
        on_loop();
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    }
}



void Task::next(){
     this->thread_.next_loop();
}
