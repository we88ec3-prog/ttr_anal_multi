
void FUN_00435cf0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
  iVar7 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00435d59;
    iVar7 = FUN_00745c20();
  }
  if ((((iVar7 != 0) && (*(int *)(iVar7 + 0x60) != 0)) &&
      ((*(uint *)(iVar7 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar7 + 0x60) != 0)) {
    FUN_0074a010(iVar7);
  }
LAB_00435d59:
  *(undefined1 *)(in_ECX + 0x158) = 0;
  *(undefined4 *)(in_ECX + 0x138) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x13c) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x140) = 0xffffffff;
  piVar2 = *(int **)(*(int *)(in_ECX + 0x148) + 4);
  cVar1 = *(char *)((int)piVar2 + 0x11);
  while (cVar1 == '\0') {
    FUN_00852020(piVar2[2]);
    piVar3 = (int *)*piVar2;
    FUN_0089120c(piVar2);
    piVar2 = piVar3;
    cVar1 = *(char *)((int)piVar3 + 0x11);
  }
  *(int *)(*(int *)(in_ECX + 0x148) + 4) = *(int *)(in_ECX + 0x148);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x148) = *(undefined4 *)(in_ECX + 0x148);
  uVar6 = 1;
  *(int *)(*(int *)(in_ECX + 0x148) + 8) = *(int *)(in_ECX + 0x148);
  *(undefined4 *)(in_ECX + 0x14c) = 0;
  do {
    (**(code **)(**(int **)(in_ECX + 0x104 + uVar6 * 4) + 0x198))(uVar6);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      puStack_10 = (undefined1 *)0x0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    bVar8 = ((uint)DAT_00f94240 & 1 << ((char)uVar6 - 1U & 0x1f)) != 0;
    if (bVar8) {
      uVar4 = FUN_006bde40(&stack0xffffffd8);
      FUN_00436890(in_ECX + 0x144,uVar4);
    }
    (**(code **)(**(int **)(in_ECX + 0x104 + uVar6 * 4) + 0x90))(bVar8);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 10);
  puVar5 = (undefined4 *)(in_ECX + 300);
  iVar7 = 3;
  do {
    (**(code **)(*(int *)*puVar5 + 0x19c))();
    (**(code **)(*(int *)*puVar5 + 0x90))(0);
    puVar5 = puVar5 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  (**(code **)(**(int **)(in_ECX + 0xfc) + 200))();
  (**(code **)(**(int **)(in_ECX + 0xf4) + 0x90))(0);
  ExceptionList = pvStack_18;
  return;
}

