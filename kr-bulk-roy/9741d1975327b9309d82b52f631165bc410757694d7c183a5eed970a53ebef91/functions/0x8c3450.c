
int FUN_008c3450(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((char)param_3 == '\0') {
    uVar2 = 0x686d7478;
    puVar4 = (undefined4 *)(param_1 + 0x310);
    puVar3 = (undefined4 *)(param_1 + 0x2ac);
  }
  else {
    uVar2 = 0x766d7478;
    puVar4 = (undefined4 *)(param_1 + 0x314);
    puVar3 = (undefined4 *)(param_1 + 0x2b4);
  }
  iVar1 = (**(code **)(param_1 + 0x1fc))(param_1,uVar2,param_2,&param_3);
  if (iVar1 == 0) {
    *puVar3 = param_3;
    uVar2 = FUN_008b9850(param_2);
    *puVar4 = uVar2;
  }
  return iVar1;
}

