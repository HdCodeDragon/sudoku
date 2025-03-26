#ifndef _SUDOKU_COLOR_H
#define _SUDOKU_COLOR_H

#include <iostream>

namespace Color
{
    enum Code
    {
        // 加粗效果
        BOLD = 1,
        // 重置颜色和样式
        RESET = 0,

        // 背景颜色
        BG_BLACK = 40,
        BG_RED = 41,
        BG_GREEN = 42,
        BG_YELLOW = 43,
        BG_BLUE = 44,
        BG_MAGENTA = 45,
        BG_CYAN = 46,
        BG_LIGHT_GRAY = 47, // 实际是白色，终端为正常显示会进行调整
        BG_DEFAULT = 49,

        // 前景颜色
        FG_BLACK = 30,
        FG_RED = 31,
        FG_GREEN = 32,
        FG_YELLOW = 33,
        FG_BLUE = 34,
        FG_MAGENTA = 35,
        FG_CYAN = 36,
        FG_LIGHT_GRAY = 37,
        FG_DEFAULT = 39,
        FG_DARK_GRAY = 90,
        FG_LIGHT_RED = 91,
        FG_LIGHT_GREEN = 92,
        FG_LIGHT_YELLOW = 93,
        FG_LIGHT_BLUE = 94,
        FG_LIGHT_MAGENTA = 95,
        FG_LIGHT_CYAN = 96,
        FG_WHITE = 97,

    };

    // 颜色修改器类，用于设置输出的颜色和样式
    class Modifier
    {
        // 模式、背景颜色和前景颜色的代码
        Code md, bg, fg;

    public:
        // 默认构造函数，设置为默认颜色和样式
        Modifier() : md(Color::RESET), bg(Color::BG_DEFAULT), fg(Color::FG_DEFAULT) {}
        // 带参数的构造函数，用于设置指定的颜色和样式
        Modifier(Code Mode, Code BackGround, Code FrontGround) : md(Mode), bg(BackGround), fg(FrontGround) {}
        // 重载输出运算符，用于输出颜色和样式代码
        friend std::ostream &
        operator<<(std::ostream &os, const Modifier &mod)
        {
            return os << "\033[" << mod.md << ";" << mod.bg << ";" << mod.fg << "m";
        }
    }; // namespace Color
}
#endif