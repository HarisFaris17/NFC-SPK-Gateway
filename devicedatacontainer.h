#ifndef DEVICEDATACONTAINER_H
#define DEVICEDATACONTAINER_H

#include <QString>

class DeviceDataContainer{
#define INVALID_COORDINATES  999
#define INVALID_POSITIVE     -1
#define INVALID_STRING       ""
    public :
#define DEFINE_LOCATOR_PARAMETERS(idx)      double x##idx = INVALID_COORDINATES, \
                                            double y##idx = INVALID_COORDINATES, \
                                            double z##idx = INVALID_COORDINATES

        DeviceDataContainer(int spk = INVALID_POSITIVE,
                       int counter = INVALID_POSITIVE,
                       QString tagId = INVALID_STRING,
                       double x = INVALID_COORDINATES,
                       double y = INVALID_COORDINATES,
                       double z = INVALID_COORDINATES,
                       DEFINE_LOCATOR_PARAMETERS(0),
                       DEFINE_LOCATOR_PARAMETERS(1),
                       DEFINE_LOCATOR_PARAMETERS(2),
                       DEFINE_LOCATOR_PARAMETERS(3)){
                        this->spk = spk;
                        this->counter = counter;
                        this->tagId = tagId;
                        this->x = x;
                        this->y = y;
                        this->z = z;
#define DEFINE_LOCATOR_COORD(idx) _DEFINE_LOCATOR_COORD(idx)
#define _DEFINE_LOCATOR_COORD(idx)  this->x##idx = x##idx; \
                                    this->y##idx = y##idx; \
                                    this->z##idx = z##idx; \

                        DEFINE_LOCATOR_COORD(0)
                        DEFINE_LOCATOR_COORD(1)
                        DEFINE_LOCATOR_COORD(2)
                        DEFINE_LOCATOR_COORD(3)



    }

    operator QString() const {return QString("spk = %1, counter = %2, tag id = %3, x = %4, y = %5, z = %6, x0 = %7, y0 = %8, z0 = %9, x1 = %10, y1 = %11, z1 = %12, x2 = %13, y2 = %14, z2 = %15, x3 = %16, y3 = %17, z3 = %18,")
                                        .arg(spk)
                                        .arg(counter)
                                        .arg(tagId)
                                        .arg(x).arg(y).arg(z)
                                        .arg(x0).arg(y0).arg(z0)
                                        .arg(x1).arg(y1).arg(z1)
                                        .arg(x2).arg(y2).arg(z2)
                                        .arg(x3).arg(y3).arg(z3);}
     setDeviceParameter(int spk, int counter, QString tagId){
         this->spk = spk;
         this->counter = counter;
         this->tagId = tagId;
     }
     setCoordinates(double x, double y, double z){
         this->x = x;
         this->y = y;
         this->z = z;
     }
#define DEFINE_SET_COORD_LOCATOR(locator) _DEFINE_SET_COORD_LOCATOR(locator)
#define _DEFINE_SET_COORD_LOCATOR(idx) setCoordinatesLocator##idx (double x##idx, double y##idx, double z##idx){ \
            this->x##idx = x##idx; \
            this->y##idx = y##idx; \
            this->z##idx = z##idx; \
        }

        DEFINE_SET_COORD_LOCATOR(0)
        DEFINE_SET_COORD_LOCATOR(1)
        DEFINE_SET_COORD_LOCATOR(2)
        DEFINE_SET_COORD_LOCATOR(3)

        setCoordinatesLocator(int locatorIdx, double x, double y, double z)
        {
            if (locatorIdx == 0) setCoordinatesLocator0(x, y, z);
            else if (locatorIdx == 1) setCoordinatesLocator1(x, y, z);
            else if (locatorIdx == 2) setCoordinatesLocator2(x, y, z);
            else if (locatorIdx == 3) setCoordinatesLocator3(x, y, z);
        }

        int spk;
        int counter;
        QString tagId;
        double x;
        double y;
        double z;
        double x0;
        double y0;
        double z0;
        double x1;
        double y1;
        double z1;
        double x2;
        double y2;
        double z2;
        double x3;
        double y3;
        double z3;

};

#endif // DEVICEDATACONTAINER_H
