
undefined4 FUN_00406700(void)

{
  uint uVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a2ac;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00405b20(unaff_EDI);
  if ((DAT_00faaf34 & 1) == 0) {
    DAT_00faaf34 = DAT_00faaf34 | 1;
    local_8 = 0;
    FUN_004073c0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcccd0);
  }
  uVar5 = (uint)DAT_00faaf39;
  if ((DAT_00faaf34 & 1) == 0) {
    DAT_00faaf34 = DAT_00faaf34 | 1;
    local_8 = 1;
    FUN_004073c0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcccd0);
  }
  uVar2 = 0;
  if ((int)DAT_00faaf54 < (int)uVar5) {
    uVar5 = DAT_00faaf54;
  }
  if (DAT_00faaf54 != 0) {
    pcVar3 = (char *)(unaff_EDI + 0x256);
    iVar4 = 7;
    do {
      if (pcVar3[-1] != '\0') {
        uVar5 = uVar5 - 1;
      }
      if (*pcVar3 != '\0') {
        uVar5 = uVar5 - 1;
      }
      if (pcVar3[1] != '\0') {
        uVar5 = uVar5 - 1;
      }
      if (pcVar3[2] != '\0') {
        uVar5 = uVar5 - 1;
      }
      pcVar3 = pcVar3 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (0 < (int)uVar5) {
      uVar2 = 1;
    }
  }
  ExceptionList = local_10;
  return uVar2;
}

