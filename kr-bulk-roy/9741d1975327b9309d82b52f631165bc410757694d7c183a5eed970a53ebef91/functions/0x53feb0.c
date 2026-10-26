
void FUN_0053feb0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  for (piVar1 = (int *)FUN_0072e2e0("Shout"); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x10]) {
    iVar2 = (**(code **)(*piVar1 + 0x14))();
    if (iVar2 != 0) {
      iVar2 = FUN_007300a0("talkidx");
      if (iVar2 != 0) {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 != (undefined4 *)0x0) {
          FUN_008917b4(puVar3);
        }
      }
      FUN_004a8680();
    }
  }
  return;
}

