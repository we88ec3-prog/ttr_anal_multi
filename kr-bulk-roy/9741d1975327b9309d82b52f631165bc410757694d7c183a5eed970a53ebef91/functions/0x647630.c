
void FUN_00647630(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  FUN_00755e50();
  FUN_00647cc0();
  piVar1 = (int *)(in_ECX + 0xfc);
  FUN_00647db0();
  FUN_006a9d90();
  FUN_006afdc0();
  if ((*(int *)(*piVar1 + 0x24c) != 0) &&
     (iVar2 = *(int *)(*(int *)(*piVar1 + 0x24c) + 0xcc), iVar2 != 0)) {
    FUN_006438f0(iVar2);
  }
  FUN_00757710();
  FUN_0075cbb0(&DAT_00c306d0);
  FUN_0075cbb0(&DAT_00c306d8);
  FUN_0075cbb0(&DAT_00c306e0);
  FUN_0075cbb0(&DAT_00c306e8);
  FUN_0075cbb0(&DAT_00c306f0);
  FUN_0075cd30(*piVar1);
  if (*(int *)(*piVar1 + 0x24c) != 0) {
    FUN_00749920(*(int *)(*piVar1 + 0x24c));
  }
                    /* WARNING: Could not recover jumptable at 0x00647701. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)*piVar1 + 200))();
  return;
}

