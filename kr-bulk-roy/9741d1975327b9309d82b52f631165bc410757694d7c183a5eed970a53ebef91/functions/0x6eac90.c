
undefined4 FUN_006eac90(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *in_ECX;
  int *piVar3;
  
  iVar1 = in_ECX[1];
  if (((0 < iVar1) && (0 < iVar1)) && (-1 < iVar1)) {
    piVar3 = (int *)*in_ECX;
    iVar2 = 0;
    do {
      if (*param_1 == *piVar3) goto LAB_006eacbf;
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < iVar1);
  }
  iVar2 = -1;
LAB_006eacbf:
  return CONCAT31((int3)((uint)iVar2 >> 8),iVar2 != -1);
}

