
void FUN_0067e8d0(void)

{
  undefined4 uVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  uint in_ECX;
  int iVar7;
  undefined4 *puStack_b8;
  int iStack_b4;
  int *piStack_b0;
  uint uStack_ac;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  uint local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_6c;
  undefined4 local_68;
  uint local_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint uStack_3c;
  uint uStack_38;
  void *pvStack_30;
  undefined4 uStack_28;
  undefined4 uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00932d5a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_9c;
  uStack_ac = DAT_00d61f20 ^ (uint)&stack0xffffff58;
  ExceptionList = &local_14;
  piStack_b0 = (int *)0x1c;
  iStack_b4 = 0x67e91d;
  local_94 = in_ECX;
  puVar4 = (undefined4 *)FUN_00891268();
  if (puVar4 != (undefined4 *)0x0) {
    uVar5 = *(undefined4 *)(in_ECX + 0x11c);
    uVar1 = *(undefined4 *)(in_ECX + 0x118);
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf4369;
    *puVar4 = FoxUI::FXUIEventI2::vftable;
    puVar4[5] = uVar1;
    puVar4[6] = uVar5;
  }
  piStack_b0 = (int *)0x67e95c;
  FUN_004072a0();
  local_90 = 0xffffffff;
  local_8c = 0xffffffff;
  local_88 = 0xffffffff;
  local_84 = 0xffffffff;
  local_80 = 0;
  local_7c = 0;
  local_64 = 7;
  local_68 = 0;
  local_78 = (int *)((uint)local_78._2_2_ << 0x10);
  local_5c = 0xffffffff;
  local_58 = 0xffffffff;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0xffffffff;
  local_c = 0;
  piStack_b0 = (int *)0x67e9bd;
  FUN_0045d560();
  local_c = 0xffffffff;
  if (7 < local_64) {
    piStack_b0 = local_78;
    iStack_b4 = 0x67e9d5;
    FUN_0089120c();
  }
  uVar3 = local_94;
  piStack_b0 = (int *)0x0;
  iStack_b4 = 0;
  puStack_b8 = (undefined4 *)0xffffffff;
  (**(code **)(**(int **)(local_94 + 0xf8) + 0x19c))(0xffffffff);
  FUN_00757710();
  (**(code **)(**(int **)(uVar3 + 0x114) + 0x94))(0);
  (**(code **)(**(int **)(uVar3 + 0xf4) + 0x94))(0);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    uStack_24 = 1;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    uStack_24 = 0xffffffff;
  }
  piStack_b0 = (int *)0x1a;
  FUN_005740f0(&piStack_b0);
  if (iStack_b4 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  uVar5 = FUN_004068f0();
  uStack_24 = 2;
  FUN_00757800(uVar5);
  uStack_24 = 0xffffffff;
  if (7 < uStack_3c) {
    FUN_0089120c(local_50);
  }
  (**(code **)(**(int **)(uVar3 + 0x110) + 0x90))(0);
  puStack_b8 = (undefined4 *)(uVar3 + 0x100);
  puVar4 = (undefined4 *)(uVar3 + 0x178);
  iStack_b4 = 3;
  do {
    (**(code **)(*(int *)*puStack_b8 + 0x19c))(0xffffffff,0xffffffff,0,0);
    FUN_00757710();
    piVar6 = (int *)FUN_00891268(0x1c);
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      iVar7 = puVar4[-1];
      piVar6[5] = puVar4[-2];
      piVar6[1] = -1;
      piVar6[2] = -1;
      piVar6[3] = 0;
      piVar6[4] = 0xf4369;
      *piVar6 = (int)FoxUI::FXUIEventI2::vftable;
      piVar6[6] = iVar7;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      uStack_28 = 3;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      uStack_28 = 0xffffffff;
    }
    if (DAT_00f95bd4 != (int *)0x0) {
      (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar6);
    }
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x10))(1);
    }
    uStack_ac = 0xffffffff;
    uStack_9c = 0;
    uStack_98 = 0;
    local_80 = 7;
    local_84 = 0;
    local_94 = local_94 & 0xffff0000;
    local_78 = (int *)0xffffffff;
    uStack_74 = 0xffffffff;
    uStack_6c = 0;
    local_68 = 0;
    local_64 = 0;
    uStack_60 = 0;
    local_5c = 0xffffffff;
    uStack_28 = 4;
    puVar4[-2] = 0xffffffff;
    puVar4[-1] = 0xffffffff;
    *puVar4 = 0xffffffff;
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0;
    puVar4[3] = 0;
    FUN_004026e0(&local_94,0,0xffffffff);
    puVar4[0xb] = local_78;
    puVar4[0xe] = uStack_6c;
    puVar4[0xf] = local_68;
    puVar4[0xc] = uStack_74;
    uStack_28 = 0xffffffff;
    puVar4[0x10] = local_64;
    puVar4[0x11] = uStack_60;
    puVar4[0x12] = local_5c;
    if (7 < local_80) {
      FUN_0089120c(local_94);
    }
    puStack_b8 = puStack_b8 + 1;
    puVar4 = puVar4 + 0x16;
    iStack_b4 = iStack_b4 + -1;
  } while (iStack_b4 != 0);
  piVar6 = piStack_b0 + 0x9e;
  iVar7 = 2;
  iStack_b4 = 0;
  do {
    FUN_00757710();
    (**(code **)(*(int *)*piVar6 + 0x94))(0);
    piVar6 = piVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  (**(code **)(*piStack_b0 + 200))();
  ExceptionList = pvStack_30;
  __security_check_cookie(uStack_38 ^ (uint)&puStack_b8);
  return;
}

