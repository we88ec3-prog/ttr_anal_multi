
undefined4 FUN_004c8e80(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x15c);
  if (((iVar1 != 0) && (*(int *)(in_ECX + 0x370) != 0)) && (*(int *)(iVar1 + 0xac) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x004c8ea9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(**(int **)(iVar1 + 0xac) + 0x38))();
    return uVar2;
  }
  return 0;
}

