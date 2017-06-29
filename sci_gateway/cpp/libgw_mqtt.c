#ifdef __cplusplus
extern "C" {
#endif
#include <mex.h> 
#include <sci_gateway.h>
#include <api_scilab.h>
#include <MALLOC.h>
static int direct_gateway(char *fname,void F(void)) { F();return 0;};
extern Gatefunc sci_int_mqtt_client_connect;
extern Gatefunc sci_int_mqtt_client_sub;
extern Gatefunc sci_int_mqtt_client_receive;
extern Gatefunc sci_int_mqtt_sub;
extern Gatefunc sci_int_mqtt_client_disconn;
extern Gatefunc sci_int_mqtt_pub;
static GenericTable Tab[]={
  {(Myinterfun)sci_gateway,sci_int_mqtt_client_connect,"int_mqtt_client_connect"},
  {(Myinterfun)sci_gateway,sci_int_mqtt_client_sub,"int_mqtt_client_sub"},
  {(Myinterfun)sci_gateway,sci_int_mqtt_client_receive,"int_mqtt_client_receive"},
  {(Myinterfun)sci_gateway,sci_int_mqtt_sub,"int_mqtt_sub"},
  {(Myinterfun)sci_gateway,sci_int_mqtt_client_disconn,"int_mqtt_client_disconn"},
  {(Myinterfun)sci_gateway,sci_int_mqtt_pub,"int_mqtt_pub"},
};
 
int C2F(libgw_mqtt)()
{
  Rhs = Max(0, Rhs);
  if (*(Tab[Fin-1].f) != NULL) 
  {
     if(pvApiCtx == NULL)
     {
       pvApiCtx = (StrCtx*)MALLOC(sizeof(StrCtx));
     }
     pvApiCtx->pstName = (char*)Tab[Fin-1].name;
    (*(Tab[Fin-1].f))(Tab[Fin-1].name,Tab[Fin-1].F);
  }
  return 0;
}
#ifdef __cplusplus
}
#endif
