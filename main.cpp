#include <Windows.h>

#include "Calculator.h"

int main(int argc,char** argv)
{
    QApplication app(argc,argv);

    Calculator myCalculator;

    ShowWindow(GetConsoleWindow(), SW_HIDE);
    myCalculator.show();

    return app.exec();
}
