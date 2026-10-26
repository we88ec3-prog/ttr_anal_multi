
void FUN_0083de80(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,int *param_4,
                 int param_5,double param_6)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = (**(code **)(*param_4 + 4))();
  if (*(int *)(iVar2 + 4) == -0x5ece0000) {
    iVar2 = (**(code **)(*in_EAX + 0xf0))(param_4);
  }
  else {
    iVar2 = (**(code **)(*param_4 + 4))();
    if (*(int *)(iVar2 + 4) == -0x5ecc0000) {
      iVar2 = (**(code **)(*in_EAX + 0xec))(param_4);
    }
    else {
      iVar2 = 0;
    }
  }
  if ((param_6 == 0.0) && ((iVar2 == 2 || (param_6 = 0.0, iVar2 == 1)))) {
    param_6 = -((double)(float)in_EAX[0x2e] * (double)(float)param_3[0xb] +
                (double)(float)in_EAX[0x2b] * (double)(float)param_3[10] +
                (double)(float)in_EAX[0x28] * (double)(float)param_3[9] +
               (double)(float)in_EAX[0x31]);
  }
  *param_1 = param_2;
  puVar4 = param_1;
  for (iVar3 = 0xd; puVar4 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_3;
    param_3 = param_3 + 1;
  }
  *(double *)(param_1 + 0x10) = param_6;
  param_1[0xf] = param_4;
  param_1[0x12] = iVar2;
  piVar1 = *(int **)(param_5 + 0x1c);
  param_1[0x16] = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  param_1[0x18] = *(undefined4 *)(param_5 + 0xc);
  param_1[0x19] = *(undefined4 *)(param_5 + 8);
  param_1[0x1a] = *(undefined4 *)(param_5 + 0x20);
  param_1[0x17] = *(undefined4 *)(param_5 + 0x10);
  return;
}

