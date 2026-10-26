
undefined4 FUN_00762720(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_00769370(param_1);
  if (cVar1 != '\0') {
    FUN_007649b0(*(undefined1 *)(in_ECX + 0x140));
    FUN_007649b0(*(undefined1 *)(in_ECX + 0x141));
    FUN_00764b00(*(undefined1 *)(in_ECX + 0x150));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0x144));
    return 1;
  }
  return 0;
}

