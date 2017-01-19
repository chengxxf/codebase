#ifndef ABSTRACT_H_H
#define ABSTRACT_H_H


class AbstractRx
{

public :
	AbstractRx();
	~AbstractRx();

	virtual int init();
	virtual void RxLoop();












};

#endif
