
void FUN_00760f80(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  FUN_00746ed0(param_1);
  puVar1 = *(undefined4 **)(in_ECX + 100);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[2] + 0xc0))(param_1);
  }
  return;
}

