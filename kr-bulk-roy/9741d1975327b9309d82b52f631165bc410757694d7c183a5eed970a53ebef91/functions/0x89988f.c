
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __tmpfile_helper
   
   Library: Visual Studio 2010 Release */

int __tmpfile_helper(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  errno_t eVar3;
  size_t _Size;
  DWORD _Val;
  FILE *pFVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int local_24;
  char *local_20;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_00c85080;
  uStack_c = 0x89989b;
  iVar7 = 0;
  if (param_1 == (undefined4 *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    return 0x16;
  }
  *param_1 = 0;
  iVar2 = __mtinitlocknum(2);
  if (iVar2 == 0) {
    piVar1 = __errno();
    return *piVar1;
  }
  __lock(2);
  local_8 = (undefined *)0x0;
  if (DAT_00f8cb40 == '\0') {
    eVar3 = _strcpy_s(&DAT_00f8cb40,0x12,"\\");
    if (eVar3 != 0) {
LAB_0089996b:
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    local_20 = &DAT_00f8cb41;
    if ((DAT_00f8cb40 != '\\') && (DAT_00f8cb40 != '/')) {
      DAT_00f8cb41 = 0x5c;
      local_20 = &DAT_00f8cb42;
    }
    *local_20 = 0x74;
    pcVar6 = local_20 + 1;
    iVar2 = 0x20;
    _Size = (int)&DAT_00f8cb52 - (int)pcVar6;
    local_20 = pcVar6;
    _Val = GetCurrentProcessId();
    eVar3 = __ultoa_s(_Val,pcVar6,_Size,iVar2);
    if ((eVar3 != 0) || (eVar3 = _strcat_s(&DAT_00f8cb40,0x12,"."), eVar3 != 0)) goto LAB_0089996b;
  }
  else {
    iVar2 = FUN_00899694(0x12,0x7fffffff);
    if (iVar2 != 0) goto LAB_00899a1f;
  }
  pFVar4 = __getstream();
  if (pFVar4 == (FILE *)0x0) {
    iVar7 = 0x18;
  }
  else {
    piVar1 = __errno();
    iVar2 = *piVar1;
    piVar1 = __errno();
    *piVar1 = 0;
    do {
      eVar3 = __sopen_s(&local_24,&DAT_00f8cb40,0x8542,param_2,0x180);
      if (eVar3 != 0x11) break;
      iVar5 = FUN_00899694(0x12,0x7fffffff);
    } while (iVar5 == 0);
    piVar1 = __errno();
    if (*piVar1 == 0) {
      piVar1 = __errno();
      *piVar1 = iVar2;
    }
    if (local_24 != -1) {
      pcVar6 = __strdup(&DAT_00f8cb40);
      pFVar4->_tmpfname = pcVar6;
      if (pcVar6 == (char *)0x0) {
        __close(local_24);
      }
      else {
        pFVar4->_cnt = 0;
        pFVar4->_ptr = (char *)0x0;
        pFVar4->_base = (char *)0x0;
        pFVar4->_flag = DAT_00f8d84c | 0x80;
        pFVar4->_file = local_24;
        *param_1 = pFVar4;
      }
    }
  }
LAB_00899a1f:
  local_8 = (undefined *)0xfffffffe;
  FUN_00899a6d();
  if (iVar7 != 0) {
    piVar1 = __errno();
    *piVar1 = iVar7;
  }
  return iVar7;
}

