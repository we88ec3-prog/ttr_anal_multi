
undefined4 FUN_00506a30(void)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(in_EAX + 0x18);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    iVar2 = (**(code **)(*piVar1 + 0x18))();
    if (iVar2 != 0) break;
    piVar1 = (int *)piVar1[0x10];
  }
                    /* WARNING: Could not recover jumptable at 0x00506a58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(*piVar1 + 0x18))();
  return uVar3;
}

