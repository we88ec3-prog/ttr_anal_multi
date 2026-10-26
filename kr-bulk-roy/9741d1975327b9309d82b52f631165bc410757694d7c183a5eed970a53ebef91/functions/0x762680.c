
undefined4 FUN_00762680(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int in_ECX;
  
  cVar1 = FUN_007692c0(param_1);
  if (cVar1 != '\0') {
    iVar3 = FUN_00764fb0(*(undefined1 *)(in_ECX + 0x140));
    *(bool *)(in_ECX + 0x140) = iVar3 != 0;
    iVar3 = FUN_00764fb0(*(undefined1 *)(in_ECX + 0x141));
    *(bool *)(in_ECX + 0x141) = iVar3 != 0;
    uVar2 = FUN_00765120(*(undefined1 *)(in_ECX + 0x150));
    *(undefined1 *)(in_ECX + 0x150) = uVar2;
    FUN_00429860(in_ECX + 0x144);
    return 1;
  }
  return 0;
}

