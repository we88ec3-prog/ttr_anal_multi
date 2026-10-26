
int FUN_0040acb0(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  
  FUN_0082ef00(&param_2);
  if (local_10 == param_1[0x2f]) {
    if ((*(uint *)(param_3 + 0x28) & 0x100) != 0) {
      *(uint *)(param_3 + 0x28) = *(uint *)(param_3 + 0x28) ^ 0x100;
    }
    if (*(int *)(param_3 + 0x80) != 0) {
      *(undefined1 *)(*(int *)(param_3 + 0x80) + 200) = 1;
    }
    uVar1 = FUN_0057ef20();
    FUN_0082f200(param_1 + 0x2e,uVar1);
    iVar2 = (**(code **)(*(int *)param_1[0x29] + 0x28))();
    *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) | 0x100;
    *(undefined4 *)(iVar2 + 0x20) = param_2;
    FUN_00757710();
    uVar1 = FUN_0057ef20();
    FUN_0082f200(param_1 + 0x2a,uVar1);
    (**(code **)(*param_1 + 0x70))(iVar2);
    return param_3;
  }
  return 0;
}

