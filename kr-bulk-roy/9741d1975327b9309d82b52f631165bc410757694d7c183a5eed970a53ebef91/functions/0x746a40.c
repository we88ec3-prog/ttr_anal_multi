
int FUN_00746a40(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  iVar1 = param_3;
  param_3 = param_2;
  FUN_0082ef00(&param_3);
  if (local_8 == param_1[0x14]) {
    *(int **)(iVar1 + 0x44) = param_1;
    *(undefined4 *)(iVar1 + 0x48) = param_2;
    uVar2 = FUN_0057ef20();
    FUN_0082f200(param_1 + 0x13,uVar2);
    (**(code **)(*param_1 + 0x70))(iVar1);
    return iVar1;
  }
  return 0;
}

