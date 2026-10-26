
void FUN_005768b0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (*(int *)(iVar1 + 4) != 0) {
    (**(code **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4))();
    (**(code **)(*(int *)(*(int *)(iVar1 + 8) + 4) + 4))();
                    /* WARNING: Could not recover jumptable at 0x005768e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(*(int *)(iVar1 + 0xc) + 4) + 4))();
    return;
  }
  return;
}

