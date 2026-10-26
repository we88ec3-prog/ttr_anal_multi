
void FUN_00849600(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *unaff_FS_OFFSET;
  uint local_78 [4];
  undefined4 local_68;
  uint local_64;
  undefined4 local_5c [13];
  undefined4 local_28;
  int local_24 [4];
  uint local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914000;
  local_10 = *unaff_FS_OFFSET;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  local_64 = 0xf;
  local_68 = 0;
  local_78[0] = local_78[0] & 0xffffff00;
  FUN_00403040(param_1,0,0xffffffff);
  local_8 = 0;
  puVar2 = (undefined4 *)(param_1 + 0x1c);
  puVar3 = local_5c;
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  local_28 = *(undefined4 *)(param_1 + 0x50);
  FUN_00848e90(local_24,param_1 + 0x54);
  local_8 = 1;
  FUN_00403040(param_2,0,0xffffffff);
  puVar2 = (undefined4 *)(param_2 + 0x1c);
  puVar3 = (undefined4 *)(param_1 + 0x1c);
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_2 + 0x50);
  FUN_00848bc0(param_1 + 0x54,param_2 + 0x54);
  FUN_00403040(local_78,0,0xffffffff);
  puVar2 = local_5c;
  puVar3 = (undefined4 *)(param_2 + 0x1c);
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(param_2 + 0x50) = local_28;
  FUN_00848bc0(param_2 + 0x54,local_24);
  if (local_24[0] != 0) {
    FUN_0089120c(local_24[0]);
  }
  local_24[0] = 0;
  local_24[1] = 0;
  local_24[2] = 0;
  if (0xf < local_64) {
    FUN_0089120c(local_78[0]);
  }
  *unaff_FS_OFFSET = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

