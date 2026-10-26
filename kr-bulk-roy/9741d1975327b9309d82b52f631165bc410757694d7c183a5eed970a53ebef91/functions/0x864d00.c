
void FUN_00864d00(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x14);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(in_ECX + 0x14) = 0;
  }
  if (*(int *)(param_1 + 0x40) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00857160(*(int *)(param_1 + 0x40));
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar2;
  FUN_008629e0(*(undefined4 *)(in_ECX + 4),(undefined4 *)(in_ECX + 0x14),
               (undefined4 *)(in_ECX + 0x10));
  return;
}

