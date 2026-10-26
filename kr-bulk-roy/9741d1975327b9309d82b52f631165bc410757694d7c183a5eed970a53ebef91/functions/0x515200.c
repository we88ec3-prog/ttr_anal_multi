
void FUN_00515200(void)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_c;
  undefined1 local_5;
  
  if (in_EAX != 0) {
    iVar1 = FUN_0072e360();
    while (iVar1 != 0) {
      iVar1 = FUN_007300a0("CLASS");
      if (iVar1 == 0) {
LAB_00515257:
        local_c = 0;
      }
      else {
        puVar2 = (undefined4 *)(iVar1 + 0x30);
        if (0xf < *(uint *)(iVar1 + 0x44)) {
          puVar2 = (undefined4 *)*puVar2;
        }
        if (puVar2 == (undefined4 *)0x0) goto LAB_00515257;
        local_c = FUN_008917b4(puVar2);
      }
      iVar1 = FUN_007300a0(&DAT_00c0e1d8);
      if (iVar1 != 0) {
        puVar2 = (undefined4 *)(iVar1 + 0x30);
        if (0xf < *(uint *)(iVar1 + 0x44)) {
          puVar2 = (undefined4 *)*puVar2;
        }
        if (puVar2 != (undefined4 *)0x0) {
          FUN_008917b4(puVar2);
        }
      }
      iVar1 = FUN_007300a0("REINFORCE_CHARGE");
      if (iVar1 != 0) {
        puVar2 = (undefined4 *)(iVar1 + 0x30);
        if (0xf < *(uint *)(iVar1 + 0x44)) {
          puVar2 = (undefined4 *)*puVar2;
        }
        if (puVar2 != (undefined4 *)0x0) {
          FUN_008917b4(puVar2);
        }
      }
      iVar1 = FUN_007300a0("EXTRACT_CHARGE");
      if (iVar1 != 0) {
        puVar2 = (undefined4 *)(iVar1 + 0x30);
        if (0xf < *(uint *)(iVar1 + 0x44)) {
          puVar2 = (undefined4 *)*puVar2;
        }
        if (puVar2 != (undefined4 *)0x0) {
          FUN_008917b4(puVar2);
        }
      }
      local_5 = local_c;
      uVar3 = FUN_005158e0(&local_5);
      uVar4 = FUN_00821c50();
      FUN_00517bf0(uVar3,uVar4);
      iVar1 = FUN_0072e3c0();
    }
  }
  return;
}

