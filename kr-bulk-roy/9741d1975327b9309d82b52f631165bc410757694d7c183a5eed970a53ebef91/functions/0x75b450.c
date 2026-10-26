
undefined4 FUN_0075b450(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  
  cVar1 = FUN_00754350(param_1);
  if (cVar1 != '\0') {
    FUN_00776210(param_1);
    uVar2 = FUN_00764fb0(0xff000000);
    *(undefined4 *)(in_ECX + 0xfc) = uVar2;
    uVar2 = FUN_00764fb0(5);
    *(undefined4 *)(in_ECX + 0xcc) = uVar2;
    uVar2 = FUN_00764fb0(2);
    *(undefined4 *)(in_ECX + 200) = uVar2;
    return 1;
  }
  return 0;
}

