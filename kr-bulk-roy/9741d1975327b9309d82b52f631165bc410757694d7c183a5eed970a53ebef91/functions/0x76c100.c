
void FUN_0076c100(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  FUN_00744a40(param_1);
  puVar1 = *(undefined4 **)(in_ECX + 0xac);
  for (puVar2 = *(undefined4 **)(in_ECX + 0xa8); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*(int *)*puVar2 + 0xc0))(param_1);
  }
  return;
}

