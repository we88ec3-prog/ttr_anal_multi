
void FUN_007461a0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if ((char)param_1 == '\0') {
    if ((*(uint *)(in_ECX + 0x28) & 0x100000) != 0) {
      *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) ^ 0x100000;
    }
  }
  else {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) | 0x100000;
  }
  puVar1 = *(undefined4 **)(in_ECX + 100);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    FUN_007461a0(param_1);
  }
  return;
}

