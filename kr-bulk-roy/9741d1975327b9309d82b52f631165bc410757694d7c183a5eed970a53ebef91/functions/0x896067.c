
/* Library Function - Single Match
    __endthreadex
   
   Library: Visual Studio 2010 Release */

void __cdecl __endthreadex(uint _Retval)

{
  _ptiddata _Ptd;
  
  _Ptd = __getptd_noexit();
  if (_Ptd != (_ptiddata)0x0) {
    __freeptd(_Ptd);
  }
                    /* WARNING: Subroutine does not return */
  ExitThread(_Retval);
}

