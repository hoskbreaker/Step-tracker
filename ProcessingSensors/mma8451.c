#include <stdbool.h>
#include "i2c.h"
#include "mma8451.h"

//extern I2c_t I2c;

static inline void write_byte(uint8_t, uint8_t, uint8_t);
static inline void write_word(uint8_t, uint8_t, uint16_t);
static inline uint8_t read_byte(uint8_t, uint8_t);
static inline uint16_t read_word(uint8_t, uint8_t);

static uint8_t I2cDeviceAddr = MMA8451_I2C_ADDRESS;

static bool MMA8451Initialized = false;

void MMA8451SetDeviceAddr( uint8_t addr );

/*!
 * \brief Gets the I2C device slave address
 *
 * \retval: addr Current device slave address
 */
uint8_t MMA8451GetDeviceAddr( void );

uint8_t MMA8451Init( void )
{
    uint8_t regVal;

    MMA8451SetDeviceAddr( MMA8451_I2C_ADDRESS );

    if( MMA8451Initialized == false )
    {
        MMA8451Initialized = true;

        //MMA8451Read( MMA8451_ID, &regVal );
        regVal = read_byte(MMA8451_I2C_ADDRESS, MMA8451_ID);
        if( regVal != 0x1A )   // Fixed Device ID Number = 0x1A
        {
            return 1;
        }
        MMA8451Reset( );

        // INT pins on this chip default to push-pull output
        // set them to open drain.
        //MMA8451Write( MMA8451_CTRL_REG3, 0x01 );
        MMA8451OrientDetect( );
    }
    return 0;
}


uint8_t MMA8451Reset( )
{
    //MMA8451Write( 0x2B, 0x40 )
    uint8_t word;
    write_byte(MMA8451_I2C_ADDRESS, MMA8451_CTRL_REG2,0x40 & 0xff );//RESET ENABLE
    word = read_byte (MMA8451_I2C_ADDRESS, MMA8451_CTRL_REG2);
    if( word == 0 ) // Reset the MMA8451 with CTRL_REG2
    {
        return 0;
    }
    return 1;
}


void MMA8451SetDeviceAddr( uint8_t addr )
{
    I2cDeviceAddr = addr;
}

uint8_t MMA8451GetDeviceAddr( void )
{
    return I2cDeviceAddr;
}

uint8_t MMA8451GetXAxis( void )
{
    uint8_t orientation;

//    MMA8451Read( MMA8451_PL_STATUS, &orientation );
    orientation = read_byte(MMA8451_I2C_ADDRESS, MMA8451_OUT_X_MSB);
    return orientation;
}
uint8_t MMA8451GetYAxis( void )
{
    uint8_t orientation;

//    MMA8451Read( MMA8451_PL_STATUS, &orientation );
    orientation = read_byte(MMA8451_I2C_ADDRESS, MMA8451_OUT_Y_MSB);
    return orientation;
}

uint8_t MMA8451GetZAxis( void )
{
    uint8_t orientation;

//    MMA8451Read( MMA8451_PL_STATUS, &orientation );
    orientation = read_byte(MMA8451_I2C_ADDRESS, MMA8451_OUT_Z_MSB);
    return orientation;
}

uint8_t MMA8451Status( void )
{
    uint8_t estado;
    estado = read_byte(MMA8451_I2C_ADDRESS, MMA8451_STATUS);
    return estado;
}

void MMA8451StandBy( void )
{
    uint8_t ctrl;
    ctrl = read_byte(MMA8451_I2C_ADDRESS, MMA8451_CTRL_REG1);
    uint8_t StandBy =ctrl & ~MMA8451_ACTIVE_MASK;
    write_byte(MMA8451_I2C_ADDRESS, MMA8451_CTRL_REG1, StandBy);
}
void MMA8451Active ( void )
{
    uint8_t ctrl;
    ctrl = read_byte(MMA8451_I2C_ADDRESS, MMA8451_CTRL_REG1);
    uint8_t Active= ctrl | MMA8451_ACTIVE_MASK;
    write_byte(MMA8451_I2C_ADDRESS, MMA8451_CTRL_REG1, Active);
}
void MMA8451_2g ( void )
{
    uint8_t ctrl, mode_2g;
    MMA8451StandBy();
    ctrl = read_byte(MMA8451_I2C_ADDRESS, MMA8451_XYZ_DATA_CFG);
    mode_2g = ctrl & 0xff;
    write_byte (MMA8451_I2C_ADDRESS, MMA8451_XYZ_DATA_CFG, mode_2g);
    MMA8451Active();
}
void MMA8451_4g ( void )
{
    uint8_t ctrl, mode_2g, mode_4g;
    MMA8451StandBy();
    ctrl = read_byte(MMA8451_I2C_ADDRESS, MMA8451_XYZ_DATA_CFG);
    mode_2g= ctrl & 0xff;
    mode_4g = ctrl | 0x01;
    write_byte (MMA8451_I2C_ADDRESS, MMA8451_XYZ_DATA_CFG, mode_2g);
    write_byte (MMA8451_I2C_ADDRESS, MMA8451_XYZ_DATA_CFG, mode_4g);
    MMA8451Active();
}
void MMA8451_8g ( void )
{
    uint8_t ctrl, mode_2g, mode_8g;
    MMA8451StandBy();
    ctrl = read_byte(MMA8451_I2C_ADDRESS, MMA8451_XYZ_DATA_CFG);
    mode_2g = ctrl & 0xff;
    mode_8g = ctrl | 0x02;
    write_byte (MMA8451_I2C_ADDRESS, MMA8451_XYZ_DATA_CFG, mode_2g);
    write_byte (MMA8451_I2C_ADDRESS, MMA8451_XYZ_DATA_CFG, mode_8g);
    MMA8451Active();
}

