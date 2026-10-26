
void FUN_00758d70(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 in_ECX;
  undefined4 *unaff_ESI;
  int local_38 [4];
  int local_28 [5];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00907e50;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar1 = param_2[2];
    iVar2 = *param_2;
    *unaff_ESI = 0;
    unaff_ESI[2] = iVar1 - iVar2;
    unaff_ESI[1] = 0;
    unaff_ESI[3] = 0;
  }
  else {
    local_38[0] = 0;
    local_38[1] = 0;
    local_38[2] = 0;
    local_28[0] = 0;
    local_28[1] = 0;
    local_28[2] = 0;
    local_c = 1;
    FUN_00758180(param_1,local_38,local_28,in_ECX,param_2,*(int *)(param_1 + 0x10),param_3);
    iVar3 = local_38[0];
    iVar1 = param_2[2];
    iVar2 = *param_2;
    *unaff_ESI = 0;
    unaff_ESI[2] = iVar1 - iVar2;
    unaff_ESI[1] = 0;
    uVar5 = FUN_008fed10(uVar4);
    unaff_ESI[3] = uVar5;
    if (local_28[0] != 0) {
      FUN_0089120c(local_28[0]);
    }
    if (iVar3 != 0) {
      FUN_0089120c(iVar3);
    }
  }
  ExceptionList = local_14;
  return;
}

