
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __freopen_helper
   
   Library: Visual Studio 2010 Release */

int __freopen_helper(int *param_1,char *param_2,char *param_3,FILE *param_4,int param_5)

{
  int *piVar1;
  FILE *pFVar2;
  
  if ((((param_1 == (int *)0x0) || (*param_1 = 0, param_2 == (char *)0x0)) ||
      (param_3 == (char *)0x0)) || (param_4 == (FILE *)0x0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    return 0x16;
  }
  if (*param_2 == '\0') {
    piVar1 = __errno();
    *piVar1 = 0x16;
  }
  else {
    __lock_file(param_4);
    if ((param_4->_flag & 0x83) != 0) {
      __fclose_nolock(param_4);
    }
    param_4->_base = (char *)0x0;
    param_4->_ptr = (char *)0x0;
    param_4->_flag = 0;
    param_4->_cnt = 0;
    pFVar2 = __openfile(param_2,param_3,param_5,param_4);
    *param_1 = (int)pFVar2;
    FUN_008987f8();
    if (*param_1 != 0) {
      return 0;
    }
  }
  piVar1 = __errno();
  return *piVar1;
}

