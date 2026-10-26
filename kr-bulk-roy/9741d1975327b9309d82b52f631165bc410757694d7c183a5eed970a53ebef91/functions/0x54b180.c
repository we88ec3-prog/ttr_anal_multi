
undefined4 * FUN_0054b180(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00891268(0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = SubAI::CMoveAction::vftable;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

