
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_Box$Filler__
#define __javax_swing_Box$Filler__

#pragma interface

#include <javax/swing/JComponent.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Dimension;
    }
  }
  namespace javax
  {
    namespace accessibility
    {
        class AccessibleContext;
    }
    namespace swing
    {
        class Box$Filler;
    }
  }
}

class javax::swing::Box$Filler : public ::javax::swing::JComponent
{

public:
  Box$Filler(::java::awt::Dimension *, ::java::awt::Dimension *, ::java::awt::Dimension *);
  virtual void changeShape(::java::awt::Dimension *, ::java::awt::Dimension *, ::java::awt::Dimension *);
  virtual ::javax::accessibility::AccessibleContext * getAccessibleContext();
  virtual ::java::awt::Dimension * getMaximumSize();
  virtual ::java::awt::Dimension * getMinimumSize();
  virtual ::java::awt::Dimension * getPreferredSize();
private:
  static const jlong serialVersionUID = -1204263191910183998LL;
  ::java::awt::Dimension * __attribute__((aligned(__alignof__( ::javax::swing::JComponent)))) min;
  ::java::awt::Dimension * pref;
  ::java::awt::Dimension * max;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_Box$Filler__