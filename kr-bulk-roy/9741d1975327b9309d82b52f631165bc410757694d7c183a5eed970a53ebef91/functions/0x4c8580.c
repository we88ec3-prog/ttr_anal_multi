
void FUN_004c8580(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int *in_ECX;
  int local_3c;
  undefined1 local_38 [12];
  undefined1 local_2c [12];
  float local_20;
  float local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b1fc;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004ca890(local_14);
  pcVar1 = *(code **)(*in_ECX + 0x38);
  in_ECX[0x2b] = 1;
  (*pcVar1)();
  FUN_004c89a0();
  piVar3 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
  if (in_ECX == piVar3) {
    if ((DAT_00fb73b8 & 1) == 0) {
      DAT_00fb73b8 = DAT_00fb73b8 | 1;
      local_8 = 0;
      FUN_00560170();
      _atexit((_func_4879 *)&LAB_00bcd110);
      local_8 = 0xffffffff;
    }
    if (DAT_00fb73e8 == 0) {
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        local_8 = 1;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
        local_8 = 0xffffffff;
      }
      if ((DAT_00fab090 == (int *)0x0) && (DAT_00fab028 != (int *)0x0)) {
        DAT_00fab090 = (int *)(**(code **)(*DAT_00fab028 + 0x20))();
        (**(code **)(*DAT_00fab090 + 0x18))(3);
      }
      piVar3 = DAT_00fab090;
      pfVar4 = (float *)(**(code **)(*in_ECX + 0x50))(local_2c);
      local_1c = pfVar4[1] * 0.1;
      local_18 = pfVar4[2] * 0.1;
      local_20 = *pfVar4 * 0.1;
      (**(code **)(*piVar3 + 0xc))(&local_20);
    }
  }
  if (in_ECX[0xdb] == 0) {
    in_ECX[0xdb] = 0x1e;
  }
  else {
    in_ECX[0xdb] = in_ECX[0xdb] + -1;
  }
  FUN_004c83c0(in_ECX);
  if (in_ECX[0xd9] != 0) {
    FUN_00550780();
    puVar5 = (undefined4 *)(**(code **)(*in_ECX + 0x50))(local_2c);
    iVar2 = *(int *)(in_ECX[0xd9] + 0x24);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x28) = *puVar5;
      *(undefined4 *)(iVar2 + 0x2c) = puVar5[1];
      *(undefined4 *)(iVar2 + 0x30) = puVar5[2];
      *(undefined4 *)(iVar2 + 0x70) = 1;
    }
  }
  piVar3 = in_ECX + 0x59;
  local_3c = 0x80;
  do {
    if (*piVar3 != 0) {
      FUN_00550780();
      puVar5 = (undefined4 *)(**(code **)(*in_ECX + 0x50))(local_38);
      iVar2 = *(int *)(*piVar3 + 0x24);
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x28) = *puVar5;
        *(undefined4 *)(iVar2 + 0x2c) = puVar5[1];
        *(undefined4 *)(iVar2 + 0x30) = puVar5[2];
        *(undefined4 *)(iVar2 + 0x70) = 1;
      }
    }
    piVar3 = piVar3 + 1;
    local_3c = local_3c + -1;
  } while (local_3c != 0);
  if (in_ECX[0x105] != 0) {
    FUN_004c9140(in_ECX,in_ECX[0x104]);
    in_ECX[0x105] = in_ECX[0x105] + -1;
  }
  if (in_ECX[0x106] != 0) {
    in_ECX[0x106] = in_ECX[0x106] + -1;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

