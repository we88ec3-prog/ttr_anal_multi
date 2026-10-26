
int * FUN_00787680(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)FUN_00891268(0x24);
  piVar2 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    piVar1[2] = (int)gbORT::vftable;
    piVar1[3] = 1;
    piVar1[4] = 1;
    *piVar1 = (int)gbLinTrack<gbQuat>::vftable;
    piVar1[5] = 0;
    piVar1[6] = 0;
    piVar1[7] = 0;
    piVar1[1] = 2;
    piVar2 = piVar1;
  }
  (**(code **)(*piVar2 + 0xc))();
  return piVar2;
}

