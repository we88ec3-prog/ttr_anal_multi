
void FUN_006704b0(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00670519;
    iVar1 = FUN_00745c20();
  }
  if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) &&
      ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar1 + 0x60) != 0)) {
    FUN_0074a010(iVar1);
  }
LAB_00670519:
  FUN_00671bd0();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  switch(DAT_00f9392c) {
  case 7:
    uVar6 = 0x2ba;
    FUN_00585620(0x2ba);
    FUN_00585330(uVar6);
    FUN_00757710();
    FUN_00670670();
    break;
  case 0x15:
    uVar6 = 699;
    FUN_00585620(699);
    FUN_00585330(uVar6);
    FUN_00757710();
    FUN_00670d90();
    break;
  case 0x17:
  case 0x18:
    uVar6 = 700;
    FUN_00585620(700);
    FUN_00585330(uVar6);
    FUN_00757710();
    FUN_006714b0();
  }
  piVar4 = *(int **)(in_ECX + 0xfc);
  uVar2 = *(int *)(in_ECX + 0x100) - (int)piVar4 >> 2;
  uVar3 = 0;
  uVar5 = 0xffffffff;
  if (uVar2 != 0) {
    do {
      uVar5 = uVar3;
      if (*(int *)(DAT_00fe1a88 + 0x18) == *piVar4) break;
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 1;
      uVar5 = 0xffffffff;
    } while (uVar3 < uVar2);
  }
  if (*(int *)(*(int *)(in_ECX + 0xf4) + 0xcc) != 0) {
    FUN_0042c8e0(uVar5);
  }
  ExceptionList = local_14;
  return;
}

