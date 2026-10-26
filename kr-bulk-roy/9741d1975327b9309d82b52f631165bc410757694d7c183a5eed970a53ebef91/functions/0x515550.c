
undefined4 FUN_00515550(uint param_1,uint param_2,undefined1 param_3)

{
  int in_EAX;
  int in_ECX;
  
  FUN_00835c70(&param_1);
  if (in_ECX != *(int *)(in_EAX + 0x24)) {
    param_1 = (param_2 & 0xff) << 0x10;
    param_1 = CONCAT13(param_3,(undefined3)param_1);
    param_1 = param_1 >> 0x10;
    FUN_00826280(&param_1);
    if (param_2 != *(uint *)(in_ECX + 0x14)) {
      return *(undefined4 *)(param_2 + 0x10);
    }
  }
  return 0;
}

