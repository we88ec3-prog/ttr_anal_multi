
void FUN_008e1dd0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  
  puVar1 = (undefined4 *)FUN_008b9f30();
  *puVar1 = unaff_ESI;
  puVar1[1] = param_1;
  puVar1[0x62] = puVar1 + 2;
  return;
}

