#include <QtTest>
#include <mockdevice.h>
#include <controller.h>
#include <app.h>

class DeviceInputOutputTests : public QObject
{
    Q_OBJECT

private slots:
    void mockDeviceInput();
    void verifyDeviceOutput();
};

void DeviceInputOutputTests::mockDeviceInput()
{
    MockDevice mockDevice;
    mockDevice.open(QIODevice::ReadWrite);

    Controller controller;
    controller.setDevice(&mockDevice);
    controller.writeLeft();
    controller.writeRight();

    QVERIFY(mockDevice.readAll() == "LeftRight");
}

void DeviceInputOutputTests::verifyDeviceOutput()
{
    MockDevice mockDevice;
    mockDevice.open(QIODevice::ReadWrite);

    App app(&mockDevice);
    app.start();

    QVERIFY(mockDevice.readAll() == "Start");
}

QTEST_APPLESS_MAIN(DeviceInputOutputTests)

#include "tst_example.moc"
