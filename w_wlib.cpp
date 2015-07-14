//#include "stdafx.h"

//new 1.1.12
//1. read/write vectorm1 rabotal i v novom (NS), no bil ubram t.k. bil ubran v starom
//2. read/wrie Bytes v //NS zakomentirovan - kak eto skageta?

//was bef 1.1.12 #include "../include/w_wlibV2.h"
#include "w_wlib.h" //new 1.1.12

//max write-read string size. if size will be grater - string will be truncated
const int CHAR_SIZE = 17000;

const char chChar = 'A';
const char chUnsignedChar = 'B';
const char chShort = 'C';
const char chUnsignedShort = 'D';
const char chSignedInt = 'E';
const char chUnsignedInt = 'F';
const char chLong = 'G';
const char chUnsignedLong = 'H';
const char chFloat = 'I';
const char chDouble = 'J';
const char chLongDouble = 'K';
const char chBool = 'L';
const char chRECT = 'M';
const char chCOLORREF = 'N';
const char chLOGFONT = 'O';
const char chComplex = 'P';
const char chString = 'Q';
const char chSYSTEMTIME = 'R';
const char chVectorM1Complex = 'S';
const char chVectorM1Double = 'T';
const char chCharArray = 'V';
const char chVersionHeader[10] = {'a', '\t', 'f', '\r', 'J', 'a', 't', '5', '1', 'r'};
//NS start
//new 1.5.8
//GUID FROM guidgen.exe BC-5, but last two symbols = 00 (header version 0)
//{82 B9 83 C6 9A 17 46 16 BF 60 57 17 CB 37 94 31} //GUID1
//{76 AF 1D BC D0 CA 45 BF 81 5A 5A BF C5 12 80 E7} //GUID2
//veroiatnost sovpadenia 10**(-28) => esli zapis 1 MB to 1 raz na 10**22 zapisei
//PERVIE 10 bytes u Header, Header1, ..., HeaderN dolgni sovpadat
const char byteHeader[32] = {0x82, 0xB9, 0x83, 0xC6, 0x9A, 0x17, 0x46, 0x16,
							 0xBF, 0x60, 0x57, 0x17, 0xCB, 0x37, 0x94, 0x31,
							 0x76, 0xAF, 0x1D, 0xBC, 0xD0, 0xCA, 0x45, 0xBF,
							 0x81, 0x5A, 0x5A, 0xBF, 0xC5, 0x12, 0x80, 0x00};
//Header1 tolko dlia primera - kogda izmeniu format zapisi v sleduiushii raz
const char byteHeader1[32] = {0x82, 0xB9, 0x83, 0xC6, 0x9A, 0x17, 0x46, 0x16,
							 0xBF, 0x60, 0x57, 0x17, 0xCB, 0x37, 0x94, 0x31,
							 0x76, 0xAF, 0x1D, 0xBC, 0xD0, 0xCA, 0x45, 0xBF,
							 0x81, 0x5A, 0x5A, 0xBF, 0xC5, 0x12, 0x80, 0x01};
const int nH = 32; //ne meniat
const int nTypeName = 64;
//NS stop

//==========================
// class bofstream
//==========================
//NS void bofstream::writeBytes(const void *p, int len)
bool bofstream::writeBytes(const void *p, int len) //NS

