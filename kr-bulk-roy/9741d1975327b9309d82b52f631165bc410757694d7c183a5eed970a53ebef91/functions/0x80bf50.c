
void FUN_0080bf50(int param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 in_ECX;
  int iVar6;
  undefined1 local_40 [4];
  int local_3c;
  int local_38;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009116c8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar6 = *(int *)(param_1 + 0x2c);
  local_14 = uVar2;
  local_38 = FUN_0080c1c0(in_ECX);
  if ((local_38 == *(int *)(param_1 + 0x2c)) || (cVar1 = FUN_005436a0(uVar2), cVar1 != '\0')) {
    local_3c = *(int *)(param_1 + 0x2c);
    piVar3 = &local_3c;
  }
  else {
    piVar3 = &local_38;
  }
  if (*piVar3 == iVar6) {
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = local_34[0] & 0xffffff00;
    FUN_0040b0b0(in_ECX,0);
    local_18 = param_2;
    local_8 = 0;
    uVar5 = FUN_005435c0(local_34);
    FUN_0080c560(param_1 + 0x28,local_40,uVar5);
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
  }
  else {
    puVar4 = (undefined4 *)FUN_0080c0f0(param_1 + 0x28);
    puVar4 = (undefined4 *)*puVar4;
    for (iVar6 = 0x17; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar4 = *param_2;
      param_2 = param_2 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

