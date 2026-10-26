
void FUN_006bf310(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint in_ECX;
  undefined1 auStack_84 [4];
  uint local_80;
  undefined4 local_7c;
  int local_78;
  uint local_74;
  uint auStack_70 [4];
  undefined4 uStack_60;
  uint uStack_5c;
  uint uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093bed0;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_84;
  ExceptionList = &local_14;
  local_74 = in_ECX;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff70);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (((in_ECX < 10) && (local_78 = in_ECX * 0x210 + DAT_00f94304, *(int *)(local_78 + 0x5c) != 0))
     && (local_78 != 0)) {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c = 1;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
    }
    local_c = 0xffffffff;
    iVar1 = FUN_005c7190();
    if (iVar1 != 0) {
      FUN_0082ef00(&local_7c);
    }
    FUN_00745060();
    (**(code **)(*(int *)param_1[0x31] + 200))();
    uVar2 = FUN_00483f00((&PTR_DAT_00d6a1c4)[in_ECX]);
    local_c = 2;
    FUN_00757800(uVar2);
    local_c = 0xffffffff;
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c = 3;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c = 0xffffffff;
    }
    iVar1 = FUN_005c7190();
    if (iVar1 != 0) {
      local_80 = local_74;
      FUN_0082ef00(&local_80);
    }
    FUN_00745060();
    (**(code **)(*(int *)param_1[0x32] + 200))();
    FUN_007597b0(0);
    (**(code **)(*(int *)param_1[0x20] + 200))();
    FUN_00757f20();
    (**(code **)(*(int *)param_1[0x27] + 200))();
    FUN_007597b0(0);
    (**(code **)(*(int *)param_1[0x21] + 200))();
    FUN_00757f20();
    (**(code **)(*(int *)param_1[0x28] + 200))();
    FUN_007597b0(0);
    (**(code **)(*(int *)param_1[0x22] + 200))();
    FUN_00757f20();
    (**(code **)(*(int *)param_1[0x29] + 200))();
    FUN_007597b0(0);
    (**(code **)(*(int *)param_1[0x23] + 200))();
    FUN_00757f20();
    (**(code **)(*(int *)param_1[0x2a] + 200))();
    FUN_007597b0(0);
    (**(code **)(*(int *)param_1[0x24] + 200))();
    FUN_00757f20();
    (**(code **)(*(int *)param_1[0x2b] + 200))();
    FUN_007597b0(0);
    (**(code **)(*(int *)param_1[0x25] + 200))();
    FUN_00757f20();
    (**(code **)(*(int *)param_1[0x2c] + 200))();
    FUN_007597b0(0);
    (**(code **)(*(int *)param_1[0x26] + 200))();
    FUN_00757f20();
    (**(code **)(*(int *)param_1[0x2d] + 200))();
    if ((DAT_00fdf3d4 & 1) == 0) {
      DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
      local_c = 4;
      FUN_006f4380();
      _atexit((_func_4879 *)&LAB_00bce6d0);
      local_c = 0xffffffff;
    }
    FUN_006f5680();
    if ((*(undefined **)(DAT_00fdf3c8 + 8) == &DAT_00c0bfd8) ||
       (*(int *)(*(undefined **)(DAT_00fdf3c8 + 8) + -8) != 5)) {
      FID_conflict__wprintf("Error UseTable \'%s\'\n","g_CharExplain");
    }
    else {
      FUN_006f4f40("GetExplain",1,&DAT_00c0d6dc,local_74);
      iVar1 = FUN_004a2af0(0xffffffff);
      if (iVar1 == 0) {
        FUN_00757710();
      }
      else {
        FUN_00402b70(iVar1);
        local_c = 5;
        FUN_004028b0(auStack_70);
        local_c = CONCAT31(local_c._1_3_,6);
        FUN_00757710();
        if (7 < uStack_40) {
          FUN_0089120c(uStack_54);
        }
        local_c = 0xffffffff;
        uStack_40 = 7;
        uStack_44 = 0;
        uStack_54 = uStack_54 & 0xffff0000;
        if (0xf < uStack_5c) {
          FUN_0089120c(auStack_70[0]);
        }
        uStack_5c = 0xf;
        uStack_60 = 0;
        auStack_70[0] = auStack_70[0] & 0xffffff00;
      }
    }
    *(int *)(DAT_00fdf3c8 + 8) = *(int *)(DAT_00fdf3c8 + 8) + -0x10;
    (**(code **)(*param_1 + 200))();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_84);
  return;
}

