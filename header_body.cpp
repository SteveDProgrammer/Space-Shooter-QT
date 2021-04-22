//Health Bar Outer Frame

#include "header_body.h"

header_body::header_body()
{
    setPixmap(QPixmap(":/Assets/misc/HealthBarFrame.png").scaled(320,65,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}
