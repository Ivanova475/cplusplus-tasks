#include <SFML/Graphics.hpp>

#include "game.h"


int main()
{
    Game game;
    game.Run();

    return 0;
}


/*#include <iostream>

#include "forest.h"


const int height = 10;
const int width = 20;


int main()
{
    Forest forest(height, width);

    while (1)
    {
        getchar();
        std::cout << forest << "\n" << std::endl;
        forest.Update();
    }

    return 0;
}
*/



