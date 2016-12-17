################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PlaceDescriptionService.cpp \
../PlaceDescriptionServiceBehavior.cpp \
../Soundex.cpp \
../SoundexBehavior.cpp 

OBJS += \
./PlaceDescriptionService.o \
./PlaceDescriptionServiceBehavior.o \
./Soundex.o \
./SoundexBehavior.o 

CPP_DEPS += \
./PlaceDescriptionService.d \
./PlaceDescriptionServiceBehavior.d \
./Soundex.d \
./SoundexBehavior.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


