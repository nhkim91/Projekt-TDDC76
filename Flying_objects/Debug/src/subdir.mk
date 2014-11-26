################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/alien.cpp \
../src/bullet.cpp \
../src/flying_objects_test.cpp \
../src/meteorite.cpp \
../src/player.cpp \
../src/power_up.cpp 

OBJS += \
./src/alien.o \
./src/bullet.o \
./src/flying_objects_test.o \
./src/meteorite.o \
./src/player.o \
./src/power_up.o 

CPP_DEPS += \
./src/alien.d \
./src/bullet.d \
./src/flying_objects_test.d \
./src/meteorite.d \
./src/player.d \
./src/power_up.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I"/Users/anton/Documents/workspace/Projekt-TDDC76/Flying_objects/Framework" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


