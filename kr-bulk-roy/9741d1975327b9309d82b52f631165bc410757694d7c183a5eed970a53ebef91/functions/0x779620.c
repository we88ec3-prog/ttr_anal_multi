
void FUN_00779620(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  int *piVar6;
  int local_c;
  
  iVar4 = param_1;
  *(undefined4 *)(unaff_ESI + 4) = *(undefined4 *)(param_1 + 4);
  iVar5 = param_1 - unaff_ESI;
  *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(param_1 + 8);
  piVar6 = (int *)(unaff_ESI + 0x10);
  local_c = 3;
  param_1 = param_1 + 0x30;
  do {
    iVar2 = *(int *)(iVar5 + (int)piVar6);
    if (*piVar6 != iVar2) {
      if (((iVar2 != 0) && (piVar3 = *(int **)(iVar2 + 8), piVar3 != (int *)0x0)) &&
         (piVar3[0x27] = piVar3[0x27] + 1, piVar3[0x27] == 1)) {
        (**(code **)(*piVar3 + 0x24))();
      }
      if ((*piVar6 != 0) && (piVar3 = *(int **)(*piVar6 + 8), piVar3 != (int *)0x0)) {
        piVar1 = piVar3 + 0x27;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar3 + 0x28))();
        }
      }
      *piVar6 = iVar2;
    }
    FUN_004026e0(param_1 + -0x1c,0,0xffffffff);
    FUN_004026e0(param_1,0,0xffffffff);
    param_1 = param_1 + 0x40;
    piVar6 = piVar6 + 0x10;
    local_c = local_c + -1;
  } while (local_c != 0);
  *(undefined4 *)(unaff_ESI + 0xcc) = *(undefined4 *)(iVar4 + 0xcc);
  *(undefined4 *)(unaff_ESI + 0xd0) = *(undefined4 *)(iVar4 + 0xd0);
  *(undefined4 *)(unaff_ESI + 0xd4) = *(undefined4 *)(iVar4 + 0xd4);
  *(undefined4 *)(unaff_ESI + 0xd8) = *(undefined4 *)(iVar4 + 0xd8);
  *(undefined4 *)(unaff_ESI + 0xdc) = *(undefined4 *)(iVar4 + 0xdc);
  *(undefined4 *)(unaff_ESI + 0xe0) = *(undefined4 *)(iVar4 + 0xe0);
  *(undefined4 *)(unaff_ESI + 0xe4) = *(undefined4 *)(iVar4 + 0xe4);
  *(undefined4 *)(unaff_ESI + 0xe8) = *(undefined4 *)(iVar4 + 0xe8);
  *(undefined4 *)(unaff_ESI + 0xec) = *(undefined4 *)(iVar4 + 0xec);
  *(undefined4 *)(unaff_ESI + 0xf0) = *(undefined4 *)(iVar4 + 0xf0);
  *(undefined4 *)(unaff_ESI + 0xf4) = *(undefined4 *)(iVar4 + 0xf4);
  *(undefined4 *)(unaff_ESI + 0xf8) = *(undefined4 *)(iVar4 + 0xf8);
  *(undefined4 *)(unaff_ESI + 0xfc) = *(undefined4 *)(iVar4 + 0xfc);
  *(undefined4 *)(unaff_ESI + 0x100) = *(undefined4 *)(iVar4 + 0x100);
  *(undefined4 *)(unaff_ESI + 0x104) = *(undefined4 *)(iVar4 + 0x104);
  *(undefined4 *)(unaff_ESI + 0x108) = *(undefined4 *)(iVar4 + 0x108);
  *(undefined1 *)(unaff_ESI + 0x10c) = *(undefined1 *)(iVar4 + 0x10c);
  *(undefined4 *)(unaff_ESI + 0x110) = *(undefined4 *)(iVar4 + 0x110);
  return;
}

