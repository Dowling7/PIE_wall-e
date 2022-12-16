#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"
//width320, height240
void setup()
{
  Config_Init();
  LCD_Init();
  LCD_Clear(0xffff);
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  Paint_DrawString_EN(30, 10, "WALL-E V1.0", &Font24, YELLOW, RED);
  Paint_DrawString_EN(100, 110, "BOOTING", &Font24, YELLOW, RED);
  LCD_Clear(0xffff);



  

  }

void opened_eyes(){
  Paint_DrawRectangle(95, 100, 145, 125, BLUE,  DOT_PIXEL_2X2,DRAW_FILL_EMPTY);  
  Paint_DrawRectangle(175, 100, 225, 125, BLUE,  DOT_PIXEL_2X2,DRAW_FILL_EMPTY);  
  Paint_DrawPoint(120, 113, BLACK, DOT_PIXEL_4X4,DOT_FILL_AROUND);
  Paint_DrawPoint(200, 113, BLACK, DOT_PIXEL_4X4,DOT_FILL_AROUND);
  LCD_Clear(0xffff);
}

void look_right(){
  Paint_DrawRectangle(150, 100, 225, 125, BLUE,  DOT_PIXEL_2X2,DRAW_FILL_EMPTY);  
  Paint_DrawRectangle(250, 100, 300, 125, BLUE,  DOT_PIXEL_2X2,DRAW_FILL_EMPTY);  
  Paint_DrawPoint(200, 113, BLACK, DOT_PIXEL_4X4,DOT_FILL_AROUND);
  Paint_DrawPoint(280, 113, BLACK, DOT_PIXEL_4X4,DOT_FILL_AROUND);
  delay(1000);
  LCD_Clear(0xffff);
}

void look_left(){
  Paint_DrawRectangle(20, 100, 70, 125, BLUE,  DOT_PIXEL_2X2,DRAW_FILL_EMPTY);  
  Paint_DrawRectangle(95, 100, 170, 125, BLUE,  DOT_PIXEL_2X2,DRAW_FILL_EMPTY);  
  Paint_DrawPoint(120, 113, BLACK, DOT_PIXEL_4X4,DOT_FILL_AROUND);
  Paint_DrawPoint(40, 113, BLACK, DOT_PIXEL_4X4,DOT_FILL_AROUND);
  delay(1000);
  LCD_Clear(0xffff);

}

void semiopened_eyes(){
  Paint_DrawRectangle(95, 110, 145, 115, BLUE,  DOT_PIXEL_2X2,DRAW_FILL_EMPTY);  
  Paint_DrawRectangle(175, 110, 225, 115, BLUE,  DOT_PIXEL_2X2,DRAW_FILL_EMPTY);  
  Paint_DrawPoint(120, 113, BLACK, DOT_PIXEL_4X4,DOT_FILL_AROUND);
  Paint_DrawPoint(200, 113, BLACK, DOT_PIXEL_4X4,DOT_FILL_AROUND);
  LCD_Clear(0xffff);
}

void closed_eyes(){
  Paint_DrawLine(95, 113, 145, 111, BLACK, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
  Paint_DrawLine(175, 111, 225, 113, BLACK, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
  LCD_Clear(0xffff);

}

void blink_eyes(){
  semiopened_eyes();
  closed_eyes();
  semiopened_eyes();
  opened_eyes();
  
  
}

void loop()
{
  look_left();
  opened_eyes();
  look_right();
  opened_eyes();
  blink_eyes();
  
  
  
}



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
