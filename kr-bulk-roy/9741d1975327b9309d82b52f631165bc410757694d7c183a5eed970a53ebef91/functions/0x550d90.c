
void FUN_00550d90(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if (*(int *)(puVar2[2] + 0x24) != 0) {
      FUN_007be5f0();
    }
  }
  FUN_00550dd0(in_ECX);
  return;
}

