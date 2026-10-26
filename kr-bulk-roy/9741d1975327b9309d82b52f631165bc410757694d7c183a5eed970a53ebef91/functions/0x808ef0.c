
int FUN_00808ef0(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  undefined4 *puVar4;
  
  (**(code **)(*unaff_ESI + 0x14))();
  puVar1 = (undefined4 *)FUN_00891268(0x24);
  iVar3 = 1;
  puVar4 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[8] = 1;
    puVar4 = puVar1;
  }
  iVar2 = FUN_0072e2e0("CONDITIONLIST");
  if ((iVar2 != 0) && (iVar2 = FUN_00808fa0(param_1,puVar4), iVar2 == 0)) {
    iVar3 = 0;
  }
  iVar2 = FUN_0072e2e0("ACTIONLIST");
  if (((iVar2 == 0) || (iVar2 = FUN_008090f0(param_1,puVar4), iVar2 != 0)) && (iVar3 != 0)) {
    FUN_007bb350();
    return iVar3;
  }
  if (puVar4 != (undefined4 *)0x0) {
    FUN_008097e0(puVar4);
    FUN_0089120c(puVar4);
  }
  return 0;
}

