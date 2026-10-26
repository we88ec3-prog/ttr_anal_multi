
void FUN_0064df60(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined1 *puVar5;
  int iStack_7c;
  int iStack_78;
  undefined1 auStack_74 [16];
  int iStack_64;
  undefined1 auStack_58 [16];
  int iStack_48;
  uint uStack_20;
  uint local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093d89a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_7c;
  ExceptionList = &local_14;
  iVar4 = **(int **)(in_ECX + 0xfc);
  uVar1 = FUN_0064e8a0(DAT_00d61f20 ^ (uint)&stack0xffffff78);
  (**(code **)(iVar4 + 0x90))(uVar1);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    puStack_10 = (undefined1 *)0x0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  iVar4 = *(int *)(DAT_00fab130 + 0x5eac);
  FUN_00757710();
  FUN_00757710();
  iStack_78 = in_ECX + 0x114;
  FUN_00402160(&DAT_00bed1fc,0);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    puStack_10 = (undefined1 *)0x1;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  FUN_0064e6c0(DAT_00fb934d != '\0');
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    puStack_10 = (undefined1 *)0x2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    puStack_10 = (undefined1 *)0xffffffff;
  }
  switch(DAT_00f9392c) {
  case 2:
    if (((uint)(*(int **)(in_ECX + 0xf4))[10] >> 8 & 1) != 0) {
      (**(code **)(**(int **)(in_ECX + 0xf4) + 0x94))(0);
    }
  default:
    goto switchD_0064e0dd_caseD_3;
  case 4:
    iStack_7c = iVar4;
    iVar2 = FUN_004a77a0();
    FUN_005366c0(&iStack_7c);
    if ((iVar4 == *(int *)(iVar2 + 0x24)) || (iVar4 == -0x10)) goto switchD_0064e0dd_caseD_3;
    iVar2 = FUN_0040f060();
    uVar3 = *(undefined4 *)(iVar2 + 0x48);
    FUN_0048a850(uVar3);
    FUN_0082a6a0(uVar3);
    puStack_10 = (undefined1 *)0x3;
    if (iStack_64 == 0) {
      puVar5 = (undefined1 *)(*(int *)(iVar4 + 0x28) + 4);
    }
    else {
      puVar5 = auStack_74;
    }
    FUN_00757800(puVar5);
    FUN_004026e0(*(int *)(in_ECX + 0x10c) + 0xe8,0,0xffffffff);
    if (*(int *)(iVar4 + 0x14) != 0) {
      FUN_00757710();
    }
    break;
  case 9:
    iVar2 = FUN_0040f060();
    uVar3 = *(undefined4 *)(iVar2 + 0x48);
    FUN_0048a850(uVar3);
    FUN_0082a6a0(uVar3);
    puStack_10 = (undefined1 *)0x4;
    if (iStack_64 == 0) {
      FUN_004452c0(iVar4);
      uVar3 = FUN_00823620(iVar4);
      puStack_10._0_1_ = 5;
      FUN_00757800(uVar3);
      puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,4);
      FUN_004fa440();
    }
    else {
      FUN_00757800(auStack_74);
    }
    FUN_004026e0(*(int *)(in_ECX + 0x10c) + 0xe8,0,0xffffffff);
    break;
  case 0x1c:
    puVar5 = &stack0xffffff80;
    FUN_00420830(puVar5);
    iStack_7c = FUN_0081bb60(puVar5);
    if (iStack_7c == 0) goto switchD_0064e0dd_caseD_3;
    iVar4 = FUN_0040f060();
    uVar3 = *(undefined4 *)(iVar4 + 0x48);
    FUN_0048a850(uVar3);
    FUN_0082a6a0(uVar3);
    puStack_10 = (undefined1 *)0x6;
    if (iStack_48 == 0) {
      puVar5 = (undefined1 *)(iStack_7c + 4);
    }
    else {
      puVar5 = auStack_58;
    }
    FUN_00757800(puVar5);
    FUN_004026e0(*(int *)(in_ECX + 0x10c) + 0xe8,0,0xffffffff);
    if (1 < *(uint *)(iStack_7c + 0x28)) {
      puVar5 = &stack0xffffff80;
      FUN_00420830(puVar5);
      FUN_0081c9e0(puVar5);
      FUN_00757710();
    }
  }
  FUN_004fa440();
switchD_0064e0dd_caseD_3:
  ExceptionList = pvStack_18;
  __security_check_cookie(uStack_20 ^ (uint)&stack0xffffff80);
  return;
}

