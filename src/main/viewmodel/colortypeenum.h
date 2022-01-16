#ifndef COLORTYPEENUM_H
#define COLORTYPEENUM_H

#include <QObject>


class ColorTypeEnum: public QObject
{
    Q_OBJECT
public:
    enum Value{
        Accent,
        Background,
        Primary,
        PrimaryText,
        Surface
    };
    Q_ENUM(Value)
};

typedef ColorTypeEnum::Value ColorType;
#endif // COLORTYPEENUM_H
