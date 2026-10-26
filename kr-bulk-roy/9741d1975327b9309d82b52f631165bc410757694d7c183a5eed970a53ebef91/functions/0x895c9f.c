
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    __callthreadstart
   
   Library: Visual Studio 2010 Release */

void __callthreadstart(void)

{
  _ptiddata p_Var1;
  _EXCEPTION_POINTERS *local_18;
  
  p_Var1 = __getptd();
  (*p_Var1->_initaddr)(p_Var1->_initarg);
  __endthread();
  __XcptFilter(local_18->ExceptionRecord->ExceptionCode,local_18);
  return;
}

