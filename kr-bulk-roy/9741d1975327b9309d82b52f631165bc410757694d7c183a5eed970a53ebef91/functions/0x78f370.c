
void FUN_0078f370(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_2c;
  
  iVar1 = param_1;
  if (param_1 != param_2) {
    while (iVar2 = iVar1 + 0x3c, iVar2 != param_2) {
      FUN_007866a0();
      if (local_2c < *(int *)(param_1 + 0x14)) {
        FUN_007908f0(param_1,param_1);
        FUN_00789f20();
        iVar1 = iVar2;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x14);
        iVar3 = iVar2;
        while (local_2c < iVar1) {
          FUN_00789f20();
          iVar1 = *(int *)(iVar3 + -100);
          iVar3 = iVar3 + -0x3c;
        }
        FUN_00789f20();
        iVar1 = iVar2;
      }
    }
  }
  return;
}

