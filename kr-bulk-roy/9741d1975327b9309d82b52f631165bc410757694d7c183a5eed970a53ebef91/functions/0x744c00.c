
undefined4 FUN_00744c00(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  int in_ECX;
  
  cVar1 = FUN_00754c20(param_1);
  if (cVar1 != '\0') {
    uVar2 = FUN_00765120(*(undefined1 *)(in_ECX + 0x158));
    *(undefined1 *)(in_ECX + 0x158) = uVar2;
    FUN_00776ca0(param_1);
    return 1;
  }
  return 0;
}

