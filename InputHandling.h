#ifndef InvalidInput_H
#define InvalidInput_H


class InvalidInput
{
public:
	InvalidInput(char* in_ptr) : msg_ptr(in_ptr) { }
	const char* const msg_ptr;
private:
	InvalidInput(); // no default construction
};

#endif