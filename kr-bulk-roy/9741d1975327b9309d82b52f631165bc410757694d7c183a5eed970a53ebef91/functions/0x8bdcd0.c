
void FUN_008bdcd0(void)

{
  undefined4 *puVar1;
  
  puVar1 = _malloc(0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = FUN_008bdb60;
    puVar1[3] = FUN_008bdb80;
    puVar1[2] = FUN_008bdba0;
  }
  return;
}

