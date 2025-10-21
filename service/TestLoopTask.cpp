#include "TestLoopTask.hpp"

TestLoopTask::TestLoopTask(int a): LoopTask("TestTask",5)
{
    printf("test2 \n");

}

TestLoopTask::~TestLoopTask(){}


void TestLoopTask::on_loop(){

    printf( "loop start\n");
    vTaskDelay(pdMS_TO_TICKS(2000));
}

