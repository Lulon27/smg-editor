#include "RedStar/MyHeader.h"
#include "RedStar/RedStarApp.h"
#include "RedStar/Window.h"

int main()
{
    logWelcome();

    RedStar::RedStarApp editor;

    editor.run();
    return 0;
}