#ifndef _SUDOKU_SCENE_H_
#define _SUDOKU_SCENE_H_

#include <iostream>
#include <vector>
#include "common.h"
#include "block.h"
#include "command.h"

// 数独场景类
class CScene
{
public:
  // 构造函数，初始化场景的列数和当前点
  CScene(int index = 3);
  // 析构函数，释放资源
  virtual ~CScene();

  // 生成数独谜题
  void generate();
  // 显示数独场景
  void show() const;

  // 设置当前点的值
  bool setCurValue(const int nCurValue, int &nLastValue);
  // 设置指定点的值
  bool setPointValue(const point_t &, const int);
  // 获取当前点
  point_t getCurPoint();

  // 随机擦除指定数量的格子
  void eraseRandomGrids(const int count);
  // 检查数独是否完成
  bool isComplete();

  // 开始游戏
  void play();
  // 保存数独场景到文件
  bool save(const char *filename);
  // 从文件加载数独场景
  bool load(const char *filename);

  // 设置操作模式
  void setMode(KeyMode mode);

private:
  // 初始化场景，将每个格子的指针放到 block 里面
  void init();
  // 设置当前点的值
  void setValue(const int);
  // 设置指定点的值
  void setValue(const point_t &, const int);
  // 打印下划线
  void printUnderline(int line_no = -1) const;

private:
  // 键映射指针
  KeyMap *keyMap{};
  // 场景的最大列数
  int _max_column;
  // 当前点
  point_t _cur_point;
  // 列 block 数组
  CBlock _column_block[9];
  // 行 block 数组
  CBlock _row_block[9];
  // 九宫格 block 数组
  CBlock _xy_block[3][3];
  // 数独格子数组
  point_value_t _map[81];

  // 命令向量，用于记录操作历史
  std::vector<CCommand> _vCommand;
};

#endif