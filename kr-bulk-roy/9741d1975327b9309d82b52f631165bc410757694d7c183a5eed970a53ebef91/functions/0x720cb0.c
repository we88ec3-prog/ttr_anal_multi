
void FUN_00720cb0(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x14) != 8) {
    FUN_00720bf0();
    return;
  }
  FUN_0071d0d0();
  uVar1 = FUN_00720cb0();
  puVar2 = (undefined4 *)FUN_0071bdb0();
  if (puVar2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0071f670();
  }
  *puVar2 = 0x20d;
  puVar2[1] = uVar1;
  puVar2[2] = 0;
  puVar2[3] = 0;
  return;
}

