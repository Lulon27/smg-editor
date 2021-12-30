#include <spdlog/spdlog.h>
#include "RedStar/MyHeader.h"
#include "RedStar/SMGEditor.h"

int main()
{
    logWelcome();

    RedStar::Application editor;
    editor.run();
    return 0;
}