
void FUN_00720a00(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0x14) == 0x10) {
    FUN_0071d0d0();
    puVar2 = (undefined4 *)FUN_0071bdb0();
    if (puVar2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0071f670();
    }
    *puVar2 = 0x139;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    iVar1 = *(int *)(param_1 + 0x14);
    if ((((iVar1 != 0x14) && (iVar1 != 0x16)) && (iVar1 != 0x17)) && (iVar1 != 0x18)) {
      if (iVar1 != 9) {
        return;
      }
      FUN_00720950(param_1);
      return;
    }
  }
  else if (*(int *)(param_1 + 0x14) == 0x11) {
    FUN_0071d0d0();
    puVar2 = (undefined4 *)FUN_0071bdb0();
    if (puVar2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0071f670();
    }
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    *puVar2 = 0x139;
    puVar3 = (undefined4 *)FUN_0071bdb0();
    if (puVar3 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_0071f670();
    }
    *puVar3 = 0x2050138;
    puVar3[1] = puVar2;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    FUN_00720950(param_1);
    return;
  }
  FUN_00720950(param_1);
  return;
}

