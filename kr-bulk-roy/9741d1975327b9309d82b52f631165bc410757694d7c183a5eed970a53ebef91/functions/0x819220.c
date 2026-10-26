
undefined4 FUN_00819220(undefined4 *param_1,char param_2)

{
  int in_EAX;
  int in_ECX;
  
  FUN_008195e0(&param_1);
  if (in_ECX == *(int *)(in_EAX + 4)) {
    return 0;
  }
  FUN_008196d0();
  if (*(undefined4 **)(in_ECX + 0x14) == param_1) {
    if (param_2 != '\0') {
      return 0;
    }
    if (*(int *)(in_ECX + 0x18) == 0) {
      return 0;
    }
    param_1 = (undefined4 *)**(undefined4 **)(in_ECX + 0x14);
  }
  return param_1[4];
}

