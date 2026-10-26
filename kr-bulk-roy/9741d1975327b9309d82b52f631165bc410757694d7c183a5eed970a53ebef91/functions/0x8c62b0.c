
undefined4 FUN_008c62b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  int iVar6;
  
  puVar5 = (undefined1 *)FUN_008c6180(param_3);
  if (puVar5 == (undefined1 *)0x0) {
    return 0xffffffff;
  }
  uVar1 = puVar5[4];
  uVar2 = puVar5[5];
  uVar3 = puVar5[6];
  uVar4 = puVar5[7];
  if (CONCAT31(CONCAT21(CONCAT11(*puVar5,puVar5[1]),puVar5[2]),puVar5[3]) != 0) {
    iVar6 = FUN_008c6070(param_2);
    if (iVar6 != 0) {
      return 1;
    }
  }
  if (CONCAT31(CONCAT21(CONCAT11(uVar1,uVar2),uVar3),uVar4) != 0) {
    iVar6 = FUN_008c60f0(param_2);
    if (iVar6 != 0) {
      return 0;
    }
  }
  return 0xffffffff;
}