{
 //NS if(!p) return;
 //NS if(len <= 0) return;
 if(!p) return false; //NS
 if(len <= 0) return false; //NS
 write((char*)p, len);
 return true; //ne nashel kto pokazivaet esli oshibka zapisi //NS

}

 bofstream& operator<<(bofstream& bofs, char& q)
{
 //1.11.06 !!! string iz odnogo simvola ona pishet kak char, i voznikaet problema
 //            pri chtenii pri kontrole tipov
 if(bofs.bNewFormat) bofs.writeBytes(&chChar, 1);
 bofs.writeBytes(&q, sizeof(char));
 return bofs;
}

 bofstream& operator<<(bofstream& bofs, unsigned char& q)
{
 if(bofs.bNewFormat) bofs.writeBytes(&chUnsignedChar, 1);
 bofs.writeBytes(&q, sizeof(unsigned char));
 return bofs;
}

 bofstream& operator<<(bofstream& bofs, short& q)
{
 if(bofs.bNewFormat) bofs.writeBytes(&chShort, 1);
 bofs.writeBytes(&q, sizeof(short));
 return bofs;
}

 bofstream& operator<<(bofstream& bofs, unsigned short& q)
{
 if(bofs.bNewFormat) bofs.writeBytes(&chUnsignedShort, 1);
 bofs.writeBytes(&q, sizeof(unsigned short));
 return bofs;
}

 bofstream& operator<<(bofstream& bofs, signed int& q)
{
 if(bofs.bNewFormat) bofs.writeBytes(&chSignedInt, 1);
 bofs.writeBytes(&q, sizeof(int));
 return bofs;
}

 bofstream& operator<<(bofstream& bofs, unsigned int& q)
{
 if(bofs.bNewFormat) bofs.writeBytes(&chUnsignedInt, 1);
 bofs.writeBytes(&q, sizeof(unsigned int));
 return bofs;
}

 bofstream& operator<<(bofstream& bofs, long& q)
{
 if(bofs.bNewFormat) bofs.writeBytes(&chLong, 1);
 bofs.writeBytes(&q, sizeof(long));
 return bofs;
}

 bofstream& operator<<(bofstream& bofs, unsigned long& q)
{
 if(bofs.bNewFormat) bofs.writeBytes(&chUnsignedLong, 1);
 bofs.writeBytes(&q, sizeof(unsigned long));
 return bofs;
}

 bofstream& operator<<(bofstream& bofs, float& q)
{
 if(bofs.bNewFormat) bofs.writeBytes(&chFloat, 1);
 bofs.writeBytes(&q, sizeof(float));
 return bofs;
}

 bofstream& operator<<(bofstream& bofs, double& q)
{
 if(bofs.bNewFormat) bofs.writeBytes(&chDouble, 1);
 bofs.writeBytes(&q, sizeof(double));
 return bofs;
}

 bofstream& operator<<(bofstream& bofs, long double& q)
{
 if(bofs.bNewFormat) bofs.writeBytes(&chLongDouble, 1);
 bofs.writeBytes(&q, sizeof(long double));
 return bofs;
}

bofstream& operator<<(bofstream& bofs, bool& q)
{
 if(bofs.bNewFormat) bofs.writeBytes(&chBool, 1);
 bofs.writeBytes(&q, sizeof(bool));
 return bofs;
}

// bofstream& operator<<(bofstream& bofs, RECT& q)
// {
//  if(bofs.bNewFormat) bofs.writeBytes(&chRECT, 1);
//  bofs.writeBytes(&q, sizeof(RECT));
//  return bofs;
// }

// bofstream& operator<<(bofstream& bofs, LOGFONT& q)
// {
//  if(bofs.bNewFormat) bofs.writeBytes(&chLOGFONT, 1);
//  bofs.writeBytes(&q, sizeof(LOGFONT));
//  return bofs;
// }

// bofstream& operator<<(bofstream& bofs, SYSTEMTIME& q)
// {
//  if(bofs.bNewFormat) bofs.writeBytes(&chSYSTEMTIME, 1);
//  bofs.writeBytes(&q, sizeof(SYSTEMTIME));
//  return bofs;
// }

// bofstream& operator<<(bofstream& bofs, char q[])
// {
//  if(bofs.bNewFormat) bofs.writeBytes(&chCharArray, 1);
//  bofs.writeBytes(q, sizeof(q));
//  return bofs;
// }

// bofstream& operator<<(bofstream& bofs, complex& q)
// {
//  if(bofs.bNewFormat) bofs.writeBytes(&chComplex, 1);
//  bofs.writeBytes(&q, sizeof(complex));
//  return bofs;
// }

