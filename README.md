# Linux下的OLED驱动demo

## 项目描述

本项目实现了下述功能：

1. 驱动OLED设备，显示图形/字符串
2. 获取系统信息，显示到OLED上

## 使用方法

在linux环境下，直接make即可

```bash
make all
```

或手动进行编译

```bash
gcc oled_display.c get_system_info.c ssd1306_i2c.c -lwiringPi -o oled_display
```

## 项目依赖

1. wiringPi库

## 参考链接

https://github.com/iliapenev/ssd1306_i2c

