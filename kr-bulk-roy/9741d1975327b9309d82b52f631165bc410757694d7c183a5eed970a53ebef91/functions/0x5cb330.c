
uint FUN_005cb330(undefined4 param_1,undefined4 param_2,short param_3)

{
  int *piVar1;
  uint uVar2;
  int in_ECX;
  
  if (param_3 == 0xd) {
    param_3 = 10;
  }
  uVar2 = 0;
  switch(param_3) {
  case 1:
  case 3:
  case 0x16:
  case 0x18:
    break;
  default:
    uVar2 = 0;
    piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x14);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x19c))();
      (**(code **)(*piVar1 + 0x194))(param_3);
      (**(code **)(*piVar1 + 0x1a0))();
      uVar2 = (**(code **)(*piVar1 + 0x1a4))();
    }
  }
  return uVar2 & 0xffffff00;
}

