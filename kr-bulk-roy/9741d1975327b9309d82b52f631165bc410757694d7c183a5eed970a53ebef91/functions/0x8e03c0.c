
void FUN_008e03c0(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  int iVar1;
  
  if (*(char *)(in_EAX + 0x40) == '\0') {
    *(undefined1 *)(in_EAX + 0x40) = 1;
    iVar1 = FUN_008e0360();
    if (iVar1 == 0) {
      FUN_008e0330(param_1,param_2);
    }
  }
  return;
}

