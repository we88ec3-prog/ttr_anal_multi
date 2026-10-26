
void FUN_007b3190(int *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  uVar2 = param_1[1] - *param_1 >> 2;
  if (uVar2 != 0) {
    do {
      (**(code **)(**(int **)(*param_1 + uVar1 * 4) + 0x10))();
      uVar1 = uVar1 + 1;
    } while (uVar1 < uVar2);
  }
  return;
}

