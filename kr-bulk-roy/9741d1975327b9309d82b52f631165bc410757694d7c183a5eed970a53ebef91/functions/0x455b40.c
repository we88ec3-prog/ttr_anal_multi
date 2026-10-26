
void FUN_00455b40(void)

{
  void *_Dst;
  undefined4 uVar1;
  int in_ECX;
  undefined4 *puVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  int *piVar8;
  bool bVar9;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
  iVar6 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00455ba9;
    iVar6 = FUN_00745c20();
  }
  if ((((iVar6 != 0) && (*(int *)(iVar6 + 0x60) != 0)) &&
      ((*(uint *)(iVar6 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar6 + 0x60) != 0)) {
    FUN_0074a010(iVar6);
  }
LAB_00455ba9:
  *(undefined1 *)(in_ECX + 400) = 0;
  _Dst = *(void **)(in_ECX + 0x154);
  if (_Dst != *(void **)(in_ECX + 0x158)) {
    FID_conflict__memcpy(_Dst,*(void **)(in_ECX + 0x158),0);
    *(void **)(in_ECX + 0x158) = _Dst;
  }
  FUN_00851420();
  uVar5 = 1;
  do {
    (**(code **)(**(int **)(in_ECX + 0x120 + uVar5 * 4) + 0x198))(uVar5);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      puStack_10 = (undefined1 *)0x0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      puStack_10 = (undefined1 *)0xffffffff;
    }
    bVar9 = ((uint)DAT_00f94240 & 1 << ((char)uVar5 - 1U & 0x1f)) != 0;
    if (bVar9) {
      uVar1 = FUN_006bde40(&stack0xffffffd8);
      FUN_00436890(in_ECX + 0x164,uVar1);
    }
    (**(code **)(**(int **)(in_ECX + 0x120 + uVar5 * 4) + 0x90))(bVar9);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 10);
  puVar2 = (undefined4 *)(in_ECX + 0x148);
  iVar6 = 3;
  do {
    (**(code **)(*(int *)*puVar2 + 0x19c))();
    (**(code **)(*(int *)*puVar2 + 0x90))(0);
    puVar2 = puVar2 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  (**(code **)(**(int **)(in_ECX + 0x118) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x11c) + 200))();
  (**(code **)(**(int **)(in_ECX + 0xf4) + 0x90))
            (2 < (uint)(*(int *)(in_ECX + 0x158) - *(int *)(in_ECX + 0x154) >> 2));
  FUN_007597b0(0);
  (**(code **)(**(int **)(in_ECX + 0x10c) + 200))();
  FUN_007597b0(0);
  FUN_007597b0(1);
  (**(code **)(**(int **)(in_ECX + 0x110) + 200))();
  FUN_007597b0(0);
  (**(code **)(**(int **)(in_ECX + 0x114) + 200))();
  iVar6 = (*(int *)(DAT_00fc0c6c + 0xc) - *(int *)(DAT_00fc0c6c + 8)) / 0x34;
  if (iVar6 != 0) {
    puVar3 = *(uint **)(DAT_00fc0c6c + 8);
    puVar7 = (uint *)0x0;
    do {
      if (*puVar3 == (uint)*(ushort *)(in_ECX + 0x178)) {
        puVar7 = puVar3;
      }
      puVar3 = puVar3 + 0xd;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (puVar7 != (uint *)0x0) {
      iVar6 = (int)(puVar7[10] - puVar7[9]) / 0x24;
      piVar4 = (int *)0x0;
      if (iVar6 != 0) {
        piVar8 = (int *)puVar7[9];
        do {
          if (*piVar8 == 1) {
            piVar4 = piVar8;
          }
          piVar8 = piVar8 + 9;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        if (piVar4 != (int *)0x0) {
          FUN_00757800(piVar4 + 2);
          (**(code **)(**(int **)(in_ECX + 0x108) + 200))();
        }
      }
    }
  }
  ExceptionList = pvStack_18;
  return;
}

