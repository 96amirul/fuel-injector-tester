//============================================================================================<p>//VARIABLES GLOBALES y CONSTANTES
//============================================================================================
const int b_800rpm = 8;
const int b_1500rpm = 7;
const int b_3600rpm = 10;
const int b_5000rpm = 11;
const int b_salir = 4;
const int b_consflujo = 3; //boton flujo constante al presionar
const int LEDReady = 13;  //Indicador Ready
const int LedRPM = 6;     //Indicador RPM en funcionamiento
const int LED800rpm = 5;  //Indicador 800rpm
const int LED1500rpm = 2; //Indicador 1500rpm
const int LED3600rpm = 12; //Indicador 3600rpm
const int LED5000rpm = A0; //Indicador 5000rpm
const int inject1 = 9;    //pin de injeccion pin9</p><p>//estas variables guardan el flash pattern
int inject_State = LOW;             // estado utilizado para setear el pin
unsigned long previousMillis = 0;        // sera guardara la ultima vez que el pin injeccion fue actualizado</p><p>//Estados de pin Entradas (botones)
int eb_800rpm;
int eb_1500rpm;
int eb_3600rpm;
int eb_5000rpm;
//int eb_usonido;
int eb_salir;
int eb_consflujo;</p><p>//============================================================================================
//SETUP
//============================================================================================
void setup() {
  
  //entradas
  pinMode (b_800rpm, INPUT);
  pinMode (b_1500rpm, INPUT);
  pinMode (b_3600rpm, INPUT);
  pinMode (b_5000rpm, INPUT);
  pinMode (b_salir, INPUT);
  pinMode (b_consflujo, INPUT);
  //pinMode (b_usonido, INPUT);</p><p>  //Salidas
  pinMode (LEDReady, OUTPUT);
  pinMode (LedRPM, OUTPUT);
  pinMode (inject1, OUTPUT);
  pinMode (LED800rpm, OUTPUT);
  pinMode (LED1500rpm, OUTPUT);
  pinMode (LED3600rpm, OUTPUT);
  pinMode (LED5000rpm, OUTPUT);</p><p> // analogReference(INTERNAL);
  Serial.begin(9600);
  digitalWrite (LEDReady, HIGH);
}</p><p>//============================================================================================
//VOID LOOP
//============================================================================================
void loop() {</p><p>  eb_800rpm = digitalRead(b_800rpm);
  eb_1500rpm = digitalRead(b_1500rpm);
  eb_3600rpm = digitalRead(b_3600rpm);
  eb_5000rpm = digitalRead(b_5000rpm);
  //eb_usonido = digitalRead(b_usonido);
  eb_salir = digitalRead(b_salir);
  eb_consflujo = digitalRead(b_consflujo);</p><p>//SELECCION DE SUB RUTINAS - FUNCIONES DE PULSOS</p><p>  //activa a 800rpm
  if (eb_800rpm == HIGH)
  {
    Pulse_800rpm();
  }
  //activa a 1500rpm
  if (eb_1500rpm == HIGH)
  {
    Pulse_1500rpm ();
  }
  //activa a 3600rpm
  if (eb_3600rpm == HIGH)
  {
    Pulse_3600rpm ();
  }</p><p>  //activa a 5000rpm
  if (eb_5000rpm == HIGH)
  {
    Pulse_5000rpm ();
  }</p><p>  //activa inject1 mientras este presionado luego apaga al soltar el boton
  if (eb_consflujo == HIGH)
  {
  digitalWrite(inject1, HIGH);
  }
    else 
      {
        digitalWrite(inject1, LOW);
       }  
 
 
/*  //activa el limpiador ultrasonido
  if (eb_usonido == HIGH)
  {
    u_sonido ();
  }
*/
}   //cierra el void loop()</p><p>//============================================================================================
//SUB RUTINAS
//============================================================================================</p><p>void Pulse_800rpm() {
afuera:
  delay(300);
  for (; ;) {   //800RPM aproximadamente Modo IDLE
    digitalWrite(LedRPM, HIGH);
    digitalWrite(LED800rpm, HIGH);
    eb_salir = digitalRead(b_salir);
    long OnTime = 76;           // tiempo encendido en milisegundos
    long OffTime = 61;          // tiempo apagado en milisegundos</p><p>    // verifica si cambio el tiempo del estado del pin de injeccion
    unsigned long currentMillis = millis();</p><p>    if ((inject_State == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      inject_State = LOW;  // lo apaga
      previousMillis = currentMillis;  // Recuerda el tiempo
      digitalWrite(inject1, inject_State);  // actualiza el Inject1 actual
    }
    else if ((inject_State == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      inject_State = HIGH;  // lo encuende
      previousMillis = currentMillis;   // Rercuerda el tiempo
      digitalWrite(inject1, inject_State);   // actualiza el Inject1 actual
    }</p><p>    else if (eb_salir == HIGH) {
      digitalWrite(LedRPM, LOW); //apaga el led RPM
      digitalWrite(LED800rpm, LOW);
      break;
    }</p><p>  }</p><p>}</p><p>void Pulse_1500rpm() {
afuera:
  delay(300);
  for (; ;) {   //1500RPM 
    digitalWrite(LedRPM, HIGH);
    digitalWrite(LED1500rpm, HIGH);
    eb_salir = digitalRead(b_salir);
    long OnTime = 40;           // tiempo encendido en milisegundos
    long OffTime = 32;          // tiempo apagado en milisegundos</p><p>    // verifica si cambio el tiempo del estado del pin de injeccion
    unsigned long currentMillis = millis();</p><p>    if ((inject_State == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      inject_State = LOW;  // lo apaga
      previousMillis = currentMillis;  // Recuerda el tiempo
      digitalWrite(inject1, inject_State);  // actualiza el Inject1 actual
    }
    else if ((inject_State == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      inject_State = HIGH;  // lo encuende
      previousMillis = currentMillis;   // Rercuerda el tiempo
      digitalWrite(inject1, inject_State);   // actualiza el Inject1 actual
    }</p><p>    else if (eb_salir == HIGH) {
      digitalWrite(LedRPM, LOW); //apaga el led RPM
      digitalWrite(LED1500rpm, LOW);
      break;
    }</p><p>  }</p><p>}</p><p>void Pulse_3600rpm() {
afuera:
  delay(300);
  for (; ;) {   //3600RPM 
    digitalWrite(LedRPM, HIGH);
    digitalWrite(LED3600rpm, HIGH);
    eb_salir = digitalRead(b_salir);
    long OnTime = 16.6;           // tiempo encendido en milisegundos
    long OffTime = 13.28;          // tiempo apagado en milisegundos</p><p>    // verifica si cambio el tiempo del estado del pin de injeccion
    unsigned long currentMillis = millis();</p><p>    if ((inject_State == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      inject_State = LOW;  // lo apaga
      previousMillis = currentMillis;  // Recuerda el tiempo
      digitalWrite(inject1, inject_State);  // actualiza el Inject1 actual
    }
    else if ((inject_State == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      inject_State = HIGH;  // lo encuende
      previousMillis = currentMillis;   // Rercuerda el tiempo
      digitalWrite(inject1, inject_State);   // actualiza el Inject1 actual
    }</p><p>    else if (eb_salir == HIGH) {
      digitalWrite(LedRPM, LOW); //apaga el led RPM
      digitalWrite(LED3600rpm, LOW);
      break;
    }</p><p>  }</p><p>}</p><p>void Pulse_5000rpm() {
afuera:
  delay(300);
  for (; ;) {   //5000RPM 
    digitalWrite(LedRPM, HIGH);
    digitalWrite(LED5000rpm, HIGH);
    eb_salir = digitalRead(b_salir);
    long OnTime = 10.52;           // tiempo encendido en milisegundos
    long OffTime = 8.4;          // tiempo apagado en milisegundos</p><p>    // verifica si cambio el tiempo del estado del pin de injeccion
    unsigned long currentMillis = millis();</p><p>    if ((inject_State == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      inject_State = LOW;  // lo apaga
      previousMillis = currentMillis;  // Recuerda el tiempo
      digitalWrite(inject1, inject_State);  // actualiza el Inject1 actual
    }
    else if ((inject_State == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      inject_State = HIGH;  // lo encuende
      previousMillis = currentMillis;   // Rercuerda el tiempo
      digitalWrite(inject1, inject_State);   // actualiza el Inject1 actual
    }</p><p>    else if (eb_salir == HIGH) {
      digitalWrite(LedRPM, LOW); //apaga el led RPM
      digitalWrite(LED5000rpm, LOW);
      break;
    }</p><p>  }</p><p>}</p><p>/*Esta parte sera dejada para programar correctamente el tiempo de encendido ya pagado 
de la limpiadora ultra sonido*</p><p>*
void u_sonido() {
afuera:
  delay(300);
  for (; ;) {   //800RPM aproximadamente Modo IDLE
    digitalWrite(LedRPM, HIGH);       //indicador RPM
    digitalWrite(ledusonido, HIGH);   //enciende led indicador ultra sonido
    eb_salir = digitalRead(b_salir);  //Estado boton salir
    
    unsigned long time = millis();
    int toggle = 1;
    
   digitalWrite(d_usonido, LOW);    //enciende la ultrasonido
   // delay (10);
   // digitalWrite(d_usonido, LOW);     //apaga el estado de d_usonido para dejar listo para otro proceso
   
 if(millis()-time > 1000)     //Has one second passed?
  {
    toggle = !toggle;          //If so not toggle 
    digitalWrite(d_usonido, toggle);  //toggle usonido
    time = millis();           //and reset time.
  }
  
    long OnTime = 76;           // tiempo encendido en milisegundos
    long OffTime = 61;          // tiempo apagado en milisegundos</p><p>    // verifica si cambio el tiempo del estado del pin de injeccion
    unsigned long currentMillis = millis();</p><p>    if ((inject_State == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      inject_State = LOW;  // lo apaga
      previousMillis = currentMillis;  // Recuerda el tiempo
      digitalWrite(inject1, inject_State);  // actualiza el Inject1 actual
    }
    else if ((inject_State == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      inject_State = HIGH;  // lo encuende
      previousMillis = currentMillis;   // Rercuerda el tiempo
      digitalWrite(inject1, inject_State);   // actualiza el Inject1 actual
    }</p><p>    else if (eb_salir == HIGH) {
      digitalWrite(LedRPM, LOW); //apaga el led RPM
      digitalWrite(ledusonido, LOW); //apaga el indicador de limpiadora ultrasonido
      break;
    }</p><p>  }</p><p>}
*/</p>
