
/* Library Function - Single Match
    __wsplitpath
   
   Library: Visual Studio 2010 Release */

void __cdecl
__wsplitpath(wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext)

{
  __wsplitpath_helper(_FullPath,_Drive,-(_Drive != (wchar_t *)0x0) & 3,_Dir,
                      -(uint)(_Dir != (wchar_t *)0x0) & 0x100,_Filename,
                      -(uint)(_Filename != (wchar_t *)0x0) & 0x100,_Ext,
                      -(uint)(_Ext != (wchar_t *)0x0) & 0x100);
  return;
}

