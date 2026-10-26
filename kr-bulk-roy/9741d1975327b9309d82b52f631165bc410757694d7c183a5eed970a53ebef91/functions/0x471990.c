
undefined4 FUN_00471990(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  int in_ECX;
  
  cVar1 = FUN_00748c40(param_1);
  if (cVar1 != '\0') {
    FUN_00744710(param_1);
    FUN_00429860(in_ECX + 0xd0);
    FUN_00429860(in_ECX + 0xd4);
    FUN_00429860(in_ECX + 0xd8);
    uVar2 = FUN_00765120(*(undefined1 *)(in_ECX + 0xe0));
    *(undefined1 *)(in_ECX + 0xe0) = uVar2;
    return 1;
  }
  return 0;
}

