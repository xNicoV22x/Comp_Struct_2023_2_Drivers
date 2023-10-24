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

#endif /* INC_RING_BUFFER_H_ */
