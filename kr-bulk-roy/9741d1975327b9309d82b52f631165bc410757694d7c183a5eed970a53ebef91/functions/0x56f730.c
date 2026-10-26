
void FUN_0056f730(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  float *unaff_EDI;
  
  iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x1c) + 0x18))();
  fVar1 = *(float *)(unaff_ESI + 100);
  iVar4 = (**(code **)(**(int **)(unaff_ESI + 0x1c) + 0x18))();
  fVar2 = *(float *)(unaff_ESI + 100);
  iVar5 = (**(code **)(**(int **)(unaff_ESI + 0x1c) + 0x18))();
  *unaff_EDI = (float)param_1 / ((float)iVar3 / fVar1);
  unaff_EDI[1] = (float)(iVar5 - param_2) / ((float)iVar4 / fVar2);
  return;
}

