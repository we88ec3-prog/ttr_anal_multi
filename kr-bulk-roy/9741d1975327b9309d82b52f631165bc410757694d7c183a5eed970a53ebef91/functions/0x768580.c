
undefined4 FUN_00768580(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_00769370(param_1);
  if (cVar1 != '\0') {
    FUN_00756110(*(undefined1 *)(in_ECX + 300));
    FUN_007648e0(*(undefined4 *)(in_ECX + 0x124));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0x128));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0x130));
    FUN_00764b00(*(undefined1 *)(in_ECX + 0x148));
    return 1;
  }
  return 0;
}

