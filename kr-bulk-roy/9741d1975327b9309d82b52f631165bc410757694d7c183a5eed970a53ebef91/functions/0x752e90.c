
void FUN_00752e90(void)

{
  float fVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  float fVar6;
  int unaff_ESI;
  undefined4 local_10;
  
  fVar1 = *(float *)(unaff_ESI + 0x139c) * *(float *)(unaff_ESI + 0x138c);
  *(float *)(unaff_ESI + 0x13ac) = fVar1;
  fVar6 = *(float *)(unaff_ESI + 0x13a0) * *(float *)(unaff_ESI + 0x1390);
  *(float *)(unaff_ESI + 0x13b0) = fVar6;
  *(float *)(unaff_ESI + 0x13a4) = 1.0 / *(float *)(unaff_ESI + 0x139c);
  *(float *)(unaff_ESI + 0x13a8) = 1.0 / *(float *)(unaff_ESI + 0x13a0);
  *(float *)(unaff_ESI + 0x1394) = 1.0 / *(float *)(unaff_ESI + 0x138c);
  *(float *)(unaff_ESI + 0x1398) = 1.0 / *(float *)(unaff_ESI + 0x1390);
  *(float *)(unaff_ESI + 0x13b4) = 1.0 / fVar1;
  *(float *)(unaff_ESI + 0x13b8) = 1.0 / fVar6;
  if (*(int *)(unaff_ESI + 0x1c) != 0) {
    piVar3 = *(int **)(unaff_ESI + 0xc);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      *(undefined4 *)(unaff_ESI + 0xc) = 0;
    }
    piVar4 = *(int **)(unaff_ESI + 8);
    piVar3 = (int *)(unaff_ESI + 8);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 8))(piVar4);
      *piVar3 = 0;
    }
    local_10 = (undefined4)
               (longlong)ROUND((float)*(int *)(unaff_ESI + 0xa4) * *(float *)(unaff_ESI + 0x13a8));
    uVar2 = local_10;
    local_10 = (undefined4)
               (longlong)ROUND((float)*(int *)(unaff_ESI + 0xa0) * *(float *)(unaff_ESI + 0x13a4));
    (**(code **)(**(int **)(unaff_ESI + 0x1c) + 0x5c))
              (*(int **)(unaff_ESI + 0x1c),local_10,uVar2,1,1,0x15,0,piVar3,0);
    piVar3 = (int *)*piVar3;
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x48))(piVar3,0,(undefined4 *)(unaff_ESI + 0xc));
    }
  }
  iVar5 = *(int *)(unaff_ESI + 0x165b4);
  if (iVar5 == 0) {
    return;
  }
  fVar1 = *(float *)(unaff_ESI + 0x13ac);
  uVar2 = *(undefined4 *)(unaff_ESI + 0x13b0);
  *(float *)(iVar5 + 4) = fVar1;
  *(undefined4 *)(iVar5 + 8) = uVar2;
  fVar1 = 1.0 / fVar1;
  *(float *)(iVar5 + 0xc) = fVar1;
  *(float *)(iVar5 + 0x10) = fVar1;
  return;
}

