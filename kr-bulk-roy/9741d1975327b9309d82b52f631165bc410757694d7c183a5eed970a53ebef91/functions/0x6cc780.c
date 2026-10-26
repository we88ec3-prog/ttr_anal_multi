
void FUN_006cc780(int param_1)

{
  int *piVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int *in_ECX;
  int unaff_EDI;
  undefined1 auStack_74 [4];
  int local_70;
  int local_6c;
  undefined4 uStack_68;
  int iStack_58;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092be5e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_74;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff80;
  ExceptionList = &local_14;
  uStack_68 = CONCAT13(in_ECX[0x92] != param_1,(undefined3)uStack_68);
  in_ECX[0x92] = param_1;
  FUN_006cc3a0(in_ECX);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = 0xffffffff;
  }
  local_6c = 0x2bd;
  FUN_005740f0(&local_6c);
  if (local_70 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  FUN_00757710(uVar3);
  iVar4 = in_ECX[0x92];
  if (iVar4 == 1) {
    local_70 = 0x2be;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_70);
    if (local_6c == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_00757710();
    local_70 = 0x2c1;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_70);
    if (local_6c == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uVar5 = FUN_004068f0();
    local_c = 1;
    FUN_00757800(uVar5);
    local_c = 0xffffffff;
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
    local_24 = 7;
    local_28 = 0;
    local_38 = local_38 & 0xffff0000;
  }
  else if (iVar4 == 2) {
    local_70 = 0x2bf;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_70);
    if (local_6c == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_00757710();
    local_70 = 0x2c1;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_70);
    if (local_6c == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    uVar5 = FUN_004068f0();
    local_c = 2;
    FUN_00757800(uVar5);
    local_c = 0xffffffff;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    local_40 = 7;
    local_44 = 0;
    local_54 = local_54 & 0xffff0000;
  }
  else if (iVar4 == 3) {
    local_70 = 0x2c0;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_70);
    if (local_6c == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_00757710();
    local_70 = 0x2c2;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_70);
    if (local_6c == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_00757710();
  }
  if (((int *)in_ECX[0x93] == (int *)0x0) ||
     (iVar4 = (**(code **)(*(int *)in_ECX[0x93] + 0x58))(), iVar4 == 0)) goto LAB_006ccbc8;
  piVar6 = (int *)(**(code **)(*(int *)in_ECX[0x93] + 0x58))();
  if (piVar6 == (int *)0x0) {
LAB_006ccb34:
    piVar6 = (int *)0x0;
  }
  else {
    iVar4 = (**(code **)(*piVar6 + 4))();
    if (iVar4 != 1000) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_006ccb34;
    }
  }
  FUN_007545b0();
  piVar1 = (int *)in_ECX[0x94];
  local_70 = *(int *)(in_ECX[0x98] + 0x14) + 0xf;
  iStack_58 = piVar1[3] + local_70;
  (**(code **)(*piVar1 + 0xbc))(piVar1[2],piVar1[3],piVar1[4],iStack_58);
  uStack_68 = unaff_EDI + piVar6[3];
  (**(code **)(*piVar6 + 0xbc))(piVar6[2],piVar6[3],piVar6[4],uStack_68);
LAB_006ccbc8:
  if (uStack_68._3_1_ != '\0') {
    (**(code **)(*in_ECX + 200))();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_74);
  return;
}

