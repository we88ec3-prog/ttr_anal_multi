
undefined4 FUN_0070cc40(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = param_1;
  iVar3 = FUN_006fee90(&param_1,4);
  if (iVar3 != 0) {
    FUN_0070cc10();
  }
  puVar2 = param_1;
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  uVar4 = FUN_006fef20();
  iVar3 = FUN_006fee90(uVar4,puVar2);
  if (iVar3 != 0) {
    FUN_0070cc10();
  }
  uVar4 = FUN_006fec70(*puVar1,uVar4,(int)param_1 + -1);
  return uVar4;
}

