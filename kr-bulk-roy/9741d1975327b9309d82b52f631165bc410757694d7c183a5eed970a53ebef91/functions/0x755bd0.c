
void FUN_00755bd0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x80) = param_1;
  puVar1 = *(undefined4 **)(in_ECX + 100);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[2] + 0xd8))(param_1);
  }
  return;
}

