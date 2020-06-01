#include <iostream>
#include "Texts.h"

int Main(int argc, char* argv[], char* envp[])
{
    Texts my_text;

    my_text.pushback_this_level("text 1 lvl");
    my_text.pushback_next_level("text 2 level");
    my_text.pushback_this_level("text 2 level");
    my_text.pushback_next_level("text 3 ltvtl");
    my_text.pushback_this_level("text 3 level");
    auto it = my_text.begin();
    it.delNext("text 2 level");

    my_text.print();

    std::cout << std::endl << my_text.begin() << std::endl;
    std::cout << my_text.end() << std::endl;

    return 0;
    system("pause");

}