
void FUN_00514b70(void)

{
  undefined1 uVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined1 local_18 [8];
  undefined4 local_10;
  undefined2 local_c;
  undefined4 local_8;
  
  if (in_EAX != 0) {
    iVar2 = FUN_0072e360();
    while (iVar2 != 0) {
      iVar2 = FUN_007300a0("EQUIP");
      uVar1 = 0;
      if (iVar2 == 0) {
LAB_00514bc5:
        local_8 = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_00514bc5;
        local_8 = FUN_008917b4(puVar3);
      }
      local_10 = CONCAT31(local_10._1_3_,(undefined1)local_8);
      iVar2 = FUN_007300a0("LEVEL");
      if (iVar2 != 0) {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 != (undefined4 *)0x0) {
          uVar1 = FUN_008917b4(puVar3);
        }
      }
      local_10._0_2_ = CONCAT11(uVar1,(undefined1)local_10);
      iVar2 = FUN_007300a0("RATIO");
      if (iVar2 == 0) {
LAB_00514c21:
        uVar1 = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_00514c21;
        uVar1 = FUN_008917b4(puVar3);
      }
      local_c = CONCAT11(uVar1,(undefined1)local_c);
      iVar2 = FUN_007300a0("SUCCESS");
      if (iVar2 == 0) {
LAB_00514c4e:
        uVar1 = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_00514c4e;
        uVar1 = FUN_008917b4(puVar3);
      }
      local_10._0_3_ = CONCAT12(uVar1,(undefined2)local_10);
      iVar2 = FUN_007300a0(&DAT_00c0e404);
      if (iVar2 == 0) {
LAB_00514c7b:
        uVar1 = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_00514c7b;
        uVar1 = FUN_008917b4(puVar3);
      }
      local_10 = CONCAT13(uVar1,(undefined3)local_10);
      iVar2 = FUN_007300a0("BROKEN");
      if (iVar2 == 0) {
LAB_00514ca8:
        uVar1 = 0;
      }
      else {
        puVar3 = (undefined4 *)(iVar2 + 0x30);
        if (0xf < *(uint *)(iVar2 + 0x44)) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_00514ca8;
        uVar1 = FUN_008917b4(puVar3);
      }
      local_c = CONCAT11(local_c._1_1_,uVar1);
      uVar4 = FUN_00518d30();
      FUN_00517760(local_18,uVar4);
      iVar2 = FUN_0072e3c0();
    }
  }
  return;
}

