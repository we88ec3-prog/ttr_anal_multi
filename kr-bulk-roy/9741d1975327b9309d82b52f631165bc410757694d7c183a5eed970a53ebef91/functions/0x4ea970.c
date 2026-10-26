
/* WARNING: Removing unreachable block (ram,0x004ea9b3) */

undefined4 FUN_004ea970(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  int iVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009249de;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x5ee0) != *(int *)(in_ECX + 0x5ee4)) {
    *(int *)(in_ECX + 0x5ee4) = *(int *)(in_ECX + 0x5ee0);
  }
  if (param_2 < 2) {
    uVar5 = 0;
  }
  else {
    uVar5 = (param_2 - 2) / 0xc;
  }
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    FUN_0052ef90(uVar4);
  }
  iVar1 = *(int *)(in_ECX + 0x5ee4);
  iVar2 = *(int *)(in_ECX + 0x5ee0);
  iVar3 = iVar1 - iVar2 >> 0x1f;
  iVar6 = (iVar1 - iVar2) / 0xc + iVar3;
  if (*(int *)(in_ECX + 0x5ef0) == 0) {
    FUN_004edd50(iVar2,iVar1,iVar6 - iVar3,FUN_004e7fe0);
    *(undefined4 *)(in_ECX + 0x5ef0) = 0;
  }
  else {
    FUN_004edd50(iVar2,iVar1,iVar6 - iVar3,FUN_004e7fb0);
    *(undefined4 *)(in_ECX + 0x5ef0) = 1;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4259);
  ExceptionList = local_10;
  return 0;
}

