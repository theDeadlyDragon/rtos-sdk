#include "Thread.hpp"
#include <esp_task_wdt.h>
#include <freertos/idf_additions.h>

Thread::Thread(std::string name, const Function &function, uint32_t stack, UBaseType_t priority) : _name(name), _stack_size(stack), _priority(priority), handle_(nullptr), _user_function(function)
{
}

Thread::~Thread()
{
}

void Thread::start()
{
    if (this->handle_ != nullptr)
        return;

    xTaskCreate(&Thread::entry, _name.c_str(), _stack_size, this, _priority, &handle_);
    ESP_LOGI("Thread", "Task %s started", _name);
}

void Thread::entry(void *pvParameters)
{
    Thread* self = static_cast<Thread*>(pvParameters);
        if (self->_user_function) {
            self->_user_function();  // call stored function
        }
        vTaskDelete(nullptr);
}

TaskHandle_t *Thread::gethandle()
{
    return &this->handle_;
}

void Thread::next_loop()
{
    xTaskNotifyGive(this->handle_);
}