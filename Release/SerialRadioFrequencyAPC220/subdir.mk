################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SerialRadioFrequencyAPC220/SerialRadioFrequencyAPC220.cpp 

OBJS += \
./SerialRadioFrequencyAPC220/SerialRadioFrequencyAPC220.o 

CPP_DEPS += \
./SerialRadioFrequencyAPC220/SerialRadioFrequencyAPC220.d 


# Each subdirectory must supply rules for building sources it contributes
SerialRadioFrequencyAPC220/%.o: ../SerialRadioFrequencyAPC220/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/libraries/SoftwareSerial -I"/storage/microcontroller/arduino/driver/air/radio/SerialRadioFrequency" -I"/storage/microcontroller/arduino/driver/air/radio/SerialRadioFrequencyAPC220" -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


