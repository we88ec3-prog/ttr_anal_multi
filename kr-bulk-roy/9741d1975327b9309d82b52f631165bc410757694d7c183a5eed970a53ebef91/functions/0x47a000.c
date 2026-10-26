
uint FUN_0047a000(uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar1 = param_1;
  puStack_c = &LAB_00927afa;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_8 = 0;
    FUN_004a79a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&DAT_00bccf80);
  }
  uVar3 = DAT_00fb7264 - DAT_00fb7260 >> 2;
  uVar5 = 0;
  if (uVar3 != 0) {
    do {
      if (**(uint **)(DAT_00fb7260 + uVar5 * 4) == (param_1 & 0xff)) break;
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar3);
  }
  if ((DAT_00fbace4 & 1) == 0) {
    DAT_00fbace4 = DAT_00fbace4 | 1;
    local_8 = 1;
    FUN_00825080();
    _atexit((_func_4879 *)&LAB_00bcd6d0);
    if ((DAT_00fbace4 & 1) == 0) {
      DAT_00fbace4 = DAT_00fbace4 | 1;
      local_8 = 2;
      FUN_00825080();
      _atexit((_func_4879 *)&LAB_00bcd6d0);
    }
  }
  local_8 = 0xffffffff;
  bVar2 = DAT_00fbace8;
  if ((char)param_3 == '\0') {
    iVar4 = FUN_008257b0();
    bVar2 = *(byte *)(iVar4 + 1);
  }
  param_1 = (uint)bVar2;
  if ((byte)param_2 == 0) {
    if ((int *)*unaff_EDI != (int *)0x0) {
      (**(code **)(*(int *)*unaff_EDI + 0x184))(uVar1,1,param_3);
      ExceptionList = local_10;
      return *unaff_EDI;
    }
  }
  else if ((byte)param_2 < bVar2) {
    if (unaff_EDI[1] != 0) {
      (**(code **)(*(int *)unaff_EDI[1] + 0x184))(uVar1,param_2,param_3);
      ExceptionList = local_10;
      return unaff_EDI[1];
    }
  }
  else if ((int *)*unaff_EDI != (int *)0x0) {
    (**(code **)(*(int *)*unaff_EDI + 0x184))(uVar1,param_1,param_3);
    ExceptionList = local_10;
    return *unaff_EDI;
  }
  ExceptionList = local_10;
  return param_1;
}

