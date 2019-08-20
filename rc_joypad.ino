#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#include <SPI.h>
#include "RF24.h"
 
// Cria o objeto do display para i2c 
Adafruit_SSD1306 dsp(-1); 

// Instância do Radio Transmissor
RF24 radio(9,10) 
// Endereço do Transmissor
const byte address[6] = "00006"; 
 
void setup()
{
	// Inicia o display com endereco padrão
	dsp.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	Serial.begin(9600);
	radio.begin();
	radio.openWritingPipe(address);
	radio.setPALevel(RF24_PA_HIGH);
	radio.stopListening();
}
 
void loop()
{
	// Inicia 
	dsp.clearDisplay();//limpa a tela
  
	dsp.setTextColor(WHITE);//define o texto para branco (no display ficara azul)
 
	dsp.setTextSize(1);//define o tamanho do texto
	dsp.println("POT1:");//escreve na tela a mensagem
 
	dsp.setTextSize(3);
	dsp.println("2018");
	dsp.display();//mostra as alteracoes no display, sem isso nao ira mostrar nada!!
	delay(10);
	
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

char[32] sendData(char* text){
	radio.write(&text, sizeof(text));
	radio.startListening();
	if (radio.available()){
		char text[32] = "";
		radio.read(&text, sizeof(text));
	}
	delay(10);
}