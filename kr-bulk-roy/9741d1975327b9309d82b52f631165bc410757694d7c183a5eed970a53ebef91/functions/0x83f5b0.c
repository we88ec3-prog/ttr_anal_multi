
void FUN_0083f5b0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *unaff_ESI;
  
  puVar1 = (undefined4 *)FUN_00820120();
  *puVar1 = param_1;
  puVar1[1] = param_2;
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = *unaff_ESI;
    puVar1[3] = unaff_ESI[1];
    puVar1[4] = unaff_ESI[2];
    puVar1[5] = unaff_ESI[3];
    puVar1[6] = unaff_ESI[4];
  }
  return;
}

