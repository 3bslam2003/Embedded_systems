/*
 * I2C_programe.c
 *
 *  Created on: Dec 3, 2024
 *      Author: HP
 */

#include "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "I2C_interface.h"
#include  "I2c_config.h"
#include "I2C_private.h"



void MASTER_init(u8 copy_adress)
{
if(TWI_PRESCALLER==PRESCALLER_BY_1)
{
	TWSR=0;

}
else if(TWI_PRESCALLER==PRESCALLER_BY_4)
{
	TWSR=1;
}
else if(TWI_PRESCALLER==PRESCALLER_BY_16)
{
	TWSR=2;
}
else if(TWI_PRESCALLER==PRESCALLER_BY_64)
{
	TWSR=3;
}
	TWBR= (u8) (((F_CPU/SCL_Clock)-16) / (2*TWI_PRESCALLER));
	if(copy_adress!=Null)
	{
		TWAR=(copy_adress<<1);
	}
	SET_BIT(TWCR,TWCR_TWEA);
	SET_BIT(TWCR,TWCR_TWEN);


}

void SLAVE_init(u8 copy_adress)
{

	TWAR=(copy_adress<<1);
	SET_BIT(TWCR,TWCR_TWEA);
		SET_BIT(TWCR,TWCR_TWEN);

}


TWI_ErrStatus  I2C_sendstart(void)
{
	TWI_ErrStatus  LOC_error=NoError;
SET_BIT(TWCR,TWCR_TWST);
SET_BIT(TWCR,TWCR_TWI);

while(GET_BIT(TWCR,TWCR_TWI)==0);

if((TWSR & 0xf8 )!=START_ACK)
{
	LOC_error=StartConditionErr;
}
else
{

}
return LOC_error;
}
TWI_ErrStatus  I2C_repeatstart(void)
{
	TWI_ErrStatus  LOC_error=NoError;
SET_BIT(TWCR,TWCR_TWST);
SET_BIT(TWCR,TWCR_TWI);

while(GET_BIT(TWCR,TWCR_TWI)==0);

if((TWSR & 0xf8 )!=REP_START_ACK)
{
	LOC_error=RepeatedStartError;
}
else
{

}
return LOC_error;
}
TWI_ErrStatus Master_sendslavewithwrite(u8 copy_slave_adress)
{
	TWI_ErrStatus  LOC_error=NoError;
	TWDR=(copy_slave_adress<<1);
	CLR_BIT(TWDR,0);
	CLR_BIT(TWCR,TWCR_TWST);
	SET_BIT(TWCR,TWCR_TWI);

	while(GET_BIT(TWCR,TWCR_TWI)==0);

	if((TWSR & 0xf8 )!= SLAVE_ADD_AND_WR_ACK)
	{
		LOC_error=SlaveAddressWithWriteErr;
	}
	else
	{

	}
	return LOC_error;

}
TWI_ErrStatus  Master_sendslavewithread(u8 copy_slave_adress)
{
	TWI_ErrStatus  LOC_error=NoError;
	TWDR=(copy_slave_adress<<1);
	SET_BIT(TWDR,0);
	CLR_BIT(TWCR,TWCR_TWST);
	SET_BIT(TWCR,TWCR_TWI);

	while(GET_BIT(TWCR,TWCR_TWI)==0);

	if((TWSR & 0xf8 )!= SLAVE_ADD_AND_RD_ACK)
	{
		LOC_error=SlaveAddressWithReadErr;
	}
	else
	{

	}
	return LOC_error;
}
TWI_ErrStatus  Master_senddatabyte(u8 copy_data)
{
	TWI_ErrStatus  LOC_error=NoError;
	TWDR=copy_data;
	SET_BIT(TWCR,TWCR_TWI);

	while(GET_BIT(TWCR,TWCR_TWI)==0);

	if((TWSR & 0xf8 )!= MSTR_WR_BYTE_ACK )
	{
		LOC_error=MasterWriteByteErr;
	}
	else
	{

	}
	return LOC_error;
}
TWI_ErrStatus  Master_readdatabyte(u8* copy_data)
{
	TWI_ErrStatus  LOC_error=NoError;

		SET_BIT(TWCR,TWCR_TWI);

		while(GET_BIT(TWCR,TWCR_TWI)==0);

		if((TWSR & 0xf8 )!=MSTR_RD_BYTE_WITH_ACK  )
		{
			LOC_error=MasterReadByteErr;
		}
		else
		{
			* copy_data=TWDR;
		}
		return LOC_error;
}

TWI_ErrStatus Slave_transmit_data(u8 copy_data)
{
	TWI_ErrStatus  LOC_error=NoError;
	SET_BIT(TWCR,TWCR_TWI);
				while(GET_BIT(TWCR,TWCR_TWI)==0);

				if((TWSR & 0xf8 )!=SLAVE_ADD_RCVD_WR_REQ)
					{
						LOC_error=SlaveWriteByteErr;
					}
				else
					{

					}

				TWDR=(copy_data);
				SET_BIT(TWCR,TWCR_TWI);

			while(GET_BIT(TWCR,TWCR_TWI)==0);

			if((TWSR & 0xf8 )!=SLAVE_BYTE_TRANSMITTED  )
			{
				LOC_error=SlaveWriteByteErr;
			}
			else
			{

			}
			return LOC_error;
}
TWI_ErrStatus Slave_receive_data(u8* copy_data)
{
			TWI_ErrStatus  LOC_error=NoError;
				SET_BIT(TWCR,TWCR_TWI);
				while(GET_BIT(TWCR,TWCR_TWI)==0);

				if((TWSR & 0xf8 )!=SLAVE_ADD_RCVD_RD_REQ )
					{
						LOC_error=SlaveReadByteErr;
					}
				else
					{

					}
				SET_BIT(TWCR,TWCR_TWI);
				while(GET_BIT(TWCR,TWCR_TWI)==0);

				if((TWSR & 0xf8 )!=SLAVE_DATA_RECEIVED )
				{
					LOC_error=SlaveReadByteErr;
				}
				else
				{
					* copy_data=TWDR;
				}
				return LOC_error;
}

void I2C_stopcondition()
{
SET_BIT(TWCR,TWCR_TWSTO);
SET_BIT(TWCR,TWCR_TWI);
}


