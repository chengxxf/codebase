#ifndef STRUCT_TEST_H
#define STRUCT_TEST_H
typedef struct EcfmCcMsg{

	union{	
		struct{
			unsigned int u4VidIsid;
			unsigned char u1Direction;
			unsigned char u1MdLevel;
		}Mep;

	}uMsg;

	struct{
		unsigned short int u2VlanId;
		unsigned short int u2CVlanId;

	}VlanTransInformation;


} tEcfmCcMsg;



void test_struct();




#endif
