#ifndef MOCKDEVICE_H
#define MOCKDEVICE_H

#include <QIODevice>

class MockDevice : public QIODevice {
    Q_OBJECT

protected:
    virtual qint64 readData(char *data, qint64 maxlen) override {
        const auto length = (maxlen > m_data.size()) ? m_data.size() : maxlen;
        for (auto i = 0; i < length; i++) {
            data[i] = m_data.front();
            m_data.remove(0, 1);
        }

        return length;
    }

    virtual qint64 writeData(const char *data, qint64 len) override {
        m_data.append(data, static_cast<int>(len));
        return len;
    }

private:
    QByteArray m_data;
};

#endif // MOCKDEVICE_H
