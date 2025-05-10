# Linux下的OLED驱动demo

### 项目描述

本项目实现了下述功能：

1. 驱动OLED设备，显示图形/字符串
2. 获取系统信息，显示到OLED上

### 使用方法

在linux环境下，直接make即可

```bash
make all
```

或手动进行编译

```bash
gcc oled_display.c get_system_info.c ssd1306_i2c.c -li2c -o oled_display
```

### 项目依赖

1. libi2c-dev

### 参考链接

https://github.com/iliapenev/ssd1306_i2c



## 附录

### 关于i2c-tools工具的使用

安装工具的指令如下所示

```bash
sudo apt-get install i2c-tools
```

#### 遍历i2c总线来检测设备链接情况

1. 查看有哪些i2c总线

```bash
sudo i2cdetect -l
```

2. 遍历对应的i2c总线

```
sudo i2cdetect -y 1
```



