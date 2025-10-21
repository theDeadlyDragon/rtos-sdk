#include "TestTask.hpp"

TestTask::TestTask(int a): Task("TestTask",5)
{
    printf("test2 \n");

}

TestTask::~TestTask(){}


void TestTask::on_loop(){

    printf( "test start\n");
    vTaskDelay(pdMS_TO_TICKS(2000));
}

