
void FUN_007486f0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x24) = param_1;
  if ((*(int *)(in_ECX + 0x3c) != 0) && ((*(uint *)(in_ECX + 0x28) & 0x40000) == 0)) {
    FUN_007486f0(param_1);
  }
  puVar1 = *(undefined4 **)(in_ECX + 100);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    FUN_007486f0(*(undefined4 *)(in_ECX + 0x24));
  }
  return;
}

