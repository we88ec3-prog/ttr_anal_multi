
undefined4 FUN_00754c20(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  cVar1 = FUN_00754350(param_1);
  if (cVar1 != '\0') {
    FUN_0075a620(in_ECX + 0xcc);
    FUN_00776210(param_1);
    uVar3 = FUN_00764fb0(0xff000000);
    *(undefined4 *)(in_ECX + 0x154) = uVar3;
    uVar3 = FUN_00764fb0(5);
    *(undefined4 *)(in_ECX + 0x120) = uVar3;
    uVar3 = FUN_00764fb0(2);
    *(undefined4 *)(in_ECX + 0x124) = uVar3;
    uVar2 = FUN_00765120(1);
    *(undefined1 *)(in_ECX + 200) = uVar2;
    return 1;
  }
  return 0;
}

