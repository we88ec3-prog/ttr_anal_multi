
void FUN_00665150(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  int *unaff_EDI;
  undefined1 auStack_60 [4];
  int local_5c;
  int local_58;
  undefined4 local_54;
  uint local_40;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093d35e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_60;
  ExceptionList = &local_14;
  uVar4 = 0;
  uVar1 = *(int *)(DAT_00fe1df4 + 0xc) - *(int *)(DAT_00fe1df4 + 8) >> 3;
  if (uVar1 != 0) {
    pbVar5 = *(byte **)(DAT_00fe1df4 + 8);
    do {
      if (*pbVar5 == param_1) {
        pbVar5 = *(byte **)(DAT_00fe1df4 + 8) + uVar4 * 8;
        goto LAB_006651b2;
      }
      uVar4 = uVar4 + 1;
      pbVar5 = pbVar5 + 8;
    } while (uVar4 < uVar1);
  }
  pbVar5 = (byte *)0x0;
LAB_006651b2:
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff98);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (param_1 < 10) {
    uVar1 = DAT_00f94304 + param_1 * 0x210;
    uVar1 = -(uint)(*(int *)(uVar1 + 0x5c) != 0) & uVar1;
  }
  else {
    uVar1 = 0;
  }
  if ((pbVar5 != (byte *)0x0) && (uVar1 != 0)) {
    unaff_EDI[0x44] = param_1;
    local_5c = *(int *)(pbVar5 + 4);
    iVar2 = FUN_00404ba0();
    local_58 = *(int *)(iVar2 + 0x6864);
    FUN_007597b0(0);
    uVar3 = FUN_00662800();
    local_c = 1;
    FUN_00757800(uVar3);
    local_c = 0xffffffff;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    uVar3 = FUN_00665560();
    local_c = 2;
    FUN_00757800(uVar3);
    local_c = 0xffffffff;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    FUN_00412df0();
    local_c = 3;
    FUN_00757710();
    local_c = 0xffffffff;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    FUN_00412df0();
    local_c = 4;
    FUN_00757710();
    local_c = 0xffffffff;
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
    uStack_38 = uStack_38 & 0xffff0000;
    uStack_24 = 7;
    uStack_28 = 0;
    (**(code **)(*(int *)unaff_EDI[0x42] + 0x90))(local_5c <= local_58);
    (**(code **)(*unaff_EDI + 200))();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_60);
  return;
}

