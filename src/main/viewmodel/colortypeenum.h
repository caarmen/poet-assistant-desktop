#ifndef COLORTYPEENUM_H
#define COLORTYPEENUM_H

#include <QObject>


class ColorTypeEnum: public QObject
{
    Q_OBJECT
public:
    enum Value{
        Background,
        Surface
        // TODO Add others as needed
    };
    Q_ENUM(Value)
};

typedef ColorTypeEnum::Value ColorType;
#endif // COLORTYPEENUM_H
