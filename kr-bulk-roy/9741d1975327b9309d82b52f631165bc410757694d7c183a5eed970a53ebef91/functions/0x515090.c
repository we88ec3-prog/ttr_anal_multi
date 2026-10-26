
void FUN_00515090(void)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  uint local_10;
  
  if (in_EAX != 0) {
    iVar1 = FUN_0072e360();
    while (iVar1 != 0) {
      iVar1 = FUN_007300a0("CLASS");
      if (iVar1 != 0) {
        puVar2 = (undefined4 *)(iVar1 + 0x30);
        if (0xf < *(uint *)(iVar1 + 0x44)) {
          puVar2 = (undefined4 *)*puVar2;
        }
        if (puVar2 != (undefined4 *)0x0) {
          FUN_008917b4(puVar2);
        }
      }
      iVar1 = FUN_007300a0(&DAT_00c0e1d8);
      if (iVar1 == 0) {
LAB_00515124:
        local_10 = 0;
      }
      else {
        puVar2 = (undefined4 *)(iVar1 + 0x30);
        if (0xf < *(uint *)(iVar1 + 0x44)) {
          puVar2 = (undefined4 *)*puVar2;
        }
        if (puVar2 == (undefined4 *)0x0) goto LAB_00515124;
        local_10 = FUN_008917b4(puVar2);
      }
      iVar1 = FUN_007300a0(&DAT_00c0e44c);
      if (iVar1 == 0) {
LAB_00515154:
        uVar3 = 0;
      }
      else {
        puVar2 = (undefined4 *)(iVar1 + 0x30);
        if (0xf < *(uint *)(iVar1 + 0x44)) {
          puVar2 = (undefined4 *)*puVar2;
        }
        if (puVar2 == (undefined4 *)0x0) goto LAB_00515154;
        uVar3 = FUN_008917b4(puVar2);
      }
      piVar4 = (int *)FUN_00515800(&DAT_00fe3040);
      if ((uint)(piVar4[1] - *piVar4 >> 4) <= uVar3) {
        FUN_00655d40();
      }
      piVar6 = (int *)(uVar3 * 0x10 + *piVar4);
      if ((uint)(piVar6[1] - *piVar6 >> 2) <= local_10) {
        FUN_005f7e40(local_10 + 1);
      }
      iVar1 = FUN_007300a0("CHARGE");
      if (iVar1 == 0) {
LAB_005151c7:
        uVar5 = 0;
      }
      else {
        puVar2 = (undefined4 *)(iVar1 + 0x30);
        if (0xf < *(uint *)(iVar1 + 0x44)) {
          puVar2 = (undefined4 *)*puVar2;
        }
        if (puVar2 == (undefined4 *)0x0) goto LAB_005151c7;
        uVar5 = FUN_008917b4(puVar2);
      }
      *(undefined4 *)(*(int *)(*piVar4 + uVar3 * 0x10) + local_10 * 4) = uVar5;
      iVar1 = FUN_0072e3c0();
    }
  }
  return;
}

