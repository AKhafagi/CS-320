#include "lua.hpp"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    cout<<"Assignment #3-1, Anas Khafagi, anas.khafagi@gmail.com\n";
    
    if (argc >= 3 || argc < 2) {
        cout << "Prog3_1 requires 1 commandline argument" << endl;
        return 0;
    }
    int s = 0;

    lua_State *L = luaL_newstate();

    // load the libs
    luaL_openlibs(L);

    //run a Lua scrip here
    luaL_dofile(L, argv[1]);
    lua_close(L);

    return 0;
}

