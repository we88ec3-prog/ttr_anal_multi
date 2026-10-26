
undefined4 FUN_006eb8b0(void)

{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  int iVar3;
  
  iVar3 = unaff_ESI[4] + -1;
  if (-1 < iVar3) {
    iVar2 = iVar3 * 0x218;
    do {
      piVar1 = *(int **)(iVar2 + 0x214 + unaff_ESI[3]);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *(undefined4 *)(iVar2 + 0x214 + unaff_ESI[3]) = 0;
      }
      if ((-1 < iVar3) && (iVar3 < unaff_ESI[4])) {
        FID_conflict__memcpy
                  ((void *)(unaff_ESI[3] + iVar2),(void *)(unaff_ESI[3] + iVar2 + 0x218),
                   (unaff_ESI[4] - iVar3) * 0x218 - 0x218);
        unaff_ESI[4] = unaff_ESI[4] + -1;
      }
      iVar2 = iVar2 + -0x218;
      iVar3 = iVar3 + -1;
    } while (-1 < iVar3);
  }
  iVar3 = unaff_ESI[7] + -1;
  if (-1 < iVar3) {
    iVar2 = iVar3 * 0x5c;
    do {
      piVar1 = *(int **)(unaff_ESI[6] + 0x58 + iVar2);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *(undefined4 *)(unaff_ESI[6] + 0x58 + iVar2) = 0;
      }
      if ((-1 < iVar3) && (iVar3 < unaff_ESI[7])) {
        FID_conflict__memcpy
                  ((void *)(unaff_ESI[6] + iVar2),(void *)(unaff_ESI[6] + iVar2 + 0x5c),
                   (unaff_ESI[7] - iVar3) * 0x5c - 0x5c);
        unaff_ESI[7] = unaff_ESI[7] + -1;
      }
      iVar2 = iVar2 + -0x5c;
      iVar3 = iVar3 + -1;
    } while (-1 < iVar3);
  }
  iVar3 = unaff_ESI[1] + -1;
  if (-1 < iVar3) {
    iVar2 = iVar3 * 0x234;
    do {
      piVar1 = *(int **)(iVar2 + 0x230 + *unaff_ESI);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *(undefined4 *)(iVar2 + 0x230 + *unaff_ESI) = 0;
      }
      if ((-1 < iVar3) && (iVar3 < unaff_ESI[1])) {
        FID_conflict__memcpy
                  ((void *)(*unaff_ESI + iVar2),(void *)(*unaff_ESI + iVar2 + 0x234),
                   (unaff_ESI[1] - iVar3) * 0x234 - 0x234);
        unaff_ESI[1] = unaff_ESI[1] + -1;
      }
      iVar2 = iVar2 + -0x234;
      iVar3 = iVar3 + -1;
    } while (-1 < iVar3);
  }
  return 0;
}