// bofstream& operator<<(bofstream& bofs, string& q)
// {
//  if(bofs.bNewFormat) bofs.writeBytes(&chString, 1);
//  int n = strlen(q.c_str());
//  if(n >= CHAR_SIZE) n = 17000;
//  bofs << n;
//  bofs.writeBytes(q.c_str(), n);
//  return bofs;
// }
/* //NS net
bofstream& operator<<(bofstream& bofs, vectorm1<complex>& q)
{
// char s[512]; sprintf(s, "%d", q.size());
// ::MessageBox(0, s, "qqq", MB_OK);
 if(bofs.bNewFormat) bofs.writeBytes(&chVectorM1Complex, 1);
 int nn = q.size();
 bofs << nn;
 bofs.writeBytes(q.begin(), nn*16);
 return bofs;
}

bofstream& operator<<(bofstream& bofs, vectorm1<double>& q)
{
 if(bofs.bNewFormat) bofs.writeBytes(&chVectorM1Double, 1);
 int n = q.size();
 bofs << n;
 bofs.writeBytes(q.begin(), n*8);
 return bofs;
}
//NS net */
void bofstream::WriteVersion(char* sVer, int iVer)
{
 char s[25];

 if(bNewFormat)
	writeBytes(chVersionHeader, sizeof(chVersionHeader));
 strncpy(s, sVer, 24);
 s[24] = '\0';
 writeBytes(s, sizeof(s));
 writeBytes(&iVer, sizeof(iVer));
}

//NS start
bool bofstream::WriteHeader()



{
 if(iFormat == 0) 
	 return writeBytes(byteHeader, nH);
 if(iFormat == 1) 
	 return writeBytes(byteHeader1, nH);

 return false;




}

bool bofstream::WriteClassID(string& sClassType, string& sClassRWName, int iDataVersion)
{
// int nSize = 32;
 char sCT[nTypeName], sRW[nTypeName];
 strncpy(sCT, sClassType.c_str(), nTypeName);
 strncpy(sRW, sClassRWName.c_str(), nTypeName);
 sCT[nTypeName - 1] = '\0';
 sRW[nTypeName - 1] = '\0';
 if(!writeBytes(sCT, nTypeName)) return false;
 if(!writeBytes(sRW, nTypeName)) return false;
 if(!writeBytes(&iDataVersion, 4)) return false;

 return true;
}

