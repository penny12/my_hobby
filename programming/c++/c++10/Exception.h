#ifndef __EXCEPTION_H_
#define __EXCEPTION_H_

class Exception
{
public:
  virtual ~Exception();

public:
  virtual const char* What() const = 0;
};

#endif // __EXCEPTION_H_
