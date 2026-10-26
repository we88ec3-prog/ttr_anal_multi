
void FUN_008ba140(int *param_1,code *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 4);
    if (param_2 != (code *)0x0) {
      (*param_2)(param_3,*(undefined4 *)(iVar2 + 8),param_4);
    }
    FUN_008b9f80(param_3,iVar2);
    iVar2 = iVar1;
  }
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

