
undefined4 * FUN_00803980(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00891268(0x5c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = IS3D::CGravitonSpear::vftable;
    FUN_00803c90();
    return puVar1;
  }
  return (undefined4 *)0x0;
}

