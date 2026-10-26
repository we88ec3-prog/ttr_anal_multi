
void FUN_008fe030(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *in_ECX;
  uint uVar6;
  bool bVar7;
  undefined4 local_74;
  uint local_70;
  undefined4 *local_6c;
  undefined4 local_68;
  uint local_54;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00921c0f;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_74 = param_3;
  local_70 = 0;
  local_6c = in_ECX;
  local_14 = uVar2;
  iVar3 = FUN_00891268(0xa0,uVar2);
  uVar4 = 0;
  local_8 = 0;
  bVar7 = iVar3 != 0;
  if (bVar7) {
    local_4c = local_4c & 0xffff0000;
    local_38 = 7;
    local_3c = 0;
    FUN_00402160(L"__FrontFaceCache",0x10);
    local_8 = CONCAT31(local_8._1_3_,1);
    local_70 = 1;
    uVar4 = FUN_0073a110(0x100,0,1);
    in_ECX = local_6c;
  }
  uVar6 = (uint)bVar7;
  in_ECX[4] = uVar4;
  local_8 = 0xffffffff;
  if ((bVar7) && (uVar6 = 0, 7 < local_38)) {
    FUN_0089120c(local_4c);
  }
  puVar5 = (undefined4 *)FUN_00891268(0x4c,uVar2);
  local_8 = 3;
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    FUN_0046e270("UI/ImageSets/RandomItem_CardFrame.dds");
    local_8 = CONCAT31(local_8._1_3_,4);
    uVar6 = uVar6 | 2;
    local_70 = uVar6;
    FUN_0073b090(puVar5);
    *puVar5 = Graphics::CSimpleTexture::vftable;
    puVar5[1] = Graphics::CSimpleTexture::vftable;
    puVar5[2] = Graphics::CSimpleTexture::vftable;
    puVar5[0x11] = 0;
    puVar5[0x12] = 0;
    in_ECX = local_6c;
  }
  *in_ECX = puVar5;
  local_8 = 0xffffffff;
  if (((uVar6 & 2) != 0) && (7 < local_38)) {
    FUN_0089120c(local_4c);
  }
  iVar3 = FUN_00891268(4);
  local_8 = 6;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00571750(iVar3,param_2);
  }
  uVar2 = DAT_00f8d9a4 & 1;
  in_ECX[3] = uVar4;
  in_ECX[5] = param_1;
  if (uVar2 == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 7;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  local_6c = param_1;
  FUN_008438c0(&local_6c);
  if (local_70 == DAT_00f8d91c) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(local_70 + 0x10);
  }
  local_1c = 7;
  local_20 = 0;
  local_30 = (uint)local_30._2_2_ << 0x10;
  FUN_00402160(&DAT_00bed1fc,0);
  local_8._0_1_ = 8;
  local_8._1_3_ = 0;
  if (iVar3 != 0) {
    FUN_004026e0(iVar3,0,0xffffffff);
  }
  uVar2 = DAT_00fe5ae4 & 1;
  in_ECX[8] = local_74;
  if (uVar2 == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 9;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8._0_1_ = 8;
  }
  local_74 = 0x1f0;
  FUN_005740f0(&local_74);
  if (local_6c != DAT_00fe5ac8) {
    uVar4 = FUN_004068f0();
    local_8._0_1_ = 10;
    FUN_004041f0(uVar4,0,0xffffffff);
    local_8 = CONCAT31(local_8._1_3_,8);
    if (7 < local_54) {
      FUN_0089120c(local_68);
    }
    FUN_00571ac0(in_ECX[1],&local_30,param_4);
    FUN_005719b0();
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

