#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "vincent.h"

int main()
{
  ofstream myfile;
  myfile.open ("font.h");
  myfile << "#ifndef FONT_H"<<endl;
  myfile << "#define FONT_H 1"<<endl;
  myfile << "unsigned char font_data[128][8] = {"<<endl;
  for (int charnum=0;charnum<128;charnum++)
  {
          unsigned char char_data[8];
          unsigned char char_data_out[8];
          for (int i=0;i<8;i++)
          {
                  char_data[i]=font_data[charnum][i];
          }
          
          for (int i=0;i<8;i++)
          {
                  unsigned char r=0;
                  for (int j=0;j<8;j++)
                  {
                          if(char_data[j]&(1<<i))
                          {
                                  r+=(1<<j);
                          }
                  }
                  char_data_out[7-i]=r;
          }
          
          
          myfile << "//"<<hex<<setfill('0')<<setw(2)<<"0x"<<charnum<<"="<<dec<<charnum<<endl;
          myfile << "{";
          for (int i=0;i<8;i++)
          {
                  myfile <<hex<<setfill('0')<<"0x"<<setw(2)<< (int)char_data_out[i]<<",";
          }
          myfile << "},"<<endl;
  }
  myfile << "};\n";
  myfile << "#endif\n";
  myfile.close();
  return 0;
        
}
