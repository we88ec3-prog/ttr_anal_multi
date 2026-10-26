
void FUN_004e4470(undefined4 *param_1)

{
  uint uVar1;
  int in_ECX;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_68;
  uint local_54;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00930230;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x697d) = *param_1;
  *(undefined4 *)(in_ECX + 0x6981) = param_1[1];
  *(undefined2 *)(in_ECX + 0x6985) = *(undefined2 *)(param_1 + 2);
  *(undefined1 *)(in_ECX + 0x6987) = *(undefined1 *)((int)param_1 + 10);
  switch(*(undefined1 *)(in_ECX + 0x6983)) {
  case 0:
    uVar2 = 0x23;
    FUN_005855b0(0x23,uVar1);
    FUN_00585330(uVar2);
    uVar2 = FUN_00426ec0();
    local_8 = 0;
    FUN_0040f8c0(uVar2);
    FUN_004d6b30(uVar2);
    if (local_54 < 8) goto switchD_004e44d5_default;
    goto LAB_004e461c;
  case 1:
  case 2:
    uVar3 = uVar1;
    if (((char)((ulonglong)*(uint *)(in_ECX + 0x697f) / 0xe10) == '\x03') &&
       ((byte)(((ulonglong)*(uint *)(in_ECX + 0x697f) % 0xe10) / 0x3c) < 2)) {
      uVar2 = 0x24;
      FUN_005855b0(0x24,uVar1);
      FUN_00585330(uVar2);
      uVar2 = FUN_00426ec0();
      local_8 = 1;
      FUN_0040f8c0(uVar2);
      FUN_004d6b30(uVar2);
      local_8 = 0xffffffff;
      FUN_004fa440();
    }
    uVar2 = 0x25;
    FUN_005855b0(0x25,uVar3);
    FUN_00585330(uVar2);
    uVar2 = FUN_00426ec0();
    local_8 = 2;
    FUN_0040f8c0(uVar2);
    FUN_004d6b30(uVar2);
    local_68 = local_30;
    local_38 = local_1c;
    break;
  case 3:
    uVar2 = 0x26;
    FUN_005855b0(0x26,uVar1);
    FUN_00585330(uVar2);
    uVar2 = FUN_00426ec0();
    local_8 = 3;
    FUN_0040f8c0(uVar2);
    FUN_004d6b30(uVar2);
    local_68 = local_4c;
    break;
  default:
    goto switchD_004e44d5_default;
  }
  if (7 < local_38) {
LAB_004e461c:
    FUN_0089120c(local_68);
  }
switchD_004e44d5_default:
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

