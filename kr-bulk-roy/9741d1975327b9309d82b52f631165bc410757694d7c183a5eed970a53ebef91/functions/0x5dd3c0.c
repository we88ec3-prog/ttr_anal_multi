
void FUN_005dd3c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 char param_5)

{
  int in_EAX;
  undefined4 in_EDX;
  undefined4 unaff_ESI;
  
  FUN_005d7240(in_EDX,unaff_ESI,param_1,param_2);
  FUN_005d7af0(param_3);
  FUN_005dd050(*(undefined4 *)(in_EAX + 0x248),*(undefined4 *)(in_EAX + 0x24c));
  FUN_005dd110(unaff_ESI);
  (**(code **)(**(int **)(in_EAX + 0x2a4) + 0x94))(0);
  *(undefined1 *)(in_EAX + 0x2a1) = 0;
  (**(code **)(**(int **)(in_EAX + 0x2b0) + 0x94))(param_4);
  if (((*(int *)(in_EAX + 0x25c) == 0) || (*(char *)(in_EAX + 0x2cc) != '\0')) ||
     (*(char *)(in_EAX + 0x2a1) != '\0')) {
    if ((*(uint *)(in_EAX + 0x28) & 8) != 0) {
      *(uint *)(in_EAX + 0x28) = *(uint *)(in_EAX + 0x28) ^ 8;
    }
  }
  else {
    *(uint *)(in_EAX + 0x28) = *(uint *)(in_EAX + 0x28) | 8;
  }
  (**(code **)(**(int **)(in_EAX + 700) + 0x94))(param_5 == '\0');
  return;
}

