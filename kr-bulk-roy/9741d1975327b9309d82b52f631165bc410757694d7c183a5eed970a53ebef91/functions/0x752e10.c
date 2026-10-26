
void FUN_00752e10(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int in_EAX;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(in_EAX + 0x139c) = param_1;
  *(undefined4 *)(in_EAX + 0x13a0) = param_2;
  FUN_00752e90();
  piVar1 = *(int **)(in_EAX + 0x13c4);
  if (piVar1 != (int *)0x0) {
    uVar2 = FUN_008fed10();
    uVar3 = FUN_008fed10();
    (**(code **)(*piVar1 + 0xbc))(0,0,uVar2,uVar3);
  }
  return;
}

