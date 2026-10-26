
undefined4 FUN_0075bf00(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_007543c0(param_1);
  if (cVar1 != '\0') {
    FUN_00756110(*(undefined1 *)(in_ECX + 0xd4));
    FUN_007648e0(*(undefined4 *)(in_ECX + 0xd0));
    return 1;
  }
  return 0;
}

