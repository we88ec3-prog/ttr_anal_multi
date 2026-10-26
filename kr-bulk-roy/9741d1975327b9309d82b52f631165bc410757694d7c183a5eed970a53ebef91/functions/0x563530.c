
void FUN_00563530(float param_1,float param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  float fVar4;
  int local_8;
  
  FUN_0082ef00(&param_1);
  if ((local_8 != *(int *)(in_ECX + 0x1c)) && (iVar1 = *(int *)(local_8 + 0x10), iVar1 != 0)) {
    if (DAT_00fba7cc == 0) {
      iVar2 = FUN_00891268(0x1380);
      if (iVar2 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    fVar4 = 0.0;
    param_2 = (float)(int)param_2 / (float)*(int *)(DAT_00fba7cc + 0x1360);
    iVar2 = *(int *)(iVar1 + 0x15c);
    if ((iVar2 == 0) || (*(int *)(iVar1 + 0x370) == 0)) {
      param_1 = 0.0;
    }
    else {
      param_1 = *(float *)(iVar2 + 0xb4);
    }
    param_1 = param_1 + param_2;
    if (((iVar2 != 0) && (*(int *)(iVar1 + 0x370) != 0)) && (*(int *)(iVar2 + 0xac) != 0)) {
      fVar3 = (float10)(**(code **)(**(int **)(iVar2 + 0xac) + 0xc))();
      fVar4 = (float)fVar3;
    }
    param_2 = fVar4;
    if ((*(int *)(iVar1 + 0x15c) != 0) && (*(int *)(iVar1 + 0x370) != 0)) {
      FUN_007a6830(param_1);
    }
    if (((param_2 <= param_1) && (*(int *)(iVar1 + 0x15c) != 0)) && (*(int *)(iVar1 + 0x370) != 0))
    {
      FUN_007a6830(param_2);
      return;
    }
  }
  return;
}

