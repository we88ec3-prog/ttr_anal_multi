
void FUN_007780c0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int unaff_ESI;
  int unaff_EDI;
  int local_10;
  int local_8;
  
  *(undefined4 *)(unaff_ESI + 4) = *(undefined4 *)(unaff_EDI + 4);
  local_8 = unaff_EDI + 0x30;
  *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(unaff_EDI + 8);
  piVar4 = (int *)(unaff_ESI + 0x10);
  local_10 = 9;
  do {
    iVar2 = *(int *)((unaff_EDI - unaff_ESI) + (int)piVar4);
    if (*piVar4 != iVar2) {
      if (((iVar2 != 0) && (piVar3 = *(int **)(iVar2 + 8), piVar3 != (int *)0x0)) &&
         (piVar3[0x27] = piVar3[0x27] + 1, piVar3[0x27] == 1)) {
        (**(code **)(*piVar3 + 0x24))();
      }
      if ((*piVar4 != 0) && (piVar3 = *(int **)(*piVar4 + 8), piVar3 != (int *)0x0)) {
        piVar1 = piVar3 + 0x27;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar3 + 0x28))();
        }
      }
      *piVar4 = iVar2;
    }
    FUN_004026e0(local_8 + -0x1c,0,0xffffffff);
    FUN_004026e0(local_8,0,0xffffffff);
    local_8 = local_8 + 0x40;
    piVar4 = piVar4 + 0x10;
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  *(undefined4 *)(unaff_ESI + 0x24c) = *(undefined4 *)(unaff_EDI + 0x24c);
  *(undefined4 *)(unaff_ESI + 0x250) = *(undefined4 *)(unaff_EDI + 0x250);
  *(undefined4 *)(unaff_ESI + 0x254) = *(undefined4 *)(unaff_EDI + 0x254);
  *(undefined4 *)(unaff_ESI + 600) = *(undefined4 *)(unaff_EDI + 600);
  *(undefined4 *)(unaff_ESI + 0x25c) = *(undefined4 *)(unaff_EDI + 0x25c);
  *(undefined4 *)(unaff_ESI + 0x260) = *(undefined4 *)(unaff_EDI + 0x260);
  *(undefined4 *)(unaff_ESI + 0x264) = *(undefined4 *)(unaff_EDI + 0x264);
  *(undefined4 *)(unaff_ESI + 0x268) = *(undefined4 *)(unaff_EDI + 0x268);
  *(undefined4 *)(unaff_ESI + 0x26c) = *(undefined4 *)(unaff_EDI + 0x26c);
  *(undefined4 *)(unaff_ESI + 0x270) = *(undefined4 *)(unaff_EDI + 0x270);
  *(undefined4 *)(unaff_ESI + 0x274) = *(undefined4 *)(unaff_EDI + 0x274);
  *(undefined4 *)(unaff_ESI + 0x278) = *(undefined4 *)(unaff_EDI + 0x278);
  *(undefined4 *)(unaff_ESI + 0x27c) = *(undefined4 *)(unaff_EDI + 0x27c);
  *(undefined4 *)(unaff_ESI + 0x280) = *(undefined4 *)(unaff_EDI + 0x280);
  *(undefined4 *)(unaff_ESI + 0x284) = *(undefined4 *)(unaff_EDI + 0x284);
  *(undefined4 *)(unaff_ESI + 0x288) = *(undefined4 *)(unaff_EDI + 0x288);
  *(undefined4 *)(unaff_ESI + 0x28c) = *(undefined4 *)(unaff_EDI + 0x28c);
  *(undefined4 *)(unaff_ESI + 0x290) = *(undefined4 *)(unaff_EDI + 0x290);
  *(undefined4 *)(unaff_ESI + 0x294) = *(undefined4 *)(unaff_EDI + 0x294);
  *(undefined4 *)(unaff_ESI + 0x298) = *(undefined4 *)(unaff_EDI + 0x298);
  *(undefined4 *)(unaff_ESI + 0x29c) = *(undefined4 *)(unaff_EDI + 0x29c);
  *(undefined4 *)(unaff_ESI + 0x2a0) = *(undefined4 *)(unaff_EDI + 0x2a0);
  *(undefined4 *)(unaff_ESI + 0x2a4) = *(undefined4 *)(unaff_EDI + 0x2a4);
  *(undefined4 *)(unaff_ESI + 0x2a8) = *(undefined4 *)(unaff_EDI + 0x2a8);
  *(undefined4 *)(unaff_ESI + 0x2ac) = *(undefined4 *)(unaff_EDI + 0x2ac);
  *(undefined4 *)(unaff_ESI + 0x2b0) = *(undefined4 *)(unaff_EDI + 0x2b0);
  *(undefined4 *)(unaff_ESI + 0x2b4) = *(undefined4 *)(unaff_EDI + 0x2b4);
  *(undefined4 *)(unaff_ESI + 0x2b8) = *(undefined4 *)(unaff_EDI + 0x2b8);
  *(undefined4 *)(unaff_ESI + 700) = *(undefined4 *)(unaff_EDI + 700);
  *(undefined4 *)(unaff_ESI + 0x2c0) = *(undefined4 *)(unaff_EDI + 0x2c0);
  *(undefined4 *)(unaff_ESI + 0x2c4) = *(undefined4 *)(unaff_EDI + 0x2c4);
  *(undefined4 *)(unaff_ESI + 0x2c8) = *(undefined4 *)(unaff_EDI + 0x2c8);
  *(undefined4 *)(unaff_ESI + 0x2cc) = *(undefined4 *)(unaff_EDI + 0x2cc);
  *(undefined4 *)(unaff_ESI + 0x2d0) = *(undefined4 *)(unaff_EDI + 0x2d0);
  *(undefined4 *)(unaff_ESI + 0x2d4) = *(undefined4 *)(unaff_EDI + 0x2d4);
  *(undefined4 *)(unaff_ESI + 0x2d8) = *(undefined4 *)(unaff_EDI + 0x2d8);
  *(undefined4 *)(unaff_ESI + 0x2dc) = *(undefined4 *)(unaff_EDI + 0x2dc);
  *(undefined4 *)(unaff_ESI + 0x2e0) = *(undefined4 *)(unaff_EDI + 0x2e0);
  *(undefined4 *)(unaff_ESI + 0x2e4) = *(undefined4 *)(unaff_EDI + 0x2e4);
  *(undefined4 *)(unaff_ESI + 0x2e8) = *(undefined4 *)(unaff_EDI + 0x2e8);
  *(undefined1 *)(unaff_ESI + 0x2ec) = *(undefined1 *)(unaff_EDI + 0x2ec);
  *(undefined4 *)(unaff_ESI + 0x2f0) = *(undefined4 *)(unaff_EDI + 0x2f0);
  return;
}

