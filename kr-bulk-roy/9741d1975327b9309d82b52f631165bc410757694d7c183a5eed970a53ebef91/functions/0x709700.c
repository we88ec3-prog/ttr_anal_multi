
void FUN_00709700(int param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  iVar3 = *(int *)(param_1 + 8);
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  local_18[0] = FUN_006fec70(param_1,param_2,(int)pcVar2 - (int)(param_2 + 1));
  local_10 = 4;
  FUN_006fb850(param_1,iVar3 + -0x10,local_18,*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  iVar3 = *(int *)(*(int *)(param_1 + 8) + -8);
  if ((iVar3 == 3) || ((iVar3 == 4 && (iVar3 = FUN_006f7760(), iVar3 != 0)))) {
    FUN_006f5370();
  }
  else if (param_3 < 0) {
    FUN_006f5f30(param_1,"field \'%s\' missing in date table",param_2);
    return;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  return;
}