void MMA8451DataRate( void )
{
    uint8_t DRValue = MMA8451_DR_100_HZ;
    uint8_t ctrl;
    MMA8451StandBy();
    ctrl = read_byte(MMA8451_I2C_ADDRESS, MMA8451_CTRL_REG1);
    write_byte(MMA8451_I2C_ADDRESS, MMA8451_CTRL_REG1, ctrl & 0xff);
    write_byte(MMA8451_I2C_ADDRESS, MMA8451_CTRL_REG1, ctrl | DRValue);
    MMA8451Active();
}
void MMA8451OverSampling(uint8_t mode)
{
    uint8_t ctrl;
    MMA8451StandBy();
    ctrl = read_byte(MMA8451_I2C_ADDRESS, MMA8451_CTRL_REG2);
    write_byte(MMA8451_I2C_ADDRESS, MMA8451_CTRL_REG2, ctrl & 0xff);
    if(mode == MMA8451_OSM_LNLP){
        write_byte(MMA8451_I2C_ADDRESS, MMA8451_CTRL_REG2, ctrl | MMA8451_OSM_LNLP);
        MMA8451Active();
    }else if(mode == MMA8451_OSM_HR){
        write_byte(MMA8451_I2C_ADDRESS, MMA8451_CTRL_REG2, ctrl | MMA8451_OSM_HR);
        MMA8451Active();
    }else if(mode == MMA8451_OSM_LP){
        write_byte(MMA8451_I2C_ADDRESS, MMA8451_CTRL_REG2, ctrl | MMA8451_OSM_LP);
        MMA8451Active();
    }else if(mode == MMA8451_OSM_N){
        MMA8451Active();
    }
}
void MMA8451FilterCutOff( void )
{
    uint8_t FCOValue = MMA8451_FCO_0;
    uint8_t ctrl;
    MMA8451StandBy();
    ctrl = read_byte(MMA8451_I2C_ADDRESS, MMA8451_HP_FILTER_CUTOFF);
    write_byte(MMA8451_I2C_ADDRESS, MMA8451_HP_FILTER_CUTOFF, ctrl & 0xff);
    write_byte(MMA8451_I2C_ADDRESS, MMA8451_HP_FILTER_CUTOFF, ctrl | FCOValue);
    MMA8451Active();
}
void MMA8451OrientDetect( void )
{
    MMA8451_2g();
    MMA8451DataRate();
    MMA8451OverSampling(MMA8451_OSM_N);
}
static inline void write_byte(uint8_t slave_addr, uint8_t reg, uint8_t byte)
{
    uint8_t buf[2];

    //buf[0] = TSL2561_CMD | (reg & 0xf);
    buf[0] = reg ;
    buf[1] = byte;
    i2c_write(slave_addr, buf, sizeof buf, STOP);
    while (i2c_busy())
        ;
}

static inline void write_word(uint8_t slave_addr, uint8_t reg, uint16_t word)
{
    uint8_t buf[3];

    //buf[0] = TSL2561_CMD | TSL2561_WORD | (reg & 0xf);
    buf[0] = reg;
    buf[1] = word;
    buf[2] = word >> 8;
    i2c_write(slave_addr, buf, sizeof buf, STOP);
    while (i2c_busy())
        ;
}
static inline uint8_t read_byte(uint8_t slave_addr, uint8_t reg)
{
//    uint8_t cmd = (reg & 0xf), buf;
    uint8_t cmd = (reg & 0xf), buf;

    i2c_write(slave_addr, &cmd, sizeof cmd, RSTART);
    while (i2c_busy())
        ;
    i2c_read(slave_addr, &buf, sizeof buf);
    while (i2c_busy())
        ;

    return buf;
}

static inline uint16_t read_word(uint8_t slave_addr, uint8_t reg)
{
    //uint8_t cmd = TSL2561_CMD | TSL2561_WORD | (reg & 0xf), buf[2];
    uint8_t cmd = (reg & 0xff);
    uint8_t buf[2];

    i2c_write(slave_addr, &cmd, sizeof cmd, RSTART);
    while (i2c_busy())
        ;
    i2c_read(slave_addr, buf, sizeof buf);
    while (i2c_busy())
        ;

    return (buf[1] << 8) | buf[0];
}
