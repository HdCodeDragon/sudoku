#ifndef _SUDOKU_COMMAND_H_
#define _SUDOKU_COMMAND_H_

#include <memory>
#include "common.h"

// 前向声明 CScene 类
class CScene;

// 命令类，用于执行和撤销操作
class CCommand
{
public:
    // 构造函数，初始化命令的所有者
    CCommand(CScene *pOwner);
    // 构造函数，初始化命令的所有者、操作点、前一个值和当前值
    CCommand(CScene *pOwner, const point_t &point, int preValue, int curValue);
    // 拷贝构造函数
    CCommand(const CCommand &);
    // 析构函数
    ~CCommand();

    // 执行命令
    bool execute(int nInputValue);
    // 撤销命令
    void undo();
    // 获取操作点
    point_t getPoint() { return _stPoint; }
    // 获取前一个值
    int getPreValue() { return _nPreValue; }
    // 获取当前值
    int getCurValue() { return _nCurValue; }
    // 设置操作点
    void setPoint(const point_t &point) { _stPoint = point; }
    // 设置前一个值
    void setPreValue(int preValue) { _nPreValue = preValue; }
    // 设置当前值
    void setCurValue(int curValue) { _nCurValue = curValue; }

private:
    // 命令的所有者
    CScene *_pOwner;
    // 操作点
    point_t _stPoint;
    // 前一个值
    int _nPreValue;
    // 当前值（实际未使用）
    int _nCurValue;
};

#endif