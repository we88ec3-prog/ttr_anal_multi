
undefined4 FUN_007692c0(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  cVar1 = FUN_00754350(param_1);
  if (cVar1 != '\0') {
    FUN_00776210(param_1);
    uVar3 = FUN_00764fb0(*(undefined4 *)(in_ECX + 0xf8));
    *(undefined4 *)(in_ECX + 0xf8) = uVar3;
    uVar3 = FUN_00764fb0(*(undefined4 *)(in_ECX + 0x104));
    *(undefined4 *)(in_ECX + 0x104) = uVar3;
    uVar3 = FUN_00764fb0(*(undefined4 *)(in_ECX + 0xfc));
    *(undefined4 *)(in_ECX + 0xfc) = uVar3;
    uVar3 = FUN_00764fb0(0);
    *(undefined4 *)(in_ECX + 0x100) = uVar3;
    uVar2 = FUN_00765120(1);
    *(undefined1 *)(in_ECX + 0xc9) = uVar2;
    return 1;
  }
  return 0;
}

