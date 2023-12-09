/************************************************************************/
/*									*/
/*  Translation of GUI Resource primitives to the actual implementing	*/
/*  GUI system. As we do not have the pretentence to introduce our own	*/
/*  GUI layer, as much as possible is done through macros. (#defines)	*/
/*									*/
/************************************************************************/

#ifndef APP_GUI_RESOURCE_H
#define APP_GUI_RESOURCE_H

/************************************************************************/
/*									*/
/*  Resource table entries. In order no to complicate things, all	*/
/*  values are strings. No attempt to make a fully generalised		*/
/*  abstracted universal solution for calling strtol() or strtod()	*/
/*  occasionally is made.						*/
/*									*/
/*  NO LONGER USE THE ARCHAIC X11 RESOURCE MECHANISM			*/
/*									*/
/************************************************************************/

typedef struct AppConfigurableResource {
	const char *acrResourceName;
	unsigned int acrStructOffset;
	const char *acrDefaultValue;
} AppConfigurableResource;

#define APP_RESOURCE(x, o, d) \
	{                     \
		(x), (o), (d) \
	}

#define APP_SET_RESOURCE(acr, x, o, d)        \
	{                                     \
		(acr)->acrResourceName = (x); \
		(acr)->acrStructOffset = (o); \
		(acr)->acrDefaultValue = (d); \
	}

#endif /* APP_GUI_RESOURCE_H */
