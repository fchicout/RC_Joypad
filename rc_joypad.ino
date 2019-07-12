#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
 
Adafruit_SSD1306 dsp(-1);//cria o objeto do display para i2c 
 
 
void setup()
{
	dsp.begin(SSD1306_SWITCHCAPVCC, 0x3C);//inicia o display com endereco padrao
}
 
void loop()
{
	dsp.clearDisplay();//limpa a tela
  
	dsp.setTextColor(WHITE);//define o texto para branco (no display ficara azul)
 
	dsp.setTextSize(1);//define o tamanho do texto
	dsp.println("POT1:");//escreve na tela a mensagem
 
	dsp.setTextSize(3);
	dsp.println("2018");
	dsp.display();//mostra as alteracoes no display, sem isso nao ira mostrar nada!!
	delay(2000);
	
	// for (int8_t i = 0; i < 64; i++)
	// {
	// 	dsp.drawLine(0, 0, 128, i, WHITE);//desenha uma linha
	// 	dsp.display();//mostra na tela
	// 	delay(1);
	// }
 
	// for (int8_t i = 63; i > -1; i--)
	// {
	// 	dsp.drawLine(0, 0, 128, i, BLACK);
	// 	dsp.display();
	// 	delay(1);
	// }
}