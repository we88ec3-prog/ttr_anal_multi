
void FUN_00703fd0(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  double *pdVar5;
  int in_EAX;
  undefined4 uVar6;
  int *in_ECX;
  int iVar7;
  
  if (in_EAX < in_ECX[3]) {
    param_2 = in_ECX[in_EAX * 2 + 5];
    if (param_2 == -1) {
      FUN_006f5f30(in_ECX[2],"unfinished capture");
    }
    else if (param_2 == -2) {
      iVar7 = in_ECX[in_EAX * 2 + 4];
      iVar3 = *in_ECX;
      iVar4 = in_ECX[2];
      pdVar5 = *(double **)(iVar4 + 8);
      *(undefined4 *)(pdVar5 + 1) = 3;
      *pdVar5 = (double)((iVar7 - iVar3) + 1);
      piVar1 = (int *)(iVar4 + 8);
      *piVar1 = *piVar1 + 0x10;
      return;
    }
    param_1 = in_ECX[in_EAX * 2 + 4];
    iVar7 = in_ECX[2];
    if (*(uint *)(*(int *)(iVar7 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar7 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
  }
  else {
    if (in_EAX != 0) {
      FUN_006f5f30(in_ECX[2],"invalid capture index");
      return;
    }
    iVar7 = in_ECX[2];
    if (*(uint *)(*(int *)(iVar7 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar7 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    param_2 = param_2 - param_1;
  }
  puVar2 = *(undefined4 **)(iVar7 + 8);
  uVar6 = FUN_006fec70(iVar7,param_1,param_2);
  *puVar2 = uVar6;
  puVar2[2] = 4;
  *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + 0x10;
  return;
}

