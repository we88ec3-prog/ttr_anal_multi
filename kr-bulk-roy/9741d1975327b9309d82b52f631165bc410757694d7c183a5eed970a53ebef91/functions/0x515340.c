
void FUN_00515340(void)

{
  undefined1 uVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  undefined2 local_c;
  
  if (in_EAX != 0) {
    iVar2 = FUN_0072e360();
    while (iVar2 != 0) {
      iVar2 = FUN_007300a0("RANK_SUM");
      if (iVar2 != 0) {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 != (undefined4 *)0x0) {
          FUN_008917b4(puVar3);
        }
      }
      iVar2 = FUN_007300a0("CHARGE");
      if (iVar2 == 0) {
LAB_005153ce:
        local_c = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_005153ce;
        local_c = FUN_008917b4(puVar3);
      }
      iVar2 = FUN_007300a0(&DAT_00c0e484);
      if (iVar2 == 0) {
LAB_005153fe:
        uVar1 = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_005153fe;
        uVar1 = FUN_008917b4(puVar3);
      }
      puVar4 = (undefined2 *)FUN_00515a90();
      *puVar4 = local_c;
      iVar2 = FUN_00515a90();
      *(undefined1 *)(iVar2 + 2) = uVar1;
      iVar2 = FUN_0072e3c0();
    }
  }
  return;
}

