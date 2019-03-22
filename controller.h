#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QIODevice>

class Controller : public QObject {
    Q_OBJECT

public:
    void setDevice(QIODevice *device) {
        m_device = device;
    }

public slots:
    void writeRight() {
        m_device->write("Right");
    }
    void writeLeft() {
        m_device->write("Left");
    }

private:
    QIODevice *m_device;
};

#endif // CONTROLLER_H
