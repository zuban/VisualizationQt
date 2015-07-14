#pragma once

// #include <string>
// #include <complex>
// #include <float.h>

using namespace std ;
// #define complex complex<double>

//bof-bifstrream
#include <fstream>
#include <string.h>

//#include "../../nacom/include/yb_trans.h"

//==========================
// class bofstream
//==========================
// template <class T> class vectorm1; //dlia obiavlenia friend operator, a v w_wlib.cpp uge vectorm1 net
class __declspec(dllexport) bofstream : public ofstream{ //NS net _declspec

 public :
//   bofstream(const char *fn
   bofstream(const char *fn) : ofstream(fn, ios::out | ios::binary)
   //NS {bNewFormat = false;}
//NS start
   {bNewFormat = false; pB = new char[1048576]; nReadMax = sizeof(pB); nRead = 0; //NS
    iFormat = 0; iPointer = 0;} //NS
//NS stop

   //new 1.11.06
   ~bofstream()
   {
	   delete pB;//NS
   }

   //NS start
//new 1.5.8
   char* pB;
   int nReadMax;
   int nRead;
   int iPointer;

   //new 1.5.8
   int iFormat;
//NS stop

   //new 1.11.06
   bool bNewFormat;

   friend bofstream& operator<< (bofstream&, signed char&);
   friend bofstream& operator<< (bofstream&, unsigned char&);
   friend bofstream& operator<< (bofstream&, signed short&);
   friend bofstream& operator<< (bofstream&, unsigned short&);
   friend bofstream& operator<< (bofstream&, signed int&);
   friend bofstream& operator<< (bofstream&, unsigned int&);
   friend bofstream& operator<< (bofstream&, signed long&);
   friend bofstream& operator<< (bofstream&, unsigned long&);
   friend bofstream& operator<< (bofstream&, float&);
   friend bofstream& operator<< (bofstream&, double&);
   friend bofstream& operator<< (bofstream&, long double&);
   friend bofstream& operator<< (bofstream&, bool&);
   // friend bofstream& operator<< (bofstream&, RECT&);
   // friend bofstream& operator<< (bofstream&, COLORREF&);
   // friend bofstream& operator<< (bofstream&, LOGFONT&);
   // friend bofstream& operator<< (bofstream&, complex&);
   // friend bofstream& operator<< (bofstream&, string&);
   // friend bofstream& operator<< (bofstream&, SYSTEMTIME&);
   // friend bofstream& operator<< (bofstream&, char *);
   // friend bofstream& operator<< (bofstream&, vectorm1<complex>&);
   // friend bofstream& operator<< (bofstream&, vectorm1<double>&);

   void WriteVersion(char* sVer, int iVer);
//ne moget bit protected, no ispolzovat ktrome kak v bofstream nelza!!  protected :
   //NS void writeBytes(const void*, int);
//NS start
  bool writeBytes(const void*, int);

   //new 1.8.8
   void WriteShort(short sh);

   //new 1.5.8
   bool WriteClassID(string& sClassType, string& sClassRWName, int iDataVersion);
   bool WriteHeader();
//NS stop
protected :
   bool bPickOpen;
};

//==========================
// class bifstream
//==========================
class __declspec(dllexport) bifstream : public ifstream{ //NS net _declspec
 public :
   bifstream(const char *fn) : ifstream(fn, ios::in | ios::binary){
	   bNewFormat = false;
	   bError = false;
	   bEndOfFile = false;
	   chType = ' ';
	   //NS for(int i = 0; i < (int)strlen(sLastVersion); i++) sLastVersion[i] = ' ';
	   //NS sLastVersion[strlen(sLastVersion) - 1] = '\0';}
//NS start
	   for(int i = 0; i < strlen(sLastVersion); i++) sLastVersion[i] = ' ';
	   sLastVersion[strlen(sLastVersion) - 1] = '\0';
       pB = new char[1048576];
	   nReadMax = sizeof(pB);
	   nRead = 0;
	   nReadTotal = false;
	   iPointer = 0;
	   iFormat = -1;
	   iHeaderPointer = 0;
	   bHeader = false;}
//NS stop

   //new 1.11.06
   ~bifstream()
   {
	   delete pB; //NS
   }

   //new 1.11.06
   bool bNewFormat;
   char chType;
   char chTypeExpected;
   bool bError;
   bool bEndOfFile;
   char sLastVersion[25]; //25 NE MENIAT!

//NS start
   //new 1.5.8
   char* pB;
   int nReadMax;
   int nRead;
   int nReadTotal;
   int iPointer;

   //new 1.5.8
   bool bFirstRead;
   int iFormat;
   int iHeaderPointer;
   bool bHeader;
//NS stop

   friend bifstream& operator>> (bifstream&, signed char&);
   friend bifstream& operator>> (bifstream&, unsigned char&);
   friend bifstream& operator>> (bifstream&, signed short&);
   friend bifstream& operator>> (bifstream&, unsigned short&);
   friend bifstream& operator>> (bifstream&, signed int&);
   friend bifstream& operator>> (bifstream&, unsigned int&);
   friend bifstream& operator>> (bifstream&, signed long&);
   friend bifstream& operator>> (bifstream&, unsigned long&);
   friend bifstream& operator>> (bifstream&, float&);
   friend bifstream& operator>> (bifstream&, double&);
   friend bifstream& operator>> (bifstream&, long double&);
   friend bifstream& operator>> (bifstream&, bool&);
   // friend bifstream& operator>> (bifstream&, RECT&);
   // friend bifstream& operator>> (bifstream&, COLORREF&);
   // friend bifstream& operator>> (bifstream&, LOGFONT&);
   // friend bifstream& operator>> (bifstream&, complex&);
   // friend bifstream& operator>> (bifstream&, char *);
   // friend bifstream& operator>> (bifstream&, SYSTEMTIME&);
   // friend bifstream& operator>> (bifstream&, string&);
   // friend bifstream& operator>> (bifstream&, vectorm1<complex>&);
   // friend bifstream& operator>> (bifstream&, vectorm1<double>&);

   bool  FindAndReadVersionHeader(bool bFind);
   bool  CheckVersion(char* sVer, int& iVer)
   {return CheckVersion(sVer, iVer, true);}
   bool  CheckVersion(char* sVer, int& iVer, bool bFind);
//NS start

   //new 1.8.8
   void ReadShort(short &sh);

   //new 1.5.8
   bool  CheckVersionNew(char* sVer, int& iVer);
//NS stop
//ne moget bit protected, no ispolzovat ktrome kak v bofstream nelza!!  protected :
  //NS bool readBytes(const void*, int);
//NS start
   bool readBytes(void*, int);
   bool readBytesOld(const void*, int);
   bool readBytesNew(char*, int);

   //new 1.5.8
   bool IsHeader(int n);
   bool ReadClassID(string& sClassType, string& sClassRWName, int &iDataVersion);
   bool ReadHeader();
//NS sto

};






