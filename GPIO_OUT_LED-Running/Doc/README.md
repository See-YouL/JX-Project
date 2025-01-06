# GPIO输出流水灯

## 硬件电路

![硬件电路](https://raw.githubusercontent.com/See-YouL/MarkdownPhotos/main/202501060935709.png)

- PB5接红色LED负极
- PB0接绿色LED负极
- PB1接蓝色LED负极

## 软件设计

### 程序设计

实现红灯(PB5), 绿灯(PB0), 蓝灯(PB1)交替闪烁

GPIO 端口设置

1. 使能GPIOB时钟
2. 配置PB5, PB0, PB1为推挽输出, 50MHz

```c
// 1. 使能GPIOB时钟
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

// 2. 配置PB5, PB0, PB1为推挽输出, 50MHz
GPIO_InitTypeDef GPIO_InitStructure; // 定义GPIO初始化结构体
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; // 端口5
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // 推挽输出
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 50MHz
GPIO_Init(GPIOB, &GPIO_InitStructure); // 初始化PB5
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; // 端口0
GPIO_Init(GPIOB, &GPIO_InitStructure); // 初始化PB0
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; // 端口1
GPIO_Init(GPIOB, &GPIO_InitStructure); // 初始化PB1
```

LED控制

1. 点亮红灯, 熄灭绿灯, 熄灭蓝灯
2. 延时
3. 点亮绿灯, 熄灭红灯, 熄灭蓝灯
4. 延时
5. 点亮蓝灯, 熄灭红灯, 熄灭绿灯
6. 延时

```c

使用GPIO_Write()函数, 直接将16位的数据写入寄存器, 控制LED的亮灭

```c
while(1)
{
    GPIO_Write(GPIOB, ~0x20); // ~0000 0000 0010 0000 仅PB5低电平
    Delay_ms(500); // 延时500ms
    GPIO_Write(GPIOB, ~0x01); // ~0000 0000 0000 0001 仅PB0低电平
    Delay_ms(500); // 延时500ms
    GPIO_Write(GPIOB, ~0x02); // ~0000 0000 0000 0010 仅PB1低电平
    Delay_ms(500); // 延时500ms
}
```
