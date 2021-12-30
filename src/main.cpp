#include <spdlog/spdlog.h>
#include "RedStar/MyHeader.h"
#include "RedStar/RedStarApp.h"

int main()
{
    logWelcome();

    RedStar::RedStarApp editor;
    editor.run();
    return 0;
}