
undefined4 FUN_006eb7d0(void)

{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  int iVar3;
  
  iVar3 = 0;
  if (0 < unaff_ESI[4]) {
    iVar2 = 0;
    do {
      piVar1 = *(int **)(iVar2 + 0x214 + unaff_ESI[3]);
      (**(code **)(*piVar1 + 0x114))(piVar1);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x218;
    } while (iVar3 < unaff_ESI[4]);
  }
  iVar3 = 0;
  if (0 < unaff_ESI[7]) {
    iVar2 = 0;
    do {
      piVar1 = *(int **)(unaff_ESI[6] + 0x58 + iVar2);
      (**(code **)(*piVar1 + 0x40))(piVar1);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x5c;
    } while (iVar3 < unaff_ESI[7]);
  }
  iVar3 = unaff_ESI[1] + -1;
  if (-1 < iVar3) {
    iVar2 = iVar3 * 0x234;
    do {
      if (*(int *)(*unaff_ESI + 0x228 + iVar2) == 0) {
        piVar1 = *(int **)(*unaff_ESI + 0x230 + iVar2);
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
      }
      iVar2 = iVar2 + -0x234;
      iVar3 = iVar3 + -1;
    } while (-1 < iVar3);
  }
  return 0;
}

