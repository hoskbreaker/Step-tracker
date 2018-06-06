#ifndef __MMA8451_H__
#define __MMA8451_H__

#include <stdint.h>

/*
 * MMA8451 I2C address
 */
#define MMA8451_I2C_ADDRESS                          0x1C // 0x1C connected to GND
#define MMA8451_ACTIVE_MASK                          0x01 //


/*
 * MMA8451 Data Rate Values
 */
#define MMA8451_DR_800_HZ                            0x00 //
#define MMA8451_DR_400_HZ                            0x01 //
#define MMA8451_DR_200_HZ                            0x02 //
#define MMA8451_DR_100_HZ                            0x03 //
#define MMA8451_DR_50_HZ                             0x04 //
#define MMA8451_DR_12_5_HZ                           0x05 //
#define MMA8451_DR_6_25_HZ                           0x06 //
#define MMA8451_DR_1_563_HZ                          0x07 //

/*
 * MMA8451 Oversampling Modes
 */
#define MMA8451_OSM_N                                0x00 //
#define MMA8451_OSM_LNLP                             0x01 //
#define MMA8451_OSM_HR                               0x02 //
#define MMA8451_OSM_LP                               0x03 //

/*
 * MMA8451 Filter Cut Off Modes
 */
#define MMA8451_FCO_0                                0x00 //
#define MMA8451_FCO_1                                0x01 //
#define MMA8451_FCO_2                                0x02 //
#define MMA8451_FCO_3                                0x03 //


/*
 * MMA8451 Registers
 */
#define MMA8451_STATUS                               0x00 //
#define MMA8451_OUT_X_MSB                            0x01 //
#define MMA8451_OUT_X_LSB                            0x02 //
#define MMA8451_OUT_Y_MSB                            0x03 //
#define MMA8451_OUT_Y_LSB                            0x04 //
#define MMA8451_OUT_Z_MSB                            0x05 //
#define MMA8451_OUT_Z_LSB                            0x06 //
#define MMA8451_SYSMOD                               0x0B //
#define MMA8451_INT_SOURCE                           0x0C //
#define MMA8451_ID                                   0x0D //
#define MMA8451_XYZ_DATA_CFG                         0x0E //
#define MMA8451_HP_FILTER_CUTOFF                     0x0F //
#define MMA8451_PL_STATUS                            0x10 //
#define MMA8451_PL_CFG                               0x11 //
#define MMA8451_PL_COUNT                             0x12 // Orientation debounce
#define MMA8451_PL_BF_ZCOMP                          0x13 //
#define MMA8451_PL_THS_REG                           0x14 //
#define MMA8451_FF_MT_SRC                            0x16 //
#define MMA8451_TRANSIENT_CFG                        0x1D // Transient enable
#define MMA8451_TRANSIENT_SRC                        0x1E // Transient read/clear interrupt
#define MMA8451_TRANSIENT_THS                        0x1F // Transient threshold
#define MMA8451_TRANSIENT_COUNT                      0x20 // Transient debounce
#define MMA8451_PULSE_SRC                            0x22 //
#define MMA8451_CTRL_REG1                            0x2A //
#define MMA8451_CTRL_REG2                            0x2B //
#define MMA8451_CTRL_REG3                            0x2C // Interrupt control
#define MMA8451_CTRL_REG4                            0x2D // Interrupt enable
#define MMA8451_CTRL_REG5                            0x2E // Interrupt pin selection

/*!
 * \brief Initializes the device
 *
 * \retval status [SUCCESS, FAIL]
 */
uint8_t MMA8451Init( void );

/*!
 * \brief Resets the device
 *
 * \retval status [SUCCESS, FAIL]
 */
uint8_t MMA8451Reset( void );

/*!
 * \brief Initializes the orientation detection
 */
void MMA8451OrientDetect( void );

/*!
 * \brief Gets the orientation state.
 *
 * \retval orientation Bit 6 [1: Horizontal, 0: Vertical]
 *                     Bit 0 [1: Face down, 0: Face up]
 *                     Other bits don't care.
 */

//------------added----------------------//
uint8_t MMA8451GetXAxis( void );
uint8_t MMA8451GetYAxis( void );
uint8_t MMA8451GetZAxis( void );
uint8_t MMA8451Status( void );
void MMA8451StandBy( void );
void MMA8451Active ( void );
void MMA8451_2g ( void );
void MMA8451_4g ( void );
void MMA8451_8g ( void );
void MMA8451DataRate( void );
void MMA8451OverSampling ( uint8_t mode);
//---------------------------------------//
#endif // __MMA8451_H__
