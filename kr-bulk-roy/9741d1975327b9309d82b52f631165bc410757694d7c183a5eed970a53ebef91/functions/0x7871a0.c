
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_007871a0(void)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_00891268(0x28);
  if (piVar1 != (int *)0x0) {
    piVar1[2] = (int)gbORT::vftable;
    piVar1[3] = 1;
    piVar1[4] = 1;
    *(undefined1 *)(piVar1 + 5) = 0;
    *piVar1 = (int)gbHybridTrack<gbVec3<float>_>::vftable;
    piVar1[6] = 0;
    piVar1[7] = 0;
    piVar1[8] = 0;
    piVar1[1] = 4;
    (**(code **)(*piVar1 + 0xc))();
    return piVar1;
  }
  (**(code **)(_DAT_00000000 + 0xc))();
  return (int *)0x0;
}

