
undefined4 * FUN_0071bcf0(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  char cVar3;
  undefined1 *unaff_EDI;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 *local_8;
  
  puVar1 = param_2;
  FUN_0071bc90(param_1);
  FUN_0071bc20();
  if (param_3 < 4) {
    param_2 = (undefined4 *)0x1;
  }
  else {
    param_2 = (undefined4 *)FUN_0071a680(*unaff_EDI,unaff_EDI[3]);
  }
  local_8 = (undefined1 *)0x0;
  param_3 = 0;
  cVar3 = FUN_0071a720(&local_8,&param_3);
  puVar2 = local_8;
  if (cVar3 == '\0') {
    puVar1[2] = 0;
    puVar1[1] = 0;
    *puVar1 = 3;
    return puVar1;
  }
  FUN_0071b910(&local_14,local_8,param_3,*param_1);
  if (puVar2 != unaff_EDI) {
    param_1[1] = puVar2;
  }
  *puVar1 = local_14;
  puVar1[1] = local_10;
  puVar1[2] = param_2;
  return puVar1;
}

