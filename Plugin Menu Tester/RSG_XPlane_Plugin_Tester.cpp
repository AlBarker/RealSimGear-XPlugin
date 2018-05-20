// Downloaded from https://developer.x-plane.com/code-sample/x-plane-menu-sdk-sample/


#include "XPLMMenus.h"
#include <string.h>
#if IBM
	#include <windows.h>
#endif

#ifndef XPLM300
	#error This is made to be compiled against the XPLM300 SDK
#endif

int g_menu_container_idx; // The index of our menu item in the Plugins menu
XPLMMenuID g_menu_id; // The menu container we'll append all our menu items to
void menu_handler(void *, void *);

PLUGIN_API int XPluginStart(
						char *		outName,
						char *		outSig,
						char *		outDesc)
{
	strcpy(outName, "MenuPlugin");
	strcpy(outSig, "xpsdk.examples.menuplugin");
	strcpy(outDesc, "A sample plug-in that demonstrates and exercises the X-Plane menu API.");

	g_menu_container_idx = XPLMAppendMenuItem(XPLMFindPluginsMenu(), "Sample Menu", 0, 0);
	g_menu_id = XPLMCreateMenu("RealSimGear Test", XPLMFindPluginsMenu(), g_menu_container_idx, menu_handler, NULL);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 CDI", (void *)"CDI", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 OBS", (void *)"OBS", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 MSG", (void *)"MSG", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 FPL", (void *)"FPL", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 VNAV", (void *)"VNAV", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 PROC", (void *)"PROC", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 COMM FLIP", (void *)"COMM_FLIP", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 NAV FLIP", (void *)"NAV_FLIP", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 RANGE OUT", (void *)"RANGE_OUT", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 RANGE IN", (void *)"RANGE_IN", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 DIRECT", (void *)"DIRECT", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 MENU", (void *)"MENU", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 CLR", (void *)"CLR", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 ENTER", (void *)"ENT", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 Nav/Com Toggle", (void *)"TOG", 1);
	XPLMAppendMenuItem(g_menu_id, "Press GPS1 PUSH CSR", (void *)"CSR", 1);
	
	
	// Changed your mind? You can destroy the submenu you created with XPLMDestroyMenu(),
	// then remove the "Sample Menu" item from the "Plugins" menu with XPLMRemoveMenuItem().
	//XPLMDestroyMenu(g_menu_id);
	//XPLMRemoveMenuItem(XPLMFindPluginsMenu(), g_menu_container_idx);

	XPLMMenuID aircraft_menu = XPLMFindAircraftMenu();
	if(aircraft_menu) // This will be NULL unless this plugin was loaded with an aircraft (i.e., it was located in the current aircraft's "plugins" subdirectory)
	{
		XPLMAppendMenuItemWithCommand(aircraft_menu, "Toggle Settings (Command-Based)", XPLMFindCommand("sim/operation/toggle_settings_window"));
	}
	
	return 1;
}

PLUGIN_API void	XPluginStop(void)
{
	// Since we created this menu, we'll be good citizens and clean it up as well
	XPLMDestroyMenu(g_menu_id);
	// If we were able to add a command to the aircraft menu, it will be automatically removed for us when we're unloaded
}

PLUGIN_API void XPluginDisable(void) { }
PLUGIN_API int XPluginEnable(void) { return 1; }
PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFrom, int inMsg, void * inParam) { }

void menu_handler(void * in_menu_ref, void * in_item_ref)
{
	if(!strcmp((const char *)in_item_ref, "CDI"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_cdi"));
	}
	else if(!strcmp((const char *)in_item_ref, "OBS"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_obs"));
	}
	else if (!strcmp((const char *)in_item_ref, "MSG"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_msg"));
	}
	else if (!strcmp((const char *)in_item_ref, "VNAV"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_vnav"));
	}
	else if (!strcmp((const char *)in_item_ref, "FPL"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_fpl"));
	}
	else if (!strcmp((const char *)in_item_ref, "PROC"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_proc"));
	}
	else if (!strcmp((const char *)in_item_ref, "COMM_FLIP"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_com_ff"));
	}
	else if (!strcmp((const char *)in_item_ref, "NAV_FLIP"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_nav_ff"));
	}
	else if (!strcmp((const char *)in_item_ref, "RANGE_OUT"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_zoom_out"));
	}
	else if (!strcmp((const char *)in_item_ref, "RANGE_IN"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_zoom_in"));
	}
	else if (!strcmp((const char *)in_item_ref, "DIRECT"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_direct"));
	}
	else if (!strcmp((const char *)in_item_ref, "MENU"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_menu"));
	}
	else if (!strcmp((const char *)in_item_ref, "CLR"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_clr"));
	}
	else if (!strcmp((const char *)in_item_ref, "ENT"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_ent"));
	}
	else if (!strcmp((const char *)in_item_ref, "TOG"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_nav_com_tog"));
	}
	else if (!strcmp((const char *)in_item_ref, "CSR"))
	{
		XPLMCommandOnce(XPLMFindCommand("sim/GPS/g430n1_cursor"));
	}
}