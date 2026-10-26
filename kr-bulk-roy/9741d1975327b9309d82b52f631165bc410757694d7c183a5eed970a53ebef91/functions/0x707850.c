
void FUN_00707850(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = __errno();
  uVar2 = FUN_00898466(*piVar1);
  FUN_006f5580(param_1,"%s: %s",param_2,uVar2);
  if (*(int *)(*(int *)(param_1 + 8) + -8) != 4) {
    iVar3 = FUN_006fb5d0();
    if (iVar3 == 0) {
      FUN_006f5da0(1);
      return;
    }
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
  }
  FUN_006f5da0(1);
  return;
}

