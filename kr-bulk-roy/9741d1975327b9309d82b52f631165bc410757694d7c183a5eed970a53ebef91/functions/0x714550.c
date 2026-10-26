
void FUN_00714550(char *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char ****_Filename;
  FILE *pFVar6;
  char *pcVar7;
  char ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009215b4;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((DAT_00fba814 != 0) && (iVar3 = FUN_00714c50(param_1,0), iVar3 != 0)) goto LAB_00714750;
  if ((DAT_00fe4c98 & 1) == 0) {
    DAT_00fe4c98 = DAT_00fe4c98 | 1;
    local_8 = 0;
    FUN_007142d0(uVar2);
    _atexit((_func_4879 *)&LAB_00bd0760);
    local_8 = 0xffffffff;
  }
  if (DAT_00fe4c94 != '\0') {
    if ((DAT_00fe4c98 & 1) == 0) {
      DAT_00fe4c98 = DAT_00fe4c98 | 1;
      local_8 = 1;
      FUN_007142d0(uVar2);
      _atexit((_func_4879 *)&LAB_00bd0760);
      local_8 = 0xffffffff;
    }
    cVar1 = FUN_007143b0();
    if (cVar1 == '\0') {
      uVar4 = FUN_00714260();
      cVar1 = FUN_00714470(uVar4);
      if (cVar1 == '\0') goto LAB_00714750;
    }
  }
  if ((DAT_00fe364c & 1) == 0) {
    DAT_00fe364c = DAT_00fe364c | 1;
    DAT_00fe3648 = '\0';
    _memset(&DAT_00fe3548,0,0x100);
  }
  if (DAT_00fe3648 != '\0') {
    pcVar5 = (char *)FUN_00713ff0();
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
    pcVar7 = pcVar5;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar5,(int)pcVar7 - (int)(pcVar5 + 1));
    local_8 = 2;
    pcVar7 = param_1;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    FUN_00401fc0(param_1,(int)pcVar7 - (int)(param_1 + 1));
    iVar3 = FUN_00717b60();
    if (iVar3 != 0) {
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      goto LAB_00714750;
    }
    _Filename = (char ****)local_30[0];
    if (local_1c < 0x10) {
      _Filename = local_30;
    }
    pFVar6 = _fopen((char *)_Filename,"rb");
    if (pFVar6 != (FILE *)0x0) {
      _fclose(pFVar6);
      FUN_00402c50();
      goto LAB_00714750;
    }
    FUN_00402c50();
  }
  iVar3 = FUN_00717b60();
  if ((iVar3 == 0) && (pFVar6 = _fopen(param_1,"rb"), pFVar6 != (FILE *)0x0)) {
    _fclose(pFVar6);
  }
LAB_00714750:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

