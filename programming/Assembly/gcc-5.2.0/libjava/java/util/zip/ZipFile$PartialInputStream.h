
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_zip_ZipFile$PartialInputStream__
#define __java_util_zip_ZipFile$PartialInputStream__

#pragma interface

#include <java/io/InputStream.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace nio
    {
      namespace charset
      {
          class Charset;
          class CharsetDecoder;
      }
    }
  }
}

class java::util::zip::ZipFile$PartialInputStream : public ::java::io::InputStream
{

public:
  ZipFile$PartialInputStream(::java::io::RandomAccessFile *, jint);
public: // actually package-private
  void setLength(jlong);
private:
  void fillBuffer();
public:
  jint available();
  jint read();
  jint read(JArray< jbyte > *, jint, jint);
  jlong skip(jlong);
public: // actually package-private
  void seek(jlong);
  void readFully(JArray< jbyte > *);
  void readFully(JArray< jbyte > *, jint, jint);
  jint readLeShort();
  jint readLeInt();
private:
  ::java::lang::String * decodeChars(JArray< jbyte > *, jint, jint);
public: // actually package-private
  ::java::lang::String * readString(jint);
public:
  void addDummyByte();
private:
  static ::java::nio::charset::Charset * UTF8CHARSET;
  ::java::nio::charset::CharsetDecoder * __attribute__((aligned(__alignof__( ::java::io::InputStream)))) utf8Decoder;
  ::java::io::RandomAccessFile * raf;
  JArray< jbyte > * buffer;
  jlong bufferOffset;
  jint pos;
  jlong end;
  jint dummyByteCount;
public:
  static ::java::lang::Class class$;
};

#endif // __java_util_zip_ZipFile$PartialInputStream__