
/* Library Function - Multiple Matches With Different Base Names
    _fscanf
    _fscanf_s
   
   Library: Visual Studio 2010 Release */

int __cdecl FID_conflict__fscanf(FILE *_File,char *_Format,...)

{
  int iVar1;
  
  iVar1 = vfscanf(__input_l,_File,_Format,0,&stack0x0000000c);
  return iVar1;
}

