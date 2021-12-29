#include <spdlog/spdlog.h>
#include "SMGEditor/MyHeader.h"

int main()
{
    logWelcome();

    int a = 4;
    int b = 2;
    spdlog::info("{} + {} = {}", a, b, add(4, 2));
    return 0;
}