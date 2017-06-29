/***********************************************************************
 * SIVP - Scilab Image and Video Processing toolbox
 * Copyright (C) 2012 - DIGITEO - Allan CORNET
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
#ifndef __GW_MQTT_H__
#define __GW_MQTT_H__

#ifdef __cplusplus
extern "C" {
#endif

	int sci_int_mqtt_pub(char * fname);
	int sci_int_mqtt_sub(char * fname);
	//int sci_int_mqtt_pub_async(char * fname);
	//int sci_int_mqtt_sub_async(char * fname);
	int sci_int_mqtt_client_connect(char * fname);
	int sci_int_mqtt_client_sub(char * fname);
	int sci_int_mqtt_client_disconn(char * fname);
	int sci_int_mqtt_client_receive(char * fname);
	//int sci_int_ArtemisLoadDLL(char * fname);
	//int sci_int_main(int argc, const char* argv[]);

#ifdef __cplusplus
};
#endif

#endif /* __GW_MQTT_H__ */
















