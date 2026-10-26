
/* Library Function - Single Match
    __splitpath
   
   Library: Visual Studio 2010 Release */

void __cdecl __splitpath(char *_FullPath,char *_Drive,char *_Dir,char *_Filename,char *_Ext)

{
  __splitpath_helper(_FullPath,_Drive,-(_Drive != (char *)0x0) & 3,_Dir,
                     -(uint)(_Dir != (char *)0x0) & 0x100,_Filename,
                     -(uint)(_Filename != (char *)0x0) & 0x100,_Ext,
                     -(uint)(_Ext != (char *)0x0) & 0x100);
  return;
}

