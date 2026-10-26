
void FUN_00501ca0(void)

{
  undefined4 *puVar1;
  int extraout_ECX;
  
  FUN_00553b60();
  if ((*(int *)(extraout_ECX + 0x34) == 4) && (*(int *)(extraout_ECX + 0x2c) < 1)) {
    puVar1 = (undefined4 *)(extraout_ECX + 0x88);
    *(undefined4 *)(extraout_ECX + 0x98) = 0;
    if (7 < *(uint *)(extraout_ECX + 0x9c)) {
      puVar1 = (undefined4 *)*puVar1;
    }
    *(undefined2 *)puVar1 = 0;
    puVar1 = (undefined4 *)(extraout_ECX + 0xa4);
    *(undefined4 *)(extraout_ECX + 0xb4) = 0;
    if (7 < *(uint *)(extraout_ECX + 0xb8)) {
      puVar1 = (undefined4 *)*puVar1;
    }
    *(undefined2 *)puVar1 = 0;
  }
  return;
}

