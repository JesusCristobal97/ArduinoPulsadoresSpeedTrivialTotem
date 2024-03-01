#include "Keyboard.h"
// Definir los pines para los botones
const int botonRojo = 2;
const int botonAzul = 4;
const int botonAmarillo = 7;
const int botonVerde = 8;

unsigned long tiempoBloqueo = 0; // Variable para almacenar el tiempo hasta el cual se bloquean los botones
const unsigned long retardoBloqueo = 1000; // Tiempo de bloqueo en milisegundos

void setup() {
  // Iniciar comunicación serial 
 
  pinMode(botonRojo, INPUT_PULLUP);
  pinMode(botonAzul, INPUT_PULLUP);
  pinMode(botonAmarillo, INPUT_PULLUP);
  pinMode(botonVerde, INPUT_PULLUP);

  Keyboard.begin();
}

void loop() {
  unsigned long tiempoActual = millis();

   if (tiempoActual > tiempoBloqueo) {
    // Leer el estado de los botones
    int estadoRojo = digitalRead(botonRojo);
    int estadoAzul = digitalRead(botonAzul);
    int estadoAmarillo = digitalRead(botonAmarillo);
    int estadoVerde = digitalRead(botonVerde);

    // Si se presiona el botón rojo, devolver la letra 'R'
    if (estadoRojo == LOW) {
      Keyboard.write('S');
      tiempoBloqueo = tiempoActual + retardoBloqueo;
    }

    // Si se presiona el botón azul, devolver la letra 'A'
    if (estadoAzul == LOW) {
      Keyboard.write('A');
      tiempoBloqueo = tiempoActual + retardoBloqueo;
    }

    // Si se presiona el botón amarillo, devolver la letra 'A'
    if (estadoAmarillo == LOW) {
      Keyboard.write('D');
    tiempoBloqueo = tiempoActual + retardoBloqueo;
    }

    // Si se presiona el botón verde, devolver la letra 'V'
    if (estadoVerde == LOW) {
      Keyboard.write('F');
      tiempoBloqueo = tiempoActual + retardoBloqueo;
    }
  }
}