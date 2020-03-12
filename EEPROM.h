#ifndef EEPROM_H_
#define EEPROM_H_
#include "types.h"

//Macros
#define Write_reg_32bit(address,val) ((*(volatile uint32*)(address))=val)
#define Read_reg_32bit(address) *(volatile uint32*)(address)
#define EEPROM_INIT_OK      0
#define EEPROM_INIT_ERROR   1
// Addresses
#define EEPROM_EESUPP_ERETRY    0x00000004  // Erase Must Be Retried
#define EEPROM_EESUPP_PRETRY    0x00000008
#define RCGCEEPROM             (*((volatile unsigned long *)0x400FE658))
#define EEDONE                 (*((volatile unsigned long *)0x400AF018))
#define SREEPROM               (*((volatile unsigned long *)0x400FE558))
#define EEPROM_EEBLOCK         (*((volatile unsigned long *)0x400AF004))   // EEPROM Current Block
#define EEPROM_EEOFFSET        (*((volatile unsigned long *)0x400AF008))   // EEPROM Current Offset
#define EEPROM_EERDWR          (*((volatile unsigned long *)0x400AF010))   // EEPROM Read-Write Data 
#define EEPROM_EESUB           (*((volatile unsigned long *)0x400FE567))
#define EEPROM_Unlock          (*((volatile unsigned long *)0x0x400AF020))
#define EEPROM_Protection       (*((volatile unsigned long *)0x400AF030))
#define EEPROM_Password_EEPASS2 (*((volatile unsigned long *)0x400AF03C))
// Functions Prototypes 
uint32  EEPROMInit(void);
uint8 EEPROMRead(void);
uint32 EEPROMBlockPasswordSet( void );
void EEPROMWrite (uint32  *passward_4bit);









































#endif