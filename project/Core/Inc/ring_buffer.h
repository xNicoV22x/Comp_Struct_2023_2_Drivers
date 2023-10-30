/*
 * ring_buffer.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Nicolas
 */

#ifndef INC_RING_BUFFER_H_
#define INC_RING_BUFFER_H_

//Libreria estandar para enteros incluida
#include <stdint.h>

//definicion de un tipo(macro en C) / tipo = estructura
typedef struct {
	uint8_t *buffer; 	/*!\ Pointer to memory location */ //*: Apuntador A Memoria
	uint16_t head;	 	/*!\ To write new data */
	uint16_t tail;   	/*!\ To read old data */

	uint16_t capacity;	//Capacidad
	uint16_t is_full;  	//Buffer lleno

} ring_buffer_t; //Se refiere a un tipo de estructura (nombre) *la t se usa como conveción


//Crear y declarar la funcion de inicialización
void ring_buffer_init(ring_buffer_t *ring_buffer, uint8_t *buffer, uint16_t capacity);

//Crear función para poner datos en el buffer con la estructura de control
uint8_t ring_buffer_put(ring_buffer_t *ring_buffer, uint8_t data);

//Crear e implementar el prototipo de la función de leer
uint8_t ring_buffer_get(ring_buffer_t *ring_buffer, uint8_t *data);

uint16_t ring_buffer_size(ring_buffer_t *ring_buffer);

uint8_t ring_buffer_is_empty(ring_buffer_t *ring_buffer);

#endif /* INC_RING_BUFFER_H_ */
