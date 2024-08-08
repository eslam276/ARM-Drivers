/*****************************************************************/
/*****************************************************************/
/********************		Author: Eslam Nasr  	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: SCB				**************/
/********************		Version: 1.00			**************/
/********************		Date: 20-9-2023			**************/
/*****************************************************************/
/*****************************************************************/




#ifndef SCB_INTERFACE_H
#define SCB_INTERFACE_H



typedef enum
{
	PRI_GROUP_0 = 0,
	PRI_GROUP_1,
	PRI_GROUP_2,
	PRI_GROUP_3,
	PRI_GROUP_4,
	PRI_GROUP_5,
	PRI_GROUP_6,
	PRI_GROUP_7
}PRI_Group_t;

void SCB_voidSetPriorityGroup(PRI_Group_t Copy_enPriorityGroup);




#endif
