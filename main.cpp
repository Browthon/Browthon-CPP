#include <Core/Application.hpp>

int main(int argc, char** argv)
{
    auto app = Bn::Application(argc, argv);
    if (app.isClosing())
    {
        return 0;
    }
    return app.exec();
}