//new 1.8.8
void bofstream::WriteShort(short sh)
{
 if(bNewFormat) writeBytes(&chShort, 1);
 writeBytes(&sh, sizeof(short));
}
//NS stop
//==========================
// class bifstream
//==========================
/* NS
bool bifstream::readBytes(const void *p, int len)
{
 //Daet false tolko pri konce faila
 if(!p) return true;
 if(len <= 0) return true;
 
 read((char*)p, len);

 if( gcount() != len){
	 bEndOfFile = true;
	 return false;}
 return true;
}
NS*/

 bifstream& operator>>(bifstream& bifs, char& q)
{
 if(bifs.bNewFormat){
   if(bifs.bError || bifs.bEndOfFile) return bifs;
   bifs.chType = ' ';
   bifs.chTypeExpected = chChar;
   bifs.readBytes(&bifs.chType, 1);
   if(bifs.bEndOfFile) return bifs;
   if(bifs.chType != bifs.chTypeExpected){
     bifs.bError = true;
	 return bifs;}}
 bifs.readBytes(&q, sizeof(char));
 return bifs;
}

 bifstream& operator>>(bifstream& bifs, unsigned char& q)
{
 if(bifs.bNewFormat){
   if(bifs.bError || bifs.bEndOfFile) return bifs;
   bifs.chType = ' ';
   bifs.chTypeExpected = chUnsignedChar;
   bifs.readBytes(&bifs.chType, 1);
   if(bifs.bEndOfFile) return bifs;
   if(bifs.chType != bifs.chTypeExpected){
     bifs.bError = true;
	 return bifs;}}
 bifs.readBytes(&q, sizeof(unsigned char));
 return bifs;
}

 bifstream& operator>>(bifstream& bifs, short& q)
{
 if(bifs.bNewFormat){
   if(bifs.bError || bifs.bEndOfFile) return bifs;
   bifs.chType = ' ';
   bifs.chTypeExpected = chShort;
   bifs.readBytes(&bifs.chType, 1);
   if(bifs.bEndOfFile) return bifs;
   if(bifs.chType != bifs.chTypeExpected){
     bifs.bError = true;
	 return bifs;}}
 bifs.readBytes(&q, sizeof(short));
 return bifs;
}

 bifstream& operator>>(bifstream& bifs, unsigned short& q)
{
 if(bifs.bNewFormat){
   if(bifs.bError || bifs.bEndOfFile) return bifs;
   bifs.chType = ' ';
   bifs.chTypeExpected = chUnsignedChar;
   bifs.readBytes(&bifs.chType, 1);
   if(bifs.bEndOfFile) return bifs;
   if(bifs.chType != bifs.chTypeExpected){
     bifs.bError = true;
	 return bifs;}}
 bifs.readBytes(&q, sizeof(unsigned short));
 return bifs;
}

 bifstream& operator>>(bifstream& bifs, signed int& q)
{
 if(bifs.bNewFormat){
   if(bifs.bError || bifs.bEndOfFile) return bifs;
   bifs.chType = ' ';
   bifs.chTypeExpected = chSignedInt;
   bifs.readBytes(&bifs.chType, 1);
   if(bifs.bEndOfFile) return bifs;
   if(bifs.chType != bifs.chTypeExpected){
     bifs.bError = true;
	 return bifs;}}
 bifs.readBytes(&q, sizeof(int));
 return bifs;
}

 bifstream& operator>>(bifstream& bifs, unsigned int& q)
{
 if(bifs.bNewFormat){
   if(bifs.bError || bifs.bEndOfFile) return bifs;
   bifs.chType = ' ';
   bifs.chTypeExpected = chUnsignedInt;
   bifs.readBytes(&bifs.chType, 1);
   if(bifs.bEndOfFile) return bifs;
   if(bifs.chType != bifs.chTypeExpected){
     bifs.bError = true;
	 return bifs;}}
 bifs.readBytes(&q, sizeof(unsigned int));
 return bifs;
}

 bifstream& operator>>(bifstream& bifs, long& q)
{
 if(bifs.bNewFormat){
   if(bifs.bError || bifs.bEndOfFile) return bifs;
   bifs.chType = ' ';
   bifs.chTypeExpected = chLong;
   bifs.readBytes(&bifs.chType, 1);
   if(bifs.bEndOfFile) return bifs;
   if(bifs.chType != bifs.chTypeExpected){
     bifs.bError = true;
	 return bifs;}}
 bifs.readBytes(&q, sizeof(long));
 return bifs;
}

 bifstream& operator>>(bifstream& bifs, unsigned long& q)
{
 if(bifs.bNewFormat){
   if(bifs.bError || bifs.bEndOfFile) return bifs;
   bifs.chType = ' ';
   bifs.chTypeExpected = chUnsignedLong;
   bifs.readBytes(&bifs.chType, 1);
   if(bifs.bEndOfFile) return bifs;
   if(bifs.chType != bifs.chTypeExpected){
     bifs.bError = true;
	 return bifs;}}
 bifs.readBytes(&q, sizeof(unsigned long));
 return bifs;
}

 bifstream& operator>>(bifstream& bifs, float& q)
{
 if(bifs.bNewFormat){
   if(bifs.bError || bifs.bEndOfFile) return bifs;
   bifs.chType = ' ';
   bifs.chTypeExpected = chFloat;
   bifs.readBytes(&bifs.chType, 1);
   if(bifs.bEndOfFile) return bifs;
   if(bifs.chType != bifs.chTypeExpected){
     bifs.bError = true;
	 return bifs;}}
 bifs.readBytes(&q, sizeof(float));
 return bifs;
}

 bifstream& operator>>(bifstream& bifs, double& q)
{
 if(bifs.bNewFormat){
   if(bifs.bError || bifs.bEndOfFile) return bifs;
   bifs.chType = ' ';
   bifs.chTypeExpected = chDouble;
   bifs.readBytes(&bifs.chType, 1);
   if(bifs.bEndOfFile) return bifs;
   if(bifs.chType != bifs.chTypeExpected){
     bifs.bError = true;
	 return bifs;}}
 bifs.readBytes(&q, sizeof(double));
 return bifs;
}

 bifstream& operator>>(bifstream& bifs, long double& q)
{
 if(bifs.bNewFormat){
   if(bifs.bError || bifs.bEndOfFile) return bifs;
   bifs.chType = ' ';
   bifs.chTypeExpected = chLongDouble;
   bifs.readBytes(&bifs.chType, 1);
   if(bifs.bEndOfFile) return bifs;
   if(bifs.chType != bifs.chTypeExpected){
     bifs.bError = true;
	 return bifs;}}
 bifs.readBytes(&q, sizeof(long double));
 return bifs;
}

 bifstream& operator>>(bifstream& bifs, bool& q)
{
 if(bifs.bNewFormat){
   if(bifs.bError || bifs.bEndOfFile) return bifs;
   bifs.chType = ' ';
   bifs.chTypeExpected = chBool;
   bifs.readBytes(&bifs.chType, 1);
   if(bifs.bEndOfFile) return bifs;
   if(bifs.chType != bifs.chTypeExpected){
     bifs.bError = true;
	 return bifs;}}
 bifs.readBytes(&q, sizeof(bool));
 return bifs;
}

