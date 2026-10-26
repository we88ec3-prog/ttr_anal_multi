
void FUN_005e9d20(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_8;
  
  local_8 = 0;
  do {
    piVar1 = *(int **)(param_1 + local_8 * 4);
    if ((piVar1 != (int *)0x0) && (((uint)piVar1[10] >> 0xf & 1) != 0)) {
      (**(code **)(*piVar1 + 0x120))();
      puVar2 = (undefined4 *)piVar1[0x19];
      for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
        FUN_00746b80();
      }
      if ((piVar1[10] & 0x8000U) != 0) {
        piVar1[10] = piVar1[10] ^ 0x8000;
      }
    }
    local_8 = local_8 + 1;
  } while (local_8 < 9);
  piVar1 = *(int **)(param_1 + 0x5c);
  if ((piVar1 != (int *)0x0) && (((uint)piVar1[10] >> 0xf & 1) != 0)) {
    (**(code **)(*piVar1 + 0x120))();
    puVar2 = (undefined4 *)piVar1[0x19];
    for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
      FUN_00746b80();
    }
    if ((piVar1[10] & 0x8000U) != 0) {
      piVar1[10] = piVar1[10] ^ 0x8000;
    }
  }
  return;
}

