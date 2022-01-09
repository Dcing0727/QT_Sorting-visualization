# QT_Sorting visualization
## QT简介

QT是一个跨平台C++图形用户界面应用程序开发框架，可以用来做一些常用的应用程序，这次用Qt实现一个多种排序可视化的小程序。
GUI（Graphical User Interface，又称图形用户接口）是指采用图形方式显示的计算机操作用户界面。

QT creator 是用于开发QT程序的IDE，集成了QT designer, Assistant,Linguist。
Qt Designer 是设计界面用的
Qt Assistant 是帮助
Qt Linguist 是设计多国语言时用到的工具

## 文件介绍

**.pro**：项目文件：用来告诉qmake关于为这个应用程序创建makefile所需要的细节。例如，一个源文件和头文件的列表、任何应用程序特定配置。例如，一个必需链接的额外库或者一个额外的包含路径、都应该放到项目文件中。

**.h**：头文件

**.ui**：窗口界面文件，双击项目文件目录树中的文件 **widget.ui**，会打开一个集成在 Qt Creator 中的 Qt Designer【ui设计器】 对窗体进行可视化设计

**.cpp**:程序文件

**.qrc**：是qt的资源文件，本质上是xml文件，可以使用rcc命令来编译
 

## 任务功能说明
1)	完成相关排序算法：双路快速排序、快速排序、归并排序、插入排序、堆排序、选择排序等
2)	实现算法排序过程的可视化

## 代码实现地址
 
