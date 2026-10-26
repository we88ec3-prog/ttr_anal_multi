
undefined4 FUN_00744c50(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_00754cc0(param_1);
  if (cVar1 != '\0') {
    FUN_00764b00(*(undefined1 *)(in_ECX + 0x158));
    FUN_00776bf0(param_1);
    return 1;
  }
  return 0;
}

