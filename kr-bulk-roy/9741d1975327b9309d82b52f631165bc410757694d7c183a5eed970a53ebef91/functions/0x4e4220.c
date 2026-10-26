
void FUN_004e4220(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined1 local_30 [28];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093029c;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  switch(*(undefined2 *)(param_1 + 2)) {
  case 0:
    uVar3 = 0x39;
    FUN_005855b0(0x39,local_14);
    FUN_00585330(uVar3);
    uVar3 = FUN_00498f60();
    local_8 = 0;
    FUN_0040f8c0(uVar3);
    FUN_004d6b30(uVar3);
    break;
  case 1:
    uVar3 = 0x3a;
    FUN_005855b0(0x3a,local_14);
    FUN_00585330(uVar3);
    uVar3 = FUN_00498f60();
    local_8 = 2;
    FUN_0040f8c0(uVar3);
    FUN_004d6b30(uVar3);
    break;
  case 2:
    uVar3 = 0x3b;
    FUN_005855b0(0x3b,local_14);
    FUN_00585330(uVar3);
    uVar3 = FUN_00498f60();
    local_8 = 1;
    FUN_0040f8c0(uVar3);
    FUN_004d6b30(uVar3);
    break;
  case 3:
    uVar3 = 0x3c;
    FUN_005855b0(0x3c,local_14);
    uVar3 = FUN_00585330(uVar3);
    FUN_00402250(uVar3);
    puVar4 = local_30;
    local_8 = 3;
    FUN_0040f8c0(puVar4);
    FUN_004d6b30(puVar4);
    break;
  default:
    goto switchD_004e4261_default;
  }
  local_8 = 0xffffffff;
  FUN_004fa440();
switchD_004e4261_default:
  uVar1 = DAT_00faadd4 & 1;
  *(uint *)(in_ECX + 0x68b8) = (uint)*(ushort *)(param_1 + 2);
  *(uint *)(in_ECX + 0x68bc) = (uint)*(ushort *)(param_1 + 4);
  if (uVar1 == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 4;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058ab80(0xf42ab,*(undefined4 *)(in_ECX + 0x68bc));
  if (*(int *)(in_ECX + 0x68bc) == 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 5;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x18);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf4363;
      *puVar2 = FoxUI::FXUIEventB1::vftable;
      *(undefined1 *)(puVar2 + 5) = 1;
    }
    FUN_0058aa50(puVar2);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

