
void FUN_008cd510(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_88 [32];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar5 = 0;
  for (iVar3 = param_3; 0 < iVar3; iVar3 = iVar3 - param_3) {
    param_3 = iVar3;
    if (0x10 < iVar3) {
      param_3 = 0x10;
    }
    iVar1 = param_3 * 2;
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        iVar5 = iVar5 + *(int *)(param_4 + iVar4 * 4);
        iVar2 = FUN_008b7c80(iVar5);
        local_88[iVar4] = iVar2 >> 0x10;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        local_88[iVar4 + 1] = local_88[iVar4 + 1] - local_88[iVar4];
        iVar4 = iVar4 + 2;
      } while (iVar4 < iVar1);
    }
    FUN_008cd1a0(param_3);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

