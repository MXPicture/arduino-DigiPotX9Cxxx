/*
 * DigiPotX9Cxxx.h - Arduino library for managing digital potentiometers X9Cxxx (xxx = 102,103,104,503).
 * By Timo Fager, Jul 29, 2011.
 * Released to public domain.
 **/

#ifndef DigiPotX9Cxxx_h
#define DigiPotX9Cxxx_h

#include "Arduino.h"

#define DIGIPOT_UP   HIGH
#define DIGIPOT_DOWN LOW
#define DIGIPOT_MAX_AMOUNT 99
#define DIGIPOT_UNKNOWN 255

class DigiPot
{
 public:
  DigiPot();
  DigiPot(uint8_t incPin, uint8_t udPin, uint8_t csPin);
  void setup(uint8_t incPin, uint8_t udPin, uint8_t csPin);
  void increase(uint8_t amount);
  void decrease(uint8_t amount);
  void change(uint8_t direction, uint8_t amount);
  void set(uint8_t value);
  uint8_t get();
  void reset();

  virtual void overwrite(uint8_t value) { this->_currentValue = constrain(value, 0, DIGIPOT_MAX_AMOUNT); }; //! no movement is performed
  
  virtual void setDelayMicros(uint16_t micros) { this->_delayMicros = micros; };
  virtual uint16_t getDelayMicros() { return this->_delayMicros; };

 private:
  uint8_t _incPin;
  uint8_t _udPin;
  uint8_t _csPin;
  uint8_t _currentValue;
  uint16_t _delayMicros = 2;
};

#endif
