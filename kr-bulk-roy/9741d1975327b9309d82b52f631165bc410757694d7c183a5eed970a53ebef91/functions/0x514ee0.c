
undefined4 FUN_00514ee0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_EAX;
  int in_ECX;
  
  FUN_00835c70(&param_1);
  if (in_ECX != *(int *)(in_EAX + 0x80)) {
    FUN_00835c70(&stack0x00000008);
    puVar1 = param_1;
    if (param_1 != *(undefined4 **)(in_ECX + 0x14)) {
      FUN_008438c0(&stack0x0000000c);
      if (param_1 == (undefined4 *)puVar1[5]) {
        param_1 = *(undefined4 **)puVar1[5];
      }
      return param_1[4];
    }
  }
  return 0;
}

