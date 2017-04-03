/****************************************************************************/
/*                                  Telemetry system                        */
/*------------------------------------------------------------- ------------*/
/*                                  Speed calculation                       */ 
/****************************************************************************/



#include <TimerOne.h>
int cont = 0 ;
float dist = 0 ;
int t_interrup = 30000 ;// Tempo de 1 microsegundo
unsigned int numero = 0 ;
int Raio = 7 ; //Raio da roda do Carrinho
float delta_contador = 0; //Variação do contador
float vel = 0 ; //Velocidade angular do carrinho
int bit15 = LOW; 
int bit14 = LOW;
int bit13 = LOW;
int bit12 = LOW;
int bit11 = LOW;
int bit10 = LOW;
int bit09 = LOW;
int bit08 = LOW;
int bit07 = LOW; 
int bit06 = LOW;
int bit05 = LOW;
int bit04 = LOW;
int bit03 = LOW;
int bit02 = LOW;
int bit01 = LOW;
int bit00 = LOW;
//----------------------------------
int OE = 5 ; // Bit OE setado na porta 5 do Arduino
int Sel = 4  ; // Bit Sel setado na porta 4 do Arduino
int RST = 3 ; // bit RST porta 3
//---------------------------------------------------------
int port13 = 13; //Portas de leitura no Arduino
int port12 = 12;
int port11 = 11;
int port10 = 10;
int port09 =  9;
int port08 =  8;
int port07 =  7;
int port06 =  6;

//---------------------------------------------------------

void leitura()
{

  digitalWrite(OE,LOW); //Inicia Leitura
  digitalWrite(Sel,LOW); //Lendo High Byte 
  bit15 = digitalRead(port13);
  bit14 = digitalRead(port12);
  bit13 = digitalRead(port11);
  bit12 = digitalRead(port10);
  bit11 = digitalRead(port09);
  bit10 = digitalRead(port08);
  bit09 = digitalRead(port07);
  bit08 = digitalRead(port06);
  //----------------------------------------------------------
  digitalWrite(Sel,HIGH); //Lendo LOW Byte 
  bit07 = digitalRead(port13);   
  bit06 = digitalRead(port12);
  bit05 = digitalRead(port11);
  bit04 = digitalRead(port10);
  bit03 = digitalRead(port09);
  bit02 = digitalRead(port08);
  bit01 = digitalRead(port07);
  bit00 = digitalRead(port06);
    
 digitalWrite(OE,HIGH);// Encerrar leitura
 digitalWrite(RST,LOW); // Reseta o contador de posição 
 digitalWrite(RST,HIGH); // Contador não resetado 
// ----------------------------------------------
  numero = 0  ; // Zerar a variavel de contagem da posição de leitura no encoder 
  
  // concatenação dos bits 
  numero = numero | (bit00 << 0 ); // bitXX vai para a posição XX e depois é somado com o valor anterior ( Operação OU )
  numero = numero | (bit01 << 1 );
  numero = numero | (bit02 << 2 );
  numero = numero | (bit03 << 3 );
  numero = numero | (bit04 << 4 );
  numero = numero | (bit05 << 5 );
  numero = numero | (bit06 << 6 );
  numero = numero | (bit07 << 7 );
  numero = numero | (bit08 << 8 );
  numero = numero | (bit09 << 9 );
  numero = numero | (bit10 << 10 );
  numero = numero | (bit11 << 11 );
  numero = numero | (bit12 << 12 );
  numero = numero | (bit13 << 13 );
  numero = numero | (bit14 << 14 );
  numero = numero | (bit15 << 15 );
//------------------------------------------------------------------------------------------------------------------------------------//

  delta_contador = ((numero));
  if (delta_contador <= 32768) // ate metade do contador a velocidade é positiva
  { 
   delta_contador = (numero);
  }
  else 
  {
    delta_contador = (delta_contador - 65535 ); // maximo do contador 2 elevado a 16 menos 1

  }
    
  Serial1.println(delta_contador);        
}


void setup() 
{
  Serial1.begin(9600);  //XBee pins 0 e 1
  Timer1.initialize(t_interrup);
  Timer1.attachInterrupt(leitura); 
  
  pinMode(RST,OUTPUT); // Pino Reset
  pinMode(OE,OUTPUT); //Pino OE
  pinMode(Sel,OUTPUT); //Pino Sel
  pinMode(6,INPUT);  //Bit 00
  pinMode(7,INPUT);  //Bit 01
  pinMode(8,INPUT);  //Bit 02
  pinMode(9,INPUT);  //Bit 03
  pinMode(10,INPUT); //Bit 04
  pinMode(11,INPUT); //Bit 05
  pinMode(12,INPUT); //Bit 06
  pinMode(13,INPUT); //Bit 07

 digitalWrite(OE,HIGH); //Inicia entrada de dados [TRIST STATE]
 digitalWrite(Sel,HIGH); //Lendo High Byte 
 numero = 0 ;
}

void loop()
{
 
}


