
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __tmpnam_helper
   
   Library: Visual Studio 2010 Release */

int __tmpnam_helper(char *param_1,uint param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  errno_t eVar4;
  _ptiddata p_Var5;
  char *pcVar6;
  size_t sVar7;
  char *_Filename;
  undefined4 uVar8;
  int local_20;
  
  local_20 = 0;
  piVar2 = __errno();
  iVar1 = *piVar2;
  iVar3 = __mtinitlocknum(2);
  if (iVar3 == 0) {
    *param_5 = 0;
    piVar2 = __errno();
    local_20 = *piVar2;
  }
  else {
    __lock(2);
    if (param_3 == 0) {
      _Filename = &DAT_00f8cb30;
      uVar8 = 0xe;
    }
    else {
      _Filename = &DAT_00f8cb54;
      uVar8 = 0x12;
    }
    if (*_Filename != '\0') goto LAB_00899794;
    FUN_008995ea(param_3);
    do {
      eVar4 = __access_s(_Filename,0);
      if (eVar4 != 0) {
        if (param_1 == (char *)0x0) {
          p_Var5 = __getptd_noexit();
          if (p_Var5 == (_ptiddata)0x0) {
LAB_008997c8:
            local_20 = 0xc;
            break;
          }
          if (p_Var5->_namebuf0 == (char *)0x0) {
            pcVar6 = __malloc_crt(0xe);
            p_Var5->_namebuf0 = pcVar6;
            if (pcVar6 == (char *)0x0) goto LAB_008997c8;
          }
          param_1 = p_Var5->_namebuf0;
          param_2 = 0xe;
        }
        else if ((param_3 != 0) && (sVar7 = _strlen(_Filename), param_2 <= sVar7)) {
          local_20 = 0x22;
          if (param_2 != 0) {
            *param_1 = '\0';
          }
          break;
        }
        eVar4 = _strcpy_s(param_1,param_2,_Filename);
        if (eVar4 != 0) {
                    /* WARNING: Subroutine does not return */
          __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        break;
      }
LAB_00899794:
      iVar3 = FUN_00899694(uVar8,param_4);
    } while (iVar3 == 0);
    FUN_00899852();
    *param_5 = param_1;
    piVar2 = __errno();
    if (local_20 == 0) {
      *piVar2 = iVar1;
    }
    else {
      *piVar2 = local_20;
    }
  }
  return local_20;
}

