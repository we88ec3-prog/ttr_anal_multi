
void FUN_0056b7f0(int param_1,short *param_2)

{
  short sVar1;
  int iVar2;
  undefined1 auStack_224 [4];
  short local_220 [256];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_224;
  iVar2 = (int)local_220 - (int)param_2;
  do {
    sVar1 = *param_2;
    *(short *)(iVar2 + (int)param_2) = sVar1;
    param_2 = param_2 + 1;
  } while (sVar1 != 0);
  local_1c = 0;
  local_18 = 0x437f0000;
  local_20 = 0xffffffff;
  local_14 = 0;
  FUN_0056bd50(param_1 + 4,local_220);
  if ((6 < *(uint *)(param_1 + 0x14)) && (*(int *)(param_1 + 0x14) != 0)) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    if (*(uint *)(param_1 + 0xc) <= *(uint *)(param_1 + 0x10)) {
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    iVar2 = *(int *)(param_1 + 0x14) + -1;
    *(int *)(param_1 + 0x14) = iVar2;
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
  }
  FUN_0056b8b0();
  __security_check_cookie(local_c ^ (uint)auStack_224);
  return;
}

