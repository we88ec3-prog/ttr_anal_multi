
void FUN_004fece0(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int in_ECX;
  bool bVar4;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40 [4];
  undefined4 local_30;
  uint local_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  puStack_10 = &LAB_0092438e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_60;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_2c = 7;
  local_30 = 0;
  local_40[0] = local_40[0] & 0xffff0000;
  bVar4 = *(char *)(param_1 + 2) != '\0';
  if (bVar4) {
    iVar1 = (uint)*(byte *)(param_1 + 3) * 0x40 + 0x6070;
  }
  else {
    iVar1 = (uint)*(byte *)(param_1 + 3) * 0x40 + 0x5eb0;
  }
  local_c = (uint)bVar4;
  puVar3 = (undefined4 *)(iVar1 + in_ECX);
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[4] = 0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  puVar3[7] = 0;
  FUN_004026e0(local_40,0,0xffffffff);
  local_c = 0xffffffff;
  if (7 < local_2c) {
    FUN_0089120c(local_40[0],uVar2);
  }
  uVar2 = DAT_00faadd4 & 1;
  *(undefined4 *)(in_ECX + 0x623c) = 0;
  if (uVar2 == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 2;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aad0(0xf4264);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_60);
  return;
}