//  bifstream& operator>>(bifstream& bifs, RECT& q)
// {
//  if(bifs.bNewFormat){
//    if(bifs.bError || bifs.bEndOfFile) return bifs;
//    bifs.chType = ' ';
//    bifs.chTypeExpected = chRECT;
//    bifs.readBytes(&bifs.chType, 1);
//    if(bifs.bEndOfFile) return bifs;
//    if(bifs.chType != bifs.chTypeExpected){
//      bifs.bError = true;
// 	 return bifs;}}
//  bifs.readBytes(&q, sizeof(RECT));
//  return bifs;
// }

//  bifstream& operator>>(bifstream& bifs, LOGFONT& q)
// {
//  if(bifs.bNewFormat){
//    if(bifs.bError || bifs.bEndOfFile) return bifs;
//    bifs.chType = ' ';
//    bifs.chTypeExpected = chLOGFONT;
//    bifs.readBytes(&bifs.chType, 1);
//    if(bifs.bEndOfFile) return bifs;
//    if(bifs.chType != bifs.chTypeExpected){
//      bifs.bError = true;
// 	 return bifs;}}
//  bifs.readBytes(&q, sizeof(LOGFONT));
//  return bifs;
// }

//  bifstream& operator>>(bifstream& bifs, SYSTEMTIME& q)
// {
//  if(bifs.bNewFormat){
//    if(bifs.bError || bifs.bEndOfFile) return bifs;
//    bifs.chType = ' ';
//    bifs.chTypeExpected = chSYSTEMTIME;
//    bifs.readBytes(&bifs.chType, 1);
//    if(bifs.bEndOfFile) return bifs;
//    if(bifs.chType != bifs.chTypeExpected){
//      bifs.bError = true;
// 	 return bifs;}}
//  bifs.readBytes(&q, sizeof(SYSTEMTIME));
//  return bifs;
// }

//  bifstream& operator>>(bifstream& bifs, char q[])
// {
//  if(bifs.bNewFormat){
//    if(bifs.bError || bifs.bEndOfFile) return bifs;
//    bifs.chType = ' ';
//    bifs.chTypeExpected = chCharArray;
//    bifs.readBytes(&bifs.chType, 1);
//    if(bifs.bEndOfFile) return bifs;
//    if(bifs.chType != bifs.chTypeExpected){
//      bifs.bError = true;
// 	 return bifs;}}
//  bifs.readBytes(q, sizeof(q));
//  return bifs;
// }

//  bifstream& operator>>(bifstream& bifs, complex& q)
// {
//  if(bifs.bNewFormat){
//    if(bifs.bError || bifs.bEndOfFile) return bifs;
//    bifs.chType = ' ';
//    bifs.chTypeExpected = chComplex;
//    bifs.readBytes(&bifs.chType, 1);
//    if(bifs.bEndOfFile) return bifs;
//    if(bifs.chType != bifs.chTypeExpected){
//      bifs.bError = true;
// 	 return bifs;}}
//  bifs.readBytes(&q, sizeof(complex));
//  return bifs;
// }

