################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Grafico.cpp \
../Punto.cpp \
../Segmento.cpp \
../test2.cpp 

OBJS += \
./Grafico.o \
./Punto.o \
./Segmento.o \
./test2.o 

CPP_DEPS += \
./Grafico.d \
./Punto.d \
./Segmento.d \
./test2.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


