/**
  ******************************************************************************
  * @file    main.c
  * @author  eric
  * @version V0.0.1
  * @date    6-Jauary-2025 
  * @brief   实现红灯闪烁
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
 * @brief 实现红灯闪烁
 * @param None
 * @retval None 
 */
int main(void)
{
    // 使能GPIOB时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // GPIO Configuration
    GPIO_InitTypeDef GPIO_InitStructure; // 定义GPIO初始化结构体
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; // 端口5
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; // 推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // 50MHz
    GPIO_Init(GPIOB, &GPIO_InitStructure); // 初始化GPIOB


    while(1)
    {
        GPIO_ResetBits(GPIOB, GPIO_Pin_5); // PB5输出低电平, 点亮红灯
        Delay_ms(500); // 延时500ms
        GPIO_SetBits(GPIOB, GPIO_Pin_5); // PB5输出高电平, 熄灭红灯
        Delay_ms(500); // 延时500ms
    }

}
