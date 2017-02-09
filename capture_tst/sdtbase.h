#ifndef SDT_BASE_HH
#define SDT_BASE_HH


typedef struct Ip6Address
{

	union
	{
		unsigned char u1ByteAddr[16];
		unsigned char u2ShortAddr[8];
		unsigned char u1WordAddr[4];

	}ip6_addr_u;

#define u4_addr ip6_addr_u.u4WordAddr
#define u2_addr ip6_addr_u.u2ShortAddr
#define u1_addr ip6_addr_u.u1ByteAddr

}tIpAddr;


class SktDes
{
public:

	SktDes(){}
	tIpAddr LocalIpAddr;
	tIpAddr RemoteIpAddr;

















};
#endif
