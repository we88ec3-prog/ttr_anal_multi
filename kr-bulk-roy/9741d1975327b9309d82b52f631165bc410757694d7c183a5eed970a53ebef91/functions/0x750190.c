
void FUN_00750190(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != 0) {
    FUN_007503c0();
    FUN_007501e0(param_1);
    FUN_00750240();
    FUN_00750290(param_1);
    puVar1 = *(undefined4 **)(param_1 + 100);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      FUN_00750190(puVar2[2]);
    }
  }
  return;
}

