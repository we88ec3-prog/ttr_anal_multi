
undefined4 FUN_0075bfb0(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  int in_ECX;
  
  cVar1 = FUN_00748c40(param_1);
  if (cVar1 != '\0') {
    FUN_00744710(param_1);
    uVar2 = FUN_00765120(*(undefined1 *)(in_ECX + 0xa4));
    *(undefined1 *)(in_ECX + 0xa4) = uVar2;
    FUN_00776ca0(param_1);
    return 1;
  }
  return 0;
}

