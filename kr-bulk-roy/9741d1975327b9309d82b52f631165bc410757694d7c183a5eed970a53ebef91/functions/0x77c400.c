
void FUN_0077c400(int *param_1,float param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((*(float *)(in_ECX + 0x44) < param_2) && (param_3 != '\0')) {
    FUN_008ff2e0((double)(param_2 / *(float *)(in_ECX + 0x44)));
  }
  iVar6 = *(int *)(in_ECX + 0x30) - *(int *)(in_ECX + 0x28);
  iVar5 = *(int *)(in_ECX + 0x34) - *(int *)(in_ECX + 0x2c);
  iVar3 = 0;
  if (0 < *(int *)(in_ECX + 0x40)) {
    FUN_0043c810();
    iVar3 = FUN_008fed10();
  }
  iVar1 = *(int *)(in_ECX + 0x38);
  iVar4 = (iVar3 % iVar1) * iVar6 + *(int *)(in_ECX + 0x28);
  iVar2 = *(int *)(in_ECX + 0x3c);
  *param_1 = iVar4;
  param_1[2] = iVar4 + iVar6;
  iVar3 = ((iVar3 / iVar1) % iVar2) * iVar5 + *(int *)(in_ECX + 0x2c);
  param_1[1] = iVar3;
  param_1[3] = iVar3 + iVar5;
  return;
}

