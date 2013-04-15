/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPARK_UTILITIES_H
#define __SPARK_UTILITIES_H

#include "hw_config.h"

#define SPARK_BUF_LEN	32

//#define BYTE_N(x,n) (((x) >> n*8) & 0x000000FF)

//#define SPARK_SERVER_IP	"54.235.79.249"
#define SPARK_SERVER_PORT	8989

char Spark_Connect(void);
void Spark_Disconnect(void);
void Spark_Process_API_Response(void);

void userCallback(char *callback_name);
void userCallbackWithData(char *callback_name, char *callback_data, long data_length);

//void userFunction(void) __attribute__ ((weak, alias ("Default_Handler")));
char userFunction(char *user_arg) __attribute__ ((weak));

#endif  /* __SPARK_UTILITIES_H */