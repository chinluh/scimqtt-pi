/***********************************************************************
* MQTT Client Module - Scilab MQTT Client Module with PAHO Library 
* Original work Copyright (C) 2017  Tan Chin Luh
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
***********************************************************************/
#include "common.h"

int sci_int_mqtt_pub(char * fname)
{	
	CheckInputArgument(pvApiCtx, 6, 6);
	CheckOutputArgument(pvApiCtx, 0, 1);

	char *ADDRESS = NULL;
	GetString(1, ADDRESS);
	char *TOPIC = NULL;
	GetString(2, TOPIC);
	char *PAYLOAD = NULL;
	GetString(3, PAYLOAD);
	char *CLIENTID = NULL;
	GetString(4, CLIENTID);
	double *val = NULL;
	int iRows			= 0;
	int iCols			= 0;
	GetDouble(5,val,iRows,iCols);
	int QOS = int(*val);
	GetDouble(6,val,iRows,iCols);
	unsigned long TIMEOUT = (unsigned long)(*val);
	
	MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    
	int rc;
	MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    
	conn_opts.keepAliveInterval = 60;
    conn_opts.cleansession = 1;

	SciErr sciErr;
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        sciprint("Failed to connect, return code %d\n", rc);
    }

    pubmsg.payload = PAYLOAD;
    pubmsg.payloadlen = strlen(PAYLOAD);
    pubmsg.qos = QOS;
    pubmsg.retained = 1;
    
	MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);

	MQTTClient_disconnect(client,10000);
    MQTTClient_destroy(&client);

	return 0;

}
