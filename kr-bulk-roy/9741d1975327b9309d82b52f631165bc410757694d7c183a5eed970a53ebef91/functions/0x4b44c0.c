
void FUN_004b44c0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_0040f060();
                    /* WARNING: Could not recover jumptable at 0x004b44d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)*puVar1 + 4))();
  return;
}

