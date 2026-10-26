
uint * FUN_00719da0(uint *param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_ESI;
  
  FUN_0071ba40(unaff_ESI);
  puVar1 = param_1;
  while( true ) {
    if (puVar1 == (uint *)0x0) {
      *param_1 = 0;
      return param_1;
    }
    if ((*puVar1 & 7) == 1) break;
    puVar2 = (undefined4 *)FUN_0071bb00(unaff_ESI);
    puVar1 = (uint *)*puVar2;
  }
  *param_1 = (uint)puVar1;
  return param_1;
}

