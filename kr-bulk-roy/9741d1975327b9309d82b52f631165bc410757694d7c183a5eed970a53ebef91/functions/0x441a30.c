
void FUN_00441a30(void)

{
  int *piVar1;
  int in_ECX;
  
  FUN_004067f0();
  *(undefined4 *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0xb0) = 0;
  piVar1 = *(int **)(in_ECX + 0x140);
  if ((piVar1 != (int *)0x0) && (((uint)piVar1[10] >> 8 & 1) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x00441a6d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0xd4))();
    return;
  }
  return;
}

