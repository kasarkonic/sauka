#include "widgets_list.h"
#include "valve.h"
#include "pipe.h"
#include "pump.h"
#include "dyno.h"
#include "tvertne.h"
#include "mix.h"








widgets_list::widgets_list() {

add(valve, " Valve1");



}




void widgets_list::add( int npk ,QString name )
  {
    settings.name = name;

    widgetArray[npk] =
}

