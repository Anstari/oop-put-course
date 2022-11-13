#include <iostream>
#include "Game.h"
#include "Title.h"

using namespace std;


int main()
{
    Title title("The Elder Scrolls V", "TES V");
    Game game1(title, "Bethesda Game Studios", 20.99, 2011);
    game1.ChangeGamePrice(31.99);
    game1.ShowGameInfo();
    return 0;
}

