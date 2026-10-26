
void FUN_0082d6e0(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  float fVar4;
  int *piVar5;
  float local_8;
  
  local_8 = 9999999.0;
  piVar1 = (int *)*param_1;
  piVar2 = (int *)*piVar1;
  piVar5 = piVar2;
  for (; piVar2 != piVar1; piVar2 = (int *)*piVar2) {
    iVar3 = piVar2[2];
    fVar4 = *(float *)(iVar3 + 0xc) + *(float *)(iVar3 + 8);
    if (fVar4 < local_8) {
      *param_2 = iVar3;
      piVar5 = piVar2;
      local_8 = fVar4;
    }
  }
  if (piVar5 != (int *)*param_1) {
    *(int *)piVar5[1] = *piVar5;
    *(int *)(*piVar5 + 4) = piVar5[1];
    FUN_0089120c(piVar5);
    param_1[1] = param_1[1] + -1;
  }
  return;
}

