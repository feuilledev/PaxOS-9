#include "lua_switch.hpp"
#include "lua_gui.hpp"
#include "lua_file.hpp"

LuaSwitch::LuaSwitch(LuaWidget* parent, int x, int y, LuaGui* gui)
{
    widget = new Switch(x, y);
    init(widget, parent);

    auto my_lambda = [](int x, int y) -> int {
        return x + y;
    };

    this->gui = gui;

    sol::function lua_function = this->gui->lua->lua["donothing"];

    onClick(lua_function);
}