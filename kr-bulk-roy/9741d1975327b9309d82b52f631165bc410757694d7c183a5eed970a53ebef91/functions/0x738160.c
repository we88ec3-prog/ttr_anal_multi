
undefined4 FUN_00738160(float param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x130) < 1) {
    if (*(int *)(unaff_ESI + 0x11c) == 0) {
      if (*(int **)(unaff_ESI + 0x118) != (int *)0x0) {
        (**(code **)(**(int **)(unaff_ESI + 0x118) + 8))();
        *(undefined4 *)(unaff_ESI + 0x118) = 0;
      }
      *(undefined4 *)(unaff_ESI + 0x11c) = 1;
      uVar2 = FUN_007347f0(*(undefined4 *)(unaff_ESI + 0x128));
      *(undefined4 *)(unaff_ESI + 0x118) = uVar2;
      *(undefined4 *)(unaff_ESI + 0x120) = *(undefined4 *)(unaff_ESI + 0x128);
      *(undefined4 *)(unaff_ESI + 0x124) = *(undefined4 *)(unaff_ESI + 300);
    }
    if (*(int *)(unaff_ESI + 0x134) == 0) {
      if (0.1 < param_1) {
        param_1 = 0.1;
      }
      if (*(int *)(unaff_ESI + 0x14) == 1) {
        iVar4 = 0;
        if (0 < *(int *)(unaff_ESI + 0xc)) {
          pfVar5 = (float *)(unaff_ESI + 0x98);
          do {
            pfVar5[-0x20] = 1.0;
            iVar3 = *(int *)(unaff_ESI + 0xc) * iVar4;
            iVar4 = iVar4 + 1;
            *pfVar5 = (float)(int)(((-(uint)(*(int *)(unaff_ESI + 0xc) != 1) & 0xffffff81) + 0xff) -
                                  iVar3);
            pfVar5 = pfVar5 + 1;
          } while (iVar4 < *(int *)(unaff_ESI + 0xc));
        }
        *(undefined4 *)(unaff_ESI + 0x14) = 2;
      }
      if (*(int *)(unaff_ESI + 0x14) == 2) {
        iVar4 = 0;
        if (0 < *(int *)(unaff_ESI + 0xc)) {
          pfVar5 = (float *)(unaff_ESI + 0x98);
          do {
            iVar4 = iVar4 + 1;
            pfVar5[-0x20] = (float)iVar4 * 0.125 * param_1 + pfVar5[-0x20];
            fVar1 = *pfVar5 - (float)*(int *)(unaff_ESI + 0x10) * param_1;
            *pfVar5 = fVar1;
            if (fVar1 < 0.0) {
              *pfVar5 = 0.0;
            }
            pfVar5 = pfVar5 + 1;
          } while (iVar4 < *(int *)(unaff_ESI + 0xc));
        }
        if (*(float *)(unaff_ESI + 0x98) == 0.0) {
          if (*(int **)(unaff_ESI + 0x118) != (int *)0x0) {
            (**(code **)(**(int **)(unaff_ESI + 0x118) + 8))();
            *(undefined4 *)(unaff_ESI + 0x118) = 0;
          }
          *(undefined4 *)(unaff_ESI + 0x14) = 0;
        }
      }
    }
    return 0;
  }
  *(int *)(unaff_ESI + 0x130) = *(int *)(unaff_ESI + 0x130) + -1;
  DAT_00fba7dc = 1;
  return 0;
}

