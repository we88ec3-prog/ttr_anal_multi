
void FUN_00745bd0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  if (((uint)in_ECX[10] >> 0xe & 1) != 0) {
    (**(code **)(*in_ECX + 0x134))(param_1,param_2);
  }
  puVar1 = (undefined4 *)in_ECX[0x19];
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    FUN_00745bd0(param_1,param_2);
  }
  return;
}