// bifstream& operator>>(bifstream& bifs, string& q)
// {
//  int n;
//  char s[257];
//  char* ss;
//  bool b = false;

//  //1.11.06 string iz odnogo simvola ona pishet kak char, i nado smotret
//  //        kak string tak i char
//  if(bifs.bNewFormat){
//    if(bifs.bError || bifs.bEndOfFile) return bifs;
//    bifs.chType = ' ';
//    bifs.chTypeExpected = chString;
//    bifs.readBytes(&bifs.chType, 1);
//    if(bifs.bEndOfFile) return bifs;
//    if(bifs.chType != bifs.chTypeExpected && bifs.chType != chChar){ //sm primechanie
//      bifs.bError = true;
// 	 return bifs;}
//    if(bifs.chType == chChar){
// 	   char qq[2] = {'\0', '\0'};
// 	   bifs.readBytes(&qq[1], sizeof(char));
//        if(bifs.bEndOfFile) return bifs;
// 	   q = qq;
//        return bifs;
//    }
//  }
//  bifs >> n;
//  if(n == 0) q = "";
// // if(n < 0 || n > CHAR_SIZE) exit(-1); //- error!!!!!, add in future
//  //1.4.6
//  //NS if(n < 0 || n > CHAR_SIZE) return bifs; //exit(-1); //- error!!!!!, add in future
//  if(n < 0 || n > CHAR_SIZE){ //NS
// 	 bifs.bError = true; //new 1.5.8 //NS
// 	 return bifs;} //exit(-1); //- error!!!!!, add in future //NS


//  if(n > 255){
//    b = true;
//    ss = new char[n+1];}

//  if(b){
// 	 for(int i = 0; i < n; i++){
// 		 if(bifs.bNewFormat){
// 	       bifs.readBytes(&ss[i], sizeof(char));
//            if(bifs.bEndOfFile) return bifs;
// 		 }
// 		 else
// 		   bifs >> ss[i];
// 	 }
//    ss[n] = '\0';
//    q = ss;
//    delete ss;}
//  else{
// 	 for(int i = 0; i < n; i++){
// 		 if(bifs.bNewFormat){
// 	       bifs.readBytes(&s[i], sizeof(char));
//            if(bifs.bEndOfFile) return bifs;
// 		 }
// 		 else
// 		   bifs >> s[i];
// 	 }
//    s[n] = '\0';
//    q = s;}

//  return bifs;
// }
/*NS net
bifstream& operator>>(bifstream& bifs, vectorm1<complex>& q)
{
 int n;

 if(bifs.bNewFormat){
   if(bifs.bError || bifs.bEndOfFile) return bifs;
   bifs.chType = ' ';
   bifs.chTypeExpected = chVectorM1Complex;
   bifs.readBytes(&bifs.chType, 1);
   if(bifs.bEndOfFile) return bifs;
   if(bifs.chType != bifs.chTypeExpected){
     bifs.bError = true;
	 return bifs;}}
 bifs >> n;
 complex c = complex(0., 0.);

 q.resize(n, complex(0., 0.));
// q.resize((size_t)n, 0.);
// q.resize(n);//, complex(0., 0.));
 bifs.readBytes(q.begin(), n*16);
 return bifs;
}

bifstream& operator>>(bifstream& bifs, vectorm1<double>& q)
{
 int n;

 if(bifs.bNewFormat){
   if(bifs.bError || bifs.bEndOfFile) return bifs;
   bifs.chType = ' ';
   bifs.chTypeExpected = chVectorM1Double;
   bifs.readBytes(&bifs.chType, 1);
   if(bifs.bEndOfFile) return bifs;
   if(bifs.chType != bifs.chTypeExpected){
     bifs.bError = true;
	 return bifs;}}
 bifs >> n;

 q.resize(n, 0.);
 bifs.readBytes(q.begin(), n*8);
 return bifs;
}
NS net*/
//for bef 1.5.8

