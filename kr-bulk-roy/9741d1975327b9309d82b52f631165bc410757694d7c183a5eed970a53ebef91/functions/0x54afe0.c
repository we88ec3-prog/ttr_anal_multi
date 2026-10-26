
/* WARNING: Removing unreachable block (ram,0x0054b00b) */

undefined4 * FUN_0054afe0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = SubAI::CPhaseCondition::vftable;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar2 = puVar1;
  }
  return puVar2;
}

