#include "lua.hpp"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    cout<<"Assignment #3-3, Anas Khafagi, anas.khafagi@gmail.com\n";
    if (argc >= 3 || argc < 2) {
        cout << "Prog3_1 requires 1 commandline argument" << endl;
        return 0;
    }
    string line;
    lua_State *L = luaL_newstate();

    // load the libs
    luaL_openlibs(L);

    //run a Lua script here
    luaL_dofile(L, argv[1]);
    getline(cin, line);
    string arg;
    arg = "return InfixToPostfix(\'" + line + "\')";
    luaL_dostring(L, arg.c_str());
    string result = luaL_checkstring(L, -1);
    cout << result << endl;
    lua_pop(L,-1);
    lua_close(L);

    return 0;
}

