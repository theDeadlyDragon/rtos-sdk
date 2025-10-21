
typedef enum {
    DEVICE_EVENT,   // note: use uppercase by convention
    
    SENSOR_EVENT,
    COMMAND_EVENT
} MessageType;

struct MessageBase
{
  MessageType type;
  MessageBase(MessageType type):type(type){} 
};


struct DeviceEventMessage: public MessageBase
{
    DeviceEventMessage(): MessageBase(MessageType::DEVICE_EVENT){
        
    }
};
