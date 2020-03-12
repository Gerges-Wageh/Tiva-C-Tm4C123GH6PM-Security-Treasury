#include <stdbool.h>
#include <stdint.h>

#include "types.h"
#include "EEPROM.h"

// EEPROM Initialization

uint32 EEPROMInit(void)
	
{     uint32 ui32Status;   
	//enable EEPROM Clock
	RCGCEEPROM |= 0x00000001;
  // Insert delay 
	SysCtlDelay(2);
	// wait until EEDONE register is clear to indicate that eeprom is ready 
     while ( EEDONE != 0) 
	 {
		 ;
	 }
	//Support and status Control to be zero either there will be error 
	 ui32Status = Read_reg_32bit(EEPROM_EESUB);
    if(ui32Status & (EEPROM_EESUPP_PRETRY | EEPROM_EESUPP_ERETRY))
    {
        return(EEPROM_INIT_ERROR);
    }
	 
// RESET EEPROM module 
		SREEPROM &= 0x0;
		
// Insert a delay 
	SysCtlDelay(2);	

		  while ( EEDONE != 0) 
	 {
		 ;
	 }
	  ui32Status = Read_reg_32bit(EEPROM_EESUB);
    if(ui32Status & (EEPROM_EESUPP_PRETRY | EEPROM_EESUPP_ERETRY))
    {
        return(EEPROM_INIT_ERROR);
    }
	 
  
    return(EEPROM_INIT_OK);
}


//Read Data from EEPROM
uint8 EEPROMRead()
{    uint32 read_word;
	   uint8  read_byte;
	//Block number 1
    EEPROM_EEBLOCK &=  0x01;
	// Register number 0
	  EEPROM_EEOFFSET &=  0x00;
 // Return the data from register data pointed to by block and offset register 
    read_word=Read_reg_32bit(EEPROM_EERDWR);
// Return the specific byte with the 4 bit password 
	 read_byte = read_word & 0x00000001 ;
	return read_byte;


}
uint32_t EEPROMBlockPasswordSet( void )
{
	EEPROM_EEBLOCK =  0x01; //use block 1 
	EEPROM_EEOFFSET = 0x0;  // use register 0 in the block 1
	EEPROM_Protection= 0x02; 
	EEPROM_Password_EEPASS2 = 0x01 ; // password
	
}
void EEPROM_Write_passward (uint32_t *passward_4bit)
{ EEPROM_Password_EEPASS2 = 0x01 ;
	EEPROM_EEBLOCK =  0x01; //use block 1 
	EEPROM_EEOFFSET = 0x0;  // use register 0 in the block 1
	*passward_4bit &= 0x01;
  Write_reg_32bit(EEPROM_EERDWR,*passward_4bit);
	EEPROMBlockPasswordSet();
}


