
void FUN_00746450(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if ((char)param_2 == '\0') {
    if ((param_1 & *(uint *)(in_ECX + 0x28)) != 0) {
      *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) ^ param_1;
    }
  }
  else {
    *(uint *)(in_ECX + 0x28) = *(uint *)(in_ECX + 0x28) | param_1;
  }
  puVar1 = *(undefined4 **)(in_ECX + 100);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if (((char)param_3 == '\0') || ((*(byte *)(puVar2[2] + 0x28) & 0x30) == 0)) {
      FUN_00746450(param_1,param_2,param_3);
    }
  }
  return;
}

