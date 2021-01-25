#include <WiFi.h> 
#include "Adafruit_VL53L0X.h"
typedef enum SensorState{
    IDLE = 0,
    LOWENERGY = 1,
    MEDIUMENERGY = 2,
    HIGHENERGY = 3
}typeState_t;

class Sensor{
private:
    WiFiClient client;
    int id;

    void sendToActuator();

protected:
    int address;
    int pin;
    typeState_t state = IDLE;

    void setState(typeState_t state);

public:
    Sensor(int id, int pin, int address);
    virtual void init();
    void setClient(WiFiClient client);
    virtual void readSensor();
};

class SensorShort : public Sensor{
protected:
    Adafruit_VL53L0X lox = Adafruit_VL53L0X();

public:
    SensorShort(int id, int pin, int address);
    void init();
    virtual void readSensor();
};

class SensorLong : public Sensor{
public:
    SensorLong(int id, int pin, int address);
    void init();
    void readSensor();
};

class SensorBottom : public SensorShort{
public:
    SensorBottom(int id, int pin, int address) : SensorShort(id, pin, address){}
    void readSensor();
};