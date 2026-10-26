
void FUN_008cfc00(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = 0;
  do {
    if (in_ECX == (&DAT_00be7760)[uVar1]) {
      *(undefined4 *)(param_1 + uVar1 * 4) = 2;
      return;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 10);
  return;
}

