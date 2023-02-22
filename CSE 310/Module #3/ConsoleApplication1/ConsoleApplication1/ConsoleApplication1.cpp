#include <iostream>
#include "player.h"
#include "actor.h"
#include "assault.h"
#include "heavy.h"

int main()
{
    Actor actor("Actor Test");
    cout << actor.GetName() << endl;
    Assault assault("Assault Test");
    cout << assault.GetName() << endl;
    Heavy heavy("Heavy Test");
    cout << heavy.GetName();
}