
void FUN_0067b2e0(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *in_ECX;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_44;
  void *pvStack_40;
  undefined4 uStack_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092c9b6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_44;
  uStack_54 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  uStack_58 = 0x1c;
  uStack_5c = 0x67b320;
  puVar4 = (undefined4 *)FUN_00891268();
  if (puVar4 != (undefined4 *)0x0) {
    iVar1 = in_ECX[0x45];
    iVar2 = in_ECX[0x44];
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[3] = 0;
    puVar4[4] = 0xf4369;
    *puVar4 = FoxUI::FXUIEventI2::vftable;
    puVar4[5] = iVar2;
    puVar4[6] = iVar1;
  }
  uStack_58 = 0x67b361;
  FUN_004072a0();
  uStack_58 = 0;
  uStack_5c = 0;
  iStack_60 = -1;
  uStack_64 = 0xffffffff;
  uStack_68 = 0x67b377;
  (**(code **)(*(int *)in_ECX[0x3d] + 0x19c))();
  uStack_68 = 0;
  uStack_6c = 0;
  uStack_70 = 0xffffffff;
  (**(code **)(*(int *)in_ECX[0x3e] + 0x19c))(0xffffffff);
  FUN_00757710();
  FUN_00757710();
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    uStack_2c = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    uStack_2c = 0xffffffff;
  }
  uStack_5c = 0x1a;
  FUN_005740f0(&uStack_5c);
  if (iStack_60 != DAT_00fe5ac8) {
    uVar5 = FUN_004068f0();
    uStack_2c = 1;
    FUN_00757800(uVar5);
    uStack_2c = 0xffffffff;
    if (7 < uStack_44) {
      FUN_0089120c(uStack_58);
    }
    uStack_58 = uStack_58 & 0xffff0000;
    uStack_44 = 7;
    (**(code **)(*(int *)in_ECX[0x47] + 0x94))(0);
    (**(code **)(*(int *)in_ECX[0x46] + 0x94))(0);
    in_ECX[0x44] = -1;
    in_ECX[0x45] = -1;
    (**(code **)(*(int *)in_ECX[0x43] + 0x90))(0);
    FUN_0067b500();
    (**(code **)(*in_ECX + 200))();
    ExceptionList = pvStack_40;
    __security_check_cookie(&uStack_70);
    return;
  }
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}

