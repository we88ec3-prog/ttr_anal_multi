
void FUN_00773390(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  char *****pppppcVar8;
  char *pcVar9;
  int in_ECX;
  int iVar10;
  float10 fVar11;
  int iStack_94;
  int iStack_90;
  int local_8c;
  int local_88;
  int iStack_84;
  int iStack_80;
  int *piStack_7c;
  char ****local_70 [4];
  undefined4 uStack_60;
  uint local_5c;
  undefined4 uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  char ****appppcStack_38 [4];
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00920a08;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_94;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff60;
  ExceptionList = &local_14;
  local_88 = param_1;
  if (*(uint *)(in_ECX + 0x1c) < 8) {
    iVar5 = in_ECX + 8;
  }
  else {
    iVar5 = *(int *)(in_ECX + 8);
  }
  local_8c = in_ECX;
  uVar4 = FUN_00764d80(local_70,iVar5,uVar3);
  local_c = 0;
  FUN_00402800(uVar4);
  local_c = 0xffffffff;
  if (7 < local_5c) {
    FUN_0089120c(local_70[0]);
  }
  if (*(uint *)(in_ECX + 0x38) < 8) {
    iVar5 = in_ECX + 0x24;
  }
  else {
    iVar5 = *(int *)(in_ECX + 0x24);
  }
  uVar4 = FUN_00764d80(local_70,iVar5,uVar3);
  local_c = 1;
  FUN_00402800(uVar4);
  local_c = 0xffffffff;
  if (7 < local_5c) {
    FUN_0089120c(local_70[0]);
  }
  if (*(uint *)(in_ECX + 0x54) < 8) {
    iVar5 = in_ECX + 0x40;
  }
  else {
    iVar5 = *(int *)(in_ECX + 0x40);
  }
  uVar4 = FUN_00764d80(local_70,iVar5);
  local_c = 2;
  FUN_00402800(uVar4);
  local_c = 0xffffffff;
  if (7 < local_5c) {
    FUN_0089120c(local_70[0]);
  }
  uVar1 = FUN_00765120(*(undefined1 *)(in_ECX + 0x7c));
  *(undefined1 *)(in_ECX + 0x7c) = uVar1;
  fVar11 = (float10)FUN_00764f00(*(undefined4 *)(in_ECX + 0x80));
  *(float *)(in_ECX + 0x80) = (float)fVar11;
  uStack_54 = (uint)uStack_54._2_2_ << 0x10;
  uStack_40 = 7;
  uStack_44 = 0;
  FUN_00402160(L"FONTITEM",8);
  local_c = 3;
  FUN_004297b0();
  pppppcVar8 = (char *****)appppcStack_38[0];
  if (uStack_24 < 0x10) {
    pppppcVar8 = appppcStack_38;
  }
  iVar5 = FUN_0072e2e0(pppppcVar8);
  if (0xf < uStack_24) {
    FUN_0089120c(appppcStack_38[0]);
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  appppcStack_38[0] = (char ****)((uint)appppcStack_38[0] & 0xffffff00);
  while (iVar5 != 0) {
    iStack_94 = 0;
    iStack_90 = 0;
    FUN_00429860(&iStack_94);
    FUN_00429860(&iStack_90);
    if ((iStack_94 != 0xf61a) || (piVar6 = _malloc(0x20), piVar6 == (int *)0x0)) goto LAB_0077373c;
    DAT_00fba828 = DAT_00fba828 + 1;
    piVar6[2] = 0;
    piVar6[3] = 0;
    *(undefined1 *)(piVar6 + 5) = 0;
    iStack_94 = 0;
    piVar6[1] = DAT_00fba828;
    *piVar6 = (int)FoxUI::FXUIFontItem::vftable;
    piVar6[4] = 0xe;
    FUN_00429860(&iStack_94);
    iVar7 = (**(code **)(*piVar6 + 4))();
    if ((iStack_94 != iVar7) ||
       (cVar2 = (**(code **)(*piVar6 + 0x14))(iVar5), iVar7 = local_8c, cVar2 == '\0')) {
      if (7 < uStack_40) {
        FUN_0089120c(uStack_54);
      }
      goto LAB_007739f5;
    }
    iVar10 = local_8c + 0x5c;
    if (iVar10 != 0) {
      iStack_94 = iStack_90;
      FUN_008438c0(&iStack_94);
      if (iStack_84 == *(int *)(iVar7 + 0x60)) {
        piVar6[2] = local_8c;
        iStack_80 = iStack_90;
        piStack_7c = piVar6;
        uVar4 = FUN_0057ef20();
        FUN_0057e850(iVar10,uVar4);
      }
    }
    FUN_004297b0();
    pppppcVar8 = (char *****)local_70[0];
    if (local_5c < 0x10) {
      pppppcVar8 = local_70;
    }
    for (iVar5 = *(int *)(iVar5 + 0x40); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x40)) {
      pcVar9 = (char *)(iVar5 + 0x20);
      if (0xf < *(uint *)(iVar5 + 0x34)) {
        pcVar9 = *(char **)pcVar9;
      }
      iVar7 = __stricmp(pcVar9,(char *)pppppcVar8);
      if (iVar7 == 0) goto LAB_00773709;
    }
    iVar5 = 0;
LAB_00773709:
    if (0xf < local_5c) {
      FUN_0089120c(local_70[0]);
    }
    local_5c = 0xf;
    uStack_60 = 0;
    local_70[0] = (char ****)((uint)local_70[0] & 0xffffff00);
  }
  FUN_00402160(L"FONTITEM",8);
  uVar4 = FUN_00633110(local_70,&uStack_54,L"BOLD");
  local_c._0_1_ = 4;
  FUN_00402800(uVar4);
  local_c = CONCAT31(local_c._1_3_,3);
  if (7 < local_5c) {
    FUN_0089120c(local_70[0]);
  }
  FUN_004297b0();
  pppppcVar8 = (char *****)local_70[0];
  if (local_5c < 0x10) {
    pppppcVar8 = local_70;
  }
  iVar5 = FUN_0072e2e0(pppppcVar8);
  if (0xf < local_5c) {
    FUN_0089120c(local_70[0]);
  }
  local_5c = 0xf;
  uStack_60 = 0;
  local_70[0] = (char ****)((uint)local_70[0] & 0xffffff00);
  while (iVar5 != 0) {
    iStack_94 = 0;
    iStack_90 = 0;
    FUN_00429860(&iStack_94);
    FUN_00429860(&iStack_90);
    if ((iStack_94 != 0xf61a) || (piVar6 = _malloc(0x20), piVar6 == (int *)0x0)) {
      if (7 < uStack_40) {
        FUN_0089120c(uStack_54);
      }
      goto LAB_007739f5;
    }
    piVar6[2] = 0;
    piVar6[3] = 0;
    *(undefined1 *)(piVar6 + 5) = 0;
    iStack_94 = 0;
    DAT_00fba828 = DAT_00fba828 + 1;
    piVar6[1] = DAT_00fba828;
    *piVar6 = (int)FoxUI::FXUIFontItem::vftable;
    piVar6[4] = 0xe;
    FUN_00429860(&iStack_94);
    iVar7 = (**(code **)(*piVar6 + 4))();
    if ((iStack_94 != iVar7) ||
       (cVar2 = (**(code **)(*piVar6 + 0x14))(iVar5), iVar7 = local_8c, cVar2 == '\0'))
    goto LAB_0077373c;
    iVar10 = local_8c + 0x6c;
    if (iVar10 != 0) {
      local_88 = iStack_90;
      FUN_008438c0(&local_88);
      if (iStack_84 == *(int *)(iVar7 + 0x70)) {
        piVar6[2] = local_8c;
        iStack_80 = iStack_90;
        piStack_7c = piVar6;
        uVar4 = FUN_0057ef20();
        FUN_0057e850(iVar10,uVar4);
      }
    }
    FUN_004297b0();
    pppppcVar8 = (char *****)appppcStack_38[0];
    if (uStack_24 < 0x10) {
      pppppcVar8 = appppcStack_38;
    }
    for (iVar5 = *(int *)(iVar5 + 0x40); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x40)) {
      pcVar9 = (char *)(iVar5 + 0x20);
      if (0xf < *(uint *)(iVar5 + 0x34)) {
        pcVar9 = *(char **)pcVar9;
      }
      iVar7 = __stricmp(pcVar9,(char *)pppppcVar8);
      if (iVar7 == 0) goto LAB_00773987;
    }
    iVar5 = 0;
LAB_00773987:
    if (0xf < uStack_24) {
      FUN_0089120c(appppcStack_38[0]);
    }
    uStack_24 = 0xf;
    uStack_28 = 0;
    appppcStack_38[0] = (char ****)((uint)appppcStack_38[0] & 0xffffff00);
  }
  if (7 < uStack_40) {
    FUN_0089120c(uStack_54);
  }
LAB_007739f5:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&iStack_94);
  return;
LAB_0077373c:
  if (7 < uStack_40) {
    FUN_0089120c(uStack_54);
  }
  goto LAB_007739f5;
}

