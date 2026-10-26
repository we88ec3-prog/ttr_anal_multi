
void FUN_008b94d0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  
  if ((param_1 != 0) && (piVar1 = *(int **)(param_1 + 4), 0 < *(short *)(param_1 + 2))) {
    uVar2 = 0;
    do {
      *piVar1 = *piVar1 + param_2;
      piVar1[1] = piVar1[1] + param_3;
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 2;
    } while ((int)(uVar2 & 0xffff) < (int)*(short *)(param_1 + 2));
  }
  return;
}

