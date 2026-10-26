
undefined4 FUN_008c6200(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uVar7;
  
  puVar5 = (undefined1 *)FUN_008c6180(param_4);
  if (puVar5 == (undefined1 *)0x0) {
    return 0;
  }
  uVar1 = puVar5[4];
  uVar2 = puVar5[5];
  uVar3 = puVar5[6];
  uVar4 = puVar5[7];
  if (CONCAT31(CONCAT21(CONCAT11(*puVar5,puVar5[1]),puVar5[2]),puVar5[3]) != 0) {
    iVar6 = FUN_008c6070(param_3);
    if (iVar6 != 0) {
      uVar7 = (**(code **)(*(int *)(param_2 + 0xc) + 0xc))(param_2,param_3);
      return uVar7;
    }
  }
  if (CONCAT31(CONCAT21(CONCAT11(uVar1,uVar2),uVar3),uVar4) != 0) {
    uVar7 = FUN_008c60f0(param_3);
    return uVar7;
  }
  return 0;
}

