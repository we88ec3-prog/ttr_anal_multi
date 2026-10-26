
void FUN_005fb8c0(int param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *in_ECX;
  int *piVar6;
  int iStack_98;
  int iStack_94;
  int local_90;
  undefined1 auStack_8c [44];
  int iStack_60;
  undefined1 auStack_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093ecd3;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_98;
  ExceptionList = &local_14;
  local_90 = param_1;
  if (in_ECX == (int *)0x0) {
LAB_005fb92d:
    in_ECX = (int *)0x0;
  }
  else {
    iVar3 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffff60);
    if (iVar3 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_005fb92d;
    }
  }
  if (in_ECX[5] != 0x6a7) goto LAB_005fbb83;
  piVar6 = (int *)in_ECX[6];
  if (piVar6 == (int *)0x0) {
LAB_005fb967:
    piVar6 = (int *)0x0;
  }
  else {
    iVar3 = (**(code **)(*piVar6 + 4))();
    if (iVar3 != 0x105ba) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_005fb967;
    }
  }
  if ((*(char *)(local_90 + 0x144) == '\0') && (*(char *)(local_90 + 0x145) == '\0')) {
    FUN_005fd080(piVar6[5],piVar6[6]);
  }
  else {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      uStack_c = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      uStack_c = 0xffffffff;
    }
    iStack_94 = 0xee;
    FUN_005740f0(&iStack_94);
    if (iStack_98 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar4 = (undefined4 *)(iStack_98 + 0x10);
    if (7 < *(uint *)(iStack_98 + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    FUN_007572f0(puVar4);
    uStack_c._0_1_ = 1;
    uStack_c._1_3_ = 0;
    iStack_98 = 0;
    FUN_00848020(&iStack_98);
    if (iStack_94 != iStack_60) {
      *(undefined4 *)(iStack_94 + 0x18) = 0xffff0000;
      *(undefined1 *)(iStack_94 + 0x1c) = 1;
      FUN_007591a0(*(int *)(iStack_94 + 0x10),
                   *(int *)(iStack_94 + 0x14) - *(int *)(iStack_94 + 0x10),0xffff0000);
    }
    FUN_00759ac0(0);
    puVar4 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      iVar3 = piVar6[6];
      iVar1 = piVar6[5];
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf4425;
      *puVar4 = FoxUI::FXUIEventI2::vftable;
      puVar4[5] = iVar1;
      puVar4[6] = iVar3;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      uStack_c._0_1_ = 2;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      uStack_c._0_1_ = 1;
    }
    iStack_98 = 0x196;
    FUN_005740f0(&iStack_98);
    if (iStack_94 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar5 = (undefined4 *)(iStack_94 + 0x10);
    if (7 < *(uint *)(iStack_94 + 0x24)) {
      puVar5 = (undefined4 *)*puVar5;
    }
    FUN_007572f0(puVar5);
    uStack_c._0_1_ = 3;
    FUN_00407330(0xd1,auStack_8c,auStack_54,puVar4,local_90);
    uStack_c = CONCAT31(uStack_c._1_3_,1);
    FUN_00757640(auStack_54);
    uStack_c = 0xffffffff;
    FUN_00757640(auStack_8c);
  }
LAB_005fbb83:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&iStack_98);
  return;
}

