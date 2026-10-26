
void FUN_005b3e20(int param_1)

{
  undefined1 *puVar1;
  undefined4 in_ECX;
  
  FUN_005b7c50(param_1);
  puVar1 = *(undefined1 **)(param_1 + 0x10);
  if (puVar1 == (undefined1 *)0xf4294) {
    FUN_005b3fe0(in_ECX);
  }
  else {
    if (puVar1 == (undefined1 *)0xf4295) {
      FUN_005b43d0();
      return;
    }
    if (puVar1 == &DAT_000f4296) {
      FUN_005b44c0();
      return;
    }
  }
  return;
}

