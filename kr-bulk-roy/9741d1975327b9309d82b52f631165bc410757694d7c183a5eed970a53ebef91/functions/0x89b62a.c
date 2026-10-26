
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __dupenv_s
   
   Library: Visual Studio 2010 Release */

errno_t __cdecl __dupenv_s(char **_PBuffer,size_t *_PBufferSizeInBytes,char *_VarName)

{
  int *piVar1;
  char *_Str;
  size_t sVar2;
  char *_Dst;
  errno_t eVar3;
  int local_20;
  
  __lock(7);
  local_20 = 0;
  if (_PBuffer != (char **)0x0) {
    *_PBuffer = (char *)0x0;
    if (_PBufferSizeInBytes != (size_t *)0x0) {
      *_PBufferSizeInBytes = 0;
    }
    if (_VarName != (char *)0x0) {
      _Str = __getenv_helper_nolock(_VarName);
      if (_Str != (char *)0x0) {
        sVar2 = _strlen(_Str);
        sVar2 = sVar2 + 1;
        _Dst = _calloc(sVar2,1);
        *_PBuffer = _Dst;
        if (_Dst == (char *)0x0) {
          piVar1 = __errno();
          *piVar1 = 0xc;
          piVar1 = __errno();
          local_20 = *piVar1;
        }
        else {
          eVar3 = _strcpy_s(_Dst,sVar2,_Str);
          if (eVar3 != 0) {
                    /* WARNING: Subroutine does not return */
            __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          if (_PBufferSizeInBytes != (size_t *)0x0) {
            *_PBufferSizeInBytes = sVar2;
          }
          local_20 = 0;
        }
      }
      goto LAB_0089b6d9;
    }
  }
  piVar1 = __errno();
  local_20 = 0x16;
  *piVar1 = 0x16;
  FUN_00893343();
LAB_0089b6d9:
  FUN_0089b6f8();
  return local_20;
}

