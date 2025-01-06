/**
  ******************************************************************************
  * @file    main.c
  * @author  eric
  * @version V0.0.1
  * @date    6-Jauary-2025 
  * @brief   实现红绿蓝灯交替闪烁
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FUCTIONS WHICH IS FOR GUIDANCE ONLY
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "Delay.h"

/**
 * @brief 实现红绿蓝灯交替闪烁
 * @param None
 * @retval None 
 */
int main(void)
{
    // 使能GPIOB时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // 配置PB5, PB0, PB1为推挽输出, 50MHz
    GPIO_InitTypeDef GPIO_InitStructure; // 定义GPIO初始化结构体
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; // 端口5
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // 推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 50MHz
    GPIO_Init(GPIOB, &GPIO_InitStructure); // 初始化PB5
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; // 端口0
    GPIO_Init(GPIOB, &GPIO_InitStructure); // 初始化PB0
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1; // 端口1
    GPIO_Init(GPIOB, &GPIO_InitStructure); // 初始化PB1

    while(1)
    {
        GPIO_Write(GPIOB, ~0x20); // ~0000 0000 0010 0000 仅PB5低电平
        Delay_ms(500); // 延时500ms
        GPIO_Write(GPIOB, ~0x01); // ~0000 0000 0000 0001 仅PB0低电平
        Delay_ms(500); // 延时500ms
        GPIO_Write(GPIOB, ~0x02); // ~0000 0000 0000 0010 仅PB1低电平
        Delay_ms(500); // 延时500ms
    }
}
