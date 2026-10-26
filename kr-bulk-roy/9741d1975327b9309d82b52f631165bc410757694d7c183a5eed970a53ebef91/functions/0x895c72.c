
/* Library Function - Single Match
    __endthread
   
   Library: Visual Studio 2010 Release */

void __cdecl __endthread(void)

{
  _ptiddata _Ptd;
  
  _Ptd = __getptd_noexit();
  if (_Ptd != (_ptiddata)0x0) {
    if ((HANDLE)_Ptd->_thandle != (HANDLE)0xffffffff) {
      CloseHandle((HANDLE)_Ptd->_thandle);
    }
    __freeptd(_Ptd);
  }
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}

