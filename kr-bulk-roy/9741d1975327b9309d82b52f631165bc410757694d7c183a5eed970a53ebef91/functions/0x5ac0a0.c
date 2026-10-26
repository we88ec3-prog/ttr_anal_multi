
void FUN_005ac0a0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x164);
  if (((*(uint *)(iVar1 + 0x28) >> 8 & 1) != 0) && (*(char *)(iVar1 + 0xa8) != '\0')) {
    FUN_00654f90(*(undefined4 *)(iVar1 + 0xb0));
                    /* WARNING: Could not recover jumptable at 0x005ac0d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(iVar1 + 0xb0) + 200))();
    return;
  }
  return;
}

