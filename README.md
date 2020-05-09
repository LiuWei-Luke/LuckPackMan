# LuckPackMan
Pack man with openGL

这是个人娱乐性质制作的仿南梦宫的经典游戏 吃豆人

Game build with CMake tool, make sure you had libraries within [CMakeLists](CMakeLists.txt). Replace libaraies which only in OS X system such like 'cocoa'.

项目采用CMake制作, 请先安装使用的库: OpenGL, glm, glew, glfw3。由于制作使用的OS X系统，未考虑兼容，在Windows下请替换相应的库，具体请查看[CMakeLists](CMakeLists.txt).

## Display
Here is an image shows how the game looks like.

![image](https://github.com/LiuWei-Luke/LuckPackMan/blob/master/display.gif)

## Graph
图像处理使用OpenGL库进行处理，主要的学习以及参考资料来自:

- [LearnOpenGL](https://learnopengl-cn.github.io/)

游戏中主要用到的是简单的*Shader*书写方式以及*Texture*的使用，关于地图的制作以及角色的移动则需要使用到*坐标变换*以及🎥部分的内容。 总的来说都是入门水平的知识 :)

相关库使用:
- OpenGL
- glm：一个配合OpenGL使用的数学运算库, 这里主要使用简单的矩阵以及向量计算。
- GLEW：一个配合OpenGL使用的跨系统扩展库, 主要使用到窗口的显示
- glfw3：一个配合OpenGL使用的获取用户输入的扩展库， 主要获取方向控制
- glad：配合OpenGL使用的扩展库
- stb_image.h：图片处理库

## Ghost
There are four ghosts in Pack Man, they all have own strategy for catching player.

在吃豆人中， 每个*ghost*都有其相应的属性：颜色，速度，追踪策略

对于生成Ghost使用的是*工厂模式*，每个Ghost的搜寻策略则采用*策略模式*进行设计

#### search parttern
Ghost 采用的search算法使用 [*A** 算法](https://en.wikipedia.org/wiki/A*_search_algorithm)。A* 算法作为一种预见性(pre-process)算法。在大多数时候的最优解。

这里我使用了一个最小堆([min-head](https://www.cs.cmu.edu/~tcortina/15-121sp10/Unit06B.pdf))来保存 A*的结果的权重排序。虽然效率可能还不如使用STL库来插入再排序。但最为数据结构实践还是不错的选择。

#### 小红
最近的路线， 对于算法来说就是在A*计算权重的时候使用直线距离(欧氏距离)

#### 小紫
稍微绕远路一点， 计算时采用欧式距离的平方

#### 小蓝 （未实现）
它的目标距离是player正在行进方向的路口

#### 小黄 （未实现）
它的在以player为圆心的圆边上进行漫游

## 物理碰撞
由于是2D环境， 这里采用轴对称包围盒（Axis-Aligned Bounding Box）的碰撞检测模式，即判断任意两个（无旋转）矩形的任意一边是否无间距，从而判断是否碰撞。

