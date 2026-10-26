
/* WARNING: Removing unreachable block (ram,0x007d127c) */
/* WARNING: Removing unreachable block (ram,0x007d1280) */

void FUN_007d1210(void)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  int unaff_EDI;
  undefined1 local_c [4];
  undefined4 local_8;
  
  fVar3 = (float)*(int *)(unaff_EDI + 8);
  uVar6 = *(uint *)(unaff_EDI + 0x24);
  if (*(int *)(unaff_EDI + 8) < 0) {
    fVar3 = fVar3 + 4.2949673e+09;
  }
  fVar4 = (float)(int)uVar6;
  if ((int)uVar6 < 0) {
    fVar4 = fVar4 + 4.2949673e+09;
  }
  if (*(float *)(unaff_EDI + 0x28) < fVar3 / fVar4) {
    iVar5 = 0;
    do {
      if (0x1ffffffe < uVar6) break;
      iVar5 = iVar5 + 1;
      uVar6 = uVar6 * 2;
    } while (iVar5 < 3);
    local_8 = *(undefined4 *)(unaff_EDI + 4);
    if (*(int *)(unaff_EDI + 0x10) != *(int *)(unaff_EDI + 0x14)) {
      *(int *)(unaff_EDI + 0x14) = *(int *)(unaff_EDI + 0x10);
    }
    FUN_007dcc90(*(undefined4 *)(unaff_EDI + 0x10),&local_8);
    piVar1 = *(int **)(unaff_EDI + 4);
    *(uint *)(unaff_EDI + 0x20) = uVar6 - 1;
    *(uint *)(unaff_EDI + 0x24) = uVar6;
    if ((int *)*piVar1 != piVar1) {
      iVar5 = piVar1[1];
      do {
        iVar2 = **(int **)(unaff_EDI + 4);
        FUN_007d1080(local_c,iVar2 + 8,iVar2);
      } while (iVar2 != iVar5);
    }
  }
  return;
}