bool bifstream::FindAndReadVersionHeader(bool bFind)
{
 char ss;
 char s[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
 int nRead = 0;
 if(bEndOfFile) return false;
 if(bError){
	 s[9] = chType;
	 nRead = 1;}
 while(readBytes(&ss, 1) && (nRead < 10 || bFind)){
   if(bEndOfFile) return false;
   nRead++;
   for(int i = 0; i < 9; i++) s[i] = s[i+1];
   s[9] = ss;
   bool b = true;
   for(int i = 0; i < 10; i++) if(s[i] != chVersionHeader[i]) b = false;
   if(b){
	   //!!!!!!Mogno vstavit predupregdenie o tom, chto esli bila oshibke
	   //      ee ispravili, no znachit format vozmogno bolee novii
	   bError = false;
	   return true;}
 }
 return false;
}

//for bef 1.5.8

bool bifstream::CheckVersion(char* sVer, int& iVer, bool bFind)
{
 if(bNewFormat)
	 if(!FindAndReadVersionHeader(bFind)) return false;

 if(!readBytes(sLastVersion, sizeof(sLastVersion))) return false;
 if(!readBytes(&iVer, sizeof(iVer))) return false;
 sLastVersion[24] = '\0';
 //was bef 1.11.06 if(strcmp(sVer, sLastVersion) == 0) return true;
 //new 1.11.06 - if(sVer = "") - moget bit luboe
 if(strcmp(sVer, "") == 0 || strcmp(sVer, sLastVersion) == 0) return true;
 else return false;
}


//NS start (do konca faile
//Daet false dlia failov bes Header i pri lubih oshibkah
//Daet true dlia failov so starim header (10 bytes) i s novimi (16 bytes)
bool bifstream::CheckVersionNew(char* sVer, int& iVer)
{
 if(bEndOfFile) return false;
 char s[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
 int nRead = 10;
 if(!readBytes(s, 10)) return false;
 if(bEndOfFile) return false;
 bool b = true;
 for(int i = 0; i < 10; i++) if(s[i] != chVersionHeader[i]) b = false;


//::MessageBox(0, s, "s", MB_OK);
//::MessageBox(0, chVersionHeader, "ch", MB_OK);

 if(b){
//::MessageBox(0, "OK", "s", MB_OK);
	if(!readBytes(sLastVersion, sizeof(sLastVersion))) return false;
	if(!readBytes(&iVer, sizeof(iVer))) return false;
	sLastVersion[24] = '\0';
	if(strcmp(sVer, "") == 0 || strcmp(sVer, sLastVersion) == 0){
		return true;
		iFormat = -1;}
	else return false;}
 b = true;
 //U vseh Header odinakovoe nachalo
 for(int i = 0; i < 2; i++) {if(s[i] != (char)byteHeader[i]) b = false;}
// ::MessageBox(0, s, "qq", MB_OK);
// ::MessageBox(0, (char*)&byteHeader[0], s, MB_OK);
 //s[2] = '\0';
 //char ss[3] = {'\0', '\0', '\0'};
 //ss[0] = byteHeader[0];
 //ss[1] = byteHeader[1];
 //::MessageBox(0, s, ss, MB_OK);
 if(!b) return false;
 char byte[nH];
 if(!readBytes(byte, nH - 10)) return false;
 //::MessageBox(0, (char*)byte, "qq1", MB_OK);
 //::MessageBox(0, (char*)&byteHeader[10], "qq1", MB_OK);
 bool bHeaderString = true;
 bool bHeader1String = true;
 for(int i = 0; i < nH - 10; i++) if(byte[i] != byteHeader[i + 10]) bHeaderString = false;
 for(int i = 0; i < nH - 10; i++) if(byte[i] != byteHeader1[i + 10]) bHeader1String = false;
 if(bHeaderString){
	 bHeader = true;
	 iFormat = 0;
	 return true;}
 if(bHeader1String){
	 bHeader = true;
	 iFormat = 1;
	 return true;}
}

//bool bifstream::readBytes(const void *p, int len)
bool bifstream::readBytes(void *p, int len)
{
	if(iFormat < 0) return readBytesOld(p, len);
    else return readBytesNew((char*)p, len);
}

//was bef 1.5.8
bool bifstream::readBytesOld(const void *p, int len)
{
 //Daet false tolko pri konce faila
 if(!p) return true;
 if(len <= 0) return true;
 if(bEndOfFile) return false; //new 1.5.8
 
 read((char*)p, len);

 if( gcount() != len){
	 bEndOfFile = true;
	 return false;}
 return true;
}

bool bifstream::IsHeader(int n)
{
if(iFormat < 0) return false; //starii format

 for(int i = 0; i < n; i++){
	if(iFormat == 0){ 
		if(byteHeader[iHeaderPointer] != pB[iPointer + i]) iHeaderPointer = 0;
		else iHeaderPointer++;}
	if(iFormat == 1){ 
		if(byteHeader1[iHeaderPointer] != pB[iPointer + i]) iHeaderPointer = 0;
		else iHeaderPointer++;}
//	if(iHeaderPointer > 2)  ::MessageBox(0, "qq1", "qq1", MB_OK);		
	if(iHeaderPointer == nH) {
//		::MessageBox(0, "qq", "qq", MB_OK);		
		bHeader = true; iHeaderPointer = 0; iPointer = i + 1; break;}
	else bHeader = false;}

 return bHeader;
}

bool bifstream::readBytesNew(char* p, int len)
{
 //vstavit ogranichenie na max len
 if(len <= 0) return true;
 if(bEndOfFile || bHeader) return false;

 if(len <= nRead - iPointer){
    if(IsHeader(len)) return false; 
	if(p != 0) memcpy(p, &pB[iPointer], len);
	iPointer += len;
	return true;}

 else{
	 int ip = 0;
	 while(ip < len){
		int n = len - ip;
		if(n > nRead - iPointer) n = nRead - iPointer;
		if(IsHeader(n)) return false; 
		if(p != 0) memcpy(&p[ip], &pB[iPointer], n);			
		ip += n;
		iPointer += n;
		if(nRead - iPointer <= 0){
			read((char*)pB, nReadMax);
			nRead = gcount();
			nReadTotal += nRead;
			iPointer = 0;
			if(nRead != nReadMax && len - ip > nRead){
				bEndOfFile = true;
				return false;}
		}//if(nRead <= 0)
	 }//while(..)
	 return true;
 }//else if(len > nRead)
}

bool bifstream::ReadHeader()
{
	bError = false;
	if(bHeader) {bHeader = false; return true;}
	if(bEndOfFile) return false;
	while(readBytesNew(0, 1000000));
	if(bEndOfFile) return false;
	if(bHeader){bHeader = false; return true;}
	else return false;
}


//bool bifstream::ReadClassID(char sClassType[], char sClassRWName[], int &iDataVersion)
bool bifstream::ReadClassID(string& sClassType, string& sClassRWName, int &iDataVersion)
{
 char s[nTypeName];

 //int nSize = 32;
 //if(!readBytes(s, nSize - 1)) {sClassType = "Error"; sClassRWName = "Error"; return false;} //bEndOfFile vistavliaet readBytes
 if(!readBytes(s, nTypeName)) {sClassType = "Error"; sClassRWName = "Error"; return false;} //bEndOfFile vistavliaet readBytes
 s[nTypeName - 1] = '\0';
 sClassType = s;
 //if(!readBytes(s, nSize - 1)) {sClassRWName = "Error"; return false;}
 if(!readBytes(s, nTypeName)) {sClassRWName = "Error"; return false;}
 s[nTypeName - 1] = '\0';
 sClassRWName = s;
 if(!readBytes(&iDataVersion, 4)) {sClassType = "Ver Error"; sClassRWName = "Ver Error"; return false;}
 return true;
}

//new 1.8.8
void bifstream::ReadShort(short &sh)
{
 if(bNewFormat){
   if(bError || bEndOfFile) return;
   chType = ' ';
   chTypeExpected = chShort;
   readBytes(&chType, 1);
   if(bEndOfFile) return;
   if(chType != chTypeExpected){
     bError = true;
	 return;}}
 readBytes(&sh, sizeof(short));
}
//NS stop

