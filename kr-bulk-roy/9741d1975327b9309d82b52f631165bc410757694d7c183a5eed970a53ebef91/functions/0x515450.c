
void FUN_00515450(void)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  if (in_EAX != 0) {
    iVar1 = FUN_0072e360();
    while (iVar1 != 0) {
      iVar1 = FUN_007300a0("GRADE");
      if (iVar1 != 0) {
        puVar2 = (undefined4 *)(iVar1 + 0x30);
        if (0xf < *(uint *)(iVar1 + 0x44)) {
          puVar2 = (undefined4 *)*puVar2;
        }
        if (puVar2 != (undefined4 *)0x0) {
          FUN_008917b4(puVar2);
        }
      }
      iVar1 = FUN_007300a0("SAFE_MATERIAL_ITEM");
      if (iVar1 == 0) {
LAB_005154d3:
        local_8 = 0;
      }
      else {
        puVar2 = (undefined4 *)(iVar1 + 0x30);
        if (0xf < *(uint *)(iVar1 + 0x44)) {
          puVar2 = (undefined4 *)*puVar2;
        }
        if (puVar2 == (undefined4 *)0x0) goto LAB_005154d3;
        local_8 = FUN_008917b4(puVar2);
      }
      iVar1 = FUN_007300a0("REFINE_STONE_ITEM");
      if (iVar1 == 0) {
LAB_00515503:
        uVar3 = 0;
      }
      else {
        puVar2 = (undefined4 *)(iVar1 + 0x30);
        if (0xf < *(uint *)(iVar1 + 0x44)) {
          puVar2 = (undefined4 *)*puVar2;
        }
        if (puVar2 == (undefined4 *)0x0) goto LAB_00515503;
        uVar3 = FUN_008917b4(puVar2);
      }
      puVar2 = (undefined4 *)FUN_00515b10();
      *puVar2 = local_8;
      iVar1 = FUN_00515b10();
      *(undefined4 *)(iVar1 + 4) = uVar3;
      iVar1 = FUN_0072e3c0();
    }
  }
  return;
}

