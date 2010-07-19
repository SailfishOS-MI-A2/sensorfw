/**
   @file abstractsensor_a.h
   @brief D-Bus adaptor base class for sensors

   <p>
   Copyright (C) 2009-2010 Nokia Corporation

   @author Semi Malinen <semi.malinen@nokia.com
   @author Joep van Gassel <joep.van.gassel@nokia.com>
   @author Timo Rongas <ext-timo.2.rongas@nokia.com>

   This file is part of Sensord.

   Sensord is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License
   version 2.1 as published by the Free Software Foundation.

   Sensord is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with Sensord.  If not, see <http://www.gnu.org/licenses/>.
   </p>
 */

#ifndef ABSTRACTSENSORADAPTOR_H
#define ABSTRACTSENSORADAPTOR_H

#include <QtDBus/QtDBus>
#include "datatypes/datarange.h"

class AbstractSensorChannelAdaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT

public:
    virtual ~AbstractSensorChannelAdaptor() {}

protected:
    AbstractSensorChannelAdaptor(QObject *parent) : QDBusAbstractAdaptor(parent) {}

public: // PROPERTIES
    Q_PROPERTY(bool isValid READ isValid)
    bool isValid() const;

    Q_PROPERTY(QString errorString READ errorString)
    QString errorString() const;

    Q_PROPERTY(QString description READ description)
    QString description() const;

    Q_PROPERTY(QString id READ id)
    QString id() const;

    Q_PROPERTY(int interval READ interval)
    int interval() const;

    Q_PROPERTY(bool standbyOverride READ standbyOverride);
    bool standbyOverride() const;

    // TODO: put state back
    /*
    Q_PROPERTY(SensorState state READ state)
    SensorState state() const;
    */

    Q_PROPERTY(QString type READ type)
    QString type() const;

private: // PROPERTIES
    Q_PROPERTY(int errorCodeInt READ errorCodeInt)
    int errorCodeInt() const;

public Q_SLOTS: // METHODS
    void start(int sessionId);
    void stop(int sessionId);

    void setInterval(int sessionId, int value);
    int getIntervalCount();
    DataRange getAvailableInterval(int index);

    bool setStandbyOverride(int sessionId, bool value);

    int getDataRangeCount();
    DataRange getAvailableDataRange(int index);
    DataRange getCurrentDataRange();
    void requestDataRange(int sessionId, DataRange range);
    void removeDataRangeRequest(int sessionId);

Q_SIGNALS: // SIGNALS
    void propertyChanged(const QString& name);
};

#endif // ABSTRACTSENSORADAPTOR_H
