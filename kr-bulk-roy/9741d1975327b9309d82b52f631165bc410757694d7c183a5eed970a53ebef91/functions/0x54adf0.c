
undefined4 * FUN_0054adf0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00891268(8);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = SubAI::CTierCheckCondition::vftable;
    puVar1[1] = 0;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

