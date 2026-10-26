
void FUN_0073dfa0(int param_1,int param_2,uint *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int *in_EDX;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  int local_8;
  
  iVar4 = param_4[1];
  local_8 = param_4[2] - *param_4;
  if (in_EDX[2] - *in_EDX <= param_4[2] - *param_4) {
    local_8 = in_EDX[2] - *in_EDX;
  }
  iVar1 = param_4[3] - iVar4;
  if (in_EDX[3] - in_EDX[1] <= param_4[3] - iVar4) {
    iVar1 = in_EDX[3] - in_EDX[1];
  }
  piVar5 = *(int **)(param_1 + 0x44);
  if (iVar4 < iVar1 + iVar4) {
    param_1 = (iVar1 + iVar4) - iVar4;
    do {
      iVar4 = *param_4;
      if (iVar4 < local_8 + iVar4) {
        iVar4 = (local_8 + iVar4) - iVar4;
        piVar2 = piVar5;
        puVar3 = param_3;
        do {
          *puVar3 = *piVar2 << 8 | 0xffffff;
          piVar2 = piVar2 + 1;
          puVar3 = puVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      param_3 = (uint *)((int)param_3 + param_2);
      piVar5 = piVar5 + 0x800;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}

