
void FUN_005f5ac0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0xd0);
  piVar1[0x31] = (piVar1[0x31] / 0x30) * 0x30;
  (**(code **)(*piVar1 + 0x128))();
  (**(code **)(*piVar1 + 200))();
  FUN_00471530();
  return;
}

