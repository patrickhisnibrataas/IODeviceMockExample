#include "mockdevice.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    MockDevice mockDevice;
    mockDevice.open(QIODevice::ReadWrite);

    Controller controller;
    controller.setDevice(&mockDevice);
    controller.writeLeft();
    controller.writeRight();

    qDebug() << "Read: " << mockDevice.readAll();
}
