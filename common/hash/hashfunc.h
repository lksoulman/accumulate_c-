/*
 **************************************************************************
 *                                                                        *
 *                   Hash Function Algorithms Library                     *
 *                                                                        *
 *                                                                        *
 **************************************************************************
*/

#ifndef __HASHFUNC__H__
#define __HASHFUNC__H__


#include <string>


typedef unsigned int (*HashFunction)(const std::string&);


unsigned int RSHash  (const std::string& str);
unsigned int JSHash  (const std::string& str);
unsigned int PJWHash (const std::string& str);
unsigned int ELFHash (const std::string& str);
unsigned int BKDRHash(const std::string& str);
unsigned int SDBMHash(const std::string& str);
unsigned int DJBHash (const std::string& str);
unsigned int DEKHash (const std::string& str);
unsigned int BPHash  (const std::string& str);
unsigned int FNVHash (const std::string& str);
unsigned int APHash  (const std::string& str);


#endif // __HASHFUNC__H__
