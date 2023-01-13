#include "window.h"

window::window()
{

    context->setContextProperty("_String", QString("deneme"));
    context->setContextProperty("_Size", QSize(800,600));

}
