
void FUN_00874c40(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x30);
  *param_1 = *(undefined4 *)*puVar1;
  param_1[1] = *(undefined4 *)puVar1[(*(int *)(in_ECX + 0x34) - (int)puVar1 >> 2) + -1];
  return;
}

