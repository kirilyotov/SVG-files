#include "CMD.h"

CMD& CMD::program()
{
    static CMD cmd;
    return cmd;
}

void CMD::run()
{
}
