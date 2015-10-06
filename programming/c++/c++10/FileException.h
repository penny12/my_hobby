#ifndef __FILE_EXCEPTION_H_
#define __FILE_EXCEPTION_H_

#include "Exception.h"
#include <string>

class FileException : public Exception
{
public:
  FileException(const char* error);

public:
  virtual const char* What() const;

private:
  std::string m_error;  // error message
};

#endif // FILE_EXCEPTION
