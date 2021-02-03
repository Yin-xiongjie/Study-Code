#ifndef LESSON2LIB_H
#define LESSON2LIB_H

#include "QtGlobal"


//Q_DECL_EXPORT表示导出类
class Q_DECL_EXPORT Lesson2lib
{

public:
    Lesson2lib();
};

extern "C" Q_DECL_EXPORT void testfunction();
#endif // LESSON2LIB_H
