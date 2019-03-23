#ifndef APP_H
#define APP_H

#include <QIODevice>

class App {
public:
    App(QIODevice* device) {
        m_device = device;
    }

    void start() {
        m_device->write("Start");
    }

private:
    QIODevice* m_device;
};

#endif // APP_H
