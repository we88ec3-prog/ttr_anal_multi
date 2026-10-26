
void FUN_0086ffb0(int *param_1)

{
  undefined4 ***pppuVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 **local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009195a8;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x38) != 0) {
    FUN_0086d5d0(local_14);
    local_8 = 0;
    pppuVar1 = (undefined4 ***)local_30[0];
    if (local_1c < 0x10) {
      pppuVar1 = local_30;
    }
    iVar2 = (**(code **)(*param_1 + 0x24))(param_1,0,pppuVar1);
    if (iVar2 != 0) {
      puVar3 = (undefined4 *)FUN_008720b0(iVar2);
      *(undefined4 *)(in_ECX + 0x40) = *puVar3;
      *(undefined4 *)(in_ECX + 0x44) = puVar3[1];
      *(undefined4 *)(in_ECX + 0x48) = puVar3[2];
      *(undefined4 *)(in_ECX + 0x4c) = puVar3[3];
    }
    *(undefined4 *)(in_ECX + 0x38) = 0;
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

