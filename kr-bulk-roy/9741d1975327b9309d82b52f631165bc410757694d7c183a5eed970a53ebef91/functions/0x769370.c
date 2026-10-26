
undefined4 FUN_00769370(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_007543c0(param_1);
  if (cVar1 != '\0') {
    FUN_00776320(param_1);
    FUN_007649b0(*(undefined4 *)(in_ECX + 0xf8));
    FUN_007649b0(*(undefined4 *)(in_ECX + 0x104));
    FUN_007649b0(*(undefined4 *)(in_ECX + 0xfc));
    FUN_007649b0(*(undefined4 *)(in_ECX + 0x100));
    FUN_00764b00(*(undefined1 *)(in_ECX + 0xc9));
    return 1;
  }
  return 0;
}

