
void FUN_00441a80(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  int iVar4;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
  iVar1 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00441aed;
    iVar1 = FUN_00745c20();
  }
  if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x60) != 0)) &&
      ((*(uint *)(iVar1 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar1 + 0x60) != 0)) {
    FUN_0074a010(iVar1);
  }
LAB_00441aed:
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0x24c);
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xcc), iVar1 != 0)) {
    FUN_006438f0(iVar1);
  }
  FUN_00757710();
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0x24c);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  uVar2 = (uint)DAT_00f94240;
  iVar4 = 1;
  uVar3 = 2;
  do {
    if ((uVar3 >> 1 & uVar2) != 0) {
      if (*(int *)(iVar1 + 0xcc) != 0) {
        FUN_00412c70(iVar4);
      }
      FUN_00757710();
    }
    iVar4 = iVar4 + 1;
    uVar3 = uVar3 << 1 | (uint)((int)uVar3 < 0);
  } while (iVar4 < 10);
  iVar1 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if (iVar1 != 0) {
    FUN_0075cd30(*(undefined4 *)(in_ECX + 0xf8));
    FUN_00441060(in_ECX);
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0x24c);
  if (iVar1 != 0) {
    FUN_00749920(iVar1);
  }
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  FUN_004418a0();
  iVar4 = DAT_00fb1318;
  iVar1 = *(int *)(DAT_00fb1318 + 0xbfe8);
  *(undefined4 *)(iVar1 + 0x78) = 1;
  *(undefined1 *)(iVar1 + 0x80) = 1;
  iVar1 = *(int *)(iVar4 + 0xbfe8);
  *(undefined4 *)(iVar1 + 0x7c) = 0x42340000;
  *(undefined4 *)(iVar1 + 0xb0) = 1;
  ExceptionList = local_14;
  return;
}

