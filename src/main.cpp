#include <spdlog/spdlog.h>
#include "SMGEditor/MyHeader.h"
#include "SMGEditor/SMGEditor.h"

int main()
{
    logWelcome();

    smg::Application editor;
    editor.run();
    return 0;
